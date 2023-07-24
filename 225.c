#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 10000
#define MAXNAME 32

typedef struct  {
    unsigned int id;
    char name[32];
} Person;

typedef struct  {
    unsigned id1;
    unsigned id2;
} Friend;

int main(void)
{
    Person persons[MAXN];
    Friend friends_arr[MAXN];

    FILE *fp = fopen("friends","rb");
    assert(fp != NULL);

    int P;
    fread(&P,sizeof(int),1,fp);

    for (int i = 0; i < P; i++){
        fread(&persons[i],sizeof(Person),1,fp);
    }

    int F;
    fread(&F,sizeof(int),1,fp);

    for (int i = 0; i < F; i++){
        fread(&friends_arr[i],sizeof(Friend),1,fp);
    }

    char name1[MAXNAME];
    char name2[MAXNAME];

    int id1,id2;
    while (scanf("%s %s",name1,name2) == 2){
        for (int i = 0; i < P; i++){
            if (!strcmp(name1,persons[i].name)){
                id1 = persons[i].id;
                break;
            }
        }

        for (int i = 0; i < P; i++){
            if (!strcmp(name2,persons[i].name)){
                id2 = persons[i].id;
                break;
            }
        }

        bool find = 0;
        for (int i = 0; i < F; i++){
            if (friends_arr[i].id1 == id1 && friends_arr[i].id2 == id2 || friends_arr[i].id2 == id1 && friends_arr[i].id1 == id2){
                printf("yes\n");
                find = 1;
                break;
            }
        }

        if (!find){
            printf("no\n");
        }

    }




    
    
    return 0;
}
