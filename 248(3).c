#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define FIELD 9

bool in_field(int r,int c)
{
    if (r < FIELD && r >= 0 && c < FIELD && c >= 0){
        return 1;
    }
    return 0;
}

bool can_place(int nowR,int nowC,int mine_field[FIELD][FIELD],bool ans_field[FIELD][FIELD]) /* 如果擺了會大於就不行 */
{
    int dr[3] = {-1,0,1};
    int dc[3] = {-1,0,1};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (in_field(nowR+dr[i],nowC+dc[j]) && mine_field[nowR+dr[i]][nowC+dc[j]] == 0){
                // printf("nowr:%d nowc%d count:%d\n",nowR+dr[i],nowC+dc[j],mine_count(nowR+dr[i],nowC+dc[j],ans_field));
                return 0;
            }
        }
    }
    return 1;
}

void subtract_mine(int mine_field[FIELD][FIELD],int r,int c)
{
    int dr[3] = {-1,0,1};
    int dc[3] = {-1,0,1};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (in_field(r+dr[i],c+dc[j])){
                mine_field[r+dr[i]][c+dc[j]]--;
            }
        }
    }
}

void add_mine(int mine_field[FIELD][FIELD],int r,int c)
{
    int dr[3] = {-1,0,1};
    int dc[3] = {-1,0,1};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (in_field(r+dr[i],c+dc[j])){
                mine_field[r+dr[i]][c+dc[j]]++;
            }
        }
    }
}

bool mine_file_all_zero(int mine_file[FIELD][FIELD])
{
    for (int i = 0; i < FIELD; i++){
        for (int j = 0; j < FIELD; j++){
            if (mine_file[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

bool place_mine(int mine_field[FIELD][FIELD],bool ans_field[FIELD][FIELD],int step) /* guess:由右下開始填，能填盡量填 */
{
    if (step == -1){
        if (mine_file_all_zero(mine_field)){
            return 1;
        }
        return 0;
    }
    int nowR = step / FIELD;
    int nowC = step % FIELD;
    if (in_field(nowR + 2,nowC + 2) && mine_field[nowR+2][nowC+2] > 0 || mine_field[nowR][nowC] < 0){
        return 0;
    }
    if (can_place(nowR,nowC,mine_field,ans_field)){
        ans_field[nowR][nowC] = 1;
        subtract_mine(mine_field,nowR,nowC);
        if (place_mine(mine_field,ans_field,step -1)){
            return 1;
        }
        ans_field[nowR][nowC] = 0;
        add_mine(mine_field,nowR,nowC);
        return place_mine(mine_field,ans_field,step -1);
        
    }
    else{
        ans_field[nowR][nowC] = 0;
        return place_mine(mine_field,ans_field,step -1);
    }
    return 0;
}

int main(void)
{
    int mine_fild[FIELD][FIELD];
    bool ans_field[FIELD][FIELD] = {{}};
    for (int i = 0; i < FIELD; i++){
        for (int j = 0; j < FIELD; j++){
            scanf("%d",&mine_fild[i][j]);
        }
    }
    if (place_mine(mine_fild,ans_field,80)){
        // printf("ansfiled:\n");
        for (int i = 0; i < FIELD; i++){
            for (int j = 0; j < FIELD; j++){
                printf("%d%c",ans_field[i][j]," \n"[j == FIELD - 1]);
            }
        }
    }
    else{
        printf("no solution\n");
    }

    
    return 0;
}
