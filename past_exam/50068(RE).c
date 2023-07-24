#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 1000
#define MAXTREE 10000

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

void track(Node *root, int index, Node *tree_arr[])
{
    tree_arr[index] = root;

    if (root == NULL){
        return;
    }

    track(root->left, index * 2, tree_arr);
    track(root->right, index * 2 + 1, tree_arr);

    return;
}
 
void traversal(Node *root, int N, int command[])
{
    int now_Index = 1;
    Node* tree_arr[MAXTREE];
    track(root, 1, tree_arr);
    tree_arr[0] = NULL;
    for (int i = 0; i < N; i++){
        int cmd = command[i];
        int new_Index = -1;
        assert(tree_arr[now_Index] != NULL);
        if (cmd == 0){
            printf("%d\n",tree_arr[now_Index]->label);
            return;
        }
        else if (cmd == 1){
            printf("%d\n",tree_arr[now_Index]->label);
        }
        else if (cmd == 2){
            new_Index = now_Index / 2;
            if (now_Index == 1 || tree_arr[new_Index] == NULL){
                printf("%d\n",tree_arr[now_Index]->label);
                return;
            }
            now_Index = new_Index;

        }
        else if (cmd == 3){
            new_Index = now_Index * 2;
            if (tree_arr[new_Index] == NULL){
                printf("%d\n",tree_arr[now_Index]->label);
                return;
            }
            now_Index = new_Index;

        }
        else if (cmd == 4){
            new_Index = now_Index * 2 + 1;
            // printf("new:%d\n",new_Index);
            if (tree_arr[new_Index] == NULL){
                printf("%d\n",tree_arr[now_Index]->label);
                return;
            }
            now_Index = new_Index;

        }
        else if (cmd == 5){
            if (now_Index % 2 == 0 && now_Index != 0){
                new_Index = now_Index + 1;
            }
            else{
                if (now_Index % 2 != 1){
                    printf("dick\n");
                }
                new_Index = now_Index - 1;
            }
            if (now_Index == 1 || tree_arr[new_Index] == NULL){
                printf("%d\n",tree_arr[now_Index]->label);
                return;
            }
            now_Index = new_Index;

        }
        else{
            exit(1);
            assert(0);
        }
        if (now_Index == 0){
            printf("ajdsk\n");
            return;
        }
    }
}

 
Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
            6,
            newNode(
                3,
                newNode(1,
                        NULL,
                        newNode(2, NULL, NULL)
                        ),
                newNode(5,
                        newNode(4, NULL, NULL),
                        NULL
                        )               
            ),
            newNode(
                7,
                NULL,
                NULL               
            )
    );
 
    int N, command[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &command[i]);       
    }
    traversal(root, N, command);
    return 0;
}
