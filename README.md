## <p align="center"> Làm Game Xếp Hình Bằng C++ </p>

## Làm Game Xếp Hình Bằng C++

### Giới thiệu trò chơi xếp hình    

Trò chơi xếp hình cổ điển là trò chơi vô cùng quen thuộc và khá thú vị của cả thế hệ 8x 9x đến bây giờ vẫn "viral".

Bạn sẽ được cho một cái hộp kích thước 10 x 20, lúc bắt đầu trò chơi thì trạng thái của hộp đang rỗng.

Mỗi lượt bạn sẽ được cho 1 khối hình ngẫu nhiên trong 7 hình phía dưới:

<p align="center"> <img src="https://github.com/zukahai/HaiZuka/blob/master/Images/ClassicJigsawPuzzle/1.png" alt="Tieude" /> </p>

Khối hình này sẽ có xu hướng dịch chuyển xuống phía dưới, nó sẽ dừng lại khi rơi xuống đáy hộp, hoặc gặp phải một khối hình đã rơi xuống trước đó, ngay sau khi nó dừng lại thì một khối hình khác sẽ rơi xuống, nếu các hình vuông trong các khối hình gộp được thành một hàng ngang thì hàng ngang đó sẽ biến mất và các khối hình ở phía trên nó sẽ rơi xuống, thế chỗ cho hàng ngang vừa mất.

Bạn có thể di chuyển khối hình sang trái, sang phải hoặc xuống dưới, đặc biệt bạn cũng có thể xoay khối hình một góc 90o theo chiều kim đồng hồ (bạn có thể xoay nhiều lần). Nhiệm vụ của bạn là phá vỡ nhiều hàng ngang càng nhiều càng tốt, bạn sẽ bị thua nếu như không còn chỗ xuất hình cho khối hình tiếp theo.

### Game có những tính năng gì và cách chơi như thế nào

- Khi chơi thì bạn sẽ dùng các nút lên trên, xuống dưới, trái, phải để điều khiển 1 trong 7 các khối Tetromino. 
- Khi đầy 1 hàng ngang thì sẽ được tăng điểm, khi ăn nhiều hàng ngang một lúc sẽ càng được nhiều điểm. 
- Bạn có thể thấy được khối tiếp theo ở ô "NEXT" để có thể chơi như thế nào cho hợp lý. 
- Nếu như bạn không muốn dùng khối này muốn đổi sang khối NEXT tiếp theo thì bạn có thể nhấn phím "C" để có thể đổi. Hình vẽ của khối sẽ ở ô "HOLD"
- Nếu như bạn bị thua thì sẽ ngay lập tức thoát khỏi game.



### Kết
Nguổn tham khảo, phát triển từ game Tetris cổ điển.  
