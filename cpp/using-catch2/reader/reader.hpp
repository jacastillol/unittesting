#include <string>
#include <vector>

class Reader
{
    const std::string WHITESPACES{" \f\n\r\t\v"};

public:
    std::vector<std::string> split(
        const std::string& str_to_parse, const char delimiter);

    std::string trim(std::string str);
    std::string ltrim(std::string str);
    std::string rtrim(std::string str);
};