#pragma once

#include <string_view>
#include "Aliases.hpp"
#include <memory>

class IPlayer : public std::enable_shared_from_this<IPlayer>
{
public:
    virtual ~IPlayer() = default;
    virtual void addMoney(Amount) = 0;
    virtual void subtractMoney(Amount) = 0;
    virtual void makeMove() = 0;
    virtual Amount getMoney() const = 0;
    virtual std::string_view getName() const = 0;
    virtual void goToJail(Amount) = 0;
    virtual std::weak_ptr<IPlayer> tryBuy(Amount) = 0;
};