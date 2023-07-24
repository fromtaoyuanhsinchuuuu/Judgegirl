#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE 50

enum status {DEAD,DYING,HEALTHY};



inline int count_headlthy_neightbor(int grid[SIZE][SIZE],int row,int col,int cell);
inline int in_grid(int row,int col);
inline int copy(int grid[SIZE][SIZE],int outcome[SIZE][SIZE]);


extern inline int in_grid(int row,int col)
{
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE){
        return 1;
    }
    return 0;
    
}

extern inline int count_headlthy_neightbor(int grid[SIZE][SIZE],int row,int col,int cell)
{
    int dr[3] = {-1,0,1};
    int dc[3] = {-1,0,1};

    int count = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if ((dr[i] || dc[j]) && in_grid(row+dr[i],col+dc[j]) && grid[row+dr[i]][col+dc[j]] == 2){
                count++;
            }
            if (count > 3) {
                return count;
            }
        }
    }
    return count;
}

extern inline int copy(int grid[SIZE][SIZE],int outcome[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++){
        for (int c = 0; c < SIZE; c++){
            grid[r][c] = outcome[r][c];
        }
    }
    return 1;
}

void game_of_cell(int grid[50][50],int outcome[50][50],int N)
{
    int cell = -1;
    int healthy_neighbor = 0;
    for (int time = 0; time < N; time++){
        for (int nowC = 0; nowC < SIZE; nowC++){
            for (int nowR = 0; nowR < SIZE; nowR++){
                cell = grid[nowR][nowC];
                healthy_neighbor = count_headlthy_neightbor(grid,nowR,nowC,cell);
                if (cell == HEALTHY){
                    if (healthy_neighbor < 2){
                        outcome[nowR][nowC] = DEAD;
                    }
                    else if (healthy_neighbor == 2 || healthy_neighbor == 3){
                        outcome[nowR][nowC] = grid[nowR][nowC];
                    }
                    else{
                        outcome[nowR][nowC] = DYING;
                    }
                }
                else if (cell == DEAD){
                    if (healthy_neighbor == 3){
                        outcome[nowR][nowC] = HEALTHY;
                    }
                    else{
                        outcome[nowR][nowC] = grid[nowR][nowC];
                    }
                }
                else{
                    assert (cell == DYING);
                    if (healthy_neighbor == 2){
                        outcome[nowR][nowC] = HEALTHY;
                    }
                    else{
                        outcome[nowR][nowC] = grid[nowR][nowC];
                    }
                }
                
            }
        }
        copy(grid,outcome);
    }

}

int main()
{
    int grid[50][50]={0},outcome[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            printf("%d%c",outcome[i][j]," \n"[j==49]);
    return 0;
}