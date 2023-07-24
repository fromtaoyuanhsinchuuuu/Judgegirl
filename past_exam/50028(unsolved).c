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

bool find_k(Node *root, int k)
{
    if (root == NULL){
        return 0;
    }
    if (root->label == k){
        return 1;
    }
    return (find_k(root->left,k) || find_k(root->right,k));
}
 
int getNode(Node *root, int label[], int k)
{
    if (root->left == NULL || root->right == NULL){
        return 0;
    }
    if ((getNode(root->left,label,k) || getNode(root->right,label,k)) && root->label != k){
        label[getNode(root->left,label,k) + getNode(root->right,label,k)] = root->label;
        return (1 + getNode(root->left,label,k) + getNode(root->right,label,k));
    }

}

Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
        10,
            newNode(
                5,
                    newNode(1, NULL, NULL),
                    newNode(1, NULL, NULL)               
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    newNode(5, NULL, NULL)               
            )
    );
    int k;
    while (scanf("%d", &k) == 1) {
        int A[128];
        int n = getNode(root, A, k);
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}
