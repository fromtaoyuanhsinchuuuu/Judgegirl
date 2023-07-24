#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 512
#define MAXM 500

typedef struct {
    int dx;
    int dy;
} Direction;

void change_dir(int x,int y,int n,int m,Direction *dir)
{
    if (x > 1 && x < n - 1){
        if (y % 2 == 0){
            dir->dx = 1;
            dir->dy = 0;
        }
        else{
            dir->dx = -1;
            dir->dy = 0;
        }
    }
    else if (x == n - 1){
        if ((y % 2 == 0 || n == 2) && y != m - 1){
            dir->dx = 0;
            dir->dy = 1;
        }
        else{
            dir->dx = -1;
            dir->dy = 0;
        }
    }
    else if (x == 1){
        if (y == m - 1){
            dir->dx = -1;
            dir->dy = 0;
            return;
        }
        if (y % 2 == 0){
            dir->dx = 1;
            dir->dy = 0;
        }
        else{
            dir->dx = 0;
            dir->dy = 1;
        }
    }
    else if (x == 0){
        if (y == 0){
            dir->dx = 1;
            dir->dy = 0;
            return;
        }
        dir->dx = 0;
        dir->dy = -1;
    }


    return;

}


void traversal(int x,int y,int start_x,int statr_y,int n,int m,int step, Direction dir)
{
    printf("%d %d\n",x,y);
    if (step != 0 && x == start_x && y == statr_y){
        assert(step == n * m);
        return;
    }
    change_dir(x,y,n,m,&dir);
    // printf("dx:%d dy:%d\n",dir.dx,dir.dy);
    traversal(x + dir.dx,y + dir.dy,start_x,statr_y,n,m,step + 1,dir);




}


int main(void)
{
    int n,m,x,y;
    Direction dir;
    while (scanf("%d%d%d%d",&n,&m,&x,&y) != EOF){
        traversal(x,y,x,y,n,m,0,dir);
    }


    
    
    return 0;
}
