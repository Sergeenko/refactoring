#include <gtest/gtest.h> // googletest header file
#include <gmock/gmock.h>

#include "Board.hpp"
#include "Player.hpp"
#include <memory>

using testing::NiceMock;

class SquareMock : public ISquare
{
public:
  MOCK_METHOD(void, onEntry, (IPlayer&), (override));
  MOCK_METHOD(void, onPass, (IPlayer&), (override));
};

class DiceMock : public Dice
{
public:
    MOCK_METHOD(RollResult, roll, ());
};

class CyclicBoardMock : public IBoard
{
  //MOCK_METHOD(void, onEntry, (IPlayer&), (override));

};

struct BoardTest : public testing::Test
{
    CyclicBoard m_board;
};

TEST_F(BoardTest, checkCyclicity)
{
    auto l_iterator = m_board.begin();

    for(size_t index = 0; index < m_board.getSize(); index++)
    {
        l_iterator.next();
    }

    ASSERT_EQ(l_iterator, m_board.begin());
}

struct PlayerTest : BoardTest
{
    HumanPlayer m_player{"TestPlayer", std::make_unique<CyclicBoard::iterator>(m_board.begin()), 5000, Dice{2}};
    NiceMock<SquareMock> m_squareMock;
};

TEST_F(PlayerTest, checkMoneyManagement)
{
    m_player.subtractMoney(100);
    ASSERT_EQ(m_player.getMoney(), 4900);

    m_player.addMoney(100);
    ASSERT_EQ(m_player.getMoney(), 5000);
}

TEST_F(PlayerTest, aaa)
{

}