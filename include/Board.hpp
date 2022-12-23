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

        [[nodiscard]] ISquare& currentSquare() const override
        {
            return *m_squares[m_currentIndex];
        }

    private:
        std::vector<std::shared_ptr<ISquare>>& m_squares;
        size_t m_currentIndex;
    };

    iterator& begin() override
    {
        return m_startPosition;
    }

private:
    std::vector<std::shared_ptr<ISquare>> m_squares{
            std::make_shared<Start>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),

            std::make_shared<Estate>(200, 50),
            std::make_shared<Estate>(200, 50),
            std::make_shared<Estate>(200, 50),
            std::make_shared<Estate>(200, 50),

            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),

            std::make_shared<Prison>(),

            std::make_shared<Random>(std::vector<std::shared_ptr<ISquare>>{
                std::make_shared<Penalty>(),
                std::make_shared<Prison>(),
                std::make_shared<Reward>()}),


            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),
            std::make_shared<Penalty>(),

            std::make_shared<Blackhole>(std::make_shared<Penalty>()),

            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Deposit>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),
            std::make_shared<Reward>(),

            std::make_shared<Prison>()
            };
    CyclicBoard::iterator m_startPosition{m_squares, 0};
};