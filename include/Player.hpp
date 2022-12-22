#pragma once

#include "IPlayer.hpp"
#include "Aliases.hpp"
#include <cstdlib>
#include <random>
#include <utility>
#include <string>
#include <string_view>
#include <algorithm>

class Dice
{
public:
    explicit Dice(size_t p_numberOfDice) : rolls(p_numberOfDice) {}

    RollResult roll()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 6);
        for (auto& roll : rolls)
        {
            roll = distrib(gen);
        }

        return std::accumulate(rolls.begin(), rolls.end(), 0u);
    }

private:
    std::vector<size_t> rolls;
};

class GenericPlayer : public IPlayer, public std::enable_shared_from_this<IPlayer>
{
public:
    explicit GenericPlayer(std::string p_name, std::unique_ptr<IBoard::Iiterator> p_startingPosition, Amount p_startingMoney, Dice p_dice)
        : IPlayer(std::move(p_name)), m_currentPosition(std::move(p_startingPosition)), m_money(p_startingMoney), m_dice(p_dice)  {}

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

    bool operator==(IPlayer const& other) const final
    {
        return m_name == other.getName();
    }

    void goToJail(Amount p_daysInJail) override
    {
        m_daysInJailLeft = p_daysInJail;
        std::cout << getName() << " jailed for... " << m_daysInJailLeft << " days." <<'\n';
    }

protected:
    bool checkIfEnoughMoneyToBuy(Amount p_cost) const
    {
        return m_money >= p_cost;
    }

    std::unique_ptr<IBoard::Iiterator> m_currentPosition;
    int m_money;
    Dice m_dice;
    Amount m_daysInJailLeft{0};
};

class HumanPlayer : public GenericPlayer
{
public:
    using GenericPlayer::GenericPlayer;

    std::weak_ptr<IPlayer> tryBuy(Amount p_cost) override
    {
        if (checkIfEnoughMoneyToBuy(p_cost))
        {
            std::string input;
            std::cout << "Do You want to Buy this Estate? (yes/no) " << std::endl;
            while(std::getline(std::cin, input))
            {
                if (input == "yes")
                {
                    m_money -= p_cost;
                    return weak_from_this();
                }
                else if (input == "no")
                {
                    return {};
                }
            }
        }
        return {};
    }

};

class GreedyAIPlayer : public GenericPlayer
{
public:
    using GenericPlayer::GenericPlayer;

    std::weak_ptr<IPlayer> tryBuy(Amount p_cost) override
    {
        if (checkIfEnoughMoneyToBuy(p_cost))
        {
            m_money -= p_cost;
            return weak_from_this();
        }
        return {};
    }
};

class RandomAIPlayer : public GenericPlayer
{
public:
    using GenericPlayer::GenericPlayer;

    std::weak_ptr<IPlayer> tryBuy(Amount p_cost) override
    {
        if (checkIfEnoughMoneyToBuy(p_cost))
        {
            if (buyOrNotToBuy())
            {
                m_money -= p_cost;
                return weak_from_this();
            }
        }
        return {};
    }

private:
    static bool buyOrNotToBuy()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 1);

        return distrib(gen);
    }
};
