#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class Reader
{
public:
    std::vector<std::string> split(const std::string& line, const char delimiter)
    {
        std::stringstream ss{line};

        std::vector<std::string> result;
        std::string token;

        while (std::getline(ss, token, delimiter))
            result.push_back(token);

        return result;
    }
};