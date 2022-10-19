#pragma once

#include "defines.h"

class Calculator
{
public:
    Calculator(const Cases& cases);

    const std::vector<std::string>& results() const { return m_results; };

private:
    void calculate(const Case& expr);

private:
    std::vector<std::string> m_results;
};
