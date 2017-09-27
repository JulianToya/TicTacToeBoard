#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/*
BUG: toggleTurn() should change the turn to the other player, store
the new turn, and return that value. This bug causes the turn to 
switch from O to Blank.
*/
/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  return turn == X ? (turn = O) : (turn = Blank);  
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(getWinner() != Invalid) {
    return Invalid;
  }
  else if(row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    toggleTurn();
    return Invalid;
  }
  else if(board[row][column] != Blank) {
    toggleTurn();
    return board[row][column];
  }
  else {
    Piece temp = turn;
    board[row][column] = turn;
    toggleTurn();
    return temp;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{

  if(row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    return Invalid; 
  }
  
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece last;
  bool  winner = 0;

  // Check rows for winner
  for(unsigned i = 0; i < BOARDSIZE; ++i) {
    if((last = board[i][0]) == Blank) {
      continue;
    }

    for(unsigned j = 1; j < BOARDSIZE; ++j) {
      if(last != board[i][j]) {
        winner = 0;
        break;
      }        
      winner = 1;
    }
  }

  if(winner) {
    return last;
  }

  // Check columns for winner
  for(unsigned j = 0; j < BOARDSIZE; ++j) {
    if((last = board[0][j]) == Blank) {
      continue;
    }

    for(unsigned i = 1; i < BOARDSIZE; ++i) {
      if(last != board[i][j]) {
        winner = 0;
        break;
      }        
      winner = 1;
    }
  }

  if(winner) {
    return last;
  }

  // Check diagonals for winner
  for(unsigned j = 0; j < BOARDSIZE; j += 2) {
    if((last = board[0][j]) == Blank) {
      continue;
    }

    for(unsigned i = 1; i < BOARDSIZE; ++i) {
      if(j < 2) {
        if(last != board[i][j + i]) {
          winner = 0;
          break;
        }        
        winner = 1;
      }
      else {
        if(last != board[i][j - i]) {
          winner = 0;
          break;
        }        
        winner = 1;
      }
    }
    
    if(winner) {
      return last;
    }
  }

  return Invalid;  // No winner yet 
}
