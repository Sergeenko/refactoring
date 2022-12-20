#include "ISquare.hpp"

class StartSquare {};

class PenaltySquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.fine(m_fineValue);
    }

private:
    size_t m_fineValue {50};
};

class RewardSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.reward(m_rewardValue);
    }

private:
    size_t m_rewardValue {100};
};