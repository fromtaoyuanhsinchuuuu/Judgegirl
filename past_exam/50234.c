#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 105

int tower[MAXN][MAXN * MAXN] = {{}};
int height[MAXN * MAXN] = {};

typedef struct {
    int key;
    int index;
} Element;


struct Heap {
    Element *elements;
    int size;
};

struct Heap* createHeap() {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->elements = (Element *)malloc((MAXN * MAXN) * sizeof(Element));
    heap->size = 0;
    return heap;
}

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct Heap* heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->elements[index].key > heap->elements[parent].key) {
        swap(&heap->elements[index], &heap->elements[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(struct Heap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->elements[leftChild].key > heap->elements[smallest].key)
        smallest = leftChild;
    if (rightChild < heap->size && heap->elements[rightChild].key > heap->elements[smallest].key)
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap->elements[index], &heap->elements[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(struct Heap* heap, int value, int index) {
    
    if (heap->size == MAXN * MAXN) {
        printf("Heap is full. Cannot insert value.\n");
        return;
    }

    heap->elements[heap->size].index = index;
    heap->elements[heap->size].key = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

Element removeMax(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot remove minimum element.\n");
        return heap->elements[0];
    }

    Element minValue = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return minValue;
}

void printHeap(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->elements[i]);
    }
    printf("\n");
}

int main(void)
{
    int N;
    scanf("%d", &N);

    struct Heap* heap = createHeap();


    for (int i = 0; i < N; i++){
        for (int r = 0; r <= i; r++){
            for (int c = 0; c <= i; c++){
                int index = r * N + c;
                scanf("%d", &tower[i][index]);
                if (r == i || c == i){
                    insert(heap, tower[i][index], index);
                    height[index] = i;
                }
            }
        }
    }

    while (heap->size > 0){
        Element Min_element = removeMax(heap);
        printf("%d ", Min_element.key);
        Element newElement;
        newElement.index = Min_element.index, newElement.key = tower[++height[Min_element.index]][Min_element.index];
        if (height[Min_element.index] < N) insert(heap, newElement.key, newElement.index);
    }
    return 0;
}
