#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

// #ifndef _NODE_H
// #define _NODE_H
 
struct node {
    struct node *left;
    struct node *right;
    int data;
};
 
// void print_all_paths(struct node *root);
 
// #endif

bool isLeaf(struct node *node)
{
    return node->left == NULL && node->right == NULL;
}

void printPath(int path[], int path_num)
{
    for (int i = 0; i < path_num; i++){
        printf("%d%c", path[i], " \n"[i == path_num - 1]);
    }
    return;
}

void print_all_paths_V2(struct node *root, int path[], int path_num)
{
    path[path_num++] = root->data;
    if (isLeaf(root)){
        printPath(path, path_num);
        return;
    }
    
    if (root->left != NULL) print_all_paths_V2(root->left, path, path_num);
    if (root->right != NULL) print_all_paths_V2(root->right, path, path_num);
    return;
}

void print_all_paths(struct node *root)
{
    int arr[10000];
    print_all_paths_V2(root, arr, 0);
   
}
 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}
