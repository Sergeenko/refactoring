#include <vector>
#include <utility>
#include "Board.hpp"
#include <algorithm>
#include <memory>
#include <iostream>

class IPlayer;

class Monopoly
{
public:

    Monopoly(std::vector<std::unique_ptr<IPlayer>> p_players, CyclicBoard p_board)
        : m_players(std::move(p_players)), m_board(std::move(p_board)) {}

    void makeRound()
    {
        for(auto& player : m_players)
        {
            player->makeMove();
        }
    }

    bool isEndGame()
    {
        return std::any_of(
            m_players.begin(),
            m_players.end(),
            [](const std::unique_ptr<IPlayer>& p_player)
            {
                return p_player->getMoney() <= 0;
            });
    }

private:
    std::vector<std::unique_ptr<IPlayer>> m_players;
    CyclicBoard m_board;
    Amount m_startReward{200};
};