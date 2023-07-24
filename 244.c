#include <stdio.h>

int main()
{
    int special_prize[3];
    for (int i= 0 ; i < 3 ; i++){
        scanf("%d",&special_prize[i]);
    }
    int first_prize[3][8];
    for (int i = 0 ; i < 3 ; i++){
        int firstprize;
        scanf("%d",&firstprize);
        for (int j = 7 ; j >= 0 ; j--){   
            first_prize[i][j] = firstprize % 10;
            firstprize /= 10;
            // printf("firstprize:%d\n",firstprize);
        }
    }
    int sum = 0;
    int lottery;
    while (scanf("%d",&lottery) != EOF){
        for (int i = 0 ; i < 3 ; i++){
            if (lottery == special_prize[i]){
                sum +=  2000000;
            }
        }
        int lottery_array[8];
        for (int i = 7 ; i >= 0 ; i--){
            lottery_array[i] = lottery % 10;
            lottery /= 10;
        }
        for (int i = 0 ; i < 3 ; i++){
            int digits = 0;
            for (int j = 7 ; j >= 0 ; j--){
                if (lottery_array[j] == first_prize[i][j]){
                    digits++;
                    if (digits == 8){
                        sum += 200000;
                    }
                }
                else{
                    switch (digits)
                    {
                    case 7:
                        sum += 40000;
                        break;
                    case 6:
                        sum += 10000;
                        break;
                    case 5:
                        sum += 4000;
                        break;
                    case 4:
                        sum += 1000;
                        break;
                    case 3:
                        sum += 200;
                        break;
                    default:
                        break;
                    }
                    break;
                }
            }
            // printf("sum:%d\n",sum);

        }
    }
    printf("%d",sum);
    return 0;
}
