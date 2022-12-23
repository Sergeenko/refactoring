#pragma once

#include <iostream>
#include <random>
#include "IPlayer.hpp"
#include "IStrategy.hpp"

class Human : public IStrategy
{
public:
    std::weak_ptr<IPlayer> tryBuy(IPlayer& p_player, Amount p_cost) override
    {
        if (hasEnoughMoneyToBuy(p_player.getMoney(), p_cost))
        {
            std::string input;
            std::cout << "Do You want to Buy this Estate? (yes/no) " << std::endl;
            while(std::getline(std::cin, input))
            {
                if (input == "yes")
                {
                    p_player.subtractMoney(p_cost);
                    return p_player.weak_from_this();
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

class GreedyAI : public IStrategy
{
public:
    std::weak_ptr<IPlayer> tryBuy(IPlayer& p_player, Amount p_cost) override
    {
        if (hasEnoughMoneyToBuy(p_player.getMoney(), p_cost))
        {
            p_player.subtractMoney(p_cost);
            return p_player.weak_from_this();
        }
        return {};
    }
};

class RandomAI : public IStrategy
{
public:
    std::weak_ptr<IPlayer> tryBuy(IPlayer& p_player, Amount p_cost) override
    {
        if (hasEnoughMoneyToBuy(p_player.getMoney(), p_cost))
        {
            if (toBuyOrNotToBuy())
            {
                p_player.subtractMoney(p_cost);
                return p_player.weak_from_this();
            }
        }
        return {};
    }
private:
    bool toBuyOrNotToBuy()
    {
        return m_distrib(m_gen);
    }
    std::mt19937 m_gen{std::random_device()()};
    std::uniform_int_distribution<> m_distrib{0, 1};
};