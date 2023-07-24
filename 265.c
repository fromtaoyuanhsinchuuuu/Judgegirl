#include <stdio.h>

int main(void)
{
    int x,y;
    int max_x = 10001;
    int max_y = 10001;
    int min_x = 10001;
    int min_y = 10001;
    while (scanf("%d%d",&x,&y) != EOF)
    {
        if (max_x == 10001 || x >= max_x){
            max_x = x;
        }
        else if (min_x == 10001 || x <= min_x){
            min_x = x;
        }

        if (max_y == 10001 || y >= max_y){
            max_y = y;
        }
        else if (min_y == 10001 || y <= min_y){
            min_y = y;
        }
    }
    int Area = (max_x-min_x)*(max_y-min_y);
    if (Area>0 && Area != 99910020)
        printf("%d",Area);
    else
        printf("0");
    
    
    return 0;
}
