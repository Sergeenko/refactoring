#pragma once

#include <string_view>
#include "Aliases.hpp"
#include <memory>
class IPlayer
{
public:
    IPlayer(std::string p_name) : m_name(p_name){};
    virtual ~IPlayer() = default;
    virtual void addMoney(Amount) = 0;
    virtual void subtractMoney(Amount) = 0;
    virtual void makeMove() = 0;
    virtual int getMoney() const = 0;
    virtual std::string_view getName() const = 0;
    virtual std::weak_ptr<IPlayer> tryBuy(Amount) = 0;
    virtual void goToJail(Amount) = 0;
    virtual bool operator==(const IPlayer&) const = 0;

protected:
    std::string m_name;
};