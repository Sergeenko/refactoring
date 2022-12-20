#pragma once

class IPlayer;

class ISquare
{
public:
    virtual void onEntry(IPlayer&) = 0;
    virtual void onPass(IPlayer&) = 0;
    virtual ~ISquare() = default;
};