#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <reader/reader.hpp>


TEST_CASE("This is a test")
{
    Reader reader;
    std::string line{"one, two, three, four"};
    char delimiter{','};

    auto vec = reader.split(line, delimiter);

    REQUIRE(vec.size() == 4);
    REQUIRE(vec[0] == "one");
    REQUIRE(vec[1] == "two");
    REQUIRE(vec[2] == "three");
    REQUIRE(vec[3] == "four");
}