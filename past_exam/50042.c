#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int R,C;
    scanf("%d%d",&R,&C);
    int global_max = -1,global_max_row,global_max_col;
    for (int r = 1; r <= R; r++){
        int now_num;
        int local_max = -1,second_max = -2,local_max_col,second_max_col;
        for (int c = 1; c <= C; c++){
            scanf("%d",&now_num);
            if (now_num >= global_max){
                global_max = now_num;
                global_max_col = c;
                global_max_row = r;
            }
            if (now_num >= local_max){
                second_max = local_max;
                local_max = now_num;
                second_max_col = local_max_col;
                local_max_col = c;
            }
            else if (now_num < local_max && now_num >= second_max){
                second_max = now_num;
                second_max_col = c;
            }
        }
        printf("%d %d\n",local_max_col,second_max_col);
    }
    printf("%d %d",global_max_row,global_max_col);
    
    
    return 0;
}
