#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

enum PIECETYPE {STONE,QUEEN,BISHOP,ROOK};
#define Maxsize 500


bool in_the_board(int R,int C,int row,int col)
{
    if (row >= 0 && row < R && col >= 0 && col < C){
        return 1;
    }
    return 0;
}

void Attack_stright(int chess_board[Maxsize][Maxsize],int row,int col,int R,int C)
{
    /* row_attack */
    int step = 1;
    while (in_the_board(R,C,row+step,col) && !(chess_board[row+step][col])){
        chess_board[row + step][col] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row-step,col) && !(chess_board[row-step][col])){
        chess_board[row - step][col] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row,col+step) && !(chess_board[row][col+step])){
        chess_board[row][col+step] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row,col-step) && !(chess_board[row][col-step])){
        chess_board[row][col-step] = 1;
        step++;
    }
    chess_board[row][col] = 1;
    return;

}

void Attack_diagnal(int chess_board[Maxsize][Maxsize],int row,int col,int R,int C)
{
    int step = 1;
    while (in_the_board(R,C,row+step,col+step) && !(chess_board[row+step][col+step])){
        chess_board[row + step][col+step] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row-step,col-step) && !(chess_board[row-step][col-step])){
        chess_board[row- step][col-step] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row+step,col-step) && !(chess_board[row+step][col-step])){
        chess_board[row+ step][col-step] = 1;
        step++;
    }
    step = 1;
    while (in_the_board(R,C,row-step,col+step) && !(chess_board[row-step][col+step])){
        chess_board[row- step][col+step] = 1;
        step++;
    }
    chess_board[row][col] = 1;
    return;


}

int main()
{
    int chess_board[Maxsize][Maxsize] = {{}};
    int R,C;
    scanf("%d%d",&R,&C);

    int type,row,col;

    while (scanf("%d%d%d",&type,&col,&row) != EOF)
    {
        if (type == STONE){
            chess_board[row][col] = 1;
            continue;
        }
        else if (type == QUEEN){
            Attack_diagnal(chess_board,row,col,R,C);
            Attack_stright(chess_board,row,col,R,C);
        }
        else if (type == BISHOP){
            Attack_diagnal(chess_board,row,col,R,C);
        }
        else if (type == ROOK){
            Attack_stright(chess_board,row,col,R,C);
        }
        else{
            break;
        }
    }
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            printf("%d%c",chess_board[r][c]," \n"[c == C - 1]);
        }
    }    
    return 0;
}
