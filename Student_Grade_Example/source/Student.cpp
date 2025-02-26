#include <optional>
#include "Student.hpp"

// Initialize static member variable
uint64_t Student::nextId = 1;

Student::Student() : id(nextId++) {
    // All grades are initialized to std::nullopt by default
    // std::array<std::optional<int>, 6> automatically initializes with std::nullopt
}

Student::Student(const std::array<std::optional<int>, 6>& initialGrades) 
    : id(nextId++), grades(initialGrades) {
}

uint64_t Student::getId() const {
    return id;
}

std::optional<int> Student::getGrade(size_t courseIndex) const {
    if (courseIndex < grades.size()) {
        return grades[courseIndex];
    }
    return std::nullopt;
}

void Student::setGrade(size_t courseIndex, std::optional<int> grade) {
    if (courseIndex < grades.size()) {
        grades[courseIndex] = grade;
    }
}

const std::array<std::optional<int>, 6>& Student::getAllGrades() const {
    return grades;
}

std::optional<double> Student::calculateAverageGrade() const {
    int sum = 0;
    int count = 0;
    
    for (const auto& grade : grades) {
        if (grade.has_value()) {
            sum += grade.value();
            count++;
        }
    }
    
    if (count == 0) {
        return std::nullopt;
    }
    
    return static_cast<double>(sum) / count;
}

std::optional<Award> Student::calculateFinalGrade() const {
    // Check if all grades have been assigned
    for (const auto& grade : grades) {
        if (!grade.has_value()) {
            return std::nullopt;
        }
    }
    
    // All grades are assigned, calculate average
    auto averageGrade = calculateAverageGrade();
    
    // This should always have a value if we've reached here
    if (!averageGrade.has_value()) {
        return std::nullopt; // Defensive programming
    }
    
    double average = averageGrade.value();
    
    if (average > 70.0) {
        return Award::First;
    } else if (average > 50.0) {
        return Award::Second;
    } else {
        return Award::Fail;
    }
}