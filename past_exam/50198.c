#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a,b,x;
    int pin;
    int diff_number = 1;
    while(scanf("%d%d%d",&a,&b,&x) != EOF){
        while (1){
            int digits_array[100];
            int index = 0;
            int digit_of_x = x;
            while (digit_of_x >= 1)
            {
                digits_array[index] = digit_of_x % 10;
                digit_of_x /= 10;
                index++;            
            }
            int now_num = digits_array[0];
            int diff_number_array[100];
            for (int i = 0 ; i < 100 ; i++){
                diff_number_array[i] = -1;
            }
            diff_number = 1;
            int diff_number_index = 0;
            bool whether_to_put_in;
            for (int i = 0 ; i < index ; i++){
                whether_to_put_in = 1;
                for (int j = 0 ; j < 100 ; j++){
                    if (digits_array[i] == diff_number_array[j]){
                        whether_to_put_in = 0;
                    }
                }
                if (whether_to_put_in){
                    diff_number_array[diff_number_index] = digits_array[i];
                    diff_number_index++;
                }
            }
            // for (int i = 0 ; i < index ; i++){
            //     printf("diff_number_array[%d]:%d\n",i,diff_number_array[i]);
            // }
            int count = 0;
            for (int i = 0 ; i < index ; i++){
                if (diff_number_array[i] != -1){
                    count++;
                }
                else{
                    break;
                }
            }
            // printf("diff_number:%d\n",diff_number);
            if (count >= 3){
                x = (a*x) % b;
                continue;
            }
            else{
                printf("%d\n",x);
                break;
            }
        }
    }
    return 0;
}
