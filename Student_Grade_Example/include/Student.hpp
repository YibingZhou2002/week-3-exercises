#include <optional>
#include <array>
#include <cstdint>

enum class Award
{
    First,
    Second,
    Fail
};

class Student
{
private:
    static uint64_t nextId;
    uint64_t id;
    std::array<std::optional<int>, 6> grades;

public:
    Student();
    Student(const std::array<std::optional<int>, 6>& initialGrades);

    uint64_t getId() const;
    std::optional<int> getGrade(size_t courseIndex) const;
    void setGrade(size_t courseIndex, std::optional<int> grade);
    
    // Optional: add methods to get all grades
    const std::array<std::optional<int>, 6>& getAllGrades() const;
    
    // Calculate average grade
    std::optional<double> calculateAverageGrade() const;
    
    // Calculate final grade
    std::optional<Award> calculateFinalGrade() const;
};