#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Strategy.hpp"

int main()
{
    Monopoly<CyclicBoard> l_monopoly;
    l_monopoly.addPlayer<Human>("Staszek", Amount{5000}, Dice{2});
    l_monopoly.addPlayer<GreedyAI>("T-800", Amount{5000}, Dice{2});
    l_monopoly.addPlayer<RandomAI>("SkyNet", Amount{5000}, Dice{2});

    l_monopoly.play();
    l_monopoly.printEndGameStats();
    return 0;
}