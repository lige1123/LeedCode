int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int sum = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                for (int d1 = i - 1; d1 >= 0; d1--) {
                    if (board[d1][j] == 'B') {
                        break;
                    } else if(board[d1][j] == 'p') {
                        sum++;
                        break;
                    }
                }
                for (int d1 = i + 1; d1 < boardSize; d1++) {
                    if (board[d1][j] == 'B') {
                        break;
                    } else if(board[d1][j] == 'p') {
                        sum++;
                        break;
                    }
                }
                for (int d1 = j - 1; d1 >= 0; d1--) {
                    if (board[i][d1] == 'B') {
                        break;
                    } else if(board[i][d1] == 'p') {
                        sum++;
                        break;
                    }
                }
                for (int d1 = j + 1; d1 < boardColSize[i]; d1++) {
                    if (board[i][d1] == 'B') {
                        break;
                    } else if(board[i][d1] == 'p') {
                        sum++;
                        break;
                    }
                }
                break;
            }
        }
    }
    return sum;
}
