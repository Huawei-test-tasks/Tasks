#pragma once

#include "defines.h"

class Calculator
{
public:
    Calculator(const Cases& cases);

    const std::vector<int64_t>& results() const { return m_results; };

private:
    void calculate(const Case& task);

private:
    std::vector<int64_t> m_results;
};
