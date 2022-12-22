#pragma once

#include "ISquare.hpp"
#include "IPlayer.hpp"
#include <iostream>

class StartSquare : public ISquare
{
public:
    void onEntry([[maybe_unused]] IPlayer& p_player) override {}
    void onPass(IPlayer& p_player) override
    {
        p_player.addMoney(m_bonusMoney);
    }
private:
    Amount m_bonusMoney{200};
};

class PenaltySquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.subtractMoney(m_fineValue);
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    Amount m_fineValue{150};
};

class RewardSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.addMoney(m_rewardValue);
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    Amount m_rewardValue{5};
};

class DepositSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.addMoney(m_rewardValue);
        m_rewardValue = 0;
    }
    void onPass(IPlayer& p_player) override
    {
        p_player.subtractMoney(m_depositValue);
        m_rewardValue += m_depositValue;
    }

private:
    Amount m_rewardValue{0};
    Amount m_depositValue{50};
};

class EstateSquare : public ISquare
{
public:
    EstateSquare(Amount p_cost, Amount p_fine) : m_cost(p_cost), m_fine(p_fine) {}

    void onEntry(IPlayer& p_player) override
    {
        if(m_owner.expired())
        {
            m_owner = p_player.tryBuy(m_cost);
        }
        else if (p_player != *m_owner.lock())
        {
            std::cout << p_player.getName() << " was fined for stepping on " << m_owner.lock()->getName() << " field!" << std::endl;
            p_player.subtractMoney(m_fine);
            m_owner.lock()->addMoney(m_fine);
        }
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    std::weak_ptr<IPlayer> m_owner;
    Amount m_cost;
    Amount m_fine;
};