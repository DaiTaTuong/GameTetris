#ifndef LOGIC_H
#define LOGIC_H
#include<vector>
#include "tetromino.h"
#include<SDL.h>
using namespace std ;

const int BOARD_ROWS = 20;
const int BOARD_COLS = 10;
// Quy ước ô có giá trị 0 là rỗng còn ô có giá trị 1 là đã bị chiếm
extern vector<vector<int>> board;

bool IsValidPosition(const Tetromino& t);
void MoveTetromino(Tetromino& current, Uint32& lastFallTime, Uint32 fallDelay);
void LockTetromino(const Tetromino& t);
void SpawnTetromino(Tetromino& current);
void DropTetromino(Tetromino& current) ;
void ClearFullRows() ;
#endif // LOGIC_H
