
static long long seed = 1;

int sp_rand() {
    return (seed = (seed * 9301 + 49297) % 233280);
}
void sp_srand(long long t) {
    seed = t;
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
 
typedef struct Node {
    int v;
    struct Node *next;
} Node;
 
Node* mk_list(int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    // ...
    Node *prev = head;
    for (int i = 0; i < n; i++) {
        Node *u = (Node *)malloc(sizeof(Node));
        // ...
        u->v = sp_rand(), u->next = NULL;
        if (i == 0){
            head = u;
        }
        printf("%d\n",u->v);
        prev->next = u;
        prev = u;
        // ...
    }
    return head;

}
void rm_list(Node *head)
{
    if (head == NULL){
        return;
    }
    rm_list(head->next);
    free(head);
    return;

}

int main() {
    int n;
    long long s;
 
    scanf("%lld", &s);
    sp_srand(s);
    while (scanf("%d", &n) == 1) {
        Node *list = mk_list(n);
        // printf("head:%d",list->v);
        Node *u = list;
        for (int i = 0; i < n; ) {
            long long sum = 0;
            int cnt = 1;
            while (u && cnt < 100000) {
                sum += u->v * cnt;
                u = u->next, cnt++;
                i++;
            }
            // printf("%lld\n", sum);
        }
        rm_list(list);
    }
    return 0;
}
