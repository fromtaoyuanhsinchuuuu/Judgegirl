#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 14
#define MAXDIS 1400

void min_dis(int already_travel[MAXN],int n,int distance_arr[MAXN][MAXN],int nowPos,int nowDis,int *minDis)
{
    if (nowDis >= *minDis){
        return;
    }

    bool find = 0;
    for (int i = 0; i < n; i++){ // 記得對already_arr進行backtracking
        if (i != nowPos && !already_travel[i]){
            find = 1;
            already_travel[i] = 1;
            
            min_dis(already_travel,n,distance_arr,i,nowDis + distance_arr[nowPos][i],minDis);
            already_travel[i] = 0;
        }
    }  

    if (!find){
        int dis = nowDis + distance_arr[nowPos][0];
        if (dis < *minDis){
            *minDis = dis;
        }
    }

    return;


}
int main(void)
{
    int n;
    scanf("%d",&n);

    int distance_arr[MAXN][MAXN];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&distance_arr[i][j]);
        }
    }

    int already_arr[MAXN] = {};
    already_arr[0] = 1;

    int minDis = MAXDIS;
    min_dis(already_arr,n,distance_arr,0,0,&minDis);
    
    printf("%d\n",minDis);

   
    
    return 0;
}
