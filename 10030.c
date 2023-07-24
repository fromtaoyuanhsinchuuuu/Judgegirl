#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXM 512

typedef struct {
    int arr[MAXM];
} ARR_com;

inline bool sim(int A[],int B[],int m)
{
    int and = 0;
    int or = 0;
    for (int i = 0; i < m; i++){
        if (A[i] && B[i]){
            and++;
        }
        if (A[i] || B[i]){
            or++;
        }
    }

    // printf("and:%d or:%d\n",and,or);

    return ((and / (double) or) >= 0.8);

}

int main(void)
{
    int N,M;
    while (scanf("%d%d",&N,&M) != EOF){
        static ARR_com arr_com[MAXN];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                int num;
                scanf(" %c",&num);
                arr_com[i].arr[j] = num - '0';
            }

        }

        // for (int i = 0; i < M; i++){
        //     printf("%d",arr_com[0].arr[i]);

        // }

        int num = 0;
        for (int i = 0; i < N - 1; i++){
            for (int j = i + 1; j < N; j++){
                if (sim(arr_com[i].arr,arr_com[j].arr,M)){
                    num++;
                }
            }
        }

        printf("%2.2f\n",num / (((double) N * (N - 1)) / 2) * 100 );
    }
    
    return 0;
}
