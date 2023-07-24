#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXNAME 40
#define MAXSTR 1500

typedef struct Node{
    struct Node *left, *right;
    char str[MAXNAME];
    int val;
} Node;

// Function to create a new node
struct Node* createNode(char str[MAXNAME], int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->str, str);
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, char str[MAXSTR], int val) {
    if (root == NULL){
        return createNode(str, val);
    }

    if (strcmp(str, root->str) < 0){
        root->left = insert(root->left, str, val);
    }
    else{
        root->right = insert(root->right, str, val);
    }
    return root;
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, char str[MAXSTR]) {
    if (root == NULL || !strcmp(root->str, str)) {
        return root;
    }

    if (strcmp(str, root->str) < 0) {
        return search(root->left, str);
    }

    return search(root->right, str);
}

int cal(int a, int b, char c)
{
    if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else if (c == '*') return a * b;
    else{
        assert(c == '/');
        return a / b;
    }
    assert(0);
    return 0;
}

int main(void)
{
    char expression[MAXSTR];
    fgets(expression, MAXSTR, stdin);

    char variable[MAXNAME];

    int val = 0;
    char trash = 'a';
    Node *root = NULL;
    while (scanf("%s", variable) != EOF){
        scanf("%*c");
        scanf("%c", &trash);
        scanf("%*c");
        scanf("%d", &val);

        root = insert(root, variable, val);
    }

    char str[MAXSTR];
    char symbols[MAXSTR];
    int numbers[MAXSTR];


    int num_index = 0, symbol_index = 0;
    char c;
    int str_index = 0;
    int expression_index = 0;
    int expreesin_len = strlen(expression);

    while (expression_index < expreesin_len - 1){
        int i = 0;
        for (;isprint(expression[expression_index]) && expression[expression_index] != ' '; i++, expression_index++){
            str[i] = expression[expression_index];
        }
        str[i] = '\0';
        expression_index++;
        if (str[0] == '(') continue;
        else if (isdigit(str[0])) numbers[num_index++] = atoi(str);
        else if (str[0] == ')'){
            int b = numbers[--num_index];
            int a = numbers[--num_index];
            char c = symbols[--symbol_index];
            numbers[num_index++] = cal(a, b, c);
        }
        else if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'){
            symbols[symbol_index++] = str[0];
        }
        else{
            if (!(isalpha(str[0]) || str[0] == '_' || str[0] == '$')) break;
            numbers[num_index++] = search(root, str)->val;
        }
    }
    printf("%d\n", numbers[0]);
    
    return 0;
}
