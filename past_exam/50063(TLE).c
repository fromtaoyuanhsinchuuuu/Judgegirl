#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 11
#define MAXM 60

typedef struct {
    int friend1,friend2;
} Friend;

int abs(int a) 
{
    return (a >= 0)? a: -a;
}

int dis(int permute_num,int permute_arr[MAXN],int m,Friend friends[MAXM])
{
    int max = -1;
    for (int i = 0; i < m; i++){
        int pos1 = -1,pos2 = -1;
        for (int j = 0; j < permute_num; j++){
            if (permute_arr[j] == friends[i].friend1){
                pos1 = j;
            }
            if (permute_arr[j] == friends[i].friend2){
                pos2 = j;
            }
        }

        if (pos1 != -1 && pos2 != -1 && abs(pos2 - pos1) > max){
            max = abs(pos2 - pos1);
        }
    }

    return max;
}

void sol(int n,Friend friends[MAXM],int permute_arr[MAXN],int permute_num,int *min_dis,int m,int ans_arr[MAXN])
{

    int now_dis = MAXN;
    if (permute_num >= n / 2 - 1){
        now_dis = dis(permute_num,permute_arr,m,friends);
        if (now_dis != -1 && now_dis >= *min_dis){
            return;
        }
    }
    // printf("now_dis:%d min_dis:%d\n",now_dis,*min_dis);
    if (permute_num == n){
        // now_dis = dis(permute_num,permute_arr,m,friends);
        // if (now_dis < *min_dis){
        for (int i = 0; i < n; i++){
            ans_arr[i] = permute_arr[i]; 
        }
        *min_dis = now_dis;
        // }
        return;
    }

    for (int i = 0; i < n; i++){
        bool find = 0;
        for (int j = 0; j < permute_num; j++){
            assert(permute_arr[j] != -1);
            if (permute_arr[j] == i){
                find = 1;
                break;
            }
        }

        if (find){
            continue;
        }

        permute_arr[permute_num] = i;
        sol(n,friends,permute_arr,permute_num + 1,min_dis,m,ans_arr);
        permute_arr[permute_num] = -1;
    }
    return;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    int m;
    scanf("%d",&m);

    Friend friends[MAXM];
    for (int i = 0; i < m; i++){
        char letter1,letter2;
        scanf(" %c %c",&letter1,&letter2);

        friends[i].friend1 = letter1 - 'A';
        friends[i].friend2 = letter2 - 'A';
    }

    int mindis = MAXN;
    int permute_arr[MAXN],ans_arr[MAXN];

    sol(n,friends,permute_arr,0,&mindis,m,ans_arr);

    printf("%d\n",mindis);
    for (int i = 0; i < n; i++){
        printf("%c%c",ans_arr[i] + 'A'," \n"[i == n - 1]);
    }



    
   
    
    return 0;
}
