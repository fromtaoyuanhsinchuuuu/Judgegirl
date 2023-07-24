#include <stdio.h>

int main()
{
    int n = 0;
    int x;
    int first_num;
    scanf("%d",&first_num);
    int second_num;
    int hour = first_num/10000;
    int minute = ((first_num-(first_num/10000)*10000))/100;
    int second = (first_num - (first_num/10000)*10000 -  (((first_num-(first_num/10000)*10000))/100*100));
    first_num = 3600*hour + 60*minute + second ;
    int difference = 0;
    int count = 0;
    int minimum_difference;
    while (scanf("%d",&second_num) != EOF)
    {
        hour = second_num/10000;
        minute = ((second_num-(second_num/10000)*10000))/100;
        second = (second_num - (second_num/10000)*10000 -  (((second_num-(second_num/10000)*10000))/100*100));
        second_num = 3600*hour + 60*minute + second ;
        difference = (first_num - second_num > 0)? first_num - second_num : second_num - first_num;
        if (count == 0 || difference < minimum_difference){
            minimum_difference = difference;
        }
        count += 1;
        first_num = second_num;
    }
    printf("%d",minimum_difference);    
    return 0;
}
