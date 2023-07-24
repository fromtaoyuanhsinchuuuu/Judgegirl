#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SQ(a) (a)*(a)
#define MAXDIS 2000

#define MAXNUM 12000000
#define MAXN 8

typedef struct {
    double x;
    double y;
    double z;
} Point;

double distance(Point now_Point,Point point)
{
    return sqrt(SQ(now_Point.x - point.x) + SQ(now_Point.y - point.y) + SQ(now_Point.z - point.z));
}

int min_dis_index(Point now_Point,Point points[MAXN],int N)
{
    double min_dis = (double)MAXDIS;
    int index = -1;
    for (int i = 0; i < N; i++){
        double now_dis = distance(points[i],now_Point);
        if (now_dis < min_dis){
            min_dis = now_dis;
            index = i;
        }
    }    


    assert(index != -1);
    return index;
}

int main(void)
{

    srand(time(NULL));
    int R,N;
    Point points[MAXN];
    int Case = 1;
    while (scanf("%d%d",&R,&N) != EOF){
        int count[MAXN] = {};
        for (int i = 0; i < N; i++){
            scanf("%lf%lf%lf",&points[i].x,&points[i].y,&points[i].z);
        }

        int in_side_ball = 0;
        for (int i = 0; i < MAXNUM; i++){
            double x = (rand() / (double)RAND_MAX) * (double)R * 2;
            double y = (rand() / (double)RAND_MAX) * (double)R * 2;
            double z = (rand() / (double)RAND_MAX) * (double)R * 2;

            x -= R;
            y -= R;
            z -= R;

            Point now_point;
            now_point.x = x;
            now_point.y = y;
            now_point.z = z;

            Point origin;
            origin.x = 0;
            origin.y = 0;
            origin.z = 0;
            if (distance(origin,now_point) > R){
                continue;
            }

            in_side_ball++;
            count[min_dis_index(now_point,points,N)]++;
        }

        printf("Case #%d:\n",Case);

        for (int i = 0; i < N; i++){
            printf("%1.f\n",round((count[i] / (double)in_side_ball) * 100));
        }
        Case++;
    }
    
    return 0;
}
