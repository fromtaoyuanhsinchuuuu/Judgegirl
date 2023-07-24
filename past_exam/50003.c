#include <stdio.h>
#include <stdbool.h>

int abs(int a)
{
    // a = (a == 0)? 1 : a;
    return (a >= 0 )? a : -a;
}

int max(int a,int b){
    return (a >= b)? a : b;
}

bool in_the_grid(int x,int y,int max_row,int max_col)
{
    if (x < 0 || x >= max_col || y < 0 || y >= max_row){
        return 0;
    }
    else{
        return 1;
    }
}

bool form_the_line(int grid[101][101],int first_x,int first_y,int x,int y)
{
    if (x - first_x == 0 || y - first_y == 0 || abs(first_x - x) / abs(first_y - y) == 1){
        int dx = x - first_x;
        int dy = y - first_y;
        for (int i = 0 ; i <= max(abs(dx),abs(dy)) ; i++){
            int yy = (dy != 0)? first_y + i*(dy/abs(dy)) : first_y;
            int xx = (dx != 0)? first_x + i*(dx/abs(dx)) : first_x;
            grid[yy][xx] = 1;
        }
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    int grid[101][101] = {{}}; // 最後記得倒著print row即可
    int L; // 有幾行
    int max_row,max_col;
    bool contiune_or_not = 1;
    int record_L;
    int record_point;
    scanf("%d%d%d",&L,&max_row,&max_col);
    for (int L_number = 1 ; L_number <= L  ; L_number++){
        int points; // 有幾個點
        scanf("%d",&points);
        int first_point_x;
        int first_point_y;
        for (int point_number = 1 ; point_number <= points && contiune_or_not ; point_number++){
            int x,y;
            scanf("%d%d",&x,&y);
            if (in_the_grid(x,y,max_row,max_col)){
                if (point_number == 1){
                    first_point_x = x;
                    first_point_y = y;
                }
                else{
                    if (form_the_line(grid,first_point_x,first_point_y,x,y)){
                        first_point_x = x;
                        first_point_y = y;
                        continue;
                    }
                    else{
                        contiune_or_not = 0;
                        // printf("dick\n");
                        record_L = L_number;
                        record_point = point_number;
                    }
                }
            }
            else{
                contiune_or_not = 0;
                record_L = L_number;
                record_point = point_number;
                break;
            }

        }
        
    }
    if (contiune_or_not){
        for (int i = max_row-1 ; i >= 0 ; i--){
            for (int j = 0 ; j < max_col ; j++){
                printf("%d",grid[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("ERROR %d %d",record_L,record_point);
    }
    
    

    return 0;
}
