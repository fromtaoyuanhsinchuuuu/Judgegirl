#include <stdio.h>
#define Max_n 512
#define Max_k 128

int main(void)
{
    int n,k;  /* 要執行n-k+1次 */
    scanf("%d%d",&n,&k);
    int n_matrix[Max_n][Max_n];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            scanf("%d",&n_matrix[i][j]);
        }
    }
    int k_matrix[Max_k][Max_k];
    for (int i = 0 ; i < k ; i++){
        for (int j = 0 ; j < k ; j++){
            scanf("%d",&k_matrix[i][j]);
        }
    }
    int ans_matrix[Max_n][Max_n] = {{0}};
    int ans_index = 0;
    for (int row_start = 0 ; row_start < n-k+1 ; row_start++){
        for (int col_start = 0 ; col_start < n-k+1 ; col_start++){
            int ans_row = ans_index / (n-k+1);
            int anw_col = ans_index % (n-k+1);
            // printf("ans_index:%d",ans_index);
            for (int k_row = 0 ; k_row < k ; k_row++){
                for (int k_col = 0 ; k_col < k ; k_col++){
                    ans_matrix[ans_row][anw_col] += n_matrix[row_start+k_row][col_start+k_col] * k_matrix[k_row][k_col];
                }
            }
            ans_index++;
        }
    }
    for (int i = 0 ; i < n-k+1 ; i++){
        for (int j = 0 ; j < n-k+1 ; j++){
            printf("%d ",ans_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
