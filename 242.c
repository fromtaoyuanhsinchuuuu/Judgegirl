#include <stdio.h>
#include <stdbool.h>

int abs(int a)
{
    return (a >= 0)? a : -a;
}

int min(int x1,int x2,int x3)
{
    int min = (x1 <= x2)? x1 : x2;
    min = (min <= x3)? min : x3;
    return min;
}

int max(int x1,int x2,int x3)
{
    int max = (x1 >= x2)? x1 : x2;
    max = (max >= x3)? max : x3;
    return max;
}

long long distance_square(long x,long y,long x1,long y1)
{
    return ((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

int in_one_circle(int x1,int y1,int r1,int x2,int y2,int r2,int x3,int y3,int r3)
{
    /* x1,y1為想要在的圓裡面 */
    int number = 0;
    for(int x = x1-r1 ; x <= x1+r1 ; x++){
        for (int y = y1-r1 ; y <= y1+r1 ; y++){
            if (abs(distance_square(x,y,x1,y1)) <= r1*r1 && abs(distance_square(x,y,x2,y2)) > r2*r2 && abs(distance_square(x,y,x3,y3)) > r3*r3){
                number++;
            }
        }
    }
    return number;
}

int in_three_circles(int x1,int y1,int r1,int x2,int y2,int r2,int x3,int y3,int r3)
{
    int number = 0;
    for (int x = min(x1-r1,x2-r2,x3-r3) ; x <= max(x1+r1,x2+r2,x3+r3) ; x++){
        for (int y = min(y1-r1,y2-r2,y3-r3) ; y <= max(y1+r1,y2+r2,y3+r3) ; y++){
            if (abs(distance_square(x,y,x1,y1)) <= r1*r1 && abs(distance_square(x,y,x2,y2)) <= r2*r2 && abs(distance_square(x,y,x3,y3) <= r3*r3)){
                number++;
            }
        }
    }
    return number;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++){
        long long x1,y1,r1,x2,y2,r2,x3,y3,r3;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3,&r3);
        int ans = in_one_circle(x1,y1,r1,x2,y2,r2,x3,y3,r3)+
                  in_one_circle(x2,y2,r2,x1,y1,r1,x3,y3,r3)+
                  in_one_circle(x3,y3,r3,x1,y1,r1,x2,y2,r2);
        if (!(abs(x1-x2) > r1+r2 || abs(y1-y2) > r1+r2 || abs(x1-x3) > r1+r3 || abs(x2-x3) > r2+r3 || abs(y2-y3) >= r2+r3 || abs(y1-y3) >= r1+r3)){
            ans += in_three_circles(x1,y1,r1,x2,y2,r2,x3,y3,r3);
        }
        printf("%d\n",ans);
    }
    return 0;
}
