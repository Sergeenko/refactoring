#include <vector>
#include <utility>
#include "Board.hpp"
#include <algorithm>
#include <memory>
#include <iostream>
#include "Player.hpp"

class IPlayer;

template<typename BoardType>
class Monopoly
{
public:
    template<typename PlayerType>
    void addPlayer(std::string p_name, Amount p_startingMoney, Dice p_dice)
    {
        m_players.emplace_back(std::make_shared<PlayerType>(std::move(p_name), std::make_unique<typename BoardType::iterator>(m_board.begin()), p_startingMoney, p_dice));
    }

    void play()
    {
        while(not isEndGame())
        {
            makeRound();
        }
    }

    void printEndGameStats()
    {
        std::cout <<"====== THE GAME IS OVER ======" << '\n';

        for(auto const& player : m_players)
        {
            std::cout << "====== " << player->getName() <<  " has: " << player->getMoney() << " ======" << '\n';
        }
    }
private:
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
                [](const std::shared_ptr<IPlayer>& p_player)
                {
                    return p_player->getMoney() <= 0;
                });
    }

    std::vector<std::shared_ptr<IPlayer>> m_players;
    BoardType m_board;
};