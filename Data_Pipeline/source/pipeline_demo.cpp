#include "../include/simple.hpp"
#include <iostream>
#include <vector>
#include <optional>
#include <iomanip>

// Overload operator<< for std::optional<double>
std::ostream& operator<<(std::ostream& os, const std::optional<double>& opt) {
    if (opt.has_value()) {
        os << opt.value();
    } else {
        os << "nothing";
    }
    return os;
}

// Function to print a vector of std::optional<double>
void print_optional_vector(const std::vector<std::optional<double>>& vec) {
    std::cout << "[ ";
    for (const auto& opt : vec) {
        std::cout << opt << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Create a vector of test values to demonstrate different cases
    std::vector<double> input_values = {
        -2.0,  // Negative value
        -1.0,  // Negative value
        0.0,   // Zero (will fail at reciprocal)
        0.5,   // Value between 0 and 1
        1.0,   // One (will fail at logarithm of reciprocal)
        2.0,   // Value > 1
        4.0    // Value > 1
    };
    
    // Vector to store the final results
    std::vector<std::optional<double>> results;
    
    // Process each input through the pipeline
    std::cout << "Processing pipeline: x -> 1/x -> log(1/x) -> sqrt(log(1/x))\n\n";
    std::cout << "Input\tResult\n";
    std::cout << "-----------------\n";
    
    for (double x : input_values) {
        // Apply the data pipeline: reciprocal -> logarithm -> square_root
        auto step1 = reciprocal(x);
        auto step2 = logarithm(step1);
        auto step3 = square_root(step2);
        
        // Store the final result
        results.push_back(step3);
        
        // Display input and result using the overloaded operator
        std::cout << std::fixed << std::setprecision(4);
        std::cout << x << "\t" << step3 << "\n";
    }
    
    // Demonstrate the results vector using our new print function
    std::cout << "\nResults vector: ";
    print_optional_vector(results);
    
    // Demonstrate step-by-step processing for a specific value
    double test_value = 0.5;
    std::cout << "\nDetailed processing for value " << test_value << ":\n";
    std::cout << "Original value: " << test_value << "\n";
    
    auto r = reciprocal(test_value);
    std::cout << "After reciprocal: " << r << "\n";
    
    auto l = logarithm(r);
    std::cout << "After logarithm: " << l << "\n";
    
    auto s = square_root(l);
    std::cout << "After square root: " << s << "\n";
    
    return 0;
}
