#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXNAME 90
#define MAXN 50
#define MAXACTION 10

typedef struct person 
{
    char lastname[MAXNAME];
    char firstname[MAXNAME];
    char ID[MAXNAME];
    int salary;
    int age;

} Person;

void operation(char *cmp1, char *opr, char *cmp2, bool *result, Person *persondata, int person_num)
{
    if (cmp1[0] == 'l'){
        if (opr[0] == '='){
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].lastname,cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].lastname,cmp2)){
                    result[i] = 0;
                }
                else{
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 'f'){
        if (opr[0] == '='){
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].firstname,cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].firstname,cmp2)){
                    result[i] = 0;
                }
                else{
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 'I'){
        if (opr[0] == '='){
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].ID,cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp(persondata[i].ID,cmp2)){
                    result[i] = 0;
                }
                else{
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 's'){
        if (opr[0] == '='){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].salary == atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (opr[0] == '>'){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].salary > atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (opr[0] == '<'){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].salary < atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
    }
    else{
        if (opr[0] == '='){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].age == atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (opr[0] == '>'){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].age > atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (opr[0] == '<'){
            for (int i = 0; i < person_num; i++){
                if (persondata[i].age < atoi(cmp2)){
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
    }
    
}

void PrintAction(Person personname,char aciton[])
{
    if (aciton[0] == 'l'){
        printf("%s",personname.lastname);
    }
    else if (aciton[0] == 'f'){
        printf("%s",personname.firstname);
    }
    else if (aciton[0] == 'I'){
        printf("%s",personname.ID);
    }
    else if (aciton[0] == 's'){
        printf("%d",personname.salary);
    }
    else{
        printf("%d",personname.age);
    }
    return;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    Person person_data[MAXN];

    for (int i = 0; i < n; i++){
        scanf("%s",(person_data+i)->lastname);
        scanf("%s",(person_data+i)->firstname);
        scanf("%s",(person_data+i)->ID);
        scanf("%d %d",&((person_data+i)->salary),&((person_data+i)->age));
    }
    // printf("%s",(person_data+3)->ID);

    int m;
    scanf("%d",&m);

    int action_num;
    char action_arr[MAXACTION][MAXNAME];
    char action[MAXNAME];
    char select[MAXN];
    char cmp1[MAXNAME];
    char opr[MAXNAME];
    char cmp2[MAXNAME];
    bool result[MAXN] = {};

    for (int i = 0; i < m; i++){

        scanf("%s",select);

        action_num = 0;
        while (1){
            scanf("%s",action_arr[action_num]);
            if (action_arr[action_num][0] == 'w'){
                break;
            }
            action_num++;
        }

        scanf("%s",cmp1);

        scanf("%s",opr);

        scanf("%s",cmp2);

        operation(cmp1,opr,cmp2,result,person_data,n);

        for (int j = 0; j < n; j++){
            if (result[j]){
                for (int k = 0; k < action_num; k++){
                    PrintAction(person_data[j],action_arr[k]);
                    printf("%c"," \n"[k == action_num - 1]);
                }
                
            }
        }
    }
    // printf("end");
    
    return 0;
}
