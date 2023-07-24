#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

// #ifndef HEAP_H
// #define HEAP_H
#define MAXHEAP 10
 
struct Heap{
    int ary[MAXHEAP]; // from 1
    int num;
};

int min_index(struct Heap *heap, int i)
{
    int minIndex = i, left = 2 * i, right = 2 * i + 1;
    if (left <= heap->num && heap->ary[minIndex] > heap->ary[left]) minIndex = left;
    if (right <= heap->num && heap->ary[minIndex] > heap->ary[right]) minIndex = right;
    return minIndex;
}

void swap(int ary[], int i, int j)
{
    int tmp = ary[i];
    ary[i] = ary[j];
    ary[j] = tmp;
    return;
}

void upheap(struct Heap *heap, int i)
{
    while (1){
        if (i == 1) break;
        int parentIndex = i / 2;
        // if (parentIndex == 0) break;
        if (heap->ary[parentIndex] >= heap->ary[i]) swap(heap->ary, i, parentIndex);
        else break;
        i = parentIndex;
    }
    return;
}

void dowHeap(struct Heap *heap)
{
    int i = 1;
    while (1){
        int minIndex = min_index(heap, i);
        // printf("minIndex:%d\n", minIndex);
        if (minIndex == i) break;
        swap(heap->ary, minIndex, i);
        i = minIndex;
    }
    return;
}
 
void initialize(struct Heap *heap)
{
    // heap = malloc(sizeof(struct Heap));
    for (int i = 1; i <= MAXHEAP; i++) heap->ary[i] = 2147483647;
    heap->num = 0;
    return;
}

int removeMin(struct Heap *heap)
{
    int min = heap->ary[1];
    heap->ary[1] = heap->ary[heap->num--];
    dowHeap(heap);
    return min;
}
void add(struct Heap *heap, int i)
{
    heap->ary[++(heap->num)] = i;
    upheap(heap, heap->num);
}
int isFull(struct Heap *heap)
{
    return heap->num == MAXHEAP;
}
int isEmpty(struct Heap *heap)
{
    return heap->num == 0;
}

int main(void)
{

    struct Heap *heap = malloc(sizeof(struct Heap));
    initialize(heap);
    for (int i = 0; i < 10; i++){
        int num;
        scanf("%d", &num);
        add(heap, num);
    }
    for (int i = 0; i < 10; i++){
        int k = removeMin(heap);
        printf("%d", k);
    }


    
    return 0;
}
