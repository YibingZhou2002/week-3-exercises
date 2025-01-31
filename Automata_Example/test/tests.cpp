#include <catch2/catch_test_macros.hpp>
#include "automaton.h"
#include <vector>
#include <map>

using std::vector;
using std::map;

TEST_CASE("Check that a simple automaton accepts", "[simple accept]")
{
    vector<vector<int>> M{{0,1}, {1, 1}};
    vector<int> S_A{0};
    map<char, int> A{{'a', 0}, {'b', 1}};
    Automaton only_As(A, M, S_A);

    REQUIRE(only_As.Read("aaaaa"));
    REQUIRE(!only_As.Read("aaaabaaa"));
}