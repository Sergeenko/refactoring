#pragma once

#include "IPlayer.hpp"
#include "IStrategy.hpp"
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
        RollResult result{};
        for (auto dice = m_numberOfDice; dice != 0; --dice)
        {
            result += distrib(m_gen);
        }
        return result;
    }

private:
    size_t m_numberOfDice;
    std::mt19937 m_gen{std::random_device()()};
    std::uniform_int_distribution<> distrib{1,6};
};

template<typename BoardType>
class Player : public IPlayer
{
public:
    explicit Player(std::string p_name, Amount p_startingMoney, Dice p_dice, typename BoardType::iterator p_startingPosition, IStrategy& p_strategy)
        : m_name(std::move(p_name)),
          m_currentPosition(std::move(p_startingPosition)),
          m_money(p_startingMoney),
          m_dice(std::move(p_dice)),
          m_strategy(p_strategy) {}

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
        if (m_daysInJailLeft)
        {
            --m_daysInJailLeft;
            std::cout << getName() << " days in jail left... " << m_daysInJailLeft << '\n';
            return;
        }
        auto l_rollResult = m_dice.roll();
        std::cout << getName() << " rolls: " << static_cast<unsigned>(l_rollResult) << '\n';

        while (l_rollResult--)
        {
            m_currentPosition.next();
            m_currentPosition.currentSquare().onPass(*this);
        }
        m_currentPosition.currentSquare().onEntry(*this);
        std::cout << getName() << " has: " << getMoney() << '\n';
    }

    Amount getMoney() const override
    {
        return m_money;
    }

    std::string_view getName() const override
    {
        return m_name;
    }

    void goToJail(Amount p_daysInJail) override
    {
        m_daysInJailLeft = p_daysInJail;
        std::cout << getName() << " jailed for... " << m_daysInJailLeft << " days." <<'\n';
    }

    std::weak_ptr<IPlayer> tryBuy(Amount p_cost) override
    {
        return m_strategy.tryBuy(*this, p_cost);
    }

private:
    std::string m_name;
    typename BoardType::iterator m_currentPosition;
    Amount m_money;
    Dice m_dice;
    Amount m_daysInJailLeft{0};
    IStrategy& m_strategy;
};


