#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 300000 

int Get_largest_Index(int A[MAXN],int index,int n) // AC~~
{
    int Left_index = index * 2 + 1;
    int Right_index = Left_index + 1;

    int largest_index = index;
    if (Left_index < n && A[Left_index] > A[largest_index]){
        largest_index = Left_index;
    }
    if (Right_index < n && A[Right_index] > A[largest_index]){
        largest_index = Right_index;
    }

    return largest_index;
}

void downHeap(int A[MAXN],int index,int n)
{
    int current = index;
    int largest_index = Get_largest_Index(A,current,n);
    while (largest_index != current){

        /* swap */
        int temp = A[current];
        A[current] = A[largest_index];
        A[largest_index] = temp;

        current = largest_index;
        largest_index = Get_largest_Index(A,current,n);
    }
}

void upHeap(int A[MAXN],int n,int i)
{
    while (1){
        if (i <= 0){
            break;
        }
        int parent_index = i / 2;
        if (i % 2 == 0){
            parent_index--;
        }
        if (A[parent_index] >  A[i]){
            break;
        }
        /* swap */
        int temp = A[parent_index];
        A[parent_index] = A[i];
        A[i] = temp;
        i = parent_index;
    }
    return;

}

void buildHeap(int A[MAXN],int n)
{
    for (int i =  n / 2 - 1; i >= 0; i--){
        downHeap(A,i,n);
    }
    return;
}

void insert(int A[MAXN],int n,int key)
{
    A[n] = key;
    upHeap(A,n,n);

}

void extract_MAX(int A[MAXN],int n)
{
    printf("%d ",A[0]);
    A[0] = A[n - 1];
    n--;
    downHeap(A,0,n);
    return;

}

int main(void)
{

    int n;
    scanf("%d",&n);

    int A[MAXN];
    for (int i = 0; i < n; i++){
        scanf("%d",&(A[i]));
    }

    buildHeap(A,n);
    for (int i = 0; i < n; i++){
        printf("%d%c",A[i]," \n"[i == n - 1]);
    }

    int m;
    scanf("%d",&m);

    int cmd;
    for (int i = 0; i < m; i++){
        scanf("%d",&cmd);

        if (cmd == -1){
            extract_MAX(A,n);
            n--;
        }
        else{
            insert(A,n,cmd);
            n++;
        }
    }
    





   
    
    return 0;
}
