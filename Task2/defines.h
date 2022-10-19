#pragma once

#include <string>
#include <vector>

struct Case
{
    Case(uint32_t _N, uint32_t _M)
        : N(_N), M(_M)
    {}

    Case(Case&& r)
        : N(r.N)
        , M(r.M)
        , Integers(std::move(r.Integers))
    {}

    uint32_t N;
    int64_t  M;

    std::vector<int64_t> Integers;
};

using Cases = std::vector<Case>;
