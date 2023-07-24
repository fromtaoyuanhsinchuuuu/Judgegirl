#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100001

int Get_max(int arr[MAXN],int parent_index,int heapsize)
{
    /*index從1開始 */
    /* 在三個中找最大的，並return他的index */
    int left_index = 2 * parent_index;
    int right_index = 2 * parent_index + 1;
    int largest_index = parent_index;
    if (left_index <= heapsize && arr[left_index] > arr[parent_index]){
        largest_index = left_index;
    }
    if (right_index <= heapsize && arr[right_index] > arr[largest_index]){
        largest_index = right_index;
    }
    return largest_index;
}

void Tidy_func(int arr[MAXN],int index,int heapsize)
{
    int largest_index = Get_max(arr,index,heapsize);
    while (largest_index != index){
        int temp = arr[largest_index];
        arr[largest_index] = arr[index];
        arr[index] = temp;
        index = largest_index;
        largest_index = Get_max(arr,index,heapsize);
    }
    return;
}

void build_func(int arr[MAXN],int heapsize)
{
    for (int i = (heapsize / 2); i > 0; i--){
        Tidy_func(arr,i,heapsize);
    }
    return;
}

int extract_max(int arr[MAXN],int *heapsize)
{

    int max_num = arr[1];
    arr[1] = arr[*heapsize];
    *heapsize--;
    Tidy_func(arr,1,*heapsize);
    return max_num;
}

void insert(int arr[MAXN],int key,int *heapsize)
{
    *heapsize++;
    int now_index = *heapsize;
    arr[now_index] = key;
    while (now_index > 1 && arr[now_index / 2] < arr[now_index]){
        int temp = arr[now_index];
        arr[now_index] = arr[now_index / 2];
        arr[now_index / 2] = temp;
        now_index /= 2;
    }
    return;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int arr[MAXN] = {};
    for (int i = 1; i <= N; i++){
        scanf("%d",&arr[i]);
    }

    // assert(arr[N / 2] != 0);

    build_func(arr,N);
    for (int i = 1; i <= N; i++){
        printf("%d ",arr[i]);
    }

    int M;
    scanf("%d",&M);

    int opr = 0;
    int max_num = 0;
    // printf("\n");
    int j = 0;
    for (int i = 0; i < M; i++){
        scanf("%d",&opr);
        if (opr == -1){
            max_num = extract_max(arr,&N);
            assert (max_num > 0);
            printf("%d ",max_num);
        }
        else{
            insert(arr,opr,&N);
        }
        j = i;
        // printf("j:%d\n",j);
    }
    // printf("hi\n");
    
    return 0;
}
