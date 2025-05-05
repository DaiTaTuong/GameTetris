#include "tetromino.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const vector<vector<vector<int>>> tetrominoShapes = {
    {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}}, // I
    {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}, // O
    {{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}}, // T
    {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}}, // S
    {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}}, // Z
    {{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}}, // J
    {{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}}  // L
};

Tetromino::Tetromino() {
    static bool seeded = false; // Khi dùng static thì hàm srand chỉ được gọi đúng 1 lần khi mà random các khối tetromino
    if (!seeded) { srand(time(nullptr)); seeded = true; }

    int idx = rand() % 7;
    shape = tetrominoShapes[idx];
    type = static_cast<TetrominoType>(idx);
    x = 3;
    y = 0 ;
}

Tetromino::Tetromino(vector<vector<int>> s, int startX)
    : shape(s), x(startX), y(0) {}

void Tetromino::MoveDown()  { y++; }
void Tetromino::MoveLeft()  { x--; }
void Tetromino::MoveRight() { x++; }

void Tetromino::RotateClockwise() {
    int n = shape.size();
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < n ; j++)
        {
            r[j][n - i - 1] = shape[i][j];
        }
    }
    shape = r;
}

void Tetromino::RotateCounterClockwise() {
    int n = shape.size();
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[n - j - 1][i] = shape[i][j];
    shape = r;
}

