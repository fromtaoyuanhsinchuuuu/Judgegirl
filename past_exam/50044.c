#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXR 1000
#define MAXC 1000
#define MAXLEN 1000

#define row 0
#define col 1

#define head 0
#define tail (worm_len - 1)

bool can_move(int worm[MAXLEN][2],int dir,int R,int C,int worm_len)
{
    int new_row = worm[head][row];
    int new_col = worm[head][col];
    switch (dir)
    {
        case 0:
            new_row++;
            break;
        case 1:
            new_row--;
            break;
        case 2:
            new_col++;
            break;
        case 3:
            new_col--;
            break;
        default:
            break;
    }
    int move = 1;
    for (int i = 1; i < worm_len - 1; i++){
        if (new_row == worm[i][row] && new_col == worm[i][col]){
            return 0;
        }
    }
    if (new_row < R && new_row >= 0 && new_col < C && new_col >= 0){
        return 1;
    }
    return 0;
}

int abs(int a)
{
    return (a >= 0)? a : -a;
}

void worm_in_matrix(int worm[MAXLEN][2],int matrix[MAXR][MAXC],int R,int C,int worm_len){
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            for (int i = 0; i < worm_len; i++){
                if (r == worm[i][row] && c == worm[i][col]){
                    matrix[r][c] = 1;
                    break;
                }

            }
        }
    }
    return;
}

int main(void)
{
    int R,C;
    scanf("%d%d",&R,&C);

    static int matrix[MAXR][MAXC] = {{}};

    int worm[MAXLEN][2];
    scanf("%d%d%d%d",&worm[head][row],&worm[head][col],&worm[1][row],&worm[1][col]);

    int worm_len = 0;
    worm_len = (abs(worm[head][row] - worm[1][row]) > 0)? worm_len = abs(worm[head][row] - worm[1][row]) + 1 : abs(worm[head][col] - worm[1][col]) + 1;

    worm[tail][row] = worm[1][row];
    worm[tail][col] = worm[1][col];

    int dr = (worm[tail][row] - worm[head][row]) / (worm_len - 1);
    int dc = (worm[tail][col] - worm[head][col]) / (worm_len - 1);

    for (int i = 1; i < worm_len ; i++){
        worm[i][row] = worm[head][row] + dr * i;
        worm[i][col] = worm[head][col] + dc * i;
    }

    // for (int i = 0; i < worm_len; i++){
    //     printf("%d %d\n",worm[i][row],worm[i][col]);
    // }
   
   
    // printf("worm_len:%d\n",worm_len);

    int m;
    scanf("%d",&m);

    int dir;
    for (int i = 0; i < m; i++){
        scanf("%d",&dir);
        if (can_move(worm,dir,R,C,worm_len)){
            for (int j = worm_len - 1; j >= 1; j--){
                worm[j][row] = worm[j - 1][row];
                worm[j][col] = worm[j - 1][col];
            }
            if (dir == 0){
                worm[head][row]++;
            }
            else if (dir == 1){
                worm[head][row]--;
            }
            else if (dir == 2){
                worm[head][col]++;
            }
            else{
                worm[head][col]--;
            }

        }
        else{
            break;
        }
    }
    worm_in_matrix(worm,matrix,R,C,worm_len);
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            printf("%d",matrix[r][c]);
        }
        printf("\n");
    }

    
    
    return 0;
}
