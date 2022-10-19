#pragma once

#include "defines.h"

#include <memory>
#include <unordered_set>

class Piece;
using PiecePtr = std::shared_ptr<Piece>;

inline
bool operator==(const PiecePtr& l, const PiecePtr& r)
{
    return l.get() == r.get();  // compare pointers
}

namespace std
{
    template<> struct hash<PiecePtr>
    {
        size_t operator() (const PiecePtr& value) const
        {
            return reinterpret_cast<size_t>(value.get());
        }
    };
}

class Piece
{
    friend class PiecesStorage;

    using Neighbors = std::unordered_set<PiecePtr>;

public:
    static PiecePtr create(const PieceCorners& corners);

    Piece(const PieceCorners& corners);

    decltype(PieceCorners::x1) width()  const { return m_corners.x2 - m_corners.x1; }
    decltype(PieceCorners::y1) height() const { return m_corners.y2 - m_corners.y1; }

    const PieceCorners& corners()   const { return m_corners; }
    const Neighbors&    neighbors() const { return m_neighbors; }

private:
    PieceCorners m_corners;
    Neighbors    m_neighbors;
};
