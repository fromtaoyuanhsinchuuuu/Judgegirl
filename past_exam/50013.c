#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef unsigned long long ull;

void printlonglong(int board[8][8])
{
    ull total = 0;
    for (int i = 0; i < 64; i++){
        if (board[7 - (i / 8)][7 - (i % 8)]){
            total += (1 << i);
        }
    }
    printf("total:%llu\n",total);
}

void printBlock(const unsigned long long int *block) {
    ull Block = *block;
    int board[8][8];
    for (int i = 0; i < 64; i++){
        if (Block & 1 == 1){
            board[7 - (i / 8)][7 - (i % 8)] = 1;
        }
        else{
            board[7 - (i / 8)][7 - (i % 8)] = 0;

        }
        Block >>= 1;
    }
    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            printf("%d%c",board[r][c]," \n"[c == 7]);
        }
    }

}

int bingo(const unsigned long long int *board, int *rowColumn)
{
    /* check row */
    ull row_check = 255;// 在row = 0
    ull and_board;
 
    // printBlock(board);
    for (int i = 7; i >= 0; i--){
        int move = 8 * i;
        row_check = 255;
        row_check <<= move; 

        if (((row_check) & (*board)) >= row_check){
            *rowColumn = 7 - i;
            return 1;
        }
    }

    /* check col */
    ull adder = 1;
    ull check_col = 1;
    for (int i = 1; i < 8; i++){
        check_col += (adder << (i * 8));
    }

    ull col_one = check_col;
    check_col <<= 7;
    // printf("check_col\n");
    // printBlock(&check_col);
    for (int i = 0; i < 8; i++){
        // printBlock(&check_col);
        if ((check_col & *board) >= check_col){
            *rowColumn = i;
            return 2;
        }
        check_col >>= 1;
        // printf("check_col\n");
    }

    /* check diagnaol */
    ull diagnol_one = 0;
    ull prev_diagnol = 1;
    for (int i = 0; i < 8; i++){
        diagnol_one += prev_diagnol;
        prev_diagnol <<= 9;
    }

    // printBlock(&diagnol_one);

    if ((diagnol_one & *board) >= diagnol_one){
        *rowColumn = 0;
        return 3;
    }

    ull diagnol_two = 0;
    prev_diagnol = 128;
    for (int i = 0; i < 8; i++){
        diagnol_two += prev_diagnol;
        prev_diagnol <<= 7;
    }
    // printBlock(&diagnol_two);

    if ((diagnol_two & *board) >= diagnol_two){
        *rowColumn = 1;
        return 3;
    }

    return 0;
}

int main(void)
{
    unsigned long long int board;
    int res = 0, rowColumn = 0;
    scanf("%llu", &board);
    res = bingo(&board, &rowColumn);
    if(res == 0) printf("no\n");
    else printf("%d %d\n", res, rowColumn);
    return 0;
}