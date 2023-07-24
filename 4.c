#include <stdio.h>

int main()
{
    int first_num;
    int second_num;
    int c;

    scanf("%d",&first_num);
    scanf("%d",&second_num);
    scanf("%d",&c);
    first_num += second_num + c;
    printf("%d",first_num);


    return 0;
}

