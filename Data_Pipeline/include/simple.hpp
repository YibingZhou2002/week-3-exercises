#ifndef SIMPLE_HPP
#define SIMPLE_HPP

#include <optional>

// Function to calculate reciprocal (1/x)
// Returns nullopt if x is nullopt or x = 0
std::optional<double> reciprocal(std::optional<double> x);

// Function to calculate natural logarithm
// Returns nullopt if x is nullopt or x <= 0
std::optional<double> logarithm(std::optional<double> x);

// Function to calculate square root
// Returns nullopt if x is nullopt or x < 0
std::optional<double> square_root(std::optional<double> x);

#endif // SIMPLE_HPP
