## <p align="center"> Làm Game Xếp Hình Bằng C++ </p>
<p align="center">
  <img src="https://raw.githubusercontent.com/DaiTaTuong/PicTureOfTetris/b1b66e19c44e7a71f4d1c07bdad3d8c9b8c63ea5/Menu.png
  " alt="Menu" />
</p>

## Làm Game Xếp Hình Bằng C++

### Giới thiệu trò chơi xếp hình    

Trò chơi xếp hình cổ điển là trò chơi vô cùng quen thuộc và khá thú vị của cả thế hệ 8x 9x đến bây giờ vẫn "viral".

Bạn sẽ được cho một cái hộp kích thước 10 x 20, lúc bắt đầu trò chơi thì trạng thái của hộp đang rỗng.

Mỗi lượt bạn sẽ được cho 1 khối hình ngẫu nhiên trong 7 hình phía dưới:

<p align="center"> <img src="https://github.com/zukahai/HaiZuka/blob/master/Images/ClassicJigsawPuzzle/1.png" alt="Tieude" /> </p>

Khối hình này sẽ có xu hướng dịch chuyển xuống phía dưới, nó sẽ dừng lại khi rơi xuống đáy hộp, hoặc gặp phải một khối hình đã rơi xuống trước đó, ngay sau khi nó dừng lại thì một khối hình khác sẽ rơi xuống, nếu các hình vuông trong các khối hình gộp được thành một hàng ngang thì hàng ngang đó sẽ biến mất và các khối hình ở phía trên nó sẽ rơi xuống, thế chỗ cho hàng ngang vừa mất.

Bạn có thể di chuyển khối hình sang trái, sang phải hoặc xuống dưới, đặc biệt bạn cũng có thể xoay khối hình một góc 90o theo chiều kim đồng hồ (bạn có thể xoay nhiều lần). Nhiệm vụ của bạn là phá vỡ nhiều hàng ngang càng nhiều càng tốt, bạn sẽ bị thua nếu như không còn chỗ xuất hình cho khối hình tiếp theo.

### Lập trình game xếp hình

Để dễ dàng xử lý các khối hình ta sẽ tạo ra một struct Tetromino gồm các thuộc tính:

- Loại khối hình (1 trong 7 khối hình đã nêu ở trên)
- Màu sắc của khối hình
- Tất cả tạo độ của các hình vuông có trong khối hình

Và các phương thức:

- Khởi tạo tọa độ các ô vuông của khối hình
- Xoay trái 90 độ
- Xoay phải 90 độ
- Dịch khối hình lên trên, xuống dưới, sang trái, sang phải
- Kiểm tra khôi hình và chạm

Đầu tiên khi khởi tạo các khối hình thì ta sẽ tạo ra 1 mảng vector 2 chiều có dạng một ma trận 4x4 để dễ dàng có thể thực hiện các công việc (được gói trong 1 struct):

```C++
	enum TetrominoType {
    I, O, T, S, Z, J, L
}; // gán giá trị I=0, O =1 , T=2, ...
struct Tetromino {
    std::vector<std::vector<int>> shape ;
    TetrominoType type ;
    int x, y;

    Tetromino(); // random tetromino
    Tetromino(std::vector<std::vector<int>> s, int startX);

    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void RotateClockwise();      
    void RotateCounterClockwise(); 
};
```

Phương thức xoay phải 90 độ

<p align="center"> <img src="https://github.com/zukahai/HaiZuka/blob/master/Images/ClassicJigsawPuzzle/2.png" alt="Tieude" /> </p>
<p align="center"> <img src="https://github.com/zukahai/HaiZuka/blob/master/Images/ClassicJigsawPuzzle/4.png" alt="Tieude" /> </p>

Như đã nói ở trên, khi xoay 90 độ thì ta chỉ cần xoay ma trận 4x4 ấy 90 độ sang phải hoặc sang trái.

- Ta chỉ cần viết hàm xoay ma trận là đủ. 

Các phương thức, dịch chuyển lên, xuống, sang trái, qua phải, xoay cùng chiều ngược chiều kim đồng hồ cũng như khởi tạo hình dạng và tọa độ các Tetromino.
```C++
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
    int idx = getNextTetrominoType() ;
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


```
Phương thức kiểm tra xem khối tetromino có đi ra ngoài ô không.

Để kiểm tra thì ta sẽ sử dụng hàm bool nếu như ô nào có giá trị bằng 1 thì kiểm tra xem có đi ra khỏi ô không.

```C++
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
```

Xử lý sự kiểm khi gõ phím:

```C++
	void HandleEvent(Render& render, Tetromino& current) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            render.Stop();
        }
if (event.type == SDL_KEYDOWN) {
    Tetromino temp = current;  // Tạo bản sao tạm thời của khối tetromino hiện tại

    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            temp.MoveLeft();
            if (IsValidPosition(temp)) current.MoveLeft();
            break;
        case SDLK_RIGHT:
            temp.MoveRight();
            if (IsValidPosition(temp)) current.MoveRight();
            break;
        case SDLK_DOWN:
            temp.MoveDown();
            if (IsValidPosition(temp)) current.MoveDown();
            break;
        case SDLK_z:
            temp.RotateCounterClockwise();
            if (IsValidPosition(temp)) current.RotateCounterClockwise();
            break;
        case SDLK_UP:
            temp.RotateClockwise();
            if (IsValidPosition(temp)) current.RotateClockwise();
            break;
        case SDLK_SPACE:
            DropTetromino(current) ;
            break ;
    }
}
    }
}
bool HandleMenuEvents(bool& quit) {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
            return false; // Thoát luôn
        }
        if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) {
            return true;
        }
    }
    return false;
}
```

Có nghĩa là khi ở Menu ta chỉ cần ấn bất kỳ phím nào kể cả chuột là có thể chơi được. 

Lock khối Tetromino và xóa hàng khi nó đầy 1 hàng ngang, cơ chế drop Tetromino.

```C++
		void ClearFullRows() {
    for (int y = BOARD_ROWS - 1; y >= 0; --y) {
        bool full = true;
        for (int x = 0; x < BOARD_COLS; ++x) {
            if (board[y][x] == 0) {
                full = false;
                break;
            }
        }

        if (full) {
            // Xóa hàng hiện tại bằng cách đẩy các hàng phía trên xuống
            for (int row = y; row > 0; --row) {
                board[row] = board[row - 1];
            }
            board[0] = vector<int>(BOARD_COLS, 0); // Hàng trên cùng là hàng trống
            y++; // Kiểm tra lại hàng này vì đã có hàng mới đẩy xuống
        }
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
    current = Tetromino();
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
```

### Kết

Trên đây là logic game của tôi để làm ra game lập trình, nếu còn sai sót hãy đóng góp và phát triển nhé !
