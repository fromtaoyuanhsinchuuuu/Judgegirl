#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#define OUTOFBOUND -2147483648
#define HAVENOTSET -2147483647
#define SETSUCCESS 1

void init(ARRAY *a,  int left, int right)
{
    a->left = left;
    a->right = right;
    int len = right - left + 1;
    for (int i = 0; i < len; i++){
        a->arr[SET][i] = 0;
    }
    return;
}

int set(ARRAY *a, int index, int value)
{
    if (!(index >= a->left && index <= a->right)){
        return OUTOFBOUND;
    }
    a->arr[NUM][index - a->left] = value;
    a->arr[SET][index - a->left] = 1;
    return 1;

}

int get(ARRAY *a, int index)
{
    if (!(index >= a->left && index <= a->right)){
        return OUTOFBOUND;
    }
    index -= a->left;
    if (!(a->arr[SET][index])){
        return HAVENOTSET;
    }
    return a->arr[NUM][index];
}
void print(ARRAY *a)
{
    int len = a->right - a->left + 1;
    for (int i = 0; i < len; i++){
        if (!(a->arr[SET][i])){
            printf("No value\n");
        }
        else{
            printf("%d\n",a->arr[NUM][i]);
        }
    }
    return;

}
void sort(ARRAY *a)
{
    int len = a->right - a->left + 1;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            if (a->arr[SET][j] && !(a->arr[SET][j+1])){
                a->arr[SET][j + 1] = 1;
                a->arr[NUM][j + 1] = a->arr[NUM][j];
                a->arr[SET][j] = 0;
            }
            else if (a->arr[SET][j] && a->arr[SET][j + 1] && (a->arr[NUM][j] > a->arr[NUM][j+1])){
                int temp = a->arr[NUM][j];
                a->arr[NUM][j] = a->arr[NUM][j+1];
                a->arr[NUM][j+1] = temp;
            }
        }
    }
    return;
}

void test_specall() {
    int n, l, r;
    int cmds, cmd, aid;
    int index, value;
    scanf("%d", &n);
    ARRAY *a = (ARRAY *) malloc(sizeof(ARRAY)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        init(&a[i], l, r);
    }
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &aid);
        if (cmd == 1) {
            print(&a[aid]);
        } else if (cmd == 2) {
            scanf("%d %d", &index, &value);
            int ret = set(&a[aid], index, value);
            printf("ARRAY ID %d, set(%d, %d) %s\n", aid, index, value,
                ret == SETSUCCESS ? "SUCCESS" : (ret == OUTOFBOUND ? "OUTOFBOUND" : "HAVENOTSET"));
        } else if (cmd == 3) {
            scanf("%d", &index);
            int ret = get(&a[aid], index);
            printf("ARRAY ID %d, get(%d) ", aid, index);
            if (ret == OUTOFBOUND)   
                printf(": OUTOFBOUND\n");
            else if (ret == HAVENOTSET)
                printf(": HAVENOTSET\n");
            else
                printf("= %d\n", ret);
        } else if (cmd == 4) {
            sort(&a[aid]);
        } else {
            assert(0);
        }
    }
}
int main() {
    int spec = 0;
    void (*FUNC[])() = {test_specall};
    FUNC[spec]();
    return 0;
}