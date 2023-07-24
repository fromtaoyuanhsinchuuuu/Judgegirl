#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define UP 1
#define DOWN 0

int abs(int a)
{
    return (a >= 0)? a : -a;
}

int pattern_decide(int prev_h,int now_h)
{
    return (now_h - prev_h > 0)? UP : DOWN; 
}

int main(void)
{
    int n;
    scanf("%d",&n);
    int prev_h,now_h;
    scanf("%d%d",&prev_h,&now_h);
    int fuel_consume = (now_h - prev_h > 0)? abs(prev_h - now_h) * 3 : abs(prev_h - now_h) * 2;
    int prev_pattern = pattern_decide(prev_h,now_h);
    prev_h = now_h;
    for (int i = 0; i < n - 2; i++){
        scanf("%d",&now_h);
        if (prev_pattern == UP && pattern_decide(prev_h,now_h) == UP){
            fuel_consume += abs(prev_h - now_h) * 4;
        }
        else if (prev_pattern == DOWN && pattern_decide(prev_h,now_h) == UP){
            fuel_consume += abs(prev_h - now_h) * 3;
        }
        else if (prev_pattern == UP && pattern_decide(prev_h,now_h) == DOWN){
            fuel_consume += abs(prev_h - now_h) * 3;
        }
        else{
            fuel_consume += abs(prev_h - now_h) * 2;
        }
        prev_pattern = pattern_decide(prev_h,now_h);
        prev_h = now_h;
    }
    printf("%d",fuel_consume);
    return 0;
}
