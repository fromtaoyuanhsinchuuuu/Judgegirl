#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 262144

typedef struct activity {
    int start;
    int end;
} Activity;

int cmp(const void *a, const void *b)
{
    Activity *ptr1 = (Activity *)a;
    Activity *ptr2 = (Activity *)b;
    if (ptr1->end < ptr2->end){
        return -1; 
    }
    else if (ptr1->end > ptr2->end){
        return 1;
    }
    return 0;
}

bool overlap(Activity ans_arr[],int num,Activity act)
{
    for (int i = 0; i < num; i++){
        if (act.start < ans_arr[i].end){
            return 1;
        }
    }
    return 0;

}

int select(Activity activities[], int n)
{
    // printf("dick\n");
    qsort(activities,n,sizeof(Activity),cmp);
    Activity prev = activities[0];
    int num = 0;
    for (int i = 0; i < n; i++){
        if (i == 0 || activities[i].start >= prev.end){
            num++;
            #ifdef PRINT
            printf("%d %d\n",activities[i].start,activities[i].end);
            #endif
            prev = activities[i];
        }
    }
    return num;

}
 

Activity A[MAXN];

int main() {
    int n, cases = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++){
            scanf("%d %d", &A[i].start, &A[i].end);
        }
        int ret = select(A, n);
        printf("%d\n", ret);
    }
    return 0;
}


