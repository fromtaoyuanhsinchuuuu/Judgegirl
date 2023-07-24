#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    if((x%15 == 0) && (x%7 != 0)){
        printf("0");
    }
    else{
        printf("1");
    }
    return 0;
}
