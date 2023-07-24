#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 33
#define MAXN 20000

typedef unsigned int ui;

int two_power(int power)
{
    int num = 1;
    for (int i = 0; i < power; i++){
        num *= 2;
    }
    return num;
}

int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);

    int n;
    scanf("%d",&n);

    ui Num_Arr[MAXN];
    for (int i = 0; i < n; i++){
        scanf("%u",&Num_Arr[i]);
    }

    int sum = 0;
    int power = 4;

    ui pivot = (1 << 31);
    for (int num_index = 0; num_index < n; num_index++){
        ui Now_num = Num_Arr[num_index];

        for (int i = 0; i < 32; i++){
            if (power < 0){
                printf("%c",str[sum]);
                sum = 0;
                power = 4;
            }
            if ((pivot & Now_num) != 0){
                sum += two_power(power);
            }
            power--;
            Now_num <<= 1;
        }


    }

    if (n % 5 == 0){
        printf("%c",str[sum]);
    }
    
    return 0;
}
