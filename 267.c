#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100000
#define SQ(x) ((x) * (x))

typedef struct {
    int x;
    int y;
} Point;

int distance(Point *ptr)
{
    return ((ptr->x) * (ptr->x) + (ptr->y) * (ptr->y));

}

int cmp(const void *a,const void *b)
{
    Point *ptr1 = (Point *)a;
    Point *ptr2 = (Point *)b;

    if (distance(ptr1) > distance(ptr2)){
        return 1;
    }
    else if (distance(ptr1) < distance(ptr2)){
        return -1;
    }
    else if (ptr1->x > ptr2->x){
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

int distance_between(Point point1,Point point2)
{
    return SQ(point1.x - point2.x) + SQ(point1.y - point2.y);
}



int main(void)
{
    Point points[MAXN];
    int n = 0;

    while (scanf("%d%d",&points[n].x,&points[n].y) != EOF){
        n++;
    }
    qsort(points,n,sizeof(Point),cmp);
    int dis = distance(&points[0]);
    for (int i = 0; i < n - 1; i++){
        dis += distance_between(points[i],points[i + 1]);
    }
    printf("%d",dis);





    

    
    
    return 0;
}
