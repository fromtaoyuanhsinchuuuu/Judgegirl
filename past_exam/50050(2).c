#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLEN 1000

bool inside_the_grid(int row,int col,int N)
{
    if (row < N && row >= 0 && col < N && col >= 0){
        return 1;
    }
    return 0;
}

void SpiralSnake(int N, int *snake, int *result)
{
    static int grid[MAXLEN][MAXLEN] = {{}};
    /* 最底下的row */
    grid[N - 1][N - 1] = snake[N * N - N];
    for (int dx = 1; dx <= N - 1; dx++){
        grid[N - 1][N - 1 - dx] = grid[N - 1][N - 1 - dx + 1] - 1;
        grid[N - 1 - dx][N - 1] = grid[N - 1 - dx + 1][N - 1] - N;
    }
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            printf("%d%c",grid[r][c]," \n"[c == N - 1]);
        }
    }
    



}

 
static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];
 
int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        // for(int i=0; i<N*N; i++)
            //  printf("%d%c", result[i], " \n"[i==N*N-1]);
    }
    return 0;
}
