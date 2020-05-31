#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <reader/reader.hpp>


TEST_CASE(
    "Comma separated values from a str_to_parse without whitespace",
    "[reader]")
{
    Reader reader;
    std::string str_to_parse{"one,two,three,four"};
    char delimiter{','};

    auto vec = reader.split(str_to_parse, delimiter);

    REQUIRE(vec.size() == 4);
    REQUIRE(vec[0] == "one");
    REQUIRE(vec[1] == "two");
    REQUIRE(vec[2] == "three");
    REQUIRE(vec[3] == "four");
}

TEST_CASE(
    "Comma separated values from a str_to_parse without whitespace ended with"
    " comma",
    "[reader]")
{
    Reader reader;
    std::string str_to_parse{"one,two,three,four,"};
    char delimiter{','};

    auto vec = reader.split(str_to_parse, delimiter);

    REQUIRE(vec.size() == 4);
    REQUIRE(vec[0] == "one");
    REQUIRE(vec[1] == "two");
    REQUIRE(vec[2] == "three");
    REQUIRE(vec[3] == "four");
}

TEST_CASE(
    "Comma separated values from a str_to_parse with whitespace ended with"
    " comma",
    "[reader]")
{
    Reader reader;
    std::string str_to_parse{
        "one , two ,\tthree\t\r\n,  \f\t\v four  \f\t\v ,  \f\t\v"};
    char delimiter{','};

    auto vec = reader.split(str_to_parse, delimiter);

    REQUIRE(vec.size() == 4);
    REQUIRE(vec[0] == "one");
    REQUIRE(vec[1] == "two");
    REQUIRE(vec[2] == "three");
    REQUIRE(vec[3] == "four");
}
