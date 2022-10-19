#pragma once

#include "defines.h"

#include <iostream>
#include <vector>
#include <memory>

class ParserInput;
using ParserInputPtr = std::shared_ptr<ParserInput>;

class ParserInput
{
public:
    static ParserInputPtr create(std::istream& stream);
    static ParserInputPtr create(const std::string& input_file_name);

    ParserInput(std::istream& stream);
    ParserInput(const std::string& input_file_name);

    const Cases& cases() const { return m_cases; }

private:
    Cases m_cases;
};
