#pragma once

#include <string>
#include <vector>
#include <map> 
#include <algorithm> 

using std::vector;
using std::map;
using std::string;

class Automaton
{
    public: 
    Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S_A);

    bool Read(string word);

    private:
    int state = 0;
    map<char, int> alphabet;
    // We can use a vector of vectors as a 2D array or matrix
    vector<vector<int>> transition_matrix;
    vector<int> accepting_states;
};
