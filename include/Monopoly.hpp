#include <vector>
#include <utility>

class Monopoly
{
public:

    Monopoly(std::vector<IPlayer> p_players, Board p_board)
        : m_players(std::move(p_players)), m_board(std::move(p_board)) {}


private:

    std::vector<IPlayer> m_players;
    Board m_board;

};