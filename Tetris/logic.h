#ifndef LOGIC_H
#define LOGIC_H
#include<vector>
#include "tetromino.h"
#include<SDL.h>

const int BOARD_ROWS = 20;
const int BOARD_COLS = 10;
// Quy ước ô có giá trị 0 là rỗng còn ô có giá trị 1 là đã bị chiếm
extern std::vector<std::vector<int>> board;
extern Tetromino nextTetromino;
extern int score;
extern int level ;
//extern Tetromino heldTetromino;
//extern bool hasHeldThisTurn;
//extern bool isHoldEmpty;
bool IsValidPosition(const Tetromino& t);
void MoveTetromino(Tetromino& current, Uint32& lastFallTime, Uint32 fallDelay);
void LockTetromino(const Tetromino& t);
void SpawnTetromino(Tetromino& current);
void DropTetromino(Tetromino& current) ;
void ClearFullRows() ;
//void HoldTetromino(Tetromino& current) ;
#endif // LOGIC_H
