#include <catch2/catch_all.hpp>
#include "Student.hpp"
#include <optional>
#include <array>

using namespace Catch::Matchers;

TEST_CASE("Student has unique ID", "[student]") {
    Student student1;
    Student student2;
    
    REQUIRE(student1.getId() != student2.getId());
}

TEST_CASE("Student grades initialized to nullopt", "[student]") {
    Student student;
    
    for (size_t i = 0; i < 6; ++i) {
        REQUIRE_FALSE(student.getGrade(i).has_value());
    }
}

TEST_CASE("Student grades can be set in constructor", "[student]") {
    std::array<std::optional<int>, 6> initialGrades = {
        80, 75, std::nullopt, 90, 85, 70
    };
    
    Student student(initialGrades);
    
    REQUIRE(student.getGrade(0).value() == 80);
    REQUIRE(student.getGrade(1).value() == 75);
    REQUIRE_FALSE(student.getGrade(2).has_value());
    REQUIRE(student.getGrade(3).value() == 90);
    REQUIRE(student.getGrade(4).value() == 85);
    REQUIRE(student.getGrade(5).value() == 70);
}

TEST_CASE("Student grades can be set using setter", "[student]") {
    Student student;
    
    student.setGrade(0, 95);
    student.setGrade(1, 85);
    student.setGrade(2, std::nullopt);
    
    REQUIRE(student.getGrade(0).value() == 95);
    REQUIRE(student.getGrade(1).value() == 85);
    REQUIRE_FALSE(student.getGrade(2).has_value());
    REQUIRE_FALSE(student.getGrade(3).has_value());
}

TEST_CASE("Average grade calculation works correctly", "[student]") {
    Student student;
    
    // All null grades
    REQUIRE_FALSE(student.calculateAverageGrade().has_value());
    
    // Some grades
    student.setGrade(0, 50);
    student.setGrade(1, 65);
    
    REQUIRE(student.calculateAverageGrade().has_value());
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(57.5, 0.0001));
    
    // Add another grade
    student.setGrade(2, 70);
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(61.6667, 0.0001));
    
    // Test with the example from the prompt
    Student exampleStudent;
    exampleStudent.setGrade(0, 50);
    exampleStudent.setGrade(1, 65);
    // Grades 2-5 remain nullopt
    
    REQUIRE_THAT(exampleStudent.calculateAverageGrade().value(), WithinRel(57.5, 0.0001));
}

TEST_CASE("Edge cases for average grade calculation", "[student]") {
    Student student;
    
    // Case 1: Only one grade
    student.setGrade(0, 85);
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(85.0, 0.0001));
    
    // Case 2: All grades set
    student.setGrade(1, 70);
    student.setGrade(2, 90);
    student.setGrade(3, 65);
    student.setGrade(4, 75);
    student.setGrade(5, 80);
    
    double expectedAverage = (85.0 + 70.0 + 90.0 + 65.0 + 75.0 + 80.0) / 6.0;
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(expectedAverage, 0.0001));
    
    // Case 3: Some grades set to zero (valid grades, not null)
    Student zeroStudent;
    zeroStudent.setGrade(0, 0);
    zeroStudent.setGrade(1, 0);
    zeroStudent.setGrade(2, 100);
    
    REQUIRE_THAT(zeroStudent.calculateAverageGrade().value(), WithinRel(33.3333, 0.0001));
    
    // Case 4: Set grade to nullopt after having a value
    Student resetStudent;
    resetStudent.setGrade(0, 90);
    REQUIRE(resetStudent.calculateAverageGrade().has_value());
    
    resetStudent.setGrade(0, std::nullopt);
    REQUIRE_FALSE(resetStudent.calculateAverageGrade().has_value());
}

TEST_CASE("Average calculation with boundary values", "[student]") {
    Student student;
    
    // Minimum possible grades (assuming 0 is minimum)
    student.setGrade(0, 0);
    student.setGrade(1, 0);
    
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(0.0, 0.0001));
    
    // Maximum possible grades (assuming 100 is maximum)
    student.setGrade(0, 100);
    student.setGrade(1, 100);
    
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(100.0, 0.0001));
    
    // Mix of high and low values
    student.setGrade(0, 0);
    student.setGrade(1, 100);
    
    REQUIRE_THAT(student.calculateAverageGrade().value(), WithinRel(50.0, 0.0001));
}