#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 32
#define MAXCOl 128
#define MAXN 300

// #include "10056.h"

typedef struct {
    char Name[MAXSTR];
    int score[MAXCOl];
} Person_data;

typedef struct {
    int dim_n;
    int person_num;
    Person_data Person_datas[MAXN];
} ExamTable;

int change(Person_data Person_data_1,Person_data Person_data_2,int order[MAXCOl],int Col_num)
{
    for (int i = 0; i < Col_num; i++){
        int cmp_index = order[i];
        if (Person_data_1.score[cmp_index] - Person_data_2.score[cmp_index]){
            return -(Person_data_1.score[cmp_index] - Person_data_2.score[cmp_index]);
        }
    }

    return strcmp(Person_data_1.Name,Person_data_2.Name);


}

void bubble_sort(Person_data Person_datas[MAXN],int Person_num,int Col_num,int order[MAXCOl])
{
    for (int i = 0; i < Person_num; i++){
        for (int j = 0; j < Person_num - 1; j++){
            if (change(Person_datas[j],Person_datas[j + 1],order,Col_num) > 0){
                Person_data temp = Person_datas[j];
                Person_datas[j] = Person_datas[j + 1];
                Person_datas[j + 1] = temp;
            }
        }
    }
    return;
}


void init(ExamTable *self, int n)
{
    self->dim_n = n;
    self->person_num = 0;
    return;
}

void addrow(ExamTable *self, char *name, int score[])
{
    strcpy(self->Person_datas[self->person_num].Name,name);
    for (int i = 0; i < self->dim_n; i++){
        self->Person_datas[self->person_num].score[i] = score[i];
    }
    self->person_num++;
    // printf("%d",self->person_num);
    return;

}

void print(ExamTable *self, int order[])
{
    bubble_sort(self->Person_datas,self->person_num,self->dim_n,order);

    printf("----- table begin -----\n");

    for (int i = 0; i < self->person_num; i++){
        printf("%s",self->Person_datas[i].Name);
        for (int j = 0; j < self->dim_n; j++){
            printf(", %d",self->Person_datas[i].score[j]);
        }
        printf("\n");
    }

    printf("----- end         -----\n");



}

int main(void)
{
    static ExamTable examtables[MAXN];

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int col;
        scanf("%d",&col);
        init(&examtables[i],col);
    }

    int q;
    scanf("%d",&q);

    for (int i = 0; i < q; i++){
        int cmd;
        scanf("%d",&cmd);

        if (cmd == 1){
            int index;
            scanf("%d",&index);
            char Name[MAXSTR];
            scanf("%s",Name);

            int score[128];
            for (int j = 0; j < examtables[index].dim_n; j++){
                scanf("%d",score + j);
            }
            addrow(&examtables[index],Name,score);
        }

        else if (cmd == 2){
            int index;
            scanf("%d",&index);

            int order[128];
            for (int j = 0; j < examtables[index].dim_n; j++){
                scanf("%d",&order[j]);
            }
            print(&examtables[index],order);
        }
    }
   
    
    return 0;
}
