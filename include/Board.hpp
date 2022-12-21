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

        bool operator==(const iterator& other) const
        {
            return (m_currentIndex == other.m_currentIndex) and
                (m_startingSquare == other.m_startingSquare) and
                (&m_squares == & other.m_squares);
        }

    private:
        std::vector<std::shared_ptr<ISquare>>& m_squares;
        size_t m_currentIndex;
        const size_t m_startingSquare;
    };

    CyclicBoard::iterator& begin()
    {
        return CyclicBoard::iterator{ m_squares, m_startPosition };
    }

    size_t getSize() const
    {
        return m_squares.size();
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
            std::make_shared<DepositSquare>(),
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
            std::make_shared<DepositSquare>(),
            std::make_shared<RewardSquare>(),
            std::make_shared<RewardSquare>(),
            std::make_shared<RewardSquare>(),
            std::make_shared<RewardSquare>(),
            std::make_shared<RewardSquare>()};
};