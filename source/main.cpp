#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <memory>
#include <vector>

int main()
{
    CyclicBoard l_cyclicBoard;
    std::vector<std::shared_ptr<IPlayer>> l_players;
    l_players.emplace_back(std::make_shared<HumanPlayer>("Staszek", std::make_unique<CyclicBoard::iterator>(l_cyclicBoard.begin()), Amount{5000}, Dice{2}));
    l_players.emplace_back(std::make_shared<GreedyAIPlayer>("T-800", std::make_unique<CyclicBoard::iterator>(l_cyclicBoard.begin()), Amount{5000}, Dice{2}));
    l_players.emplace_back(std::make_shared<RandomAIPlayer>("SkyNet", std::make_unique<CyclicBoard::iterator>(l_cyclicBoard.begin()), Amount{5000}, Dice{2}));

    Monopoly l_monopoly(std::move(l_players), l_cyclicBoard);

    while(not l_monopoly.isEndGame())
    {
        l_monopoly.makeRound();
    }

    l_monopoly.printEndGameStats();
    return 0;
}