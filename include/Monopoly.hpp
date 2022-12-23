#pragma once

#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <memory>
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Strategy.hpp"

template<typename BoardType>
class Monopoly
{
public:
    template<typename Strategy>
    void addPlayer(std::string p_name, Amount p_startingMoney, Dice p_dice)
    {
        m_players.emplace_back(
                std::make_shared<Player<BoardType>>(
                        std::move(p_name),
                        m_board.begin(),
                        p_startingMoney,
                        std::move(p_dice),
                        std::get<Strategy>(m_strategies)));
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
    std::tuple<Human, GreedyAI, RandomAI> m_strategies;
};