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

bool visited[MAXN] = {};
 
int City_Grid(City *capital)
{
    if (capital == NULL || visited[capital->label]) {
        return 0;
    }

    City *N_city = capital->north;
    City *E_city = capital->east;

    bool find = false;
    if (N_city != NULL && E_city != NULL && N_city->east != NULL && E_city->north != NULL) {
        if (N_city->east->label == E_city->north->label) {
            find = true;
        }
    }

    visited[capital->label] = true;

    int count = 0;
    if (find) {
        count = 1;
    }

    if (N_city != NULL) {
        count += City_Grid(N_city->east);
    }

    if (E_city != NULL) {
        count += City_Grid(E_city->north);
    }

    return count;
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
