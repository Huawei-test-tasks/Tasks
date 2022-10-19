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
    std::trim_inplace(line);

    if (line.empty())
        return;

    auto numberCases = std::stoull(line);

    m_cases.reserve(static_cast<size_t>(numberCases));

    std::vector<std::string> line_words;
    while (numberCases > 0 && !stream.eof())
    {
        std::getline(stream, line);
        std::trim_inplace(line);

        if (line.empty())
            continue;

        line_words.clear();
        std::split(line, line_words, ' ', true);

        if (line_words.size() != 3)
#ifdef ENABLE_PARSER_EXCEPTIONS
            throw std::runtime_error("The string must contain three numbers");
#else
            continue;
#endif

        Case task(std::stoul(line_words[0]), std::stoul(line_words[1]));

        auto p = std::stoul(line_words[2]);

        for (uint32_t i = 0; i < p; ++i)
        {
            std::getline(stream, line);
            std::trim_inplace(line);

            if (line.empty())
                continue;

            line_words.clear();
            std::split(line, line_words, ' ', true);

            if (line_words.size() != 4)
#ifdef ENABLE_PARSER_EXCEPTIONS
                throw std::runtime_error("The string must contain four numbers");
#else
                continue;
#endif
            auto x1 = static_cast<decltype (PieceCorners::x1)>(std::stoul(line_words[0]));
            auto y1 = static_cast<decltype (PieceCorners::x1)>(std::stoul(line_words[1]));
            auto x2 = static_cast<decltype (PieceCorners::x1)>(std::stoul(line_words[2]));
            auto y2 = static_cast<decltype (PieceCorners::x1)>(std::stoul(line_words[3]));

            if (x1 > x2 || y1 > y2)
#ifdef ENABLE_PARSER_EXCEPTIONS
                throw std::runtime_error("Piece coordinates are set incorrectly");
#else
                continue;
#endif

            x1 = std::min(x1, task.n);
            y1 = std::min(y1, task.m);
            x2 = std::min(x2, task.n);
            y2 = std::min(y2, task.m);

            task.Pieces.emplace_back(PieceCorners { x1, y1, x2, y2 });
        }

        m_cases.push_back(std::move(task));

        --numberCases;
    }

#ifdef ENABLE_PARSER_EXCEPTIONS
    if (numberCases != 0)
        throw std::runtime_error("Parser: the number of cases does not match the number of rows");
#endif

}
