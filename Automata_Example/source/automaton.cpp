#include "automaton.h"
#include <iostream>
#include <vector>
#include <map> 
#include <algorithm> 

using std::vector;
using std::map;
using std::string;

// 实现构造函数
Automaton::Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S_A) 
    : state(0), initial_state(0), alphabet(A), transition_matrix(M), 
      accepting_states(S_A), num_states(M.size()) 
{
    // 验证输入
    ValidateAlphabet(A);
    ValidateTransitionMatrix(M, A.size());
    ValidateAcceptingStates(S_A);
}

// 实现Read方法
bool Automaton::Read(string word, bool reset)
{
    if (reset) {
        state = initial_state;
    }
    
    for(auto &c : word)
    {
        auto it = alphabet.find(c);
        if (it == alphabet.end()) {
            // 创建一个建议字符串，使用remove_if和erase移除所有无效字符
            string suggestion = word;
            suggestion.erase(
                std::remove_if(suggestion.begin(), suggestion.end(), 
                    [this](char ch) { 
                        return this->alphabet.find(ch) == this->alphabet.end(); 
                    }),
                suggestion.end()
            );
            
            string error_msg = "Invalid input symbol: '" + string(1, c) + "'";
            if (!suggestion.empty()) {
                error_msg += ". Suggestion: Try '" + suggestion + "' instead";
            } else {
                error_msg += ". No valid characters found in input";
            }
            
            throw std::invalid_argument(error_msg);
        }
        size_t j = static_cast<size_t>(it->second);
        state = transition_matrix[static_cast<size_t>(state)][j];
    }
    
    return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}

void Automaton::Reset() {
    state = initial_state;
}

// 实现ValidateAlphabet方法
void Automaton::ValidateAlphabet(const map<char, int>& A) {
    for(auto& pair : A) {
        if(pair.second < 0) {
            throw std::invalid_argument("Alphabet values must be non-negative integers.");
        }
    }
}

// 实现ValidateTransitionMatrix方法
void Automaton::ValidateTransitionMatrix(const vector<vector<int>>& M, size_t alphabet_size) {
    // 确保矩阵不为空
    if (M.empty()) {
        throw std::invalid_argument("Transition matrix cannot be empty");
    }
    
    // 检查每个状态对每个字母表符号都有转移
    for (size_t i = 0; i < M.size(); i++) {
        if (M[i].size() != alphabet_size) {
            throw std::invalid_argument("Each state must have a transition for each alphabet symbol");
        }
        
        // 检查每个转移都指向有效状态
        for (size_t j = 0; j < M[i].size(); j++) {
            if (M[i][j] < 0 || M[i][j] >= static_cast<int>(M.size())) {
                throw std::invalid_argument("Transition to invalid state: " + 
                    std::to_string(M[i][j]) + " from state " + std::to_string(i));
            }
        }
    }
}

// 实现ValidateAcceptingStates方法
void Automaton::ValidateAcceptingStates(const vector<int>& S_A) {
    for (auto& state : S_A) {
        if (state < 0 || state >= num_states) {
            throw std::invalid_argument("Accepting state " + std::to_string(state) + 
                " is outside valid range [0, " + std::to_string(num_states-1) + "]");
        }
    }
}

void Automaton::PrintCurrentState() const {
    std::cout << "Current state: " << state;
    if (std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end()) {
        std::cout << " (accepting)";
    }
    std::cout << std::endl;
}

bool Automaton::IsInAcceptingState() const {
    return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}

void Automaton::PrintTransitionTable() const {
    std::cout << "Transition Table:" << std::endl;
    std::cout << "----------------" << std::endl;
    
    // 打印列标题（输入符号）
    std::cout << "State |";
    for (const auto& pair : alphabet) {
        std::cout << " '" << pair.first << "' |";
    }
    std::cout << std::endl;
    
    // 打印分隔线
    std::cout << "------|";
    for (size_t i = 0; i < alphabet.size(); i++) {
        std::cout << "-----|";
    }
    std::cout << std::endl;
    
    // 打印每个状态的转移
    for (size_t i = 0; i < transition_matrix.size(); i++) {
        std::cout << "  " << i << "   |";
        for (size_t j = 0; j < transition_matrix[i].size(); j++) {
            std::cout << "  " << transition_matrix[i][j] << "  |";
        }
        
        // 标记接受状态
        if (std::find(accepting_states.begin(), accepting_states.end(), i) != accepting_states.end()) {
            std::cout << " (accepting)";
        }
        std::cout << std::endl;
    }
}   
