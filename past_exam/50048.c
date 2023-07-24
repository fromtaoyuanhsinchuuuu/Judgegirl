#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

bool leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }
    return 0;
}

void count_day(int year, int day, int month, int results[7])
{
    /* 先算該月第一天是星期幾 */
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (leap_year(year)){
        days[1]++;
    }
    int day_diff = 0;
    for (int i = 0; i < month - 1; i++){
        day_diff += days[i];
    }

    int firstday = (day + day_diff) % 7;
    for (int i = 0; i < days[month - 1]; i++){
        results[(firstday + i)  % 7]++;
    }
    return;
}

int main(){
    int year, day, month, results[7] = {0}, i;
 
    while(scanf("%d %d %d", &year, &day, &month) == 3){
        for(i = 0; i < 7; i++)
            results[i] = 0;
        count_day(year, day, month, results);
        for(i = 0; i < 6; i++)
            printf("%d ", results[i]);
        printf("%d\n", results[i]);
    }
    return 0;
}
