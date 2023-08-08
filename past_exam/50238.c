#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int row, col, val;
    struct Node *next;
} Node;

Node *genNode(int row, int col)
{
    Node *node = malloc(sizeof(Node));
    node->row = row, node->col = col, node->val = 0, node->next = NULL;
    return node;
}

void sparseMatrixMult(int** A, int** B)
{
    Node *head = genNode(-1, -1);
    Node *ptr = head;
    for (int a_arr_index = 0; *(A + a_arr_index) != NULL; a_arr_index++){
        int *arrA = *(A + a_arr_index);
        ptr->row = arrA[0];
        for (int b_arr_index = 0; *(B + b_arr_index) != NULL; b_arr_index++){
            int *arrB = *(B + b_arr_index);
            ptr->col = arrB[0];
            for (int i = 1; arrA[i] != -1; i += 2){
                int a_col = arrA[i], a_val = arrA[i + 1];
                for (int j = 1; arrB[j] != -1; j += 2){
                    int b_row = arrB[j], b_val = arrB[j + 1];
                    if (a_col == b_row) ptr->val += a_val * b_val;
                }
            }
            if (ptr->val == 0) continue;
            printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
            ptr->val = 0;
        }
    }
}

int main (void) {
    int P, Q, R, N, M;
    assert(scanf("%d%d%d", &P, &Q, &R) == 3);
    assert(scanf("%d", &N) == 1);
    int** A = (int **) malloc(sizeof(int*)*(N+1));
    for (int i = 0; i < N; i++) {
        int rowIdx, x;
        assert(scanf("%d%d", &rowIdx, &x) == 2);
        int *row = (int *) malloc(sizeof(int)*(x*2+2));
        row[0] = rowIdx;
        for (int i = 0; i < x; i++)
            assert(scanf("%d%d", &row[i*2+1], &row[i*2+2]) == 2);
        row[x*2+1] = -1;
        A[i] = row;
    }
    A[N] = NULL;
 
    assert(scanf("%d", &M) == 1);
    int** B = (int **) malloc(sizeof(int*)*(M+1));
    for (int i = 0; i < M; i++) {
        int colIdx, y;
        assert(scanf("%d%d", &colIdx, &y) == 2);
        int *col = (int *) malloc(sizeof(int)*(y*2+2));
        col[0] = colIdx;
        for (int i = 0; i < y; i++)
            assert(scanf("%d%d", &col[i*2+1], &col[i*2+2]) == 2);
        col[y*2+1] = -1;
        B[i] = col;
    }
    B[M] = NULL;
 
    sparseMatrixMult(A, B);
}
