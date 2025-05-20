#include "rand_modern.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

static vector<int> bag;
static int bagIndex = 0;

// Sử dụng bộ tạo số ngẫu nhiên tốt hơn
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

static void refillBag() {
    bag = {0, 1, 2, 3, 4, 5, 6};
    shuffle(bag.begin(), bag.end(), rng);
    bagIndex = 0;
}

int getNextTetrominoType() {
    if (bagIndex >= bag.size()) {
        refillBag();
    }
    return bag[bagIndex++];
}
