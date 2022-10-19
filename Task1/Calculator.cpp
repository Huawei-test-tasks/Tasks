#include "Calculator.h"
#include "BigInteger.h"

Calculator::Calculator(const Cases& cases)
{
    m_results.reserve(cases.size());

    for (auto& c : cases)
        calculate(c);
}

void Calculator::calculate(const Case& task)
{
    BigInterger sum(task.A);

    sum += task.B;

    m_results.push_back(sum.toString());
}
