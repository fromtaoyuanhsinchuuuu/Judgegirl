#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define GRIDLENGTH 4
#define NOW_NUM_INDEX 0
#define ZERO_INDEX 1

bool in_the_grid(int r,int c,int Maxrow,int Maxcol)
{
    if (r >= 0 && r < Maxrow && c >= 0 && c < Maxcol){
        return 1;
    }
    return 0;
}

int move(int now_num,int grid[GRIDLENGTH][GRIDLENGTH],int temp_arr[2])
{
    if (now_num <= 15 && now_num >= 1){
        int now_num_row;
        int now_num_col;
        bool if_not_break = 1;
        for (int r = 0; r < GRIDLENGTH && if_not_break; r++){
            for (int c = 0; c < GRIDLENGTH && if_not_break; c++){
                if (grid[r][c] == now_num){
                    now_num_row = r;
                    now_num_col = c;
                    if_not_break = 0;
                    temp_arr[NOW_NUM_INDEX] = r * GRIDLENGTH + c;
                }
            }
        }
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,-1,1,0};
        for (int dir_index = 0; dir_index < 4; dir_index++){
            if (in_the_grid(now_num_row+dr[dir_index],now_num_col+dc[dir_index],GRIDLENGTH,GRIDLENGTH) && grid[now_num_row+dr[dir_index]][now_num_col+dc[dir_index]] == 0){
                temp_arr[ZERO_INDEX] = (now_num_row+dr[dir_index]) * GRIDLENGTH + now_num_col+dc[dir_index];
                return dir_index + 1;
            }
        }
        return 0;
    }
    else{
        return 0;
    }

}

bool win_configuration(int grid[GRIDLENGTH][GRIDLENGTH])
{
    int correct_num = 0;
    for (int r = 0; r < GRIDLENGTH; r++){
        for (int c = 0; c < GRIDLENGTH; c++){
            if (grid[r][c] == r * GRIDLENGTH + c + 1){
                correct_num++;
            }
            else if (r == GRIDLENGTH - 1 && c == GRIDLENGTH - 1 && grid[r][c] == 0){
                correct_num++;
            }
        }
    }
    if (correct_num == 16){
        return 1;
    }
    return 0;
}


int main(void)
{
    int grid[GRIDLENGTH][GRIDLENGTH];
    for (int r = 0; r < GRIDLENGTH; r++){
        for (int c = 0; c < GRIDLENGTH; c++){
            scanf("%d",&grid[r][c]);
        }
    }
    int now_num;
    while (1){
        scanf("%d",&now_num);
        int temp_arr[2];
        if (now_num != 0){

            int dir = move(now_num,grid,temp_arr);
            int now_num_row = temp_arr[NOW_NUM_INDEX] / GRIDLENGTH;
            int now_num_col = temp_arr[NOW_NUM_INDEX] % GRIDLENGTH;
            int zero_row = temp_arr[ZERO_INDEX] / GRIDLENGTH;
            int zero_col = temp_arr[ZERO_INDEX] % GRIDLENGTH;
            if (dir){
                grid[zero_row][zero_col] = now_num;
                grid[now_num_row][now_num_col] = 0;

            }
            else{
                // printf("now_num:%d dir:%d\n",now_num,dir);
                continue;
            }
            if (win_configuration(grid)){
                for (int r = 0; r < GRIDLENGTH; r++){
                    for (int c = 0; c < GRIDLENGTH; c++){
                        printf("%d%c",grid[r][c]," \n"[c == GRIDLENGTH - 1]);
                    }
                }
                printf("1 %d",now_num);
                break;
            }
        }
        else{
            for (int r = 0; r < GRIDLENGTH; r++){
                for (int c = 0; c < GRIDLENGTH; c++){
                    printf("%d%c",grid[r][c]," \n"[c == GRIDLENGTH - 1]);
                }
            }
            printf("0");
            break;
        }
    }
    return 0;
}
