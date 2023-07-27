#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef struct Memory{
    int start;
    int length;
    struct Memory *next;
} Memory;

void initMemory(Memory *memory, int length)
{
    memory->length = length;
    memory->start = 0;
    memory->next = NULL;
    return;
}

void printMemory(Memory *memory)
{
    printf("==========\n");
    while (memory != NULL){
        if (memory->length != 0) printf("start %d, length %d\n", memory->start, memory->length);
        memory = memory->next;
    }
    return;

}

Memory *findMemory(Memory *memory, int start)
{
    if (start >= memory->start && start <= memory->start + memory->length) return memory;
    return findMemory(memory->next, start);
}

int tail(Memory *memory)
{
    return memory->start + memory->length;
}
void allocateMemory(Memory *memory, int start, int length)
{
    Memory *target = memory, *prev = NULL;
    while (!(start >= target->start && start + length <= target->start + target->length)){
        // printf("start:%d legth:%d\n", target->start, target->length);
        prev = target;
        target = target->next;
    }
    // assert(target != NULL && target->start <= start && start + length <= target->start + target->length);
    if (start == target->start && length == target->length){ // head to head, tail to tail
        if (prev != NULL) prev->next = target->next;
        else if (target == memory) memory->length = 0;
        else *memory = *(target->next);
    }
    else if (start == target->start && start + length < tail(target)){
        target->start = start + length;
        target->length -= length;
    }
    else if (tail(target) == start + length && start > target->start){
        target->length -= length;
    }
    else{
        assert(start > target->start && tail(target) > start + length);
        int target_tail = tail(target);
        target->length -= (target->start + target->length - start);
        Memory *next = malloc(sizeof(Memory));
        next->start = start + length, next->length = target_tail - (start + length);
        next->next = target->next;
        target->next = next;
    }
}
void freeMemory(Memory *memory, int start, int length)
{
    Memory *prev = NULL, *target = memory;
    while (target != NULL){
        if (prev == NULL){
            if (target->start >= start + length){
                break;
            }
        }
        else if (prev != NULL && target != NULL && prev->start + prev->length <= start && target->start >= start + length){
            break;
        }
        prev = target;
        target = target->next;
    }
    if (target == NULL){
        if (prev->start + prev->length == start){
            prev->length += length;
            return;
        }
        Memory *next = malloc(sizeof(Memory));
        next->length = length, next->start = start, next->next = NULL;
        prev->next = next;
    }
    else if (prev == NULL){
        if (start + length == memory->start){
            memory->start = start;
            memory->length += length;
        }
        else{
            Memory *head = malloc(sizeof(Memory));
            head->start = start, head->length = length, head->next = target;
            *memory = *head;
        }
    }
    else{
        assert(target != NULL && prev != NULL);
        if (prev->start + prev->length == start && target->start == start + length){
            prev->next = target->next;
            prev->length += length + target->length;
            // int target_tail = tail(target);
            // target->start = prev->start;
            // target->length = target_tail - target->start;
            // if (memory == prev) *memory = *target;
        }
        else if (prev->start + prev->length == start){
            prev->length += length;
        }
        else if (start + length == target->start){
            target->start = start;
            target->length += length;
        }
        else{
            Memory *middle = malloc(sizeof(Memory));
            middle->start = start, middle->length = length;
            prev->next = middle, middle->next = target;
        }
    }
    return;
}

int main(void)
{
    Memory myMemory;

    char cmd;
    while (scanf("%c", &cmd) != EOF){
        int trash, start, len;
        if (cmd == 'I') {
            scanf("%d%d", &trash, &len);
            initMemory(&myMemory, len);
        }
        else if (cmd == 'A'){
            scanf("%d%d%d", &trash, &start, &len);
            allocateMemory(&myMemory, start, len);
        }
        else if (cmd == 'P'){
            scanf("%d", &trash);
            printMemory(&myMemory);
        }
        else if (cmd == 'F'){
            scanf("%d", &trash);
            scanf("%d%d", &start, &len);
            freeMemory(&myMemory, start, len);
        }
    }
    return 0;
}
