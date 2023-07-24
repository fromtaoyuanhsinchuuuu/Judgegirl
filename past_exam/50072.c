#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 10000

typedef struct City {
    int label;
    struct City *east, *north;
} City; 

int City_Grid_V2(City *capital, int visted[])
{
    City *cur_city = capital;

    if (cur_city == NULL || visted[cur_city->label]){
        return 0;
    }

    City *N_city = cur_city->north;
    City *E_city = cur_city->east;



    // if (N_city != NULL && E_city != NULL){
    //     printf("N:%d E:%d\n",N_city->label, E_city->label);
    // }

    bool find = 0;
    if (N_city != NULL && E_city != NULL && N_city->east != NULL && E_city->north != NULL){
        // printf("N_E:%d E_N:%d\n",N_city->east->label, E_city->north->label);
        assert(N_city->east->label == E_city->north->label);
        find = 1;
    }

    visted[cur_city->label] = 1;

    if (find){
        // printf("cur:%d\n",cur_city->label);
        return 1 + City_Grid_V2(N_city, visted) + City_Grid_V2(E_city, visted);
    }

    else {
        return City_Grid_V2(N_city, visted) + City_Grid_V2(E_city, visted);
    }

    printf("falut!\n");
    exit(0);

    return 0;
}

int City_Grid(City *capital)
{
    int visited[MAXN] = {};
    return City_Grid_V2(capital, visited);
}

City* newNode(int label, City *E, City *N) {
    City *u = (City *) malloc(sizeof(City));
    u->label = label, u->east = E, u->north = N;
    return u;
}

int main() {
    City *capital = newNode(0, NULL, NULL);
    capital->east = newNode(1, newNode(3, NULL, NULL), NULL);
    capital->north = newNode(2, NULL, newNode(5, NULL, NULL));
    capital->east->north = capital->north->east = newNode(4, NULL, NULL);
 
    City *temp = capital->east->north;
    temp->east = newNode(6, NULL, NULL);
    temp->north = newNode(7, NULL, NULL);
    temp->east->north = temp->north->east = newNode(8, NULL, NULL);
 
    printf("%d\n", City_Grid(capital));
    return 0;
}
 
