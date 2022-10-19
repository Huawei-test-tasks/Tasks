#include "Piece.h"

PiecePtr Piece::create(const PieceCorners& corners)
{
    return std::make_shared<Piece>(corners);
}

Piece::Piece(const PieceCorners& corners)
    : m_corners(corners)
{
}
