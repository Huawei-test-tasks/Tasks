#include "Calculator.h"
#include "Treasure/PiecesStorage.h"
#include "Treasure/Map.h"

#include <algorithm>

Calculator::Calculator(const Cases& cases)
{
    m_results.reserve(cases.size());

    for (auto& c : cases)
        calculate(c);
}

void Calculator::calculate(const Case& task)
{
    PiecesStorage piecesStorage(task);

    int32_t res = -1;
    while (!piecesStorage.empty())
    {
        Map map(piecesStorage);

        if (!map.isFull())
            continue;

        res = res != -1
            ? std::min(res, static_cast<int32_t>(map.numberAppliedPieces()))
            : static_cast<int32_t>(map.numberAppliedPieces());
    }

    m_results.push_back(res);
}
