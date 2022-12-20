#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <memory>
#include <vector>

int main()
{
    auto l_cyclicBoard = std::make_shared<CyclicBoard>();
    CyclicBoard::iterator l_startingIterator = l_cyclicBoard->begin();
    std::vector<std::unique_ptr<IPlayer>> l_players;
    l_players.emplace_back(std::make_unique<HumanPlayer>("Staszek", l_startingIterator));
    l_players.emplace_back(std::make_unique<HumanPlayer>("Waldek", l_startingIterator));

    // Monopoly l_monopoly(l_players, l_cyclicBoard);

    // while(not l_monopoly.isEndGame())
    // {
    //    l_monopoly.makeRound();
    // }

    return 0;
}