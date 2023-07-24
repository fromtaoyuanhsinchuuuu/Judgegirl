#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 51
#define MAXN 20

#define LETTERNUM 26

typedef struct {
    char str[MAXSTR];
    int cost;
} Letter;

typedef struct {
    int cost;
    int letter[LETTERNUM];
} Sol;

Sol better(Sol a,Sol b)
{
    for (int i = 0; i < LETTERNUM; i++){
        if (!(a.letter[i])){
            return b;
        }
        if (!(b.letter[i])){
            return a;
        }
    }

    return (a.cost < b.cost)? a: b;
}

Sol best(Sol nowSol,int N,int index,Letter letters[MAXN])
{
    if (index == N){
        return nowSol;
    }

    Sol select = nowSol;
    Sol not_select = nowSol;

    select.cost += letters[index].cost;
    int len = strlen(letters[index].str);
    for (int i = 0; i < len; i++){
        select.letter[letters[index].str[i] - 'a'] = 1;
    }

    return better(best(select,N,index + 1,letters),best(not_select,N,index + 1,letters));
    
}



int main(void)
{
    Letter letters[MAXN];
    int N;
    scanf("%d",&N);

    Sol solution = {0,{0}};
    for (int i = 0; i < N; i++){
        scanf("%s %d",&letters[i].str,&letters[i].cost);
    }
c
    Sol BEST_sol = best(solution,N,0,letters);
    printf("%d\n",BEST_sol.cost);




   
    
    return 0;
}
