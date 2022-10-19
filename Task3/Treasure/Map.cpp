#include "Map.h"

#include <cstring>
#include <algorithm>

Map::Map(PiecesStorage& piecesStorage)
    : m_covering(piecesStorage.width() * piecesStorage.height(), 0)
    , m_capturePieces(piecesStorage.pieces().begin(), piecesStorage.pieces().end())
    , m_piecesStorage(piecesStorage)
{
    build();
}

void Map::build()
{
    for (auto& piece : m_capturePieces)
    {
        if (!processPiece(piece))
            continue;

        if (isFull())
            return;
    }
}

bool Map::tryApply(const PiecePtr& piece)
{
    auto pieceWidth  = piece->width();

    m_cache_zeros.resize(pieceWidth, 0);
    m_cache_units.resize(pieceWidth, 1);

    for (auto y = piece->corners().y1; y < piece->corners().y2; ++y)
    {
        auto linePointer = m_covering.data() + y * m_piecesStorage.width() * sizeof(uint8_t) + piece->corners().x1;
        if (std::memcmp(linePointer, m_cache_zeros.data(), pieceWidth))
            return false;
    }

    for (auto y = piece->corners().y1; y < piece->corners().y2; ++y)
    {
        auto linePointer = m_covering.data() + y * m_piecesStorage.width() * sizeof(uint8_t) + piece->corners().x1;
        std::memcpy(linePointer, m_cache_units.data(), pieceWidth);
    }

    m_coverCount += piece->width() * piece->height();

    ++m_numberAppliedPieces;

    return true;
}

bool Map::processPiece(const PiecePtr& piece)
{
    if (!tryApply(piece))
        return false;

    if (!isFull() && !piece->neighbors().empty())
    {
        std::vector<PiecePtr> neighbors(piece->neighbors().begin(), piece->neighbors().end());

        for (auto& n : neighbors)
        {
            m_piecesStorage.deleteLink(piece, n);

            if (!processPiece(n))
            {
                m_piecesStorage.createLink(piece, n);
                continue;
            }

            if (isFull())
                break;
        }
    }

    if (piece->neighbors().empty())
        m_piecesStorage.erasePiece(piece);

    return true;
}
