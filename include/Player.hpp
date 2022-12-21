#pragma once

#include "IPlayer.hpp"
#include "Aliases.hpp"
#include <cstdlib>
#include <random>
#include <utility>
#include <string>
#include <string_view>

class Dice
{
public:
    explicit Dice(size_t p_numberOfDice) : m_numberOfDice(p_numberOfDice) {}

    RollResult roll()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 6);
        auto l_resultOne = distrib(gen);
        auto l_resultTwo = distrib(gen);
        m_currentThrow = l_resultOne + l_resultTwo;

        return m_currentThrow;
    }

private:
    size_t m_numberOfDice;
    RollResult m_currentThrow;
};

class HumanPlayer : public IPlayer
{
public:
    explicit HumanPlayer(std::string p_name, std::unique_ptr<IBoard::Iiterator> p_startingPosition, int p_startingMoney, Dice p_dice)
        : m_name(std::move(p_name)), m_currentPosition(std::move(p_startingPosition)), m_money(p_startingMoney), m_dice(p_dice)  {}

    void subtractMoney(Amount p_amount) override
    {
        m_money -= p_amount;
    }
    void addMoney(Amount p_amount) override
    {
        m_money += p_amount;
    }

    void makeMove() override
    {
        auto l_rollResult = m_dice.roll();
        std::cout << getName() << " rolls: " << static_cast<unsigned>(l_rollResult) << '\n';

        while (l_rollResult--)
        {
            m_currentPosition->next();
            m_currentPosition->currentSquare().onPass(*this);
        }
        m_currentPosition->currentSquare().onEntry(*this);
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
    std::string m_name;
    std::unique_ptr<IBoard::Iiterator> m_currentPosition;
    int m_money;
    Dice m_dice;
};