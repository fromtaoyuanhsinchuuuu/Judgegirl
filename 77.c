#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#ifndef _NODE_H
#define _NODE_H
 
struct node {
    struct node *next;
};
#endif

struct node *getNode(struct node *head, unsigned int i);

int node_num(struct node *head)
{
    if (head == NULL) return 0;
    return 1 + node_num(head->next);
}

struct node *getNode_V2(struct node *head, unsigned int i, int nodeNum)
{
    if (nodeNum - 1 < 0) return NULL;
    if (i == nodeNum - 1) return head;
    return getNode_V2(head->next, i, nodeNum - 1);

}

struct node *getNode(struct node *head, unsigned int i)
{
    int nodeNum = node_num(head);
    return getNode_V2(head, i, nodeNum);
     
}


// int main(void)
// {


    
//     return 0;
// }
