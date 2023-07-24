#include <stdio.h>
#include <stdbool.h>

bool in_the_matrix(int R,int C,int r,int c)
{
    if (!(r >= R || r < 0 || c >= C || c < 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    int R,C;
    scanf("%d%d",&R,&C);
    int matrix[101][101];
    for (int i = 0 ; i < R ; i++){
        for (int j = 0 ; j < C ; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    for (int row = 0 ; row < R ; row++){
        for (int col = 0 ; col < C ; col++){
            int now_number = matrix[row][col];
            bool print_or_not = 1;
            for (int index = 0 ; index < 4 ; index++){
                if (in_the_matrix(R,C,row+dr[index],col+dc[index])){
                    if (now_number <= matrix[row+dr[index]][col+dc[index]]){
                        print_or_not = 0;
                        break;
                    }
                }
            }
            if (print_or_not){
                printf("%d\n",now_number);
            }
        }
    }
    return 0;
}
