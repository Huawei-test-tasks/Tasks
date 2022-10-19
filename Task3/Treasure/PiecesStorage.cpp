#include "PiecesStorage.h"

PiecesStoragePtr PiecesStorage::create(const Case& task)
{
    return std::make_shared<PiecesStorage>(task);
}

PiecesStorage::PiecesStorage(const Case& task)
    : m_x_width(task.n)
    , m_y_height(task.m)
{
    m_pieces.reserve(task.Pieces.size());

    for (auto& p : task.Pieces)
        m_pieces.emplace(Piece::create(p));

    updatePiecesLinks();
}

PiecesStorage::~PiecesStorage()
{
    for (auto& p : m_pieces)
        p->m_neighbors.clear();

    m_pieces.clear();
}

void PiecesStorage::updatePiecesLinks()
{
    for (auto it1 = m_pieces.begin(); it1 != m_pieces.end(); ++it1)
    {
        auto& l = *it1;

        for (auto it2 = std::next(it1); it2 != m_pieces.end(); ++it2)
        {
            auto& r = *it2;

            if (l->m_corners.x1 == r->m_corners.x2 &&
                l->m_corners.y2 > r->m_corners.y1 && l->m_corners.y1 < r->m_corners.y2)
            {
                l->m_neighbors.insert(r);
                r->m_neighbors.insert(l);
            }

            if (r->m_corners.x1 == l->m_corners.x2 &&
                r->m_corners.y2 > l->m_corners.y1 && r->m_corners.y1 < l->m_corners.y2)
            {
                r->m_neighbors.insert(l);
                l->m_neighbors.insert(r);
            }

            if (l->m_corners.y1 == r->m_corners.y2 &&
                l->m_corners.x2 > r->m_corners.x1 && l->m_corners.x1 < r->m_corners.x2)
            {
                l->m_neighbors.insert(r);
                r->m_neighbors.insert(l);
            }

            if (r->m_corners.y1 == l->m_corners.y2 &&
                r->m_corners.x2 > l->m_corners.x1 && r->m_corners.x1 < l->m_corners.x2)
            {
                r->m_neighbors.insert(l);
                l->m_neighbors.insert(r);
            }
        }
    }
}

