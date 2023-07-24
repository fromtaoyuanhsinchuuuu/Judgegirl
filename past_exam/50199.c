#include <stdio.h>
#include <stdbool.h>

bool in_the_matrix(int Max_row,int Max_col,int row,int col)
{
    if (row < 0 || row >= Max_row || col < 0 || col >= Max_col){
        return 0;
    }
    else{
        return 1;
    }

}

void CandyCrush(int Matrix[500][500],int row,int col,int Max_row,int Max_col)
{
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    int index = 0;
    int now_number = Matrix[row][col];
    int crush[3][2] = {{row,col},{-1,-1},{-1,-1}};
    int crush_index = 1;
    int prev_row = row; 
    int prev_col = col;
    int cursh_number = 1;
    for (int i = 0 ; i < 4 ; i++){
        if (in_the_matrix(Max_row,Max_col,row+dr[i],col+dc[i]) && Matrix[row+dr[i]][col+dc[i]] == now_number && !(row+dr[i] == prev_row && col+dc[i] == prev_col)){
            crush[crush_index][0] = row + dr[i];
            crush[crush_index][1] = col + dc[i];
            row = row + dr[i];
            col = col + dc[i];
            cursh_number++;
            crush_index++;
        }
    }
    switch (cursh_number)
    {
        case 2:
            for (int i = 0 ; i < 4 ; i++){
                if (in_the_matrix(Max_row,Max_col,row+dr[i],col+dc[i]) && Matrix[row+dr[i]][col+dc[i]] == now_number && !(row+dr[i] == prev_row && col+dc[i] == prev_col)){
                    crush[crush_index][0] = row + dr[i];
                    crush[crush_index][1] = col + dc[i];
                    cursh_number++;
                }
            }
            break;
        default:
            break;
    }
    if (cursh_number == 3){
        for (int i = 0 ; i < 3 ; i++){
            int r = crush[i][0];
            int c = crush[i][1];
            Matrix[r][c] = 0;
        }
    }

}


int main(void)
{
    int Matrix[500][500];
    int R,C;
    scanf("%d%d",&R,&C);
    for (int i = 0 ; i < R ; i++){
        for (int j = 0 ; j < C ; j++){
            scanf("%d",&Matrix[i][j]);
        }
    }
    for (int row = 0 ; row < R ; row++){
        for (int col = 0 ; col < C ; col++){
            if (Matrix[row][col]){
                CandyCrush(Matrix,row,col,R,C);
            }
        }
    }
    for (int i = 0 ; i < R ; i++){
        for (int j = 0 ; j < C ; j++){
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}
