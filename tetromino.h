#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
using namespace std ;
struct Tetromino {
    vector<vector<int>> shape ;
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

