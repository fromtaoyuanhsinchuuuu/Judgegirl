#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXN 35
#define NAME 35

#define FIRST 0
#define LAST 1

typedef struct employee {
  int id;
  char first_name[NAME];
  char last_name[NAME];
  int boss_id;
} employee;

typedef struct pass_index{
    int count;
    int index_arr[MAXN];

} pass_index;

int search_index_from_name(employee people_arr[MAXN],char A_name[2][NAME],int n)
{
    for (int i = 0; i < n; i++){
        if (!strcmp(people_arr[i].first_name,A_name[FIRST]) && !strcmp(people_arr[i].last_name,A_name[LAST])){
            return i;
        }
    }
    printf("no found\n");
    return -1;
}

int search_index_from_ID(employee people_arr[MAXN],int n,int ID)
{
    for (int i = 0; i < n; i++){
        if (people_arr[i].id == ID){
            return i;
        }
    }
    printf("no found\n");
    return -1;
}

pass_index return_Index_count(int A_index,int B_index,employee people_arr[MAXN],int n,pass_index B_pass)
{
    /* 從B的bossID開始找，找到A，或是找到某人的bossID跟自己ID一樣就停*/
    int now_bossID = people_arr[B_index].boss_id;
    int now_ID = people_arr[B_index].id;
    int now_index = 0;
    // printf("now_bossID:%d now_ID:%d\n",now_bossID,now_ID);

    int count = 0;

    while (1){
        count++;
        now_index = search_index_from_ID(people_arr,n,now_bossID);
        now_bossID = people_arr[now_index].boss_id;
        now_ID = people_arr[now_index].id;
        // printf("now_bossID:%d now_ID:%d\n",now_bossID,now_ID);
        B_pass.index_arr[count - 1] = now_index;
        if (now_ID == now_bossID){
            // printf("nowID:%d nowbossID:%d\n",now_ID,now_bossID);
            B_pass.count = count;
            return B_pass;
        }
        else if (search_index_from_ID(people_arr,n,now_bossID) == A_index){
            B_pass.index_arr[count] = A_index;
            B_pass.count = count + 1;
            return B_pass;
        }
    }
    printf("no_found\n");
    return B_pass;

}



int main(void)
{
    int n;
    scanf("%d",&n);

    employee people_arr[MAXN];
    for (int i = 0; i < n; i++){
        scanf("%d",&(people_arr[i].id));
        scanf("%s %s",people_arr[i].first_name,people_arr[i].last_name);
        scanf("%d",&(people_arr[i].boss_id));
    }
    // printf("%d %s %s %d",people_arr[0].id,people_arr[0].first_name,people_arr[0].last_name,people_arr[0].boss_id);
    int m;
    scanf("%d",&m);

    char A_name[2][NAME],B_name[2][NAME];
    int A_index = -1;
    int B_index = -1;

    for (int i = 0; i < m; i++){
        scanf("%s %s %s %s",A_name[FIRST],A_name[LAST],B_name[FIRST],B_name[LAST]);
        A_index = search_index_from_name(people_arr,A_name,n);
        B_index = search_index_from_name(people_arr,B_name,n);
        assert(A_index != -1 && B_index != -1);
        // printf("A_index:%d B_index:%d\n",A_index,B_index);

        pass_index B_pass = {0,{}};
        pass_index A_pass = {0,{}};
        B_pass = return_Index_count(A_index,B_index,people_arr,n,B_pass);
        A_pass = return_Index_count(B_index,A_index,people_arr,n,A_pass);

        bool if_cont = 1;
        while (if_cont){
            for (int i = 0; i < B_pass.count && if_cont; i++){
                if (B_pass.index_arr[i] == A_index){
                    printf("supervisor\n");
                    if_cont = 0;
                    break;
                }
            }
            for (int i = 0; i < A_pass.count && if_cont; i++){
                if (A_pass.index_arr[i] == B_index){
                    printf("subordinate\n");
                    if_cont = 0;
                    break;
                }
            }
            for (int i = 0; i < A_pass.count && if_cont; i++){
                for (int j = 0; j < B_pass.count; j++){
                    if (A_pass.index_arr[i] == B_pass.index_arr[j]){
                        printf("colleague\n");
                        if_cont = 0;
                    }
                }
            }
            if (if_cont){
                printf("unrelated\n");
            }
            break;
        }
        
    }
    
    return 0;
}
