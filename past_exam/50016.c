#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define ARRSIZE 4
enum MOVETYPE {UP,RIGHT,DOWN,LEFT};

bool KeppGoing(int Puzzle[ARRSIZE][ARRSIZE],int remainK)
{
    int wrong_pos = 0;
    for (int i = 0; i < 16; i++){
        if (Puzzle[i / 4][i % 4] && Puzzle[i / 4][i % 4] != i + 1){
            wrong_pos++;
        }
    }
    
    if ((wrong_pos > remainK) || remainK == 0){
        return 0;
    }
    return 1;
}

bool winning(int Puzzle[ARRSIZE][ARRSIZE])
{
    for (int i = 0; i < 15; i++){
        if (Puzzle[i / 4][i % 4] != i + 1){
            return 0;
        }
    }
    return 1;
}

void exchange(int Puzzle[ARRSIZE][ARRSIZE],int row,int col,int ex_row,int ex_col)
{
    int temp = Puzzle[row][col];
    Puzzle[row][col] = Puzzle[ex_row][ex_col];
    Puzzle[ex_row][ex_col] = temp;
    return;
}

bool in_the_puzzle(int r,int c)
{
    if (r >= 0 && r < ARRSIZE && c >= 0 && c < ARRSIZE){
        return 1;
    }
    return 0;
}

void PrintPuzzle(int Puzzle[ARRSIZE][ARRSIZE])
{
    for (int i = 0; i < ARRSIZE; i++){
        for (int j = 0; j < ARRSIZE; j++){
            printf("%d%c",Puzzle[i][j]," \n"[j == ARRSIZE - 1]);
        }
    }
}

bool move(int Puzzle[ARRSIZE][ARRSIZE],int remainK,int row,int col)
{
    /* row,col為0的位置 */
    if (winning(Puzzle)){
        return 1;
    }
    if (!KeppGoing(Puzzle,remainK)){
        return 0;
    }

    for (int movetype = 0; movetype < 4; movetype++){
        int ex_row = row;
        int ex_col = col;
        switch (movetype)
        {
            case UP: ex_row--; break;
            
            case RIGHT: ex_col++; break;

            case DOWN: ex_row++; break;

            case LEFT: ex_col--; break;

            default: break;
        }
        if (in_the_puzzle(ex_row,ex_col)){
            exchange(Puzzle,row,col,ex_row,ex_col);
            assert(Puzzle[ex_row][ex_col] == 0);
            if (move(Puzzle,remainK - 1,ex_row,ex_col)){
                return 1;
            }
            else{
                /* 須backtracking */
                exchange(Puzzle,row,col,ex_row,ex_col);
            }
        }
        else{
            continue;
        }

    }
    return 0;
}

int main(void)
{
    int K;
    while(scanf("%d",&K) != EOF){
        int Puzzle[ARRSIZE][ARRSIZE];
        int row,col;
        for (int r = 0; r < 4; r++){
            for (int c = 0; c < 4; c++){
                scanf("%d",&Puzzle[r][c]);
                if (!Puzzle[r][c]){
                    row = r;
                    col = c;
                }

            }
        }
        printf("%d\n",move(Puzzle,K,row,col));
    }
    
    
    
    




    
    
    return 0;
}
