#pragma once

#include "defines.h"

class Calculator
{
public:
    Calculator(const Cases& cases);

    const std::vector<int32_t>& results() const { return m_results; };

private:
    void calculate(const Case& task);

private:
    std::vector<int32_t> m_results;
};
