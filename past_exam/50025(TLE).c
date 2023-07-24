#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100

bool contradict(int relation_arr[MAXN][MAXN],int choosen_arr[MAXN],int relation_arr_index,int chossen_num)
{
    for (int i = 0; i < chossen_num; i++){
        if (relation_arr[choosen_arr[i]][relation_arr_index] == 1){
            return 1;
        }
    }
    return 0;

}

bool sol(int n,int m,int choosen_arr[MAXN],int relation_arr[MAXN][MAXN],int choose_num,int relation_arr_index)
{
    if (choose_num == m){
        for (int i = 0; i < m; i++){
            printf("%d%c",choosen_arr[i]," \n"[i == m - 1]);
        }
        return 1;
    }

    if (relation_arr_index == n || choose_num + n < m || n == 0){
        return 0;
    }

    for (; relation_arr_index < n; relation_arr_index++){
        if (!contradict(relation_arr,choosen_arr,relation_arr_index,choose_num)){
            choosen_arr[choose_num] = relation_arr_index;
            if (sol(n,m,choosen_arr,relation_arr,choose_num + 1,relation_arr_index+1)){
                return 1;
            }
            choosen_arr[choose_num] = -1;
            if (sol(n,m,choosen_arr,relation_arr,choose_num,relation_arr_index+1)){
                return 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int n,m;
    int choosen_arr[MAXN]; // 須全部初始為-1
    int relation_arr[MAXN][MAXN];
    while (scanf("%d%d",&n,&m) != EOF){
        for (int i = 0; i < n; i++){
            choosen_arr[i] = -1;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d",&relation_arr[i][j]);
            }
        }
        if (!sol(n,m,choosen_arr,relation_arr,0,0)){
            printf("no solution\n");
        }
    }

    return 0;
}
