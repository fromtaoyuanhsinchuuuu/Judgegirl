#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLEN 1000
#define NUM 0
#define TURN 1

bool inside_the_grid(int row,int col,int N)
{
    if (row < N && row >= 0 && col < N && col >= 0){
        return 1;
    }
    return 0;
}

void move(int grid[2][MAXLEN][MAXLEN],int N,int dr,int dc,int startrow,int startcol)
{
    while(inside_the_grid(startrow+dr,startcol+dc,N)){
        startrow += dr;
        startcol += dc;
        grid[TURN][startrow][startcol] = 1;
    }

}

void set_turn(int grid[2][MAXLEN][MAXLEN],int N)
{
    /* 右上 */
    int dx = 1;
    int start_row = N / 2;
    int start_col = N / 2;
    int nowrow = start_row;
    int nowcol = start_col;
    move(grid,N,-1,1,start_row,start_col);
    move(grid,N,1,1,start_row,start_col);
    move(grid,N,-1,-1,start_row,start_col);
    move(grid,N,1,-1,start_row,start_col - 1);
    grid[TURN][start_row][start_col - 1] = 1;
    



}

void SpiralSnake(int N, int *snake, int *result)
{
    int grid[2][MAXLEN][MAXLEN] = {{{}}};
    set_turn(grid,N);
    
    int row = N / 2;
    int col = N / 2;
    grid[NUM][row][col] = snake[0];
    result[N * N / 2] = snake[0];
    int index = 1;
    int dr = 0;
    int dc = -1;
    // for (int r = 0; r < N; r++){
    //     for (int c = 0; c < N; c++){
    //         printf("%d%c",grid[TURN][r][c]," \n"[c == N - 1]);
    //     }
    // }
    while (index < N * N){
        row += dr;
        col += dc;
        grid[NUM][row][col] = snake[index];
        result[row * N + col] = snake[index];

        if (grid[TURN][row][col]){
            int temp = dc;
            dc = -dr;
            dr = temp;
        }
        index++;
    }
    // printf("\n");
    // for (int r = 0; r < N; r++){
    //     for (int c = 0; c < N; c++){
    //         printf("%d%c",grid[NUM][r][c]," \n"[c == N - 1]);
    //     }
    // }
    
}

 
static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];
 
int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        for(int i=0; i<N*N; i++){
            printf("%d%c", result[i], " \n"[i==N*N-1]);
        }
    }
    return 0;
}
