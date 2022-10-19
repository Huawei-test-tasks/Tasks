#include "Calculator.h"

#include <algorithm>

Calculator::Calculator(const Cases& cases)
{
    m_results.reserve(cases.size());

    for (auto& c : cases)
        calculate(c);
}

void Calculator::calculate(const Case& task)
{
    std::vector<decltype(Case::Integers)::value_type> doubleSums;

    doubleSums.reserve(task.N * task.N);

    for (auto& l : task.Integers)
    {
        for (auto& r : task.Integers)
            if (auto sum = l + r; sum <= task.M)
                doubleSums.push_back(sum);
    }

    std::sort(doubleSums.begin(), doubleSums.end());

    decltype (Case::M) res = 0;

    for (auto& ds : doubleSums)
    {
        auto need = task.M - ds;

        auto it = std::lower_bound(
                      doubleSums.rbegin()
                    , doubleSums.rend()
                    , need
                    , std::greater<decltype(doubleSums)::value_type>()
                  );

        auto allowed = it != doubleSums.rend() ? *it : 0;

        res = std::max(res, ds + allowed);
    }

    m_results.push_back(res);
}
