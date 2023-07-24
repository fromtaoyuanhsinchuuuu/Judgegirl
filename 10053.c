#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 4
#define A_turn 1
#define B_turn -1

typedef struct {
    int A_win;
    int B_win;
    int fair;
} Result;


void sol(int Board[MAXN][MAXN],int n,int turn,int A_sum,int B_sum,int last_index,Result *result,int check_board[MAXN][MAXN]) // 考慮測資沒有格子為0
{
    bool find = 0;
    // printf("A_sum:%d B_sum:%d\n",A_sum,B_sum);
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("%d%c",check_board[i][j]," \n"[j == n - 1]);
    //     }
    // }
    // printf("\n");

    int back_track_R,bacl_track_C;

    if (turn == A_turn){
        for (int col = 0; col < n; col++){
            if (check_board[last_index][col] == 0){
                find = 1;
                check_board[last_index][col] = 1;
                sol(Board,n,B_turn,A_sum + Board[last_index][col],B_sum,col,result,check_board);
                back_track_R = last_index;
                bacl_track_C = col;
                check_board[back_track_R][bacl_track_C] = 0;
            }
        }
    }

    else if (turn == B_turn){
        for (int row = 0; row < n; row++){
            if (check_board[row][last_index] == 0){
                find = 1;
                check_board[row][last_index] = 1;
                sol(Board,n,A_turn,A_sum,B_sum + Board[row][last_index],row,result,check_board);
                back_track_R = row;
                bacl_track_C = last_index;
                check_board[back_track_R][bacl_track_C] = 0;
            }
        }
    }
   

    if (!find){
        if (A_sum > B_sum){
            result->A_win++;
        }
        else if (A_sum < B_sum){
            result->B_win++;
        }
        else{
            result->fair++;
        }

        return;
    }

    return;



}



int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF){
        int Board[MAXN][MAXN];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d",&Board[i][j]);
            }
        }
        
        int A_sum = 0,B_sum = 0;
        Result result = {0,0,0};
        int check_board[MAXN][MAXN] = {{}};

        sol(Board,n,A_turn,A_sum,B_sum,0,&result,check_board);

        printf("%d %d %d\n",result.A_win,result.B_win,result.fair);




    }

   
    
    return 0;
}
