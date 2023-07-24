#include <stdio.h>
#define Maxsize 16

int main()
{
    int n;
    scanf("%d",&n);
    double maxtrix[Maxsize][Maxsize];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            scanf("%lf",&maxtrix[i][j]);
        }
    }
    double y[n];
    for (int i = 0 ; i < n ; i++){
        scanf("%lf",&y[i]);
    }
    double x[n];
    x[n-1] = y[n-1] / maxtrix[n-1][n-1];
    double multiply_x = x[n-1];
    int multiply_col = n-1;
    int ans_x_index = n-2; // 同時代表maxtrix[][]中那一row進行運算
    double col_sum;
    for (int times = 0 ; times < n-1 ; times++){
        for (int row = 0 ; row < n ; row++){
            maxtrix[row][multiply_col] = maxtrix[row][multiply_col]*multiply_x;
        }
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
            }
        } 
        col_sum = 0.000;
        for (int col = n-1 ; col > ans_x_index ; col--){
            col_sum += maxtrix[ans_x_index][col];
        }
        x[ans_x_index] = (y[ans_x_index] - col_sum)/maxtrix[ans_x_index][ans_x_index];
        multiply_x = x[ans_x_index];
        ans_x_index--;
        multiply_col--;
    }
    for (int i = 0 ; i < n ; i++){
        printf("%f\n",x[i]);

    }
    return 0;
}
