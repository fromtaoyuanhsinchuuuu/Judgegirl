#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    int sum = 0;
    int inside = 0;
    for (int i = a ; i <= b ; i++){
        sum += i;
    }
    if((b-3)-(a-1) >= 0){
        for (int i = a-1 ; i <= b-3 ; i++){
            inside += i;
        }
    }
    printf("%d\n%d",sum,sum-inside);
    return 0;
}
