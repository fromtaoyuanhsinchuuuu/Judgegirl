#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXSTR 50005

#define Right 0
#define Left 1

char STR[MAXSTR];
int STRindex = 0;

// Structure for AVL tree node
typedef struct Node 
{
    char c;
    struct Node *left, *right;
    int left_child_num, right_child_num;
    int height;
} Node;

// Function to get the height of a node
int getHeight(Node *node) 
{
    if (node == NULL) return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) 
{
    return (a > b) ? a: b;
}

// Function to create a new node with a given key
Node *newNode(char c) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->left_child_num = 0, node->right_child_num = 0;
    node->c = c;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    if (T2 != NULL) y->left_child_num = 1 + T2->left_child_num + T2->right_child_num;
    else y->left_child_num = 0;

    x->right_child_num = 1 + y->left_child_num + y->right_child_num;

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

    if (T2 != NULL) x->right_child_num = 1 + T2->left_child_num + T2->right_child_num;
    else x->right_child_num = 0;

    y->left_child_num = 1 + x->left_child_num + x->right_child_num;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(Node *node) 
{
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
Node *insertNode(Node *node, char c, int index) {
    // Perform the normal BST insertion
    if (node == NULL) return newNode(c);
    if (index <= 1 + node->left_child_num){
        node->left = insertNode(node->left, c, index);
        node->left_child_num++;
    }
    else{
        node->right = insertNode(node->right, c, index - node->left_child_num - 1);
        node->right_child_num++;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && node->left->left != NULL && node->left->left->c == c){
        return rightRotate(node);
    }

    // Left Right Case
    if (balance > 1 && node->left->right != NULL && node->left->right->c == c) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && node->right->right != NULL && node->right->right->c == c)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && node->right->left != NULL && node->right->left->c == c) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, int index) {
    // Perform standard BST delete
    if (root == NULL) return root;

    if (index < 1 + root->left_child_num){
        root->left = deleteNode(root->left, index);
        root->left_child_num--;
    }
    else if (index > 1 + root->left_child_num){
        root->right = deleteNode(root->right, index - 1 - root->left_child_num);
        root->right_child_num--;
    }
    else {
        // Node with the key value found
        // printf("delete find! char:%c\n", root->c);
        // Case 1: Node has no child or only one child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        } else {
            // Case 2: Node has two children

            // Find the inorder successor (smallest value in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->c = temp->c;

            // Delete the inorder successor
            root->right = deleteNode(root->right, 1);
            root->right_child_num--;
        }
    }

    // If the tree had only one node, return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged node pointer
    return root;
}

void PrintInOrder(Node *root)
{
    if (root == NULL) return;
    PrintInOrder(root->left);
    printf("left:%d right:%d char:%c\n", root->left_child_num, root->right_child_num, root->c);
    PrintInOrder(root->right);
    return;
}

void getSTR(Node *root)
{
    if (root == NULL) return;
    getSTR(root->left);
    STR[STRindex++] = root->c;
    STR[STRindex] = '\0';
    getSTR(root->right);
    return;
}

int main(void)
{
    char cmd[MAXSTR];

    Node *root = NULL;

    int node_num = 0;
    while (scanf("%s", cmd) != EOF){
        char opr[MAXSTR], c, buf[MAXSTR];
        if (!strcmp(cmd, "insert")){
            scanf("%*c");
            scanf("%s", opr);
            if (opr[0] == 'l'){
                scanf("%*c");
                scanf("%c", &c);
                root = insertNode(root, c, 1);
            }
            else if (opr[0] == 'r'){
                scanf("%*c");
                scanf("%c", &c);
                root = insertNode(root, c, node_num + 1);
            }
            else{
                int index = atoi(opr);
                scanf("%*c");
                scanf("%c", &c);
                root = insertNode(root, c, index);
            }
            node_num++;
        }
        else if (!strcmp(cmd, "delete")){
            scanf("%*c");
            scanf("%s", opr);
            if (opr[0] == 'l'){
                root = deleteNode(root, 1);
            }
            else if (opr[0] == 'r'){
                root = deleteNode(root, node_num);
            }
            else{
                int index = atoi(opr);
                root = deleteNode(root, index);
                // printf("index:%d", index);
            }
            node_num--;
        }
    }
    getSTR(root);

    int ans_num = 0, ans_index = 0;
    char ansC[MAXSTR];


    int now_num = 0;
    char prevC = '\0';

    for (int i = 0; i < node_num; i++){
        if (STR[i] == prevC || prevC == '\0'){
            now_num++;
        }
        if (STR[i] != prevC || i == node_num - 1){
            if (now_num > ans_num){
                ansC[0] = (prevC == '\0')? STR[i]: prevC;
                ans_index = 1;
                ans_num = now_num;
            }
            else if (now_num == ans_num){
                if (ans_num != 1) ansC[ans_index++] = (STR[i] == prevC)? STR[i]: prevC;
                else ansC[ans_index++] = STR[i];
            }
            now_num = 1;
        }
        prevC = STR[i];
    }
    // printf("\n");
    for (int i = 0; i < ans_index; i++){
        printf("%c ", ansC[i]);
    }
    printf("%d", ans_num);
    

    
    return 0;
}
