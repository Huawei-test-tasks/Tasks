#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace std
{

inline void ltrim_inplace(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim_inplace(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim_inplace(std::string& s)
{
    ltrim_inplace(s);
    rtrim_inplace(s);
}

inline size_t split(const std::string& str, std::vector<std::string>& cont, char delim, bool trimElements)
{
    size_t count = 0;
    std::size_t current, previous = 0;
    do
    {
        std::string token;
        current = str.find(delim, previous);
        if (current == std::string::npos)
            token = str.substr(previous);
        else
        {
            token = str.substr(previous, current - previous);
            previous = current + 1;
        }

        if (trimElements)
            trim_inplace(token);

        cont.emplace_back(std::move(token));
        ++count;

    } while(current != std::string::npos);

    return count;
}

}
