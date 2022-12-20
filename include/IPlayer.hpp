#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include "Aliases.hpp"


class IPlayer
{
public:
    virtual ~IPlayer() = default;
    virtual void fine(Amount) = 0;
    virtual void reward(Amount) = 0;
    virtual RollResult rollDice() const = 0;
    virtual void move(RollResult) = 0;
    virtual Position getPosition() const = 0;
    virtual int getMoney() const = 0;
    virtual std::string_view getName() const = 0;
};