#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>

class Automaton
{
public:
    Automaton(std::map<char, int> A, std::vector<std::vector<int>> M, std::vector<int> S_A);
    bool Read(std::string word, bool reset = true);
    void Reset();
    void PrintCurrentState() const;
    void PrintTransitionTable() const;
    bool IsInAcceptingState() const;

private:
    int state;
    int initial_state;
    std::map<char, int> alphabet;
    std::vector<std::vector<int>> transition_matrix;
    std::vector<int> accepting_states;
    int num_states;

    // Helper validation methods
    void ValidateAlphabet(const std::map<char, int>& A);
    void ValidateTransitionMatrix(const std::vector<std::vector<int>>& M, size_t alphabet_size);
    void ValidateAcceptingStates(const std::vector<int>& S_A);
};

#endif // AUTOMATON_H

