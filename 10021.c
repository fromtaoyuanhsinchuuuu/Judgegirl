#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXR 100
#define MAXC 100

int main(void)
{
    int R,C;
    while (scanf("%d%d",&R,&C) != EOF){
        int maze[MAXR][MAXC];
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++){
                scanf("%d",&maze[r][c]);
            }
        }

        /* dp */
        int dp[MAXR][MAXC] = {{}};
        for (int r = 0; r < R; r++){
            if (!maze[r][0]){
                dp[r][0] = 1;
            }
            else{
                dp[r][0] = 0;
                break;
            }
        }
        for (int c = 0; c < C; c++){
            if (!maze[0][c]){
                dp[0][c]= 1;
            }
            else{
                dp[0][c] = 0;
                break;
            }
        }

        for (int r = 1; r < R; r++){
            for (int c = 1; c < C; c++){
                if (maze[r][c]){
                    dp[r][c] = 0;
                    continue;
                }
                dp[r][c] = ((dp[r - 1][c] % 10000) + (dp[r][c - 1] % 10000)) % 10000;
                assert(dp[r][c] >= 0);
            }
        }
        printf("%d\n",dp[R - 1][C - 1]);

    }
    
    return 0;
}
