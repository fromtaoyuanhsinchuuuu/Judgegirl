#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

Node* GenTreeNode(int data,Node *l,Node *r){
    Node* root = (Node *)malloc(sizeof(Node));
    root->label = data;
    root->left = l;
    root->right = r;

    return root;
    

}

Node *TreeConstruct(int array[],int n,int index)
{
    if (index >= n){
        return NULL;
    }
    
    return GenTreeNode(array[index],TreeConstruct(array,n,index * 2 + 1),TreeConstruct(array,n,index * 2 + 2));

}
 
Node* construct(int array[], int n)
{
    return TreeConstruct(array,n,0);
}

void printAndFree(Node *u) {
    if (u == NULL)    return ;
    printf("%d ", u->label);
    printAndFree(u->left);
    printAndFree(u->right);
    free(u);
}
 
int main() {
    int A[32767], n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        Node *root = construct(A, n);
        printAndFree(root);
        puts("");
    }
    return 0;
}
