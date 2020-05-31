#include <reader/reader.hpp>

#include <iostream>
#include <sstream>

std::vector<std::string> Reader::split(
    const std::string& str_to_parse, const char delimiter)
{
    std::stringstream ss{str_to_parse};

    std::vector<std::string> result;
    std::string token;

    while (std::getline(ss, token, delimiter))
    {         
        if (auto trimmed_token = trim(token);
                trimmed_token != std::string())
            result.push_back(trim(trimmed_token));
    }

    return result;
}

std::string Reader::trim(std::string str)
{
    return ltrim(rtrim(str));
}

std::string Reader::ltrim(std::string str)
{
    if (auto pos = str.find_first_not_of(WHITESPACES); 
            pos != std::string::npos)
    {
        str.erase(0, pos);
    }
    else
    {
        str = std::string();
    }

    return str;
}

std::string Reader::rtrim(std::string str)
{
    if (auto pos = str.find_last_not_of(WHITESPACES); 
            pos != std::string::npos)
    {
        str.erase(pos+1);
    }

    return str;
}
