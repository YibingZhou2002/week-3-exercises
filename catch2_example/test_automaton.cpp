#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include "automaton.h"
#include <map>
#include <vector>

TEST_CASE("Automaton basic functionality", "[automaton]") {
    // Create a simple DFA that accepts strings ending with 'a'
    // States: 0 (initial), 1 (accepting)
    // Alphabet: 'a', 'b'
    // Transitions:
    //   0 --a--> 1
    //   0 --b--> 0
    //   1 --a--> 1
    //   1 --b--> 0
    
    std::map<char, int> alphabet = {{'a', 0}, {'b', 1}};
    std::vector<std::vector<int>> transitions = {
        {1, 0},  // State 0: 'a' goes to 1, 'b' goes to 0
        {1, 0}   // State 1: 'a' goes to 1, 'b' goes to 0
    };
    std::vector<int> accepting_states = {1};
    
    Automaton dfa(alphabet, transitions, accepting_states);
    
    SECTION("Valid inputs") {
        REQUIRE(dfa.Read("a") == true);
        dfa.Reset();
        REQUIRE(dfa.Read("b") == false);
        dfa.Reset();
        REQUIRE(dfa.Read("aba") == true);
        dfa.Reset();
        REQUIRE(dfa.Read("abb") == false);
    }
    
    SECTION("Invalid input handling") {
        REQUIRE_THROWS_AS(dfa.Read("abc"), std::invalid_argument);
        
        // Use REQUIRE_THROWS_WITH for string message matching instead of REQUIRE_THROWS_MATCHES
        REQUIRE_THROWS_WITH(
            dfa.Read("c"),
            Catch::Matchers::ContainsSubstring("Invalid input symbol")
        );
    }
    
    SECTION("State transitions") {
        dfa.Reset();
        dfa.Read("ab", false);
        REQUIRE(dfa.IsInAcceptingState() == false);
        
        dfa.Read("a", false);
        REQUIRE(dfa.IsInAcceptingState() == true);
        
        dfa.Read("b", false);
        REQUIRE(dfa.IsInAcceptingState() == false);
    }
}

TEST_CASE("Automaton validation", "[automaton]") {
    std::map<char, int> alphabet = {{'0', 0}, {'1', 1}};
    
    SECTION("Invalid transition matrix") {
        std::vector<std::vector<int>> invalid_transitions = {
            {0, 1},
            {2, 1}  // Invalid - points to non-existent state 2
        };
        std::vector<int> accepting_states = {1};
        
        REQUIRE_THROWS_AS(Automaton(alphabet, invalid_transitions, accepting_states), std::invalid_argument);
        
        // Use REQUIRE_THROWS_WITH for string message matching
        REQUIRE_THROWS_WITH(
            Automaton(alphabet, invalid_transitions, accepting_states),
            Catch::Matchers::ContainsSubstring("Transition to invalid state")
        );
    }
    
    SECTION("Invalid accepting states") {
        std::vector<std::vector<int>> transitions = {
            {0, 1},
            {1, 0}
        };
        std::vector<int> invalid_accepting = {2};  // Invalid - state 2 doesn't exist
        
        REQUIRE_THROWS_AS(Automaton(alphabet, transitions, invalid_accepting), std::invalid_argument);
        
        // Use REQUIRE_THROWS_WITH for string message matching
        REQUIRE_THROWS_WITH(
            Automaton(alphabet, transitions, invalid_accepting),
            Catch::Matchers::ContainsSubstring("Accepting state 2 is outside valid range")
        );
    }
}
