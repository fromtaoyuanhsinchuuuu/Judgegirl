#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define LEFT 0
#define RIGHT 1

#define MAXN 1200

int step = 0;
int step_arr[2][MAXN];

typedef struct Node{
    int key;
    int level;
    struct Node *parent, *left, *right;
} Node;

Node *genNode(int key, int level)
{
    Node *node = malloc(sizeof(Node));
    node->key = key, node->level = level;
    node->left = NULL, node->right = NULL, node->parent = NULL;
    return node;
}

int cmp(const void *a, const void *b)
{
    Node **ptr1 = (Node **)a;
    Node **ptr2 = (Node **)b;
    return (*ptr1)->level - (*ptr2)->level;
}

Node *insert(Node *root, Node *node)
{
    if (root == NULL) return node;
    if (node->key > root->key) root->right = insert(root->right, node);
    else root->left = insert(root->left, node);
    return root;
}

Node *search(Node *root, int key, int index)
{
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (key > root->key){
        step_arr[index][step++] = RIGHT;
        return search(root->right, key, index);
    }
    else{
        step_arr[index][step++] = LEFT;
        return search(root->left, key, index);
    }
}

int main(void)
{

    Node *Node_arr[MAXN];
    int N;
    scanf("%d", &N);

    int key, level;
    for (int i = 0; i < N; i++){
        scanf("%d%d", &key, &level);
        Node_arr[i] = genNode(key, level);
    }

    qsort(Node_arr, N, sizeof(Node *), cmp);
    Node *root = Node_arr[0];

    for (int i = 1; i < N; i++){
        root = insert(root, Node_arr[i]);
    }

    int Q;
    scanf("%d", &Q);

    int key1, key2;
    for (int i = 0; i < Q; i++){
        scanf("%d%d", &key1, &key2);

        step = 0;
        Node *ptr1 = search(root, key1, 0);

        step = 0;
        Node *ptr2 = search(root, key2, 1);
        if (ptr1->level >= ptr2->level){
            Node *tmp = ptr1;
            ptr1 = ptr2;
            ptr2 = tmp;
        }

        int same_step = 0;
        for (int i = 0; i < ptr1->level - 1; i++){
            if (step_arr[0][i] != step_arr[1][i]) break;
            same_step++;
        }
        printf("%d\n", ptr1->level + ptr2->level - 2 * (same_step + 1));
    }
    return 0;
}
