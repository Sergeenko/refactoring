#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"


int main()
{
    Monopoly l_monopoly({{"Staszek"}, {"Waldek"}}, Board{});

    while(not l_monopoly.isEndGame())
    {
       l_monopoly.makeRound();
    }

    return 0;
}