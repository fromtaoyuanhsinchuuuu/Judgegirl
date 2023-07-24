#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 4500

typedef struct Node{
    int num;
    struct Node *parent, *left, *right;
} Node;

int ptr = 0; // 指向下一個空的
int prev_num = 0;
Node *node_arr[MAX];

Node *genNode()
{
    Node *node = malloc(sizeof(Node));
    node->left = NULL, node->right = NULL, node->parent = NULL, node->num = prev_num;
    return node;
}

Node *merge()
{
    Node *l = node_arr[ptr - 2], *r = node_arr[ptr - 1];
    assert(l != NULL && r != NULL);
    Node *parent = malloc(sizeof(Node));
    parent->left = l, parent->right = r;
    l->parent = parent, r->parent = parent, parent->num = l->num + r->num, ptr--;
    node_arr[ptr - 1] = parent;
    return parent;
}

void treverse(Node *root, int mode)
{
    if (root == NULL) return;
    if (mode == 0){
        printf("%d\n", root->num);
        treverse(root->left, 1);
        printf("%d\n", root->num);
        treverse(root->right, 1);
    }
    else{
        printf("%d\n", root->num);
        treverse(root->right, 0);
        printf("%d\n", root->num);
        treverse(root->left, 0);
    }
    return;
}

int main(void)
{
    Node *root = NULL;
    char c = '\0', prev_c = '\0';
    while (scanf("%c", &c) != EOF){
        if (isdigit(c)){
            prev_num = prev_num * 10 + (c - '0');
        }
        else{
            if (isdigit(prev_c)) node_arr[ptr++] = genNode();
            prev_num = 0;
            if (c == ')') root = merge();
        }
        prev_c = c;
    }
    treverse(root, 0);
    return 0;
}
