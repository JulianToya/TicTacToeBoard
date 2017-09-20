/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleReturn)
{
  TicTacToeBoard test;
  Piece prevTurn;
  Piece nextTurn;

  prevTurn = test.toggleTurn();
  nextTurn = test.toggleTurn();

  ASSERT_NE(prevTurn,nextTurn); 
}

TEST(TicTacToeBoardTest, toggleVarCheck)
{
  TicTacToeBoard test;
  Piece prevTurn;
  Piece nextTurn;

  prevTurn = test.placePiece(0,0);
  nextTurn = test.placePiece(1,1);

  ASSERT_NE(prevTurn,nextTurn); 
}

TEST(TicTacToeBoardTest, placeWinner)
{
  TicTacToeBoard test;
  Piece result;

  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(0,1);
  test.toggleTurn();
  test.placePiece(0,2);

  result = test.placePiece(0,0);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutG1)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(3,0);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutG2)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(0,3);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutGBoth)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(3,3);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutL1)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(-1,0);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutL2)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(0,-1);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeOutLBoth)
{
  TicTacToeBoard test;
  Piece result;

  result = test.placePiece(-1,-1);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, placeExist)
{
  TicTacToeBoard test;
  Piece prev;
  Piece result;

  prev = test.placePiece(0,0);
  result = test.placePiece(0,0);

  ASSERT_EQ(result,prev); 
}

TEST(TicTacToeBoardTest, placeNotExist)
{
  TicTacToeBoard test;
  Piece current;
  Piece result;

  current = test.toggleTurn();
  result  = test.placePiece(0,0);

  ASSERT_EQ(result,current); 
}

TEST(TicTacToeBoardTest, placeWasPlaced)
{
  TicTacToeBoard test;
  Piece current;
  Piece result;

  current = test.toggleTurn();

  test.placePiece(0,0);

  result = test.placePiece(0,0);

  ASSERT_EQ(result,current); 
}

TEST(TicTacToeBoardTest, pieceGot)
{
  TicTacToeBoard test;
  Piece current;
  Piece result;

  test.placePiece(0,0);
  current = test.toggleTurn();
  result  = test.getPiece(0,0);

  ASSERT_EQ(result,current); 
}

TEST(TicTacToeBoardTest, pieceOutG1)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(3,0);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, pieceOutG2)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(0,3);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, pieceOutGBoth)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(3,3);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, pieceOutL1)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(-1,0);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, pieceOutL2)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(0,-1);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, pieceOutLBoth)
{
  TicTacToeBoard test;
  Piece result;

  result = test.getPiece(-1,-1);

  ASSERT_EQ(result,Invalid); 
}

TEST(TicTacToeBoardTest, winnerXRow1)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(0,1);
  test.toggleTurn();
  test.placePiece(0,2);
  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYRow1)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(0,1);
  test.toggleTurn();
  test.placePiece(0,2);
  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXRow2)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(1,0);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(1,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYRow2)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(1,0);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(1,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXRow3)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(2,0);
  test.toggleTurn();
  test.placePiece(2,1);
  test.toggleTurn();
  test.placePiece(2,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYRow3)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(2,0);
  test.toggleTurn();
  test.placePiece(2,1);
  test.toggleTurn();
  test.placePiece(2,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXCol1)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(1,0);
  test.toggleTurn();
  test.placePiece(2,0);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYCol1)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(1,0);
  test.toggleTurn();
  test.placePiece(2,0);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXCol2)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,1);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,1);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYCol2)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(0,1);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,1);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXCol3)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,2);
  test.toggleTurn();
  test.placePiece(1,2);
  test.toggleTurn();
  test.placePiece(2,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYCol3)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,2);
  test.toggleTurn();
  test.placePiece(1,2);
  test.toggleTurn();
  test.placePiece(2,2);
  test.toggleTurn();

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXDia1)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYDia1)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(0,0);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,2);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerXDia2)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,2);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,0);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, winnerYDia2)
{
  TicTacToeBoard test;
  Piece winner;

  test.toggleTurn();
  test.placePiece(0,2);
  test.toggleTurn();
  test.placePiece(1,1);
  test.toggleTurn();
  test.placePiece(2,0);

  winner = test.getWinner();

  ASSERT_NE(winner, Invalid);
}

TEST(TicTacToeBoardTest, notWinner)
{
  TicTacToeBoard test;
  Piece winner;

  test.placePiece(0,2);
  test.toggleTurn();
  test.placePiece(2,2);
  test.toggleTurn();
  test.placePiece(2,1);
  test.toggleTurn();
  winner = test.getWinner();

  ASSERT_EQ(winner, Invalid);
}
