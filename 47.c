#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXSTR 20

char prevC = '\0';
int prev_num = 0;


typedef struct Node 
{
    char c;
    struct Node *left, *right;
    int num;
    int left_child_num, right_child_num;
    int height;
} Node;

Node *maxNode = NULL;

int max(int a, int b) 
{
    return (a > b)? a: b;
}

void printANS(Node *root)
{
    if (root == NULL) return;
    printANS(root->left);
    if (prevC == '\0'){
        prevC = root->c;
        prev_num = root->num;
    }
    else if (root->c == prevC){
        prev_num += root->num;
        
    }
    else{
        printf("%c %d ", prevC, prev_num);
        prevC = root->c;
        prev_num = root->num;
    }
    if (root == maxNode){
        printf("%c %d ", root->c, prev_num);
    }
    printANS(root->right);
}

int getHeight(Node *node) 
{
    if (node == NULL) return 0;
    return node->height;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    if (T2 != NULL) y->left_child_num = T2->num + T2->left_child_num + T2->right_child_num;
    else y->left_child_num = 0;

    x->right_child_num = y->num + y->left_child_num + y->right_child_num;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    if (T2 != NULL) x->right_child_num = T2->num + T2->left_child_num + T2->right_child_num;
    else x->right_child_num = 0;

    y->left_child_num = x->num + x->left_child_num + x->right_child_num;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}


Node *findMin(Node *root)
{
    if (root == NULL) return NULL;
    if (root->left != NULL) return findMin(root->left);
    return root;
}

Node *findMax(Node *root)
{
    if (root == NULL) return NULL;
    if (root->right != NULL) return findMax(root->right);
    return root;
}

Node *genNode(char c, int num)
{
    Node *node = malloc(sizeof(Node));
    node->c = c;
    node->height = 1;
    node->left = NULL, node->right = NULL;
    node->num = num;
    node->left_child_num = 0, node->right_child_num = 0;
    return node;
}

void updateHeight(Node *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return;
}

int getBalance(Node *node) 
{
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node *insertNode(char c, int num, int index, Node *root)
{
    if (root == NULL) return genNode(c, num);
    if (index >= root->left_child_num + 1 && index <= root->left_child_num + root->num){
        // printf("rootC:%c c:%c\n", root->c, c);
        // if (c == root->c){
        //     root->num += num;
        //     return root;
        // }
        int left_num = index - root->left_child_num - 1;
        if (left_num > 0){
            Node *max_left = findMax(root->left);
            if (max_left != NULL){
                max_left->right = genNode(root->c, left_num);
                max_left->right_child_num += left_num;
                updateHeight(max_left);
            }
            else{
                root->left = genNode(root->c, left_num);
                root->left_child_num += left_num;
            }
        }

        int right_num = root->num - left_num;
        if (right_num > 0){
            Node *min_right = findMin(root->right);
            if (min_right != NULL){
                min_right->left = genNode(root->c, right_num);
                min_right->left_child_num += right_num;
                updateHeight(min_right);
            }
            else{
                root->right = genNode(root->c, right_num);
                root->right_child_num += right_num;
            }

        }
        root->c = c, root->num = num;
    }
    else if (index <= root->left_child_num){
        root->left = insertNode(c, num, index, root->left);
        root->left_child_num += num;
    }
    else{
        root->right = insertNode(c, num, index - root->left_child_num - root->num, root->right);
        root->right_child_num += num;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && root->left->left != NULL && root->left->left->c == c){
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && root->left->right != NULL && root->left->right->c == c) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && root->right->right != NULL && root->right->right->c == c)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && root->right->left != NULL && root->right->left->c == c) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged root pointer
    return root;
}

void getAns(Node *root)
{

}
void DebugAns(Node *root)
{
    if (root == NULL) return;
    DebugAns(root->left);
    printf("c:%c, num:%d, left_num:%d right_num:%d\n", root->c, root->num, root->left_child_num, root->right_child_num);
    DebugAns(root->right);
    return;
}

int main(void)
{
    char cmd[MAXSTR];

    Node *root = NULL;
    int str_num = 0;
    while (scanf("%s", cmd) != EOF){
        char c;
        int n, k;
        if (!strcmp(cmd, "insert")){
            scanf("%*c");
            char str[MAXSTR];
            scanf("%s", str);

            if (!strcmp(str, "left")){
                scanf("%*c");
                scanf("%c", &c);
                scanf("%*c");
                scanf("%d", &n);
                root = insertNode(c, n, 1, root);
            }
            else if (!strcmp(str, "right")){
                scanf("%*c");
                scanf("%c", &c);
                scanf("%*c");
                scanf("%d", &n);
                root = insertNode(c, n, str_num + 1, root);

            }
            else{
                k = atoi(str);
                scanf("%*c");
                scanf("%c", &c);
                scanf("%*c");
                scanf("%d", &n);
                root = insertNode(c, n, k, root);
            }
            str_num += n;
        }
        else{
            maxNode = findMax(root);
            prevC = '\0', prev_num = 0;
            printANS(root);
            printf("$\n");
        }
        DebugAns(root);
    }

    
    return 0;
}
