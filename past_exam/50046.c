#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXM 16

int calculate(int M,int w[MAXM][MAXM],int picture[MAXM][MAXM])
{
    int total = 0;
    for (int r = 0 ; r < M; r++){
        for (int c = 0; c < M; c++){
            total += w[r][c] * picture[r][c];
        }
    }
    return total;

}

int main(void)
{
    int w[MAXM][MAXM];
    for (int i = 0; i < MAXM; i++){
        for (int j = 0; j < MAXM; j++){
            w[i][j] = 1;
        }
    }

    int N,M;
    scanf("%d%d",&N,&M);


    int picture[MAXM][MAXM];
    int ac;
    int T = 2 * M * M;
    for (int i = 0; i < N; i++){
        scanf("%d",&ac);
        for (int r = 0; r < M; r++){
            for (int c = 0; c < M; c++){
                scanf("%d",&picture[r][c]);
            }
        }
        if (ac == (calculate(M,w,picture) >= T)){
            continue;
        }
        else if (ac){
            for (int r = 0; r < M; r++){
                for (int c = 0; c < M; c++){
                    if (picture[r][c]){
                        w[r][c] *= 2;
                    }
                }
            }
        }
        else{
            for (int r = 0; r < M; r++){
                for (int c = 0; c < M; c++){
                    if (picture[r][c]){
                        w[r][c] = (w[r][c] >= 2)? w[r][c] / 2: 1;
                    }
                }
            }
        }
    }

    int k;
    scanf("%d",&k);

    for (int i = 0; i < k; i++){
        for (int r = 0; r < M; r++){
            for (int c = 0; c < M; c++){
                scanf("%d",&picture[r][c]);
            }
        }
        if (calculate(M,w,picture) >= T){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    
    
    return 0;
}
