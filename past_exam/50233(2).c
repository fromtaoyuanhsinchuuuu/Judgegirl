#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSIZE 300000


void down_heap(int A[],int i,int N)
{
    int l = i * 2;
    int r = i * 2 + 1;

    int largest_index = i;
    if (l < N && A[l] > A[i]){
        largest_index = l;
    }
    if (r < N && A[r] > A[largest_index]){
        largest_index = r;
    }

    if (largest_index != i){
        int temp = A[i];
        A[i] = A[largest_index];
        A[largest_index] = temp;
        down_heap(A,largest_index,N);
    }
    return;
}
void Building_heap(int A[],int N)
{
    for (int i = N / 2; i >= 0; i--){
        down_heap(A,i,N);
    }
    return;
}

int extract_max(int A[],int *N){
    if (*N <= 1){
        assert (0);
    }
    int max = A[0];
    A[0] = A[*N - 1];
    *N--;
    down_heap(A,0,*N);
    return max;

}


void upheap(int A[],int i)
{
    int parent_index = i / 2;
    assert (parent_index >= 0);
    if (A[parent_index] > A[i] || i == 0){
        return;
    }
    int temp = A[parent_index];
    A[parent_index] = A[i];
    A[i] = temp;
    // printf("parent)index:%d\n",parent_index);
    upheap(A,parent_index);
    return;
}
void insert(int A[],int key,int *N)
{
    A[*N] = key;
    upheap(A,*N);
    *N++;
    return;



}

int main(void)
{
    int A[MAXSIZE];
    int N;
    scanf("%d",&N);

    for (int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }

    Building_heap(A,N);
    for (int i = 0; i < N; i++){
        printf("%d ",A[i]);
    }

    int M;
    scanf("%d",&M);

    int opr;
    for (int i = 0; i < M; i++){
        scanf("%d",&opr);
        if (opr == -1){
            int max = extract_max(A,&N);
            printf("%d\n",max);

        }
        else{
            insert(A,opr,&N);

        }
    }


    
    
    return 0;
}
