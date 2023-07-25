#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#ifndef _NODE_H
#define _NODE_H
 
struct node {
    int value;
    struct node * next;
};
 
struct node * merge(struct node *, struct node *);
 
#endif

struct node *merge(struct node *list1, struct node *list2)
{
    if (list1 == NULL || list2 == NULL) return list1 == NULL? list2: list1;
    struct node *min = (list1->value < list2->value)? list1: list2;
    struct node *max = (struct node *)((uintptr_t)min ^ (uintptr_t)list1 ^ (uintptr_t)list2);
    min->next = merge(min->next, max);
    return min;

}

