#include "../include/simple.hpp"
#include <cmath>

std::optional<double> reciprocal(std::optional<double> x) {
    // If input is nullopt, propagate nullopt
    if (!x.has_value()) {
        return std::nullopt;
    }
    
    // Check for division by zero
    if (x.value() == 0.0) {
        return std::nullopt;
    }
    
    return 1.0 / x.value();
}

std::optional<double> logarithm(std::optional<double> x) {
    // If input is nullopt, propagate nullopt
    if (!x.has_value()) {
        return std::nullopt;
    }
    
    // Logarithm is undefined for non-positive numbers
    if (x.value() <= 0.0) {
        return std::nullopt;
    }
    
    return std::log(x.value());
}

std::optional<double> square_root(std::optional<double> x) {
    // If input is nullopt, propagate nullopt
    if (!x.has_value()) {
        return std::nullopt;
    }
    
    // Square root is undefined for negative numbers
    if (x.value() < 0.0) {
        return std::nullopt;
    }
    
    return std::sqrt(x.value());
}
