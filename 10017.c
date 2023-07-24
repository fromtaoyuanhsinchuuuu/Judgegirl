#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 25000
#define MAXDIS 32767

typedef struct {
    int x;
    int y;
} Point;

int abs(int a)
{
    return (a >= 0)? a: -a;
}

int distance (Point a,Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main(void)
{
    int Turn;
    scanf("%d",&Turn);

    Point point_A[MAXN],point_B[MAXN];
    scanf("%d%d",&point_A[0].x,&point_A[0].y);

    Point Now_point;
    int A_num = 1,B_num = 0;
    for (int i = 1; i < 2 * Turn; i++){
        scanf("%d%d",&Now_point.x,&Now_point.y);

        if (i % 2 == 0){ /* A_turn */
            point_A[A_num] = Now_point;
            A_num++;
            bool cont = 1;
            int dis = 1;
            for (; (dis <= MAXDIS * 2) && cont; dis++){
                for (int j = 0; j < B_num; j++){
                    if (distance(Now_point,point_B[j]) == dis){
                        cont = 0;
                        printf("%d\n",dis);
                        break;
                    }
                }
            }
        }

        if (i % 2 != 0){ /* B_turn */
            point_B[B_num] = Now_point;
            B_num++;
            bool cont = 1;
            int dis = 1;
            for (; (dis <= MAXDIS * 2) && cont; dis++){
                for (int j = 0; j < A_num; j++){
                    if (distance(Now_point,point_A[j]) == dis){
                       printf("%d\n",dis);
                        cont = 0;
                        break;
                    }
                }
            }
        }


    }
   
    
    return 0;
}
