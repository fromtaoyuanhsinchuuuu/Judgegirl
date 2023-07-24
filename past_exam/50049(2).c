#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 1000

typedef struct two_line{
    int A_line[MAX];
    int B_line[MAX];
} two_line;

two_line find_func(int N,int A_elements[],int A_row_index[],int A_col_index[],int B_elements[],int B_row_index[],int B_col_index[],int r,int c)
{
    two_line A_and_B = {{},{}};
    /* 先找row */
    for (int i = 0; i < N; i++){
        if (A_row_index[i] == r){
            A_and_B.A_line[A_col_index[i]] = A_elements[i];
        }
    }

    for (int i = 0; i < N; i++){
        if (B_col_index[i] == c){
            A_and_B.B_line[B_row_index[i]] = B_elements[i];
        }
    }

    return A_and_B;
}

int matrix_mul(int A[],int B[],int S)
{
    int result = 0;
    for (int i = 0; i < S; i++){
        result += (A[i] * B[i]);
    }
    return result;
}


void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result)
{
    for (int i = 0; i < S*S; i++){
        result[i] = 0;
    }

    int *A_elements = ptrA[0];
    int *A_row = ptrA[1];
    int *A_col = ptrA[2];
    int *B_elements = ptrB[0];
    int *B_row = ptrB[1];
    int *B_col = ptrB[2];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (B_row[j] == A_col[i]){
                result[A_row[i] * S + B_col[j]] += (A_elements[i] *(long long) B_elements[j]);
            }
        }
    }
}


static int A_elements[MAX], A_rowind[MAX], A_colind[MAX];
static int B_elements[MAX], B_rowind[MAX], B_colind[MAX];
int main(int argc, char const *argv[])
{   
    int N, M, S;
    assert(scanf("%d %d %d", &N, &M, &S) == 3);
 
    int *ptrA[3];
    int *ptrB[3];
    ptrA[0] = A_elements, ptrA[1] = A_rowind, ptrA[2] = A_colind;
    ptrB[0] = B_elements, ptrB[1] = B_rowind, ptrB[2] = B_colind;
 
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_elements[i]) == 1);
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_rowind[i]) == 1);   
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_colind[i]) == 1);           
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_elements[i]) == 1);
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_rowind[i]) == 1);   
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_colind[i]) == 1);
 
    int *result = malloc(S*S*sizeof(int));
    matrix_multiplication(N, ptrA, M, ptrB, S, result);
    for (int i = 0; i < S; ++i)
        for (int j = 0; j < S; ++j)
              printf("%d%c", result[i * S + j], " \n"[j == S - 1]);
    return 0;
}
