#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::map;
using std::string;

int main()
{
    // 创建一个接受以'b'结尾的字符串的DFA
    vector<vector<int>> M{{0, 1}, {0, 1}};
    map<char, int> A{{'a', 0}, {'b', 1}}; 
    vector<int> S{1};
    Automaton ends_with_b(A, M, S);
    
    // 显示自动机的转移表
    std::cout << "DFA that accepts strings ending with 'b':\n";
    ends_with_b.PrintTransitionTable();
    
    std::cout << "\nThis automaton accepts strings containing only 'a' and 'b' that end with 'b'.\n";
    
    std::string input;
    
    while (true) {
        // 重置自动机状态
        ends_with_b.Reset();
        
        // 提示用户输入
        std::cout << "\nPlease enter a string (or 'quit' to exit): ";
        std::getline(std::cin, input);
        
        // 检查是否要退出
        if (input == "quit") {
            break;
        }
        
        // 尝试处理输入
        try {
            bool accepted = ends_with_b.Read(input);
            
            // 如果代码执行到这里，说明输入有效
            std::cout << "Input is valid. ";
            
            if (accepted) {
                std::cout << "The string '" << input << "' is ACCEPTED by the automaton.\n";
            } else {
                std::cout << "The string '" << input << "' is REJECTED by the automaton.\n";
            }
            
            // 输出最终状态
            ends_with_b.PrintCurrentState();
            
        } catch (const std::exception& e) {
            // 输入无效，捕获并显示错误
            std::cout << "Invalid input: " << e.what() << "\n";
            std::cout << "Please only use characters 'a' and 'b'.\n";
        }
    }
    
    std::cout << "Goodbye!\n";
    return 0;
}