#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
using namespace std ;
enum TetrominoType {
    I, O, T, S, Z, J, L
}; // gán giá trị I=0, O =1 , T=2, ...
struct Tetromino {
    vector<vector<int>> shape ;
    TetrominoType type ;
    int x, y;

    Tetromino(); // random tetromino
    Tetromino(std::vector<std::vector<int>> s, int startX);

    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void RotateClockwise();      // rotate
    void RotateCounterClockwise(); // rotate
};

#endif // TETROMINO_H

