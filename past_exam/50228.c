#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);
    int number_list[n];
    for (int i = 0 ; i < n ; i++){ // MLE 用陣列存記憶體不夠==
        long long x;
        scanf("%d",&x);
        number_list[i] = x;
    }
    if ( n == 1){
        printf("%d %d %d",number_list[0],1,number_list[0]);
    }
    else{
        int count = 0; // 數到哪
        int d; // 公差
        int sum;
        int max_sum = 0;
        int number_of_the_list;
        int max_number_of_the_list = 0;
        int first_number_of_list;
        int max_first_number_of_list; // 欲print出的first_number
        while (count < n-1){
            sum = number_list[count];
            first_number_of_list = number_list[count];
            number_of_the_list = 1;
            d = number_list[count+1] - number_list[count];
            max_first_number_of_list = number_list[count];
            for (int i = count ; i < n-1 ; i++){
                if  (number_list[i+1] - number_list[i] != d ){
                    if (sum > max_sum){
                        max_sum = sum;
                        max_number_of_the_list = number_of_the_list;
                        max_first_number_of_list = first_number_of_list;
                    }
                    else if (sum == max_sum){
                        if (number_of_the_list > max_number_of_the_list){
                            max_number_of_the_list = number_of_the_list;
                            max_first_number_of_list = first_number_of_list;
                        }
                        else if (number_of_the_list == max_number_of_the_list){
                            if (first_number_of_list > max_first_number_of_list){
                                max_first_number_of_list = first_number_of_list;
                            }
                        }
                    }
                    
                    break;
                }
                else{
                    sum += number_list[i+1];
                    number_of_the_list += 1;
                    count += 1;
                }
            }
        }
        if (max_sum == 0){
            max_sum = sum;
            max_number_of_the_list = number_of_the_list;
            max_first_number_of_list = first_number_of_list;
        }
        printf("%d %d %d",max_sum,max_number_of_the_list,max_first_number_of_list);
    }






    return 0;
}