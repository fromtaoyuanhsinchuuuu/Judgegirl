#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 16
#define MAXM 16

bool RowSum_and_ColSum_All_Zero(int m,int n,int row_sum[MAXM],int col_sum[MAXN])
{
    for (int i = 0; i < m; i++){
        if (row_sum[i] != 0){
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        if (col_sum[i] != 0){
            return 0;
        }
    }
    return 1;
}

int min(int a,int b)
{
    return (a <= b)? a: b;
}

bool same_num(int i,int sol[MAXM][MAXN],int m,int n){
    for (int r = 0; r < m; r++){
        for (int c = 0; c < n; c++){
            if (i == sol[r][c]){
                return 1;
            }
        }
    }
    return 0;
}

bool move_to_sol(int m,int n,int row_sum[MAXM],int col_sum[MAXN],int step,int sol[MAXM][MAXN])
{
    if (step == m * n){
        if (RowSum_and_ColSum_All_Zero(m,n,row_sum,col_sum)){
            return 1;
        }
        return 0;
    }

    int nowRow = step / n;
    int nowCol = step % n;

    int sum = 0;
    if (nowCol == 0 && nowRow > 0){
        if (row_sum[nowRow - 1] != 0){
            return 0;
        }

    }
    for (int i = 1; i <= m * n; i++){
        if (row_sum[nowRow] - i >= 0 && col_sum[nowCol] - i >= 0 && !same_num(i,sol,m,n)){
            sol[nowRow][nowCol] = i;
            row_sum[nowRow] -= i;
            col_sum[nowCol] -= i;
            // printf("nowStep:%d nowi:%d\n",step,i);
            if (move_to_sol(m,n,row_sum,col_sum,step + 1,sol)){
                return 1;
            }
            sol[nowRow][nowCol] = 0;
            row_sum[nowRow] += i;
            col_sum[nowCol] += i;
            continue;
        }
    }
    return 0;

}

int main(void)
{
    int m,n;
    int row_sum[MAXM] = {};
    int col_sum[MAXN] = {};
    while (scanf("%d%d",&m,&n) != EOF){
        int sol[MAXM][MAXN] = {{}};
        for (int i = 0; i < m; i++){
            scanf("%d",&row_sum[i]);
        }
        for (int i = 0; i < n; i++){
            scanf("%d",&col_sum[i]);
        }

        if (move_to_sol(m,n,row_sum,col_sum,0,sol)){
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    printf("%d%c",sol[i][j]," \n"[j == n - 1]);
                }
            }
        }
        else{
            printf("no solution\n");
        }
        

    }
    
    return 0;
}
