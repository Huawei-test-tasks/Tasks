#pragma once

#include "PiecesStorage.h"

class Map
{
public:
    Map(PiecesStorage& piecesStorage);

    bool isFull() const { return m_coverCount >= m_covering.size(); };

    size_t numberAppliedPieces() const { return m_numberAppliedPieces; }

private:
    void build();

    bool tryApply(const PiecePtr& piece);

private:
    bool processPiece(const PiecePtr& piece);

private:
    size_t m_numberAppliedPieces = 0;
    size_t m_coverCount          = 0;

    std::vector<uint8_t> m_covering;

    std::vector<PiecePtr> m_capturePieces;
    PiecesStorage&        m_piecesStorage;

    std::vector<uint8_t> m_cache_zeros;
    std::vector<uint8_t> m_cache_units;
};
