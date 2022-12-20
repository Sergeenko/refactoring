#include "Monopoly.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <memory>
#include <vector>

std::vector<std::unique_ptr<IPlayer>> createPlayers()
{
    std::vector<std::unique_ptr<IPlayer>> l_players;
    l_players.emplace_back(std::make_unique<HumanPlayer>("Staszek"));
    l_players.emplace_back(std::make_unique<HumanPlayer>("Waldek"));
    return l_players;
}

int main()
{
    Monopoly l_monopoly(createPlayers(), Board{});

    while(not l_monopoly.isEndGame())
    {
       l_monopoly.makeRound();
    }

    return 0;
}