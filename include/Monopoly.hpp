#include <vector>
#include <utility>

class Monopoly
{
public:

    Monopoly(std::vector<IPlayer> p_players, Board p_board)
        : m_players(std::move(p_players)), m_board(std::move(p_board)) {}

    void makeRound()
    {
        for(auto const& player : m_players)
        {
            auto l_rollResult =  player.rollDice();
            auto l_oldPosition = player.m_currentPosition;
            auto l_newPosition = (player.m_currentPosition + l_rollResult) % m_board.size();
            if (l_newPosition < l_oldPosition)
            {
                player.reward(m_startReward);
            }

            player.move(l_newPosition);
            m_board.m_squares[l_newPosition].onEntry(player);
        }
    }


    bool isEndGame()
    {
        return std::any_of(
            m_players.begin(),
            m_players.end(),
            [](const IPlayer& p_player)
            {
                return p_player.getMoney() <= 0;
            });
    }
private:

    std::vector<IPlayer> m_players;
    Board m_board;
    Amount m_startReward{500};

};