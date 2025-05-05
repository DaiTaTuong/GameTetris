#include "logic.h"
using namespace std ;
vector<vector<int>> board(BOARD_ROWS, vector<int>(BOARD_COLS, 0));

bool IsValidPosition(const Tetromino& t)
{
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0; j < 4 ; j++) {
            if (t.shape[i][j]) // Kiếm tra
             {
                int x = t.x + j;
                int y = t.y + i;

                if (x < 0 || x >= BOARD_COLS || y < 0 || y >= BOARD_ROWS)
                    return false;

                if (board[y][x]) return false;
            }
        }
    }
    return true;
}
void LockTetromino(const Tetromino& t) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (t.shape[i][j]) {
                int x = t.x + j;
                int y = t.y + i;
                if (y >= 0 && y < BOARD_ROWS && x >= 0 && x < BOARD_COLS) {
                    board[y][x] = 1; // đánh dấu cho ô bị chiếm là 1
                }
            }
        }
    }
}

void SpawnTetromino(Tetromino& current) {
    current = Tetromino();
}
