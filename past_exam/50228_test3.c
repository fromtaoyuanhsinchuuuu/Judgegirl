#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int first_number;
    scanf("%d",&first_number);
    if (n == 1){
        printf("%d %d %d",first_number,1,first_number);
    }
    else if (n == 2){
        int x;
        scanf("%d",&x);
        int sum = x + first_number;
        int number_of_the_list = 2;
        printf("%d %d %d",sum,2,first_number);
    }
    else{
        int x; // x為輸入的數字
        scanf("%d",&x);
        int last_number = x;
        int sum = x + first_number;
        int max_sum = 0;
        int number_of_list = 2;
        int max_number_of_list;
        int max_first_number;
        int d = x- first_number;
        for (int i = 0 ; i < n-2 ; i++){
            scanf("%d",&x);
            if (x - last_number != d){
                if (sum > max_sum || sum == max_sum && number_of_list > max_number_of_list || sum == max_sum && number_of_list == max_number_of_list && first_number > max_first_number){
                    max_sum = sum;
                    max_number_of_list = number_of_list;
                    max_first_number = first_number;
                }
                first_number = last_number;
                sum = x + first_number;
                number_of_list = 2;
                d = x - first_number;
            }
            else{
                // printf("first_number:%d\n",first_number);
                sum += x;
                number_of_list += 1;
            }
            last_number = x;
        }
        // printf("sum:%d max_sum:%d\n",sum,max_sum);
        if (sum > max_sum || sum == max_sum && number_of_list > max_number_of_list || sum == max_sum && number_of_list == max_number_of_list && first_number > max_first_number){
            max_sum = sum;
            max_number_of_list = number_of_list;
            max_first_number = first_number;
        }
        printf("%d %d %d",max_sum,max_number_of_list,max_first_number);
    }
    return 0;
}