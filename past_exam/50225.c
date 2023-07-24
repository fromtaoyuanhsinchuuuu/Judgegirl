#include <stdio.h>

int main()
{
    int N,M,k;
    scanf("%d%d%d",&N,&M,&k);
    int x=1,start_x=1,y=1,start_y=1,count=0,count2=0;
    while (count != k && count <= N*M && count2 != k )
    {
        x = start_x;
        count2 = count;
        count++;
        // printf("count:%d\n",count);
        while (x+1 <= M && count != k && count2 != k)
        {
            y = start_y;
            // printf("x:%d count:%d\n",x,count);
            count++;
            x++;
        }
        // printf("x:%d counjt:%d\n",x,count);
        count2 = count;
        start_y++;
        if (count2 != k){
            y = start_y;
        }
        // printf("count2:%d\n",count2);
        count++;
        while (y+1 <= N && count != k && count2 != k)
        {
            x = start_x;
            // printf("y:%d count:%d\n",y,count);
            count++;
            y++;
        }
        // printf("y:%d counkt:%d\n",y,count);
        start_x++;
    }
    printf("%d %d",y,x);
    return 0;
}
