#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXARR 80001
#define MAXSIZE 400

void bubble_sort(int lake[],int lake_index)
{
    for (int i = lake_index; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            if (lake[j] < lake[j+1]){
                int temp = lake[j];
                lake[j] = lake[j+1];
                lake[j+1] = temp;
            }
        }
    }
}

int lakeCount(int Map[MAXSIZE][MAXSIZE],int R,int C)
{
    int lakenum = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (Map[i][j] == 1){
                lakenum++;
            }
        }
    }
    return lakenum;
}

bool in_the_map(int R,int C,int nowR,int nowC)
{
    if (nowR >= 0 && nowR <= R - 1 && nowC >= 0 && nowC <= C - 1){
        return 1;
    }
    return 0;
}

int total(int lake_arr[],int lakeindex)
{
    int num = 0;
    for (int i = 0; i < lakeindex; i++){
        num += lake_arr[i];
    }
    return num;
}

void goLake(int Map[MAXSIZE][MAXSIZE],int R,int C,int nowR,int nowC,int lake_arr[MAXARR],int now_index)
{
    // printf("nowrow:%d nowcol:%d\n",nowR,nowC);
    Map[nowR][nowC] = 0;
    lake_arr[now_index]++;

    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    for (int i = 0; i < 4; i++){
        if (in_the_map(R,C,nowR+dr[i],nowC+dc[i]) && Map[nowR+dr[i]][nowC+dc[i]]){
            goLake(Map,R,C,nowR+dr[i],nowC+dc[i],lake_arr,now_index);
        }
    }
    return;
}

int main(void)
{
    int R,C;
    scanf("%d%d",&R,&C);

    int Map[MAXSIZE][MAXSIZE];
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf("%d",&Map[i][j]);
        }
    }

    int lake_arr[MAXARR]; // 等等要bubblesort
    int lakeindex = 0;
    int lakenum = lakeCount(Map,R,C);
    // printf("lakenum:%d\n",lakenum);

    while (lakenum != 0){
        bool breakpoint = 0;
        for (int i = 0; i < R && !breakpoint; i++){
            for (int j = 0; j < C; j++){
                if (Map[i][j]){
                    goLake(Map,R,C,i,j,lake_arr,lakeindex);
                    lakenum -= lake_arr[lakeindex];
                    breakpoint = 1;
                    break;
                }
            }
        }
        // printf("lakeindex:%d lakenum:%d\n",lakeindex,lakenum);
        lakeindex++;
    }
    // printf("lakenum:%d\n",lakenum);
    // printf("total:%d\n",total(lake_arr,lakeindex));
    bubble_sort(lake_arr,lakeindex+1);
    // printf("total:%d\n",total(lake_arr,lakeindex));
    int index = 0;
    while (lake_arr[index])
    {
        printf("%d\n",lake_arr[index]);
        index++;
    }

    return 0;
}
