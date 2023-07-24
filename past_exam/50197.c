#include <stdio.h>

int abs(int a){
    return (a >= 0)? a : -a;
}

int main()
{
    int k;
    scanf("%d",&k);
    for (int i = 1000 ; i <= 9999 ; i++){
        int first_digit = i / 1000;
        int second_digit = (i % 1000) / 100;
        int third_digit = (i % 100) / 10;
        int fourth_digit = i % 10;
        if (abs(fourth_digit - third_digit) <= k && abs(second_digit-third_digit) <= k && abs(second_digit - first_digit) <= k ){
            printf("%d\n",i);
        }
    }
    return 0;
}
