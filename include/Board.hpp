#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>
#include "IBoard.hpp"

class CyclicBoard : public IBoard
{
public:
    class iterator;
    CyclicBoard(){}

    CyclicBoard::iterator begin()
    {
        return m_iterator.begin();
    }

    class iterator
    {
    public:
        iterator(std::vector<std::shared_ptr<ISquare>>& p_squares, size_t p_index)
            : m_squares(p_squares), m_currentIndex(p_index) {}

        iterator& next()
        {
            if (++m_currentIndex == m_squares.size())
            {
                m_currentIndex = m_startingSquare;
            }

           return *this;
        }

        ISquare& currentSquare() const
        {
            return *m_squares[m_currentIndex];
        }

        iterator begin()
        {
            return iterator(m_squares, m_startingSquare);
        }

    private:
        std::vector<std::shared_ptr<ISquare>>& m_squares;
        size_t m_currentIndex{0};
        size_t m_startingSquare{0};
    };

    std::vector<std::shared_ptr<ISquare>> m_squares{
        std::make_shared<StartSquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>()};
    CyclicBoard::iterator m_iterator = CyclicBoard::iterator(m_squares, 0);
};