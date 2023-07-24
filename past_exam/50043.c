#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int max(int a,int b,int c)
{
    a = (a <= b)? b : a;
    a = (a <= c)? c : a;
    return a;
}

int min(int a,int b,int c)
{
    a = (a >= b)? b : a;
    a = (a >= c)? c : a;
    return a;
}

int cross_product(int now_x,int now_y,int x1,int y1,int x2,int y2)
{
    /* 正就return 1,負則return -1 ,0則return 0 */
    // P(now_x,now_y) A(x1,y1) B(x2,y2)
    int PA_X = x1 - now_x;
    int PA_Y = y1 - now_y;
    int PB_X = x2 - now_x;
    int PB_Y = y2 - now_y;
    long long outer_product = PA_X * PB_Y - PA_Y * PB_X;
    if (outer_product > 0){
        return 1;
    }
    else if (outer_product < 0){
        return -1;
    }
    else{
        return 0;
    }

}

bool point_in_the_traingle(int now_x,int now_y,int x1,int y1,int x2,int y2,int x3,int y3)
{
    if (cross_product(now_x,now_y,x1,y1,x2,y2) * cross_product(now_x,now_y,x2,y2,x3,y3) * cross_product(now_x,now_y,x3,y3,x1,y1) == 0){
        return 1;
    }
    if (cross_product(now_x,now_y,x1,y1,x2,y2) * cross_product(now_x,now_y,x2,y2,x3,y3) > 0 &&
        cross_product(now_x,now_y,x2,y2,x3,y3) * cross_product(now_x,now_y,x3,y3,x1,y1) > 0 ){
        return 1;
    }
    else{
        return 0;
    }

}

bool square_in_the_traingle(int now_x1,int now_y1,int now_x2,int now_y2,
                            int now_x3,int now_y3,int now_x4,int now_y4,
                            int x1,int y1,int x2,int y2,int x3,int y3)
{
    if (point_in_the_traingle(now_x1,now_y1,x1,y1,x2,y2,x3,y3) && 
        point_in_the_traingle(now_x2,now_y2,x1,y1,x2,y2,x3,y3) &&
        point_in_the_traingle(now_x3,now_y3,x1,y1,x2,y2,x3,y3) &&
        point_in_the_traingle(now_x4,now_y4,x1,y1,x2,y2,x3,y3)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    int square = 0;
    for (int now_x1 = min(x1,x2,x3); now_x1 <= max(x1,x2,x3); now_x1++){
        for (int now_y1 = min(y1,y2,y3); now_y1 <= max(y1,y2,y3); now_y1++){
            int now_x2 = now_x1 + 1;
            int now_y2 = now_y1;
            int now_x3 = now_x1;
            int now_y3 = now_y1 + 1;
            int now_x4 = now_x1 + 1;
            int now_y4 = now_y1 + 1;
            if (square_in_the_traingle(now_x1,now_y1,now_x2,now_y2,now_x3,now_y3,now_x4,now_y4,x1,y1,x2,y2,x3,y3)){
                square++;
            }
        }
    }
    printf("%d",square);

    
    
    return 0;
}
