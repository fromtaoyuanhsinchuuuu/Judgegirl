#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 300000

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

void Tidy_func(int A[MAXN],int index,int heapsize)
{
    int largest_index = Get_max(A,index,heapsize);
    if (index == largest_index){
        return;
    }
    int temp = A[largest_index];
    A[largest_index] = A[index];
    A[index] = temp;
    Tidy_func(A,largest_index,heapsize);
    return;
}

void build_func(int arr[MAXN],int heapsize)
{
    for (int i = (heapsize / 2); i >= 1; i--){
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

void upheap(int A[MAXN],int i)
{
    int parent_index = i / 2;
    // printf("key:%d parent_index:%d i:%d\n",A[i],parent_index,i);
    assert(i != 0);
    if (i == 1 || A[parent_index] > A[i]){
        return;
    }
    int temp = A[i];
    A[i] = A[parent_index];
    A[parent_index] = temp;
    upheap(A,parent_index);
    return;
}
void insert(int arr[MAXN],int key,int *heapsize) // 插到最下面讓他浮上來
{
    (*heapsize)++;
    // printf("heapsize:%d\n",*heapsize);
    int now_index = *heapsize;
    arr[now_index] = key;
    // printf("nowindex:%d  key:%d\n",now_index,key);
    upheap(arr,now_index);
    
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
        printf("%d%c",arr[i]," \n"[i == N]);
    }

    int M;
    scanf("%d",&M);

    int opr = 0;
    int max_num = 0;
    // printf("\n");
    int j = 0;
    for (int i = 0; i < M; i++){
        scanf("%d",&opr);
        // printf("N:%d\n",N);         
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
