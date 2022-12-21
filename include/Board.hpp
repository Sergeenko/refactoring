#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>
#include "IBoard.hpp"

class CyclicBoard : public IBoard
{
public:
    class iterator : public IBoard::Iiterator
    {
    public:
        iterator(std::vector<std::shared_ptr<ISquare>>& p_squares, size_t p_index)
            : m_squares(p_squares), m_currentIndex(p_index) {}

        iterator& next() override
        {
            m_currentIndex = (m_currentIndex + 1) % m_squares.size();
            return *this;
        }

        ISquare& currentSquare() const override
        {
            return *m_squares[m_currentIndex];
        }

        bool operator==(const iterator& other) const
        {
            return (m_currentIndex == other.m_currentIndex) and
                (&m_squares == &other.m_squares);
        }

    private:
        std::vector<std::shared_ptr<ISquare>>& m_squares;
        size_t m_currentIndex;
    };

    iterator& begin()
    {
        return m_startPosition;
    }

    size_t getSize() const
    {
        return m_squares.size();
    }
private:
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
    CyclicBoard::iterator m_startPosition{m_squares, 0};
};