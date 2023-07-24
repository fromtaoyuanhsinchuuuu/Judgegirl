#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXN 35
#define NAME 32

#define FIRST 0
#define LAST 1

typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;

typedef struct pass_index{
    int count;
    int index_arr[MAXN];

} pass_index;

pass_index return_Index_count(int A_index,int B_index,Employee people_arr[MAXN],int n,pass_index B_pass)
{
    /* 從B的bossID開始找，找到A，或是找到某人的bossID跟自己ID一樣就停*/
    // int now_bossID = people_arr[B_index].boss_id;
    // int now_ID = people_arr[B_index].id;
    int now_index = 0;
    // printf("now_bossID:%d now_ID:%d\n",now_bossID,now_ID);

    int count = 0;
}

 

int search_index_from_name(Employee people_arr[MAXN],char A_firstname[NAME],char A_lastname[NAME],int n)
{
    for (int i = 0; i < n; i++){
        if (!strcmp(people_arr[i].first_name,A_firstname) && !strcmp(people_arr[i].last_name,A_lastname)){
            return i;
        }
    }
    printf("no found\n");
    return -1;
}

typedef struct pass_name{
    char name_arr[MAXN][2][NAME];
    int count;
} pass_name;

bool same_name(char nowname_first[NAME],char nowname_last[NAME],char bossname_first[NAME],char bossname_last[NAME]){
    if (!strcmp(nowname_first,bossname_first) && !strcmp(nowname_last,bossname_last)){
        return 1;
    }
    return 0;
}

pass_name return_passName_func(Employee *employee,pass_name pass_name1)
{
    Employee *now_employee = employee;
    Employee *now_boss = employee->boss;
    char now_name[2][NAME];
    char boss_name[2][NAME];
    int count = 0;
    while (1){
        if (same_name(now_employee->first_name,now_employee->last_name,now_boss->first_name,now_boss->last_name)){
            strcpy(pass_name1.name_arr[count][FIRST],now_employee->first_name);
            strcpy(pass_name1.name_arr[count][LAST],now_employee->last_name);
            count++;
            pass_name1.count = count;
            return pass_name1;
        }
        else{
            strcpy(pass_name1.name_arr[count][FIRST],now_employee->first_name);
            strcpy(pass_name1.name_arr[count][LAST],now_employee->last_name);
            now_employee = now_boss;
            now_boss = now_employee->boss;
            count++;
        }

    }
    return pass_name1;
}

bool judge_boss(int count,char name_arr[MAXN][2][NAME],char boss_first[NAME],char boss_last[NAME])
{
    for (int i = 0; i < count; i++){
        if (same_name(name_arr[i][FIRST],name_arr[i][LAST],boss_first,boss_last)){
            return 1;
        }
    }
    return 0;
}


int relation(Employee *employee1, Employee *employee2) {
    /* 把2沿途經過的boss記下來 */
    pass_name pass_name1 = return_passName_func(employee1,pass_name1);
    pass_name pass_name2 = return_passName_func(employee2,pass_name2);
    if (judge_boss(pass_name1.count,pass_name1.name_arr,employee2->first_name,employee2->last_name)){
        return 1;
    }
    else if (judge_boss(pass_name2.count,pass_name2.name_arr,employee1->first_name,employee1->last_name)){
        return 2;
    }
    for (int i = 0; i < pass_name1.count; i++){
        for (int j = 0; j < pass_name2.count; j++){
            if (same_name(pass_name1.name_arr[i][FIRST],pass_name1.name_arr[i][LAST],pass_name2.name_arr[j][FIRST],pass_name2.name_arr[j][LAST])){
                return 3;
            }
        }
    }
    return 4;
}

typedef struct me {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} employee;
 
void readName(employee *e) {
    scanf("%s %s", e->first_name, e->last_name);
}
 
int nameToIndex(employee *e, employee A[], int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(A[i].first_name, e->first_name) &&
            !strcmp(A[i].last_name, e->last_name))
            return i;
    }
    return -1;
}

int main() {
    int n, m;
    employee A[32];
    Employee B[32];
    const char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i].id);
            readName(&A[i]);
            scanf("%d", &A[i].boss_id);
        }
 
        for (int i = 0; i < n; i++) {
            strcpy(B[i].first_name, A[i].first_name);
            strcpy(B[i].last_name, A[i].last_name);
            B[i].boss = NULL;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i].boss_id == A[j].id)
                    B[i].boss = &B[j];
            }
        }
        scanf("%d", &m);
        employee x, y;
        for (int i = 0; i < m; i++) {
            readName(&x);
            readName(&y);
            int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
            assert(ix != -1);
            assert(iy != -1);
            printf("%d\n", relation(&B[ix], &B[iy]));
        }
    }
    return 0;
}
