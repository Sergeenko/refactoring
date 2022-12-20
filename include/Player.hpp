#pragma once

#include "IPlayer.hpp"
#include "Aliases.hpp"
#include <cstdlib>
#include <random>
#include <utility>
#include <string_view>

class HumanPlayer : public IPlayer
{
public:
    explicit HumanPlayer(std::string p_name) : m_name(std::move(p_name)) {}

    void fine(Amount p_amount) override
    {
        m_money -= p_amount;
    }
    void reward(Amount p_amount) override
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

    void move(Position p_newPosition) override
    {
        m_currentPosition = p_newPosition;
    }

    Position getPosition() const override
    {
        return m_currentPosition;
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
    Position m_currentPosition;
    std::string m_name;
};