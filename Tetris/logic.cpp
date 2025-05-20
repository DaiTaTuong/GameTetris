#include "logic.h"
using namespace std ;
vector<vector<int>> board(BOARD_ROWS, vector<int>(BOARD_COLS, 0));
int score = 0 ;
Tetromino nextTetromino = Tetromino();
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


void ClearFullRows() {
    int rowsCleared = 0; // Số hàng đã xóa

    for (int y = BOARD_ROWS - 1; y >= 0; --y) {
        bool full = true;
        for (int x = 0; x < BOARD_COLS; ++x) {
            if (board[y][x] == 0) {
                full = false;
                break;
            }
        }

        if (full) {
            rowsCleared++; // Đếm hàng đã xóa
            // Xóa hàng hiện tại bằng cách đẩy các hàng phía trên xuống
            for (int row = y; row > 0; --row) {
                board[row] = board[row - 1];
            }
            board[0] = vector<int>(BOARD_COLS, 0); // Hàng trên cùng là hàng trống
            y++; // Kiểm tra lại hàng này vì đã có hàng mới đẩy xuống
        }
    }

    // Cập nhật điểm số dựa trên số hàng xóa
    switch (rowsCleared) {
        case 1: score += 100; break;
        case 2: score += 300; break;
        case 3: score += 500; break;
        case 4: score += 800; break; // Tetris!
        default: break;
    }
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
    ClearFullRows() ;
}

void SpawnTetromino(Tetromino& current) {
    current = nextTetromino;
    nextTetromino = Tetromino() ;
}
void MoveTetromino(Tetromino& current, Uint32& lastFallTime, Uint32 fallDelay) {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastFallTime > fallDelay) {
        Tetromino temp = current;
        temp.MoveDown();

        if (IsValidPosition(temp)) {
            current.MoveDown();
        } else {
            LockTetromino(current);
            SpawnTetromino(current);
        }

        lastFallTime = currentTime;
    }
}
void DropTetromino(Tetromino& current) {
    while (true) {
        current.MoveDown();
        if (!IsValidPosition(current)) {
            current.y--; // quay lại vị trí hợp lệ cuối cùng
            break;
        }
    }
    LockTetromino(current);
    SpawnTetromino(current);
}





