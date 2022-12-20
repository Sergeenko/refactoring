#include <cstdint>
#include <string>
#include "Aliases.hpp"

class IPlayer
{
public:
    virtual void fine(Amount) = 0;
    virtual void reward(Amount) = 0;
    virtual RollResult rollDice() = 0;

    virtual ~IPlayer() = 0;
private:
    int m_money{5000};
    Position m_currentPosition{0};
    std::string m_name;
    PlayerId m_playerId;
};