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
    std::vector<std::string> line_words;
    while (!stream.eof())
    {
        std::getline(stream, line);
        std::trim_inplace(line);

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

        auto N = static_cast<uint32_t>(std::stoul(line_words[0]));
        auto M = static_cast<int64_t>(std::stoll(line_words[1]));

        Case task(N, M);

        if (task.N == 0 && task.M == 0)
            break;

        uint32_t i = 0;
        while (i++ < task.N && !stream.eof())
        {
            std::getline(stream, line);
            std::trim_inplace(line);

            task.Integers.push_back(std::stoull(line));
        }

        m_cases.emplace_back(std::move(task));
    }
}
