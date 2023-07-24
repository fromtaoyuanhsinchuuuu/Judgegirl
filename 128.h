#include <stdio.h>
#include <stdbool.h>

bool in_the_map(int x,int y,int n)
{
    if (x < 0 || x >= n || y < 0 || y >= n){
        return 0;
    }
    else{
        return 1;
    }
}

void intersection(int map[100][100], int result[4])
{
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    int intersection = 0;
    int T_junction = 0;
    int turn = 0;
    int dead_end = 0;
    for (int row = 0 ; row < 100 ; row++){
        for (int col = 0 ; col < 100 ; col++){
            int neightbor = 0;
            int turn_or_not[4]={};
            for (int i = 0 ; i < 4 ; i++){
                if (map[row][col] && in_the_map(col+dc[i],row+dr[i],100) && map[row+dr[i]][col+dc[i]]){
                    neightbor++;
                    turn_or_not[i] = map[row+dr[i]][col+dc[i]];
                }
            }
            if (neightbor == 2){
                for (int i = 0 ; i < 4 ; i++){
                }
            }
            switch (neightbor)
            {
                case 4:
                    intersection++;
                    break;
                case 3:
                    T_junction++;
                    break;
                case 2:
                    if ((turn_or_not[0]  && turn_or_not[1]) || (turn_or_not[2] && turn_or_not[3]) || (turn_or_not[0] && turn_or_not[2]) || (turn_or_not[1] && turn_or_not[3])){
                        // printf("row:%d col:%d\n",row,col);
                        turn++;
                    }
                    break;
                case 1:
                    dead_end++;
                    break;
                default:
                    break;
            }
        }
    }
    result[0] = intersection;
    result[1] = T_junction;
    result[2] = turn;
    result[3] = dead_end;
}


