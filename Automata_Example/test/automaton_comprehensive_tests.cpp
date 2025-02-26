#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include "automaton.h"
#include <vector>
#include <map>
#include <stdexcept>

using std::vector;
using std::map;
using std::string;

// Test fixture for common automaton setups
class AutomatonFixture {
public:
    // DFA for strings ending with 'b'
    Automaton createEndsWithBAutomaton() {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {0, 1},  // State 0: 'a' stays at 0, 'b' goes to 1
            {0, 1}   // State 1: 'a' goes to 0, 'b' stays at 1
        };
        vector<int> accepting_states = {1};
        return Automaton(alphabet, transitions, accepting_states);
    }
    
    // DFA that accepts only strings with odd number of 'a's
    Automaton createOddNumberOfAsAutomaton() {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {1, 0},  // State 0 (even # of a's): 'a' -> 1, 'b' -> 0
            {0, 1}   // State 1 (odd # of a's):  'a' -> 0, 'b' -> 1
        };
        vector<int> accepting_states = {1};
        return Automaton(alphabet, transitions, accepting_states);
    }
    
    // DFA that accepts only the empty string
    Automaton createEmptyStringOnlyAutomaton() {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {2, 2},  // State 0 (initial & accepting): any input -> 2 (sink)
            {2, 2},  // State 1 (unused)
            {2, 2}   // State 2 (sink, non-accepting)
        };
        vector<int> accepting_states = {0};
        return Automaton(alphabet, transitions, accepting_states);
    }
    
    // DFA that accepts any string (always accepting)
    Automaton createAlwaysAcceptingAutomaton() {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {0, 0}  // State 0: all inputs loop back to 0
        };
        vector<int> accepting_states = {0};
        return Automaton(alphabet, transitions, accepting_states);
    }
};

TEST_CASE_METHOD(AutomatonFixture, "Basic DFA functionality", "[automaton][basic]") {
    SECTION("Strings ending with 'b'") {
        auto dfa = createEndsWithBAutomaton();
        
        // Positive cases
        REQUIRE(dfa.Read("b"));
        REQUIRE(dfa.Read("ab"));
        REQUIRE(dfa.Read("aab"));
        REQUIRE(dfa.Read("bab"));
        REQUIRE(dfa.Read("bbbbbb"));
        
        // Negative cases
        REQUIRE_FALSE(dfa.Read(""));
        REQUIRE_FALSE(dfa.Read("a"));
        REQUIRE_FALSE(dfa.Read("ba"));
        REQUIRE_FALSE(dfa.Read("aba"));
    }
    
    SECTION("Odd number of 'a's") {
        auto dfa = createOddNumberOfAsAutomaton();
        
        // Positive cases
        REQUIRE(dfa.Read("a"));
        REQUIRE(dfa.Read("aaa"));
        REQUIRE(dfa.Read("bab"));
        REQUIRE_FALSE(dfa.Read("abba"));
        
        // Negative cases
        REQUIRE_FALSE(dfa.Read(""));
        REQUIRE_FALSE(dfa.Read("aa"));
        REQUIRE_FALSE(dfa.Read("bb"));
        REQUIRE_FALSE(dfa.Read("aaaa"));
    }
    
    SECTION("Empty string only") {
        auto dfa = createEmptyStringOnlyAutomaton();
        
        // Positive case
        REQUIRE(dfa.Read(""));
        
        // Negative cases
        REQUIRE_FALSE(dfa.Read("a"));
        REQUIRE_FALSE(dfa.Read("b"));
        REQUIRE_FALSE(dfa.Read("ab"));
    }
    
    SECTION("Always accepting") {
        auto dfa = createAlwaysAcceptingAutomaton();
        
        // All strings should be accepted
        REQUIRE(dfa.Read(""));
        REQUIRE(dfa.Read("a"));
        REQUIRE(dfa.Read("b"));
        REQUIRE(dfa.Read("aaa"));
        REQUIRE(dfa.Read("bbb"));
        REQUIRE(dfa.Read("ababababa"));
    }
}

TEST_CASE("DFA state transition tracking", "[automaton][states]") {
    map<char, int> alphabet = {{'a', 0}, {'b', 1}};
    vector<vector<int>> transitions = {
        {1, 0},  // State 0: 'a' -> 1, 'b' -> 0
        {2, 1},  // State 1: 'a' -> 2, 'b' -> 1
        {0, 2}   // State 2: 'a' -> 0, 'b' -> 2
    };
    vector<int> accepting_states = {2};
    
    Automaton dfa(alphabet, transitions, accepting_states);
    
    // Test processing without reset to check state tracking
    SECTION("Single character transitions") {
        dfa.Reset();
        REQUIRE_FALSE(dfa.IsInAcceptingState());  // Initial state 0 is not accepting
        
        dfa.Read("a", false);  // Should transition to state 1
        REQUIRE_FALSE(dfa.IsInAcceptingState());
        
        dfa.Read("a", false);  // Should transition to state 2
        REQUIRE(dfa.IsInAcceptingState());
        
        dfa.Read("a", false);  // Should transition to state 0
        REQUIRE_FALSE(dfa.IsInAcceptingState());
    }
    
    SECTION("Multi-character transitions") {
        dfa.Reset();
        dfa.Read("aa", false);  // 0 -> 1 -> 2
        REQUIRE(dfa.IsInAcceptingState());
        
        dfa.Read("a", false);  // 2 -> 0
        REQUIRE_FALSE(dfa.IsInAcceptingState());
        
        dfa.Read("aaa", false);  // 0 -> 1 -> 2 -> 0
        REQUIRE_FALSE(dfa.IsInAcceptingState());
    }
    
    SECTION("Reset functionality") {
        dfa.Reset();
        dfa.Read("aa", false);
        REQUIRE(dfa.IsInAcceptingState());
        
        dfa.Reset();
        REQUIRE_FALSE(dfa.IsInAcceptingState());
        
        // Full string with reset
        REQUIRE(dfa.Read("aa"));  // Should reset and process
        REQUIRE_FALSE(dfa.Read("a"));  // Should reset and process
    }
}

TEST_CASE("DFA error handling", "[automaton][errors]") {
    SECTION("Invalid alphabet") {
        map<char, int> alphabet = {{'a', -1}, {'b', 1}}; // Negative indices not allowed
        vector<vector<int>> transitions = {{0, 1}, {1, 0}};
        vector<int> accepting_states = {1};
        
        REQUIRE_THROWS_AS(Automaton(alphabet, transitions, accepting_states), std::invalid_argument);
    }
    
    SECTION("Invalid transition matrix - wrong dimensions") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}, {'c', 2}}; // 3 symbols
        vector<vector<int>> transitions = {{0, 1}, {1, 0}}; // Only 2 transitions per state
        vector<int> accepting_states = {1};
        
        REQUIRE_THROWS_AS(Automaton(alphabet, transitions, accepting_states), std::invalid_argument);
        REQUIRE_THROWS_WITH(
            Automaton(alphabet, transitions, accepting_states),
            Catch::Matchers::ContainsSubstring("Each state must have a transition for each alphabet symbol")
        );
    }
    
    SECTION("Invalid transition matrix - invalid target state") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {{0, 1}, {1, 3}}; // State 3 doesn't exist
        vector<int> accepting_states = {1};
        
        REQUIRE_THROWS_AS(Automaton(alphabet, transitions, accepting_states), std::invalid_argument);
        REQUIRE_THROWS_WITH(
            Automaton(alphabet, transitions, accepting_states),
            Catch::Matchers::ContainsSubstring("Transition to invalid state")
        );
    }
    
    SECTION("Invalid accepting states") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {{0, 1}, {1, 0}};
        vector<int> accepting_states = {2}; // State 2 doesn't exist
        
        REQUIRE_THROWS_AS(Automaton(alphabet, transitions, accepting_states), std::invalid_argument);
        REQUIRE_THROWS_WITH(
            Automaton(alphabet, transitions, accepting_states),
            Catch::Matchers::ContainsSubstring("Accepting state 2 is outside valid range")
        );
    }
    
    SECTION("Invalid input symbols") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {{0, 1}, {1, 0}};
        vector<int> accepting_states = {1};
        Automaton dfa(alphabet, transitions, accepting_states);
        
        REQUIRE_THROWS_AS(dfa.Read("abc"), std::invalid_argument);
        REQUIRE_THROWS_WITH(
            dfa.Read("c"),
            Catch::Matchers::ContainsSubstring("Invalid input symbol")
        );
    }
}

TEST_CASE("Complex automaton examples", "[automaton][complex]") {
    SECTION("DFA for binary numbers divisible by 3") {
        // States represent the remainder when divided by 3 (0, 1, 2)
        map<char, int> alphabet = {{'0', 0}, {'1', 1}};
        vector<vector<int>> transitions = {
            {0, 1},  // Remainder 0: Next remainder after x0 is 0, after x1 is 1
            {2, 0},  // Remainder 1: Next remainder after x0 is 2, after x1 is 0 
            {1, 2}   // Remainder 2: Next remainder after x0 is 1, after x1 is 2
        };
        vector<int> accepting_states = {0};  // Divisible by 3 when remainder is 0
        Automaton div3_dfa(alphabet, transitions, accepting_states);
        
        // Test strings representing binary numbers
        REQUIRE(div3_dfa.Read(""));     // Empty string = 0, divisible by 3
        REQUIRE(div3_dfa.Read("0"));    // 0 is divisible by 3
        REQUIRE_FALSE(div3_dfa.Read("1"));   // 1 is not divisible by 3
        REQUIRE_FALSE(div3_dfa.Read("10"));  // 2 is not divisible by 3
        REQUIRE(div3_dfa.Read("11"));   // 3 is divisible by 3
        REQUIRE(div3_dfa.Read("110"));  // 6 is divisible by 3
        REQUIRE(div3_dfa.Read("1001")); // 9 is divisible by 3
        REQUIRE_FALSE(div3_dfa.Read("1000")); // 8 is not divisible by 3
    }
    
    SECTION("DFA for strings with an even number of a's AND an odd number of b's") {
        // We need 4 states to track even/odd counts of both a's and b's
        // State 0: even a's, even b's
        // State 1: odd a's, even b's
        // State 2: even a's, odd b's (accepting)
        // State 3: odd a's, odd b's
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {1, 2},  // State 0: 'a' -> 1, 'b' -> 2
            {0, 3},  // State 1: 'a' -> 0, 'b' -> 3
            {3, 0},  // State 2: 'a' -> 3, 'b' -> 0
            {2, 1}   // State 3: 'a' -> 2, 'b' -> 1
        };
        vector<int> accepting_states = {2};  // even a's, odd b's
        Automaton parity_dfa(alphabet, transitions, accepting_states);
        
        // Test various combinations
        REQUIRE_FALSE(parity_dfa.Read(""));      // even a's (0), even b's (0) - not accepting
        REQUIRE_FALSE(parity_dfa.Read("a"));     // odd a's (1), even b's (0) - not accepting
        REQUIRE(parity_dfa.Read("b"));      // even a's (0), odd b's (1) - accepting
        REQUIRE_FALSE(parity_dfa.Read("ab"));    // odd a's (1), odd b's (1) - not accepting
        REQUIRE_FALSE(parity_dfa.Read("aa"));    // even a's (2), even b's (0) - not accepting 
        REQUIRE(parity_dfa.Read("aab"));    // even a's (2), odd b's (1) - accepting
        REQUIRE_FALSE(parity_dfa.Read("abb"));   // odd a's (1), even b's (2) - not accepting
        
        // Fix: "aaabbb" has 3 'a's (odd), 3 'b's (odd) - should be rejected
        // The DFA only accepts strings with EVEN number of 'a's AND ODD number of 'b's
        REQUIRE_FALSE(parity_dfa.Read("aaabbb")); // odd a's (3), odd b's (3) - should NOT be accepting
    }
    
    SECTION("DFA for strings that don't contain 'ab' as a substring") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {
            {1, 0},  // State 0 (initial): 'a' -> 1, 'b' -> 0
            {1, 2},  // State 1 (saw an 'a'): 'a' -> 1, 'b' -> 2
            {2, 2}   // State 2 (trap state): 'a' -> 2, 'b' -> 2
        };
        vector<int> accepting_states = {0, 1};  // Any state except the trap state
        Automaton no_ab_dfa(alphabet, transitions, accepting_states);
        
        // Test various strings
        REQUIRE(no_ab_dfa.Read(""));       // Empty string doesn't contain 'ab'
        REQUIRE(no_ab_dfa.Read("a"));      // "a" doesn't contain 'ab'
        REQUIRE(no_ab_dfa.Read("b"));      // "b" doesn't contain 'ab'
        REQUIRE_FALSE(no_ab_dfa.Read("ab"));     // "ab" contains 'ab'
        REQUIRE(no_ab_dfa.Read("aa"));     // "aa" doesn't contain 'ab'
        REQUIRE(no_ab_dfa.Read("bb"));     // "bb" doesn't contain 'ab'
        REQUIRE_FALSE(no_ab_dfa.Read("aab"));    // "aab" contains 'ab'
        REQUIRE_FALSE(no_ab_dfa.Read("abb"));    // "abb" contains 'ab'
        REQUIRE(no_ab_dfa.Read("aaa"));    // "aaa" doesn't contain 'ab'
        REQUIRE(no_ab_dfa.Read("bbb"));    // "bbb" doesn't contain 'ab'
    }
}

TEST_CASE("Edge cases", "[automaton][edge]") {
    SECTION("Empty language (no accepting states)") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {{0, 0}, {1, 1}};
        vector<int> accepting_states = {}; // No accepting states
        Automaton empty_dfa(alphabet, transitions, accepting_states);
        
        // No string should be accepted
        REQUIRE_FALSE(empty_dfa.Read(""));
        REQUIRE_FALSE(empty_dfa.Read("a"));
        REQUIRE_FALSE(empty_dfa.Read("b"));
        REQUIRE_FALSE(empty_dfa.Read("ab"));
    }
    
    SECTION("Universal language (all states accepting)") {
        map<char, int> alphabet = {{'a', 0}, {'b', 1}};
        vector<vector<int>> transitions = {{0, 1}, {0, 1}};
        vector<int> accepting_states = {0, 1}; // All states are accepting
        Automaton universal_dfa(alphabet, transitions, accepting_states);
        
        // All strings should be accepted
        REQUIRE(universal_dfa.Read(""));
        REQUIRE(universal_dfa.Read("a"));
        REQUIRE(universal_dfa.Read("b"));
        REQUIRE(universal_dfa.Read("ab"));
        REQUIRE(universal_dfa.Read("abababababa"));
    }
    
    SECTION("Single character alphabet") {
        map<char, int> alphabet = {{'a', 0}};
        vector<vector<int>> transitions = {{1}, {0}};
        vector<int> accepting_states = {0};
        Automaton single_char_dfa(alphabet, transitions, accepting_states);
        
        // Accepts strings with even number of 'a's
        REQUIRE(single_char_dfa.Read(""));
        REQUIRE_FALSE(single_char_dfa.Read("a"));
        REQUIRE(single_char_dfa.Read("aa"));
        REQUIRE_FALSE(single_char_dfa.Read("aaa"));
    }
    
    SECTION("Large alphabet") {
        // Create an alphabet with many symbols
        map<char, int> alphabet;
        for (char c = 'a'; c <= 'z'; c++) {
            alphabet[c] = c - 'a'; // Map a->0, b->1, etc.
        }
        
        // Create a transition matrix that always goes to state 0
        vector<vector<int>> transitions(2, vector<int>(26, 0));
        vector<int> accepting_states = {0};
        
        Automaton large_alphabet_dfa(alphabet, transitions, accepting_states);
        
        // Test with various inputs
        REQUIRE(large_alphabet_dfa.Read(""));
        REQUIRE(large_alphabet_dfa.Read("a"));
        REQUIRE(large_alphabet_dfa.Read("z"));
        REQUIRE(large_alphabet_dfa.Read("abcdefghijklmnopqrstuvwxyz"));
    }
}
