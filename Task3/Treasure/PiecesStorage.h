#pragma once

#include "defines.h"
#include "Piece.h"

#include <unordered_map>

class PiecesStorage;
using PiecesStoragePtr = std::shared_ptr<PiecesStorage>;

class PiecesStorage
{
    friend class Map;

public:
    using Pieces = std::unordered_set<PiecePtr>;

public:
    static PiecesStoragePtr create(const Case& task);

    decltype (Case::n) width()  const { return m_x_width; }
    decltype (Case::m) height() const { return m_y_height; }

    PiecesStorage(const Case& task);
    ~PiecesStorage();

    bool empty() const {return m_pieces.empty(); }

    const Pieces pieces() const { return m_pieces; }


private:
    void deleteLink(const PiecePtr& l, const PiecePtr& r);
    void createLink(const PiecePtr& l, const PiecePtr& r);

    void erasePiece(const PiecePtr& piece);
    void updatePiecesLinks();

private:
    decltype (Case::n) m_x_width  = 0;
    decltype (Case::m) m_y_height = 0;

    Pieces m_pieces;
};

inline
void PiecesStorage::deleteLink(const PiecePtr& l, const PiecePtr& r)
{
    l->m_neighbors.erase(r);
    r->m_neighbors.erase(l);
}

inline
void PiecesStorage::createLink(const PiecePtr& l, const PiecePtr& r)
{
    l->m_neighbors.insert(r);
    r->m_neighbors.insert(l);
}

inline
void PiecesStorage::erasePiece(const PiecePtr& piece)
{
    m_pieces.erase(piece);
}
