#include <vector>
#include <utility>
#include "Board.hpp"
#include <algorithm>
#include <memory>

class IPlayer;

class Monopoly
{
public:

    Monopoly(std::vector<std::shared_ptr<IPlayer>> p_players, Board p_board)
        : m_players(std::move(p_players)), m_board(std::move(p_board)) {}

    void makeRound()
    {
        for(auto& player : m_players)
        {
            auto l_rollResult =  player->rollDice();
            auto l_oldPosition = player->getPosition();
            auto l_newPosition = (player->getPosition() + l_rollResult) % m_board.m_squares.size();
            if (l_newPosition < l_oldPosition)
            {
                player->reward(m_startReward);
            }

            player->move(l_newPosition);
            m_board.m_squares[l_newPosition]->onEntry(*player);
        }
    }


    bool isEndGame()
    {
        return std::any_of(
            m_players.begin(),
            m_players.end(),
            [](const std::shared_ptr<IPlayer>& p_player)
            {
                return p_player->getMoney() <= 0;
            });
    }
private:

    std::vector<std::shared_ptr<IPlayer>> m_players;
    Board m_board;
    Amount m_startReward{500};

};