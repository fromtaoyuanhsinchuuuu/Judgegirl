#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1000

typedef long long ll;

typedef struct {
    ll num;
    int one_num;
} Number;

int count_one(ll num)
{
    int bit = 0;
    for (int i = 0; i < sizeof(long long) * 8; i++){
        if ((num & 1) != 0){
            bit++;
        }
        num >>= 1;
    }
    return bit;

}

int cmp(const void *a,const void *b)
{
    Number* ptr1 = (Number *)a;
    Number* ptr2 = (Number *)b;
    if (ptr1->one_num > ptr2->one_num){
        return 1;
    }
    else if (ptr1->one_num < ptr2->one_num){
        return -1;
    }
    else if (ptr1->one_num == ptr2->one_num && ptr1->num > ptr2->num){
        return 1;
    }
    return -1;
}

int main(void)
{
    Number num_arr[MAXN];
    int n = 0;
    ll num;
    while (scanf("%lld",&num) != EOF){
        // printf("bit:%d\n",count_one(num));
        num_arr[n].one_num = count_one(num);
        num_arr[n].num = num;
        n++;
    }
    qsort(num_arr,n,sizeof(Number),cmp);
    for (int i = 0; i < n; i++){
        printf("%lld\n",num_arr[i].num);
    }



    
    
    return 0;
}
