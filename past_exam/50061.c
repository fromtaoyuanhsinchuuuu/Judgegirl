#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 64
#define MAXDONATE 2147483647

void sol(int donation_arr[MAXN],int hate_Matrix[MAXN][MAXN],int n,int select_arr[MAXN],int select_num,int now_index,int total,int *max_total)
{
    if (now_index == n){
        if (total > *max_total){
            *max_total = total;
        }
        return;
    }

    bool violate = 0;
    for (int i = 0; i < select_num && !violate; i++){
        if (hate_Matrix[select_arr[i]][now_index]){
            violate = 1;
            break;
        }
    }

    if (!violate){
        /* select */
        select_arr[select_num] = now_index;
        sol(donation_arr,hate_Matrix,n,select_arr,select_num + 1,now_index + 1,total + donation_arr[now_index],max_total);
        select_arr[select_num] = 0;
    }

    sol(donation_arr,hate_Matrix,n,select_arr,select_num,now_index + 1,total,max_total);
    return;

}

int main(void)
{
    int n;
    scanf("%d",&n);

    int donation_arr[MAXN];
    for (int i = 0; i < n; i++){
        scanf("%d",&donation_arr[i]);
    }

    int hate_Matrix[MAXN][MAXN];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&hate_Matrix[i][j]);
        }
    }

    int select_arr[MAXN] = {};
    int max_total = 0;

    sol(donation_arr,hate_Matrix,n,select_arr,0,0,0,&max_total);
    printf("%d",max_total);
    
    return 0;
}
