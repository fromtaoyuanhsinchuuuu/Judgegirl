#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 33
#define MAXN 10000 

typedef struct {
    int year;
    int month;
    int day;
    int amount;
    char category[MAXSTR];
} Expense;

int cmp(const void *a,const void *b)
{
    Expense *ptr1 = (Expense *)a;
    Expense *ptr2 = (Expense *)b;

    if (ptr1->year > ptr2->year){
        return 1;
    }
    else if (ptr1->year < ptr2->year){
        return -1;
    }
    else if (ptr1->month > ptr2->month){
        return 1;
    }
    else if (ptr1->month < ptr2->month){
        return -1;
    }
    else if (ptr1->day > ptr2->day){
        return 1;
    }
    else if (ptr1->day < ptr2->day){
        return -1;
    }
    return (strcmp(ptr1->category,ptr2->category));
}

int main(void)
{
    Expense exp_arr[MAXN];
    int n = 0;
    while (scanf("%d%d%d%s%d",&exp_arr[n].year,&exp_arr[n].month,&exp_arr[n].day,&(exp_arr[n].category),&exp_arr[n].amount) != EOF){
        n++;
    }

    qsort(exp_arr,n,sizeof(Expense),cmp);
    
    Expense prev_exp = exp_arr[0];

    for (int i = 1; i < n; i++){
        Expense now_exp = exp_arr[i];
        if (!(now_exp.year == prev_exp.year && now_exp.month == prev_exp.month && now_exp.day == prev_exp.day && !strcmp(prev_exp.category,now_exp.category))){
            printf("%d %d %d %s %d\n",prev_exp.year,prev_exp.month,prev_exp.day,prev_exp.category,prev_exp.amount);
        }
        else{
            now_exp.amount += prev_exp.amount;
        }
        if (i == n - 1){
            printf("%d %d %d %s %d\n",now_exp.year,now_exp.month,now_exp.day,now_exp.category,now_exp.amount);
        }
        prev_exp = now_exp;
    }



    
    
    return 0;
}
