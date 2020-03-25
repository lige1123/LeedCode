
int min(int a, int b) {
    return a > b ? b : a;
}


int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int s = 0;
    for (int  i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j]) {
                s += (4 * grid[i][j] + 2);
                if (i && grid[i - 1][j]) {
                    s -= (min(grid[i - 1][j], grid[i][j]) * 2);
                }
                if (j && grid[i][j - 1]) {
                    s -= (min(grid[i][j - 1], grid[i][j]) * 2);
                }
            }
            //printf("%d\n", s);
        }
    }
    return s;
}
