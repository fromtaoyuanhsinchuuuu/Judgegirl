#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void hash_h1(int n, int A[], int N)
{
    for (int i = 0; i < n; i++){
        A[i] = (8 * A[i]) % N;
    }
    return;
}

void hash_h2(int n, int A[], int N)
{
    for (int i = 0; i < n; i++){
        A[i] = (1+ (((2 * A[i]) - 2)) % (N - 1));
    }
    return;
}

void double_hash(int h1[], int h2[], int N, int n, int hash_table[100][100])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < N; j++){
            hash_table[i][j] = (h1[i]+ j * h2[i]) % N;
        }
    }
    return;
}





int main()
{
    int n;
    scanf("%d", &n);

    int h1[1000], h2[1000];

    int a;

    int N = 7;
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        h1[i] = a, h2[i] = a;
    }

    hash_h1(n, h1, N), hash_h2(n, h2, N);
    for (int i = 0; i < n; i++){
        printf("%d ", h1[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        printf("%d ", h2[i]);
    }

    int double_hashing_table[100][100];

    double_hash(h1, h2, N, n, double_hashing_table);
    printf("\n\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < N; j++){
            printf("%d%c", double_hashing_table[i][j], " \n"[j == N - 1]);
        }
    }

}
