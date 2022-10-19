#pragma once

#include <string>
#include <vector>

struct PieceCorners
{
    uint32_t x1;
    uint32_t y1;

    uint32_t x2;
    uint32_t y2;
};

struct Case
{
    Case(uint32_t _n, uint32_t _m)
        : n(_n), m(_m)
    {}

    Case(Case&& r)
        : n(r.n)
        , m(r.m)
        , Pieces(std::move(r.Pieces))
    {}

    uint32_t n;
    uint32_t m;

    std::vector<PieceCorners> Pieces;
};

using Cases = std::vector<Case>;
