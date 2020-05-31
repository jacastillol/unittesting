## What is a __"Unit Test"__?
1. It is a piece of code that verifies production code. 
1. It's usually a method that check what is intended to do a production code. 
1. Must test a specific functionallity, only one feature. 
1. It clear defines pass/fail criteria
1. Must run in isolation from other dependencies (e.g, a DB or service)
1. Must run as fast as possible

## Pros of using Automated Tests
1. Quick Feedback
1. Avoid Stupid Bugs
1. Immune to Regressions
1. Change Your Code Without Fear
1. In Code Documentation
1. You're already testing your code!

## Using Catch2 as a unit testing framework
Catch stands for C++ Automated Cases in Headers

### Pros
1. Single header deployment
1. No external dependencies
1. Tests names are free-form strings
1. Powerful "Assertions"
1. Excellent error messages
1. Sections

### Getting starte with Catch2
1. Download and install catch.hpp in your project
1. Write the must simple `test mytest.cpp`
    ```C++
        // Define the following macro once in the whole project
        #define CATCH_CONFIG_MAIN
        // Include the Catch2 only header
        #include <catch.hpp>


        // Write the most simple test
        // This macro creates a new test method and class if required
        TEST_CASE(
            "This is a test name", // Test Name: Free-formated string 
            "[Tag1][Tag2]") // Alphanumeric to categorize tests e.g, DB, model
        {
            // Each test must have three parts
            // 1. ARRANGE: Initialize and prepare the resources
            MyClass myClass;
            // 2. ACT: create the result
            auto result = myClass.MeaningOfLif()
            // 3. ASSERT: check to pass/fail
            REQUIRE(result)   // C++ macro
        }
    ```
1. Compile the code `g++ -I <path-to-catch.hpp> mytest.cpp -o mytests.bin`
1. Run `mytests.bin`

## About Test Name
A good name for a test should express a specific behavior, and must include the starting state, given input, expected result. Easy to be found.
1. Understand what the test does
1. Execute a subset of your tests
1. Find the test you need
1. Failure root cause analysis

Examples of proper names
1. If Age > 18 IsAdult returnst true
1. When called with xyz then return true
1. Should thron exception When invalid user
1. [BDD] Given authenticated When invalid number used Then transaction will fail
1. Called with empty --> return nullptr

## Catch & the Command Line
List by name all the test available
```
mytests.bin --list-test-names-only
```
1. Run Specific Test
    1. Test name related arguments thisTest, e.g, 
    1. "This Test"
1. Run Group of tests
    1. Customer*
    1. *Customer
1. Run all tests except
    1. Use tilda ~ like: a* ~ab* abc

### Using Tags
If you have:
```C++
TEST_CASE("Test1", "[A]") {. . .}
TEST_CASE("Test2", "[A]") {. . .}
TEST_CASE("Test3", "[B]") {. . .}
TEST_CASE("Test4", "[A][B]") {. . .}
```
If your run `mytests.bin "[A]"` tests `Test1`
If your run `mytests.bin "[B]"` tests `Test3`
If your run `mytests.bin "~[A]"` tests `Test3`
If your run `mytests.bin "[A][B]"` tests `Test4`
If your run `mytests.bin "[A],[B]"` tests all

*Special Tags* 
1. [!hide] or [.] Skip/Ignore test
1. [.][integration] -> [.integration]
1. [!throws] Exclude if run catch with -e or -nothrow
1. [!shouldfail] Reverse failing logic (pass if fail)
1. [!mayfail] Does not fail the test if assertion fails
1. [#<filename>] Use -# to specify filename as tag