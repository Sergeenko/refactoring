#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <memory>

int main()
{
    Monopoly l_monopoly({std::make_shared<HumanPlayer>("Staszek"), std::make_shared<HumanPlayer>("Waldek")}, Board{});

    while(not l_monopoly.isEndGame())
    {
       l_monopoly.makeRound();
    }

    return 0;
}