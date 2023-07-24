#include <stdio.h>

int main()
{
    int N,M,k;
    scanf("%d%d%d",&N,&M,&k);
    int x=1,start_x=1,y=1,start_y=1,count=0;
    while (count != k &&  count <= N*M && count >= 0)
    {
        x = start_x;
        y = start_y;
        // printf("count:%d\n",count);
        while (x+1 <= M && count != k)
        {
            printf("x:%d count:%d\n",x,count);
            count++;
            x++;
        }
        printf("x:%d count:%d\n",x,count);
        start_y++;
        y = start_y;
        count++;
        x = start_x;
        while (y+1 <= N && count != k)
        {
            printf("y:%d count:%d\n",y,count);
            count++;
            y++;
        }
        printf("y:%d count:%d\n",y,count);
        start_x++;
    }
    printf("%d %d",y,x);
    return 0;
}
