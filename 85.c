#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 10000000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef unsigned long long ull;

int cmp(const void *a, const void *b)
{
    Date* ptr1 = (Date*) a;
    Date* ptr2 = (Date*) b;

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
    return 0;
    
}

int cmp_func(const void *a, const void *b)
{
    ull* ptr1 = (ull*) a;
    ull* ptr2 = (ull*) b;
    // return (*ptr1 - *ptr2);
    if (*ptr1 > *ptr2){
        return 1;
    }
    else if (*ptr1 < *ptr2){
        return -1;
    }
    return 0;
    
}

int main(void)
{
    static ull data[MAXN];

    int n;
    scanf("%d",&n);
    ull year,month,day;
    for (int i = 0; i < n; i++){
        scanf("%llu%llu%llu",&year,&month,&day);
        assert(year * 10000 > 0);
        data[i] = year * 10000 + month * 100 + day;
        assert(data[i] > 0);
    }

    qsort(data,n,sizeof(ull),cmp_func);
    for (int i = 0; i < n; i++){
        ull year = data[i] / 10000;
        ull month = (data[i] - (10000 * year)) / 100;
        ull day = data[i] % 100;
        printf("%llu %llu %llu\n",year,month,day);
    }


    
    
    
    return 0;
}
