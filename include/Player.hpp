#include "IPlayer.hpp"

class HumanPlayer : public IPlayer
{
public:
    void fine(size_t p_amount) override;
    void reward(size_t p_amount) override;
    uint8_t rollDice() override;
};