#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>
#include "IBoard.hpp"

class iterator;

class CyclicBoard : public IBoard
{
public:

    CyclicBoard()
    {
        m_startingSquare = 0;
    }

private:

    class iterator
    {
    public:
        iterator(std::vector<std::unique_ptr<ISquare>>& p_squares, size_t p_index)
            : m_squares(p_squares), m_currentIndex(p_index) {}

        iterator& next()
        {
            if (++m_currentIndex == m_squares.size())
            {
                m_currentIndex = 0;
            }

           return *this;
        }

        ISquare& currentSquare() const
        {
            return *m_squares[m_currentIndex];
        }

    private:
        size_t m_currentIndex{0};
        std::vector<std::unique_ptr<ISquare>>& m_squares;
    }

    std::vector<std::unique_ptr<ISquare>> m_squares{
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),

        std::make_unique<StartSquare>(),

        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>()};
};