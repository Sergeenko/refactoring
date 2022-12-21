#pragma once

#include <string_view>
#include "Aliases.hpp"

class IPlayer
{
public:
    virtual ~IPlayer() = default;
    virtual void addMoney(Amount) = 0;
    virtual void subtractMoney(Amount) = 0;
    virtual RollResult rollDice() const = 0;
    virtual void makeMove() = 0;
    virtual int getMoney() const = 0;
    virtual std::string_view getName() const = 0;
};