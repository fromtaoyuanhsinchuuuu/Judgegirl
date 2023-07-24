#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 15

typedef struct {
    int row_arr[MAXN];
    int col_arr[MAXN];
    int diag1_[MAXN * 2 - 1]; // 左下到右上的對角線,index 0是從最左上角開始
    int diag2_[MAXN * 2 - 1]; // 左上到右下的對角線,index 0是從最左下角開始
} Arr_num;

bool in_board(int r,int c,int n)
{
    if (r < n && r >= 0 && c < n && c >= 0){
        return 1;
    }
    return 0;
}

int min(int a,int b)
{
    return (a <= b)? a: b;
}

// bool violate(int board[MAXN][MAXN],int n,int k,int *row_v,int row,int col)
// {
//     /* 檢查row , 若於row就違反了則設定row_v */
//     *row_v = 0;
//     int row_num = 0;
//     for (int c = 0; c < n; c++){
//         row_num += board[row][c];
//     }
//     if (row_num >= k){
//         *row_v = 1;
//         return 1;
//     }
//     /* check col */
//     int col_num = 0;
//     for (int r = 0; r < n; r++){
//         col_num += board[r][col];
//     }

//     if (col_num >= k){
//         return 1;
//     }

//     /* check diag */
    
//     /* 左下到右上，先找最左下的 */
//     int correct = min(n - row - 1,col);

//     int diag_row = row + correct;
//     int diag_col = col - correct;

//     assert (in_board(diag_row,diag_col,n));
//     int i = 0;
//     int diag_num1 = 0;
//     while(in_board(row - i,col + i,n)){
//         diag_num1 += board[row - i][col + i];
//         i++;
//     }

//     if (diag_num1 >= k){
//         return 1;
//     }

//     /* 左上到右下，先找最左上的 */
//     correct = min(row,col);
//     diag_row = row - correct;
//     diag_col = col - correct;

//     assert(in_board(diag_row,diag_col,n));

//     int diag_num2 = 0;
//     i = 0;

//     while (in_board(diag_row + i,diag_col + i,n)){
//         diag_num2 += board[diag_row + i][diag_col + i];
//         i++;
//     }
    
//     if (diag_num2 >= k){
//         return 1;
//     }

//     // printf("row:%d col:%d\n",row,col);

//     return 0;

// }

bool violate_2(Arr_num arr_num,int n,int k,int *row_v,int row,int col)
{
    *row_v = 0;
    if (arr_num.row_arr[row] >= k){
        *row_v = 1;
        return 1;
    }
    if (arr_num.col_arr[col] >= k || arr_num.diag1_[row + col] >= k || arr_num.diag2_[n - 1 - row + col] >= k){
        return 1;
    }
    return 0;

}


/* 用陣列紀錄放的數量可以取代violate func*/
bool sol(int board[MAXN][MAXN],int n,int m,int k,int place_num,int step,Arr_num arr_num)
{
    if (place_num == m){ // 有兩種終端條件 如果寫成if裡面放if，需要走到最後一步才可
        return 1;
    }

    if (step == n * n){
        return 0;
    }
    int nowRow = step / n;
    int nowCol = step % n;
    // printf("place_num:%d nowRow:%d nowCol:%d\n",place_num,nowRow,nowCol);

    int row_v; 

    if (place_num < k || !violate_2(arr_num,n,k,&row_v,nowRow,nowCol)){
        // printf("row:%d col:%d canplace!\n",nowRow,nowCol);
        board[nowRow][nowCol] = 1;
        arr_num.row_arr[nowRow]++;
        arr_num.col_arr[nowCol]++;
        arr_num.diag1_[nowRow + nowCol]++;
        arr_num.diag2_[n - 1 - nowRow + nowCol]++;
        if (sol(board,n,m,k,place_num + 1,step + 1,arr_num)){
            return 1;
        }
        board[nowRow][nowCol] = 0;
        arr_num.row_arr[nowRow]--;
        arr_num.col_arr[nowCol]--;
        arr_num.diag1_[nowRow + nowCol]--;
        arr_num.diag2_[n - 1 - nowRow + nowCol]--;
        
    }

    return sol(board,n,m,k,place_num,step + 1,arr_num);

}

int main(void)
{
    int n,m,k;
    Arr_num arr_num = {{0},{0},{0},{0}};
    while (scanf("%d%d%d",&n,&m,&k) != EOF){
        int board[MAXN][MAXN] = {};
        if (m <= n * n && sol(board,n,m,k,0,0,arr_num) ){
            for (int r = 0; r < n; r++){
                for (int c = 0; c < n; c++){
                    if (board[r][c]){
                        printf("o");
                    }
                    else{
                        printf(".");
                    }
                }
                printf("\n");
            }
            continue;

        }
        printf("N\n");
    }

    
    return 0;
}
