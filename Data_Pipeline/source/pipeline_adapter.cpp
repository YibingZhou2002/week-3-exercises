#include "../include/pipeline_adapter.hpp"
#include "../include/simple.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

// Implement the adapter function that lifts regular functions to work with optionals
std::function<std::optional<double>(std::optional<double>)> 
lift_to_optional(std::function<double(double)> f) {
    return [f](std::optional<double> opt) -> std::optional<double> {
        if (!opt.has_value()) {
            return std::nullopt;
        }
        return std::optional<double>(f(opt.value()));
    };
}

// Implement the adapter function for functions that already return optionals
std::function<std::optional<double>(std::optional<double>)> 
adapt_optional_output(std::function<std::optional<double>(double)> f) {
    return [f](std::optional<double> opt) -> std::optional<double> {
        if (!opt.has_value()) {
            return std::nullopt;
        }
        return f(opt.value());
    };
}

// Example regular functions that work with doubles
double square(double x) {
    return x * x;
}

double add_one(double x) {
    return x + 1.0;
}

double sine(double x) {
    return std::sin(x);
}

// Example functions that return optionals (double -> optional<double>)
std::optional<double> safe_sqrt(double x) {
    if (x < 0) {
        return std::nullopt;
    }
    return std::sqrt(x);
}

std::optional<double> safe_log(double x) {
    if (x <= 0) {
        return std::nullopt;
    }
    return std::log(x);
}

std::optional<double> safe_inverse_trig(double x) {
    if (x < -1.0 || x > 1.0) {
        return std::nullopt;
    }
    return std::asin(x);
}

// Overload operator<< for std::optional<double>
std::ostream& operator<<(std::ostream& os, const std::optional<double>& opt) {
    if (opt.has_value()) {
        os << opt.value();
    } else {
        os << "nothing";
    }
    return os;
}

int main() {
    // Input values to test
    std::vector<double> input_values = {
        -2.0,
        -1.0,
        0.0,
        0.5,
        1.0,
        2.0,
        4.0
    };

    std::cout << "Advanced Pipeline Demonstration\n";
    std::cout << "==============================\n\n";
    
    // Convert our regular functions to optional-compatible functions
    auto optional_square = lift_to_optional(std::function<double(double)>(square));
    auto optional_add_one = lift_to_optional(std::function<double(double)>(add_one));
    auto optional_sine = lift_to_optional(std::function<double(double)>(sine));
    
    // Convert our functions that already return optionals
    auto optional_safe_sqrt = adapt_optional_output(std::function<std::optional<double>(double)>(safe_sqrt));
    auto optional_safe_log = adapt_optional_output(std::function<std::optional<double>(double)>(safe_log));
    auto optional_safe_inverse_trig = adapt_optional_output(std::function<std::optional<double>(double)>(safe_inverse_trig));
    
    std::cout << "Testing pipeline with functions that already return optionals:\n";
    std::cout << "Input\tResult\n";
    std::cout << "--------------\n";
    
    for (double x : input_values) {
        // Create a pipeline using both types of adapted functions
        // Pipeline: x -> 1/x -> safe_log(1/x) -> safe_sqrt(safe_log(1/x)) -> sine(...)
        auto result = reciprocal(x);
        result = optional_safe_log(result);     // Using function that already returns optional
        result = optional_safe_sqrt(result);    // Using function that already returns optional
        result = optional_sine(result);         // Using adapted regular function
        result = optional_safe_inverse_trig(result); // Another function that returns optional
        
        std::cout << std::fixed << std::setprecision(4);
        std::cout << x << "\t" << result << "\n";
    }
    
    // Compare the behavior with our original pipeline functions
    std::cout << "\nComparison with built-in pipeline functions:\n";
    std::cout << "Input\tBuilt-in\tManual\t\tSame result?\n";
    std::cout << "-------------------------------------------------------\n";
    
    for (double x : input_values) {
        // Our original pipeline
        auto built_in = reciprocal(x);
        built_in = logarithm(built_in);
        built_in = square_root(built_in);
        
        // Equivalent pipeline using our adapter functions
        auto manual = reciprocal(x);
        manual = optional_safe_log(manual);
        manual = optional_safe_sqrt(manual);
        
        // Do they give the same result?
        bool same_result = false;
        if (built_in.has_value() && manual.has_value()) {
            same_result = std::abs(built_in.value() - manual.value()) < 1e-10;
        } else {
            same_result = !built_in.has_value() && !manual.has_value();
        }
        
        std::cout << x << "\t" << built_in << "\t\t" << manual;
        std::cout << "\t\t" << (same_result ? "Yes" : "No") << "\n";
    }
    
    // Test with nullopt
    std::cout << "\nTesting with nullopt input:\n";
    std::optional<double> null_input = std::nullopt;
    
    auto result1 = optional_safe_sqrt(null_input);
    std::cout << "optional_safe_sqrt(nullopt) = " << result1 << "\n";
    
    auto result2 = optional_safe_log(null_input);
    std::cout << "optional_safe_log(nullopt) = " << result2 << "\n";
    
    return 0;
}
