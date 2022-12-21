#pragma once

#include "ISquare.hpp"
#include "IPlayer.hpp"

class StartSquare : public ISquare {
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