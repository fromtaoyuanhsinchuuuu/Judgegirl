#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 10
#define MAXM 256
#define MAXNAME 64 
#define NUM 0
#define INDEX 1

bool circle(int bingo[MAXN][MAXM][MAXM][2],int nown,int m,int nownum,int row_circle[MAXN][MAXM],
            int col_circle[MAXN][MAXM],
            int left_to_right_diagnol_circle[MAXN],
            int right_to_left_diagnol_circle[MAXN],bool win[MAXN],int num_index[MAXN][MAXM*MAXM])
{
            int i = num_index[nown][nownum] / m;
            int j = num_index[nown][nownum] % m;
                if (i == j){
                    left_to_right_diagnol_circle[nown]++;
                    if (left_to_right_diagnol_circle[nown] == m){
                        win[nown] = 1;
                        return 1;
                    }
                }
                if (i + j == m - 1){
                    right_to_left_diagnol_circle[nown]++;
                    if (right_to_left_diagnol_circle[nown] == m){
                        win[nown] = 1;
                        return 1;
                    }
                }
                col_circle[nown][j]++;
                if (col_circle[nown][j] == m){
                    win[nown] = 1;
                    return 1;
                }
                row_circle[nown][i]++;
                if (row_circle[nown][i] == m){
                    win[nown] = 1;
                    return 1;
                }
                // if_bingo(bingo,nown,m,win,row_circle,col_circle,left_to_right_diagnol_circle,right_to_left_diagnol_circle,i,j);
                return 1;
}

int number_of_winners(bool win[MAXN],int n)
{
    int num = 0;
    for (int i = 0; i < n ; i++){
        if (win[i]){
            num++;
        }
    }
    return num;
}

int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    static int bingo[MAXN][MAXM][MAXM][2] = {};
    static int num_index[MAXN][MAXM*MAXM] = {};
    char name[MAXN][MAXNAME];
    for (int i = 0; i < n; i++){
        scanf("%s",name[i]);
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                scanf("%d",&(bingo[i][j][k][NUM]));
                num_index[i][bingo[i][j][k][NUM]] = j * m + k;
            }
        }
    }
    int nownum;
    bool win[MAXN] = {};
    int row_circle[MAXN][MAXM] = {};
    int col_circle[MAXN][MAXM] = {};
    int left_to_right_diagnol_circle[MAXN] = {};
    int right_to_left_diagnol_circle[MAXN] = {};
    int total_circle = 0;
    while (scanf("%d",&nownum) != EOF){
        total_circle++;
        for (int nown = 0; nown < n; nown++){
            circle(bingo,nown,m,nownum,row_circle,col_circle,left_to_right_diagnol_circle,right_to_left_diagnol_circle,win,num_index);
        }
        if (total_circle >= m){
            if (number_of_winners(win,n) > 0){
                printf("%d ",nownum);
                int count = 1;
                for (int nown = 0; nown < n; nown++){
                        if (win[nown]){
                            printf("%s%c",name[nown]," \n"[count == number_of_winners(win,n)]);
                            count++;
                            // printf("count:%d",count);
                        }
                }
                break;
            }
        }
    }

    return 0;
}
