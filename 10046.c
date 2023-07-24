#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 10
#define MAXM 100

typedef struct {
    int person;
    int position;
} Rule;

bool violate(int arr[MAXN],Rule rules[],int m,int num)
{
    if (num < 0){
        return 0;
    }
    for (int i = 0; i < m; i++){
        if (arr[num - 1] == rules[i].person && (num) == rules[i].position){
            // printf("vioasd!\n");
            return 1;
        }
    }
    return 0;

}

bool in_arr(int arr[MAXM],int num,int i)
{
    for (int j = 0; j < num; j++){
        if (arr[j] == i){
            return 1;
        }
    }
    return 0;
}

bool permutate(Rule rules[],int n,int m,int arr[MAXN],int num)
{
    if (violate(arr,rules,m,num)){
        // printf("adsjlkasjdasd");
        return 0;
    }
    if (num == n){
    // printf("dick");
        for (int i = 0; i < num; i++){
            printf("%c",arr[i] + 64);
        }
        printf("\n");
        return 1;
    }


    for (int i = 1; i <= n; i++){
        if (in_arr(arr,num,i)){
            continue;
        }
        arr[num] = i;
        if (permutate(rules,n,m,arr,num+1)){
            // return 1;
        }
        continue;
    }
    // printf("err!\n");
    return 0;



}

int main(void)
{
    int n,m;

    while (scanf("%d%d",&n,&m) != EOF){
        int arr[MAXN] = {};
        Rule rules[MAXM];
        for (int i = 0; i < m; i++){
            scanf("%d%d",&rules[i].person,&rules[i].position);
        }

        permutate(rules,n,m,arr,0);





    }


    return 0;
}
