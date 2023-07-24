#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int sum = 0;
    int max_sum = sum;
    int number_of_list = 0;
    int max_number_of_list = number_of_list;
    int first_number;
    scanf("%d",&first_number);
    sum += first_number;
    number_of_list += 1;
    int max_first_number = first_number; // max_first_number 為要print出的數字
    int last_number; 
    scanf("%d",&last_number);
    number_of_list += 1;
    sum += last_number;
    int d = last_number - first_number;
    int x; // x為讀進來的數
    for (int i = 0 ; i < n-2 ; i++){
        printf("firsy_number:%d\n",first_number);
        scanf("%d",&x);
        if (sum > max_sum){
            max_first_number = first_number;
        }
        if (x - last_number != d){
            if (sum > max_sum){
                max_sum = sum;
                max_number_of_list = number_of_list;
                max_first_number = first_number;
            }
            else if (sum == max_sum){
                if (number_of_list > max_number_of_list){
                    max_number_of_list = number_of_list;
                    max_first_number = first_number;
                }
                else if (number_of_list == max_number_of_list){
                    if (first_number > max_first_number){
                        max_first_number = first_number;
                    }
                }
            }
            printf("sum:%d\n",sum);
            first_number = last_number;
            last_number = x;
            d = x - first_number;
            sum = first_number + x;
            number_of_list = 2;

        }
        else{
            last_number = x;
            sum += x;
            number_of_list += 1;
        }
    }
    // printf("last_number:%d x:%d",last_number,x);
    // if (last_number + x > max_sum){
    //     max_sum = last_number + x;
    //     max_number_of_list = 2;
    //     max_first_number = last_number;
    // }
    if (sum > max_sum){
        printf("%d %d %d",sum,number_of_list,first_number);
    }
    else{
        printf("%d %d %d",max_sum,max_number_of_list,max_first_number);
    }
    return 0;
}