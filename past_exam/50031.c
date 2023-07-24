#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct 
{
    int sum;
    int larger_index;
    int smaller_index;

} Pair;


int cmp(const void *a,const void *b)
{
    int **ptrA = (int** )a;
    int **ptrB = (int** )b;
    if (**ptrA > **ptrB){
        return 1;
    }
    else if (**ptrB < **ptrB){
        return -1;
    }
    return 0;
}

int cmpINC(const void *a,const void *b)
{
    Pair *ptrA = (Pair *)a;
    Pair *ptrB = (Pair *)b;
    if (ptrA->sum > ptrB->sum){
        return 1;
    }
    else if (ptrA->sum < ptrB->sum){
        return -1;
    }
    else if (ptrA->sum == ptrB->sum && ptrA->smaller_index < ptrB->smaller_index){
        return -1;
    }
    return 1;
}

int cmpDEC(const void *a, const void *b)
{
    Pair *ptrA = (Pair *)a;
    Pair *ptrB = (Pair *)b;
    if (ptrA->sum > ptrB->sum){
        return -1;
    }
    else if (ptrA->sum < ptrB->sum){
        return 1;
    }
    else if (ptrA->sum == ptrB->sum && ptrA->larger_index > ptrB->larger_index){
        return -1;
    }
    return 1;

}

 
void pairPrint(int numbers[], int n)
{
    /* 換pointer就好 */
    assert(n % 2 == 0);
    int *ptr_arr[MAXN];
    for (int i = 0; i < n; i++){
        ptr_arr[i] = &numbers[i];
    }
    qsort(ptr_arr,n,sizeof(void*),cmp);
    Pair pairs[MAXN / 2];
    for (int i = 0; i < n / 2; i++){
        pairs[i].sum = *(ptr_arr[i]) + *(ptr_arr[n - i - 1]); 
        int larger_index = ptr_arr[i] - &(numbers[0]);
        int smaller_index = ptr_arr[n - i - 1] - &(numbers[0]);
        if (larger_index < smaller_index){
            int temp = larger_index;
            larger_index = smaller_index;
            smaller_index = temp;
        }
        pairs[i].larger_index = larger_index;
        pairs[i].smaller_index = smaller_index;
    }

    #ifdef INC
    qsort(pairs,n / 2,sizeof(Pair),cmpINC);
    for (int i = 0; i < n / 2; i++){
        printf("%d = numbers[%d] + numbers[%d]\n",pairs[i].sum,pairs[i].smaller_index,pairs[i].larger_index);
    }
    #endif

    #ifdef DEC
    qsort(pairs,n / 2,sizeof(Pair),cmpDEC);
    for (int i = 0; i < n / 2; i++){
        printf("%d = numbers[%d] + numbers[%d]\n",pairs[i].sum,pairs[i].larger_index,pairs[i].smaller_index);
    }
    #endif

    return;

}


int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int *A = (int *) malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        pairPrint(A, n);
        free(A);
    }
    return 0;
}
