#include <stdio.h>
#define N 0
#define E 1
#define S 2
#define W 3

int abs(int a)
{
    return (a >= 0)? a : -a;
}

int direction(int x,int y,int a,int b)
{
    // printf("direction:%d\n",abs(a*x + b*y) % 4);
    return (abs(a*x + b*y) % 4);
}

int gold(int x,int y,int c,int d,int e)
{
    return abs(c*x+d*y) % e;
    
}

int main(void)
{
    int a,b,c,d,e,p,q,r,s,x,y,F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&p,&q,&r,&s,&x,&y,&F);
    int gold_amount = gold(x,y,c,d,e);
    while (F > 0)
    {
        F--;
        switch (direction(x,y,a,b))
        {
            case N:
                y++;
                break;
            case E:
                x++;
                break;
            case S:
                y--;
                break;
            case W:
                x--;
                break;
            default:
                break;
        }
        // printf("x:%d y:%d\n",x,y);
        if ((x == p && y == q) || (x == r && y == s)){
           if (x == p && y == q){
                x = r;
                y = s;
           }
           else{
                x = p;
                y = q;
           }
        }
        else{
            gold_amount += gold(x,y,c,d,e);
        }
    }
    printf("%d\n%d %d",gold_amount,x,y);
    return 0;
}
