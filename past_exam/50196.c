#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(void)
{
    int nownum = 0;
    int num;
    int prev_result;
    int prev_add = 0;
    int rear_add;
    int prev_mul = 1;
    int rear_mul;
    int result;
    int prev_symbol_is_mul = 0;
    while (scanf("%d",&num) != EOF){
        if (num > 0 && num < 8){
            nownum = 10 * nownum + num;
        }
        else if (num == 8){
            prev_add = prev_add + nownum * prev_mul;
            prev_mul = 1;
            nownum = 0;
            prev_symbol_is_mul = 0;
        }
        else if (num == 9){
            prev_mul = prev_mul * nownum;
            nownum = 0;
            prev_symbol_is_mul = 1;
        }
        else if (num == 0){
            result = nownum * prev_mul + prev_add;
            printf("%d",result);
            break;
        }
    }
    return 0;
}
