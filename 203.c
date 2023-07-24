#include <stdio.h>

void collide_change_direction(int x1,int y1,int x2,int y2,int dir_1[2],int dir_2[2])
{
    if (x1 == x2 && y1 == y2){
        int temp = dir_1[0];
        dir_1[0] = dir_2[0];
        dir_2[0] = temp;
        temp = dir_1[1];
        dir_1[1] = dir_2[1];
        dir_2[1] = temp;
    }
    
}

void bounce_wall_chanege_direction(int x1,int y1,int X,int Y,int dir[2])
{
    if ((x1 == 1 || x1 == X) && !(y1 == Y || y1 == 1)){
        dir[0] = -dir[0];
    }
    else if (!(x1 == X || x1 == 1) && (y1 == Y || y1 == 1)){
        dir[1] = -dir[1];
    }
    else if ((x1 == X || x1 == 1) && (y1 == Y || y1 == 1)){
        dir[0] = -dir[0];
        dir[1] = -dir[1];
    }

}

int main(void)
{
    int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,t;
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&t);
    /* 左邊界是1,右邊界是X */
    int time = 0;
    int dir_1[2] = {dx1,dy1};
    int dir_2[2] = {dx2,dy2};
    while (time < t){
        time++;
        bounce_wall_chanege_direction(x1,y1,X,Y,dir_1);
        bounce_wall_chanege_direction(x2,y2,X,Y,dir_2);
        collide_change_direction(x1,y1,x2,y2,dir_1,dir_2);
        x1 += dir_1[0];
        y1 += dir_1[1];
        x2 += dir_2[0];
        y2 += dir_2[1];
    }
    printf("%d\n%d\n%d\n%d",x1,y1,x2,y2);
    
    return 0;
}
