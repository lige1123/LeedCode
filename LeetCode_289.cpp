
int Dx[13] = {0, 0, -1, -1, -1, 1, 1, 1};
int Dy[13] = {1, -1, 0, 1,  -1, 1, -1, 0};



void gameOfLife(int** board, int boardSize, int* boardColSize){
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
         //   printf("%d ", board[i][j]);
            int num = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + Dx[k];
                if (x < 0 || x >= boardSize) continue;
                int y = j + Dy[k];
                if (y < 0 || y >= boardColSize[i]) continue;
                num += (board[x][y] & 1);
            }
            if ((board[i][j] & 1)) {
                if (num == 2 || num == 3) {
                    board[i][j] = 0b11;
                }
            } else if(num == 3) {
                board[i][j] = 0b10;
            }
        }
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            board[i][j] >>= 1;
        }
    }
}
