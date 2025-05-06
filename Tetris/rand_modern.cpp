#include "rand_modern.h"
#include <vector>
#include <algorithm>
#include <random>
#include <SDL.h> //
using namespace std ;
static vector<int> bag;
static int bagIndex = 0;

static void refillBag() {
    bag = {0, 1, 2, 3, 4, 5, 6};
    shuffle(bag.begin(), bag.end(), default_random_engine(SDL_GetTicks()));
    bagIndex = 0;
}

int getNextTetrominoType() {
    if (bagIndex >= bag.size()) {
        refillBag();
    }
    return bag[bagIndex++];
}
// Thuật toán 7-bag
