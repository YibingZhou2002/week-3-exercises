#ifndef PIPELINE_ADAPTER_HPP
#define PIPELINE_ADAPTER_HPP

#include <functional>
#include <optional>

// Function adapter that lifts a regular function (double -> double)
// to work with optionals (optional<double> -> optional<double>)
std::function<std::optional<double>(std::optional<double>)> 
lift_to_optional(std::function<double(double)> f);

// Function adapter that converts a function with optional output (double -> optional<double>)
// to work with optional inputs (optional<double> -> optional<double>)
std::function<std::optional<double>(std::optional<double>)> 
adapt_optional_output(std::function<std::optional<double>(double)> f);

#endif // PIPELINE_ADAPTER_HPP
