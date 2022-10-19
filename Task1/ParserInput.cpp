#include "ParserInput.h"
#include "string_extention.h"

#include <cstdlib>
#include <fstream>
#include <cassert>

ParserInputPtr ParserInput::create(std::istream& stream)
{
    return std::make_shared<ParserInput>(stream);
}

ParserInputPtr ParserInput::create(const std::string& input_file_name)
{
    auto fstream = std::ifstream(input_file_name, std::ios_base::in);
    return std::make_shared<ParserInput>(fstream);
}

ParserInput::ParserInput(std::istream& stream)
{
    std::string line;

    std::getline(stream, line);
    auto numberCases = std::stoull(line);

    m_cases.reserve(numberCases);

    std::vector<std::string> line_words;
    while (numberCases > 0 && !stream.eof())
    {
        std::getline(stream, line);

        if (line.empty())
            continue;

        line_words.clear();
        std::split(line, line_words, ' ', true);

        if (line_words.size() != 2)
#ifdef ENABLE_PARSER_EXCEPTIONS
            throw std::runtime_error("The string must contain two numbers");
#else
            continue;
#endif

        m_cases.push_back(Case { std::move(line_words[0]), std::move(line_words[1]) });

        --numberCases;
    }

#ifdef ENABLE_PARSER_EXCEPTIONS
    if (numberCases != 0)
        throw std::runtime_error("Parser: the number of cases does not match the number of rows");
#endif

}
