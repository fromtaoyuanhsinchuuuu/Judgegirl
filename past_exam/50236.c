#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLEN 200

void mergeString(char** P, char L[26], char* A)
{
    int letter_arr[26];
    for (int i = 0; i < 26; i++){
        letter_arr[L[i]-97] = i;
    }    // 造出各個字元所代表的數字

    int add_to_the_pointer[MAXLEN] = {};
    int ptr_index = 0;
    int smallest_letter_num;
    int final_ptr_index;
    int A_index = 0;
    char now_letter = 0;
    while (1){
        now_letter = 0;
        smallest_letter_num = 26;
        ptr_index = 0;
        final_ptr_index = -1;
        /* 掃到NULL為止 */
        while (*(P+ptr_index) != NULL){
            now_letter = ((*(P+ptr_index))[add_to_the_pointer[ptr_index]] != '\0')? (*(P+ptr_index))[add_to_the_pointer[ptr_index]] : now_letter;
            if (isalpha(now_letter) && letter_arr[now_letter - 97] < smallest_letter_num){
                smallest_letter_num = letter_arr[now_letter - 97];
                final_ptr_index = ptr_index;
            }
            ptr_index++;
        }
        if (final_ptr_index == -1){
            break;
        }
        A[A_index] = (*(P+final_ptr_index))[add_to_the_pointer[final_ptr_index]];
        A[A_index+1] = '\0';
        add_to_the_pointer[final_ptr_index]++;
        A_index++;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
 
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}
