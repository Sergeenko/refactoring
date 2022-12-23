#pragma once

#include "Aliases.hpp"
#include <memory>

class IPlayer;

class IStrategy
{
public:
    virtual ~IStrategy() = default;
    virtual std::weak_ptr<IPlayer> tryBuy(IPlayer& p_player, Amount p_cost) = 0;
protected:
    static bool hasEnoughMoneyToBuy(Amount p_availableMoney, Amount p_cost)
    {
        return p_availableMoney >= p_cost;
    }
};