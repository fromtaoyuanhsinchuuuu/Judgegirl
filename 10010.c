#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 2000
#define MAXQ 100000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point left_lower_point;
    Point right_upper_point;
} Rectangle;

int cmp(const void *a, const void *b)
{
    Point* ptr1 = (Point*)a;
    Point* ptr2 = (Point*)b;

    if (ptr1->x > ptr1->x){
        return 1;
    }
    else if (ptr1->x < ptr2->x){
        return -1;
    }
    else if (ptr1->y > ptr2->y){
        return 1;
    }
    return -1;
}

int main(void)
{
    int R,C;
    scanf("%d%d",&R,&C);

    int n;
    scanf("%d",&n);

    static int grid[MAXN][MAXN] = {};
    for (int k = 0; k < n; k++){
        int lx,ly,rx,ry;
        scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
        int point_num = 0;
        Point points[MAXQ];

        for (int i = lx; i <= rx; i++){
            for (int j = ly; j <= ry; j++){
                if (!grid[i][j]){
                    points[point_num].x = i;
                    points[point_num].y = j;
                    point_num++;
                    grid[i][j] = 1;
                }
            }
        }
        // qsort(points,point_num,sizeof(Point),cmp);
        if (point_num == 0){
            printf("0\n");
        }
        else{
            printf("%d ",point_num);
        }
        for (int m = 0; m < point_num; m++){
            printf("(%d, %d)%c",points[m].x,points[m].y," \n"[m == point_num - 1]);
        }
    }  
    
    return 0;
}
