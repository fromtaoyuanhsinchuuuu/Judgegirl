#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSTRING 1000
#define RESULTNUM 4

int main(void)
{
    while (1){
        char num[MAXSTRING];
        int result[RESULTNUM] = {};
        int odd_and_even_digits_sum[2] = {};
        scanf("%s",num);
        int last_digit = num[strlen(num)-1] - '0';
        if (num[0] != '-'){
            for (int i = 0; i < strlen(num); i++){
                odd_and_even_digits_sum[i%2] += num[i] - '0';
            }
            if (last_digit % 2 == 0){
                result[0] = 1;
            }
            if ((odd_and_even_digits_sum[0] + odd_and_even_digits_sum[1]) % 3 == 0){
                result[1] = 1;
            }
            if (last_digit % 5 == 0){
                result[2] = 1;
            }
            if ((odd_and_even_digits_sum[0] - odd_and_even_digits_sum[1]) % 11 == 0){
                result[3] = 1;
            }
            for (int i = 0; i < RESULTNUM; i++){
                if (result[i]){
                    printf("%s%c","yes"," \n"[i == RESULTNUM - 1]);
                }
                else{
                    printf("%s%c","no"," \n"[i == RESULTNUM - 1]);
                }
            }
            // printf("diff:%d\n",odd_and_even_digits_sum[0]-odd_and_even_digits_sum[1]);
            



        }
        else{
            break;
        }

    }
    
    
    
    return 0;
}
