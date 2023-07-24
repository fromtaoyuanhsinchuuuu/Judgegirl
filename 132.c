#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXN 20
#define MAXC 8

bool can_color(int now_index,int adjacent_arr[MAXN][MAXN],int color_arr[MAXN],int now_color,int N)
{
    for (int i = 0; i < N; i++){
        if (adjacent_arr[now_index][i] && now_color == color_arr[i]){
            return 0;
        }
    }
    return 1;
}

bool color(int now_index,int N,int C,int adjacent_arr[MAXN][MAXN],int color_arr[MAXN])
{
    if (now_index == N){
        return 1;
    }
    for (int now_color = 1; now_color <= C; now_color++){
        if (can_color(now_index,adjacent_arr,color_arr,now_color,N)){
            color_arr[now_index] = now_color;
            if (color(now_index+1,N,C,adjacent_arr,color_arr)){
                return 1;
            }
        }
    }
    color_arr[now_index] = 0;
    return 0;
}

int main(void)
{
    int N,C,P;
    scanf("%d%d%d",&N,&C,&P);

    int adjacent_arr[MAXN][MAXN] = {{}};
    int color_arr[MAXN] = {};
    int a,b;
    for (int i = 0; i < P; i++){
        scanf("%d%d",&a,&b);
        adjacent_arr[a][b] = 1;
        adjacent_arr[b][a] = 1;
    }
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         printf("%d%c",adjacent_arr[i][j]," \n"[j == N - 1]);
    //     }
    // }
    if (color(0,N,C,adjacent_arr,color_arr)){
        for (int i = 0; i < N; i++){
            printf("%d\n",color_arr[i]);
        }
    }
    else{
        printf("no solution.\n");
    }





    
    
    return 0;
}
