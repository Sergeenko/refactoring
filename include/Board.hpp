#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>
#include "IBoard.hpp"

class CyclicBoard : public IBoard
{
public:
    class iterator
    {
    public:
        iterator(std::vector<std::shared_ptr<ISquare>>& p_squares, size_t p_index)
            : m_squares(p_squares), m_currentIndex(p_index), m_startingSquare{p_index} {}

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

    private:
        std::vector<std::shared_ptr<ISquare>>& m_squares;
        size_t m_currentIndex;
        size_t m_startingSquare;
    };

    typename CyclicBoard::iterator begin()
    {
        return { m_squares, m_startPosition };
    }
private:
    size_t m_startPosition{0};
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
};