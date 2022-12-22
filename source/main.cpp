#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main()
{
    Monopoly<CyclicBoard> l_monopoly;
    l_monopoly.addPlayer<HumanPlayer>("Staszek", Amount{5000}, Dice{2});
    l_monopoly.addPlayer<GreedyAIPlayer>("T-800", Amount{5000}, Dice{2});
    l_monopoly.addPlayer<RandomAIPlayer>("SkyNet", Amount{5000}, Dice{2});

    l_monopoly.play();
    l_monopoly.printEndGameStats();
    return 0;
}