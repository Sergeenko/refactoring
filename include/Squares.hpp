#pragma once

#include "ISquare.hpp"
#include "IPlayer.hpp"

class StartSquare : public ISquare {
public:
    void onEntry([[maybe_unused]] IPlayer& p_player) override {}
};

class PenaltySquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.fine(m_fineValue);
    }

private:
    size_t m_fineValue {150};
};

class RewardSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.reward(m_rewardValue);
    }

private:
    size_t m_rewardValue {50};
};