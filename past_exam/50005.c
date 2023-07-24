#include <stdio.h>

int abs(int a)
{
    return (a >= 0)? a : -a;
}


int main()
{
    int n,k,m,d;
    scanf("%d%d%d%d",&n,&k,&m,&d);
    int origin_n[10][10];
    int check_pattern[10][10];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++)
            scanf("%d",&origin_n[i][j]);
    }
    for (int i = 0 ; i < k ; i++){
        for (int j = 0 ; j < k ; j++)
            scanf("%d",&check_pattern[i][j]);
    }
    int times = (n-k+1)*(n-k+1);
    int row_start = 0;
    int col_start = 0;
    int ans_left_upper;
    int row_ans = -1;
    int col_ans = -1;
    for (int time = 0 ; time < times ; time++){
        int origin_not_match_sum = 0;
        int check_pattern_not_match_sum = 0;
        int not_match = 0;
        int not_match_sum = 0;
        for (int row = 0 ; (row < k) && (not_match <= m) && (not_match_sum <= d); row++){
            for (int col = 0 ; (col < k) && (not_match <= m) && (not_match_sum <= d) ; col++){
                if (origin_n[row+row_start][col+col_start] != check_pattern[row][col]){ 
                    not_match++;
                    check_pattern_not_match_sum += check_pattern[row][col];
                    origin_not_match_sum += origin_n[row+row_start][col+col_start];
                }
            }
        }
        not_match_sum += abs(check_pattern_not_match_sum - origin_not_match_sum);
        if ((not_match <= m) && (not_match_sum <= d) && ((row_start > row_ans) || (row_start == row_ans && col_start > col_ans))){
            row_ans = row_start;
            col_ans = col_start;
        }
        row_start = (col_start == n-k)? row_start+1 : row_start;
        col_start = (col_start+k == n)? 0 : col_start+1;
    }
    printf("%d %d",row_ans,col_ans);
    return 0;
}
