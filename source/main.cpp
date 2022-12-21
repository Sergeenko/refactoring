#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <memory>
#include <vector>

int main()
{
    CyclicBoard l_cyclicBoard;
    std::vector<std::unique_ptr<IPlayer>> l_players;
    l_players.emplace_back(std::make_unique<HumanPlayer>("Staszek", l_cyclicBoard.begin(), 5000, Dice{2}));
    l_players.emplace_back(std::make_unique<HumanPlayer>("Waldek", l_cyclicBoard.begin(), 5000, Dice{2}));

    Monopoly l_monopoly(std::move(l_players), l_cyclicBoard);

    while(not l_monopoly.isEndGame())
    {
    l_monopoly.makeRound();
    }

    return 0;
}