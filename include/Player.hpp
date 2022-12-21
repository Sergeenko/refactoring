#pragma once

#include "IPlayer.hpp"
#include "Aliases.hpp"
#include <cstdlib>
#include <random>
#include <utility>
#include <string>
#include <string_view>

class HumanPlayer : public IPlayer
{
public:
    explicit HumanPlayer(std::string p_name, CyclicBoard::iterator p_startingPosition)
        : m_name(std::move(p_name)), m_currentPosition(std::move(p_startingPosition)) {}

    void subtractMoney(Amount p_amount) override
    {
        m_money -= p_amount;
    }
    void addMoney(Amount p_amount) override
    {
        m_money += p_amount;
    }

    RollResult rollDice() const override
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 6);
        auto l_resultOne = distrib(gen);
        auto l_resultTwo = distrib(gen);
        return l_resultOne + l_resultTwo;
    }

    void makeMove() override
    {
        auto l_rollResult = rollDice();
        std::cout << getName() << " rolls: " << static_cast<unsigned>(l_rollResult) << '\n';

        while (l_rollResult--)
        {
            m_currentPosition.next();
            m_currentPosition.currentSquare().onPass(*this);
        }
        m_currentPosition.currentSquare().onEntry(*this);
        std::cout << getName() << " has: " << getMoney() << '\n';
    }

    int getMoney() const override
    {
        return m_money;
    }

    std::string_view getName() const override
    {
        return m_name;
    }

private:
    int m_money{5000};
    std::string m_name;
    typename CyclicBoard::iterator m_currentPosition;
};