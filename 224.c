#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

 
struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;

typedef struct traverse{

    Employee* traverse_arr[35];
    int count;

}traverse;
 
Employee* find_employee_by_id( Employee *set, int n, int id )
{
    for (int i = 0; i < n; i++){
        if (id == set[i].id){
            return  &(set[i]);
        }
    }

}

Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name )
{
    for (int i = 0; i < n; i++){
        if (!strcmp(set[i].first_name,first_name) && !(strcmp(set[i].last_name,last_name))){
            return &set[i];
        }
    }

}

Employee* find_root_boss( Employee *set, int n, Employee *employee )
{
    printf("我他媽根本沒用到這函式==");

}

traverse trav_func(Employee *A, Employee *set,int n)
{
    traverse A_trav;
    A_trav.traverse_arr[0] = A;
    Employee *nowEmployee = A;
    Employee *nowBoss = find_employee_by_id(set,n,A->boss_id);
    int index = 1;
    while (nowEmployee != nowBoss){
        A_trav.traverse_arr[index] = nowBoss;
        nowEmployee = nowBoss;
        nowBoss = find_employee_by_id(set,n,nowEmployee->boss_id);
        index++;
    }

    A_trav.count = index;
    return A_trav;

}

int check_relationship(Employee *set, int n, Employee *A, Employee *B)
{
    traverse A_trav = trav_func(A,set,n);
    traverse B_trav = trav_func(B,set,n);

    /* check surbordinate */
    for (int i = 0; i < B_trav.count; i++){
        if (B_trav.traverse_arr[i] == A){
            return 2;

        }
    }

    /* check supervisor */
    for (int i = 0; i < A_trav.count; i++){
        if (A_trav.traverse_arr[i] == B){
            return 1;
        }
    }

    /* check colleague */
    for (int i = 0; i < A_trav.count; i++){
        for (int j = 0; j < B_trav.count; j++){
            if (A_trav.traverse_arr[i] == B_trav.traverse_arr[j]){
                return 3;
            }
        }
    }
    return 0;
}
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A); 
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
 
        scanf("%s %s", first_name_B, last_name_B); 
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
 
        type = check_relationship(set, n, A, B);
        // printf("aasdasd");
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
        // printf("dick");
    }
    free_storage(&set);
    return 0;
}