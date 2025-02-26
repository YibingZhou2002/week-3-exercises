# Catch2 Example with Automaton Testing

This example demonstrates how to use Catch2 to test a C++ Automaton class implementation.

## Building and Running Tests

```bash
# Create a build directory
mkdir -p build && cd build

# Configure with CMake
cmake ..

# Build
make

# Run tests
./run_tests
```

## Key Catch2 Features Demonstrated

1. **Basic Test Cases**: Using `TEST_CASE` and `REQUIRE`
2. **Sections**: Using `SECTION` to organize sub-tests with shared setup
3. **Exception Testing**: Using `REQUIRE_THROWS_AS` and `REQUIRE_THROWS_WITH`
4. **Matchers**: Using `Catch::Matchers::Contains` for string comparison

## Helpful Catch2 Command Line Options

```bash
# Run tests with specific tags
./run_tests "[automaton]"

# List all tests without running them
./run_tests --list-tests

# Run tests in random order
./run_tests --order rand

# Run specific test by name
./run_tests "Automaton basic functionality"

# Generate output in JUnit format
./run_tests -r junit -o test-results.xml
```

## Further Documentation

For complete Catch2 documentation, visit:
https://github.com/catchorg/Catch2/tree/devel/docs
