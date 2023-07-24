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

void PrintAction(Person *personname,char aciton[])
{
    if (aciton[0] == 'l'){
        printf("%s",personname->lastname);
    }
    else if (aciton[0] == 'f'){
        printf("%s",personname->firstname);
    }
    else if (aciton[0] == 'I'){
        printf("%s",personname->ID);
    }
    else if (aciton[0] == 's'){
        printf("%d",personname->salary);
    }
    else{
        printf("%d",personname->age);
    }
    return;
} 

void operation(char cmp1[],char opr[],char cmp2[],bool result[],Person *persondata,int person_num,char action_arr[MAXACTION][MAXNAME],int action_num)
{
    if (cmp1[0] == 'l'){
        if (!strcmp(opr,"==")){
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->lastname,cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->lastname,cmp2)){
                    result[i] = 0;
                }
                else{
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 'f'){
        if (!strcmp(opr,"==")){
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->firstname,cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->firstname,cmp2)){
                    result[i] = 0;
                }
                else{
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 'I'){
        if (!strcmp(opr,"==")){
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->ID,cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else{
            for (int i = 0; i < person_num; i++){
                if (!strcmp((persondata+i)->ID,cmp2)){
                    result[i] = 0;
                }
                else{
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
            }
        }
    }
    else if (cmp1[0] == 's'){
        if (!strcmp(opr,"==")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->salary == atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (!strcmp(opr,">")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->salary > atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (!strcmp(opr,"<")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->salary < atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
    }
    else{
        if (!strcmp(opr,"==")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->age == atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (!strcmp(opr,">")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->age > atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
        else if (!strcmp(opr,"<")){
            for (int i = 0; i < person_num; i++){
                if ((persondata+i)->age < atoi(cmp2)){
                    for (int j = 0; j < action_num; j++){
                        PrintAction(persondata+i,action_arr[j]);
                        printf("%c"," \n"[j == action_num - 1]);
                    }
                    result[i] = 1;
                }
                else{
                    result[i] = 0;
                }
            }
        }
    }
    
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
    for (int i = 0; i < m; i++){

        char select[MAXN];
        scanf("%s",select);

        action_num = 0;
        char action_arr[MAXACTION][MAXNAME];
        while (1){
            char action[MAXNAME];
            scanf("%s",action);

            if (action[0] == 'w'){
                break;
            }
            else{
                strcpy(action_arr[action_num],action);
                action_num++;
            }
        }

        char cmp1[MAXNAME];
        scanf("%s",cmp1);

        char opr[MAXNAME];
        scanf("%s",opr);

        char cmp2[MAXNAME];
        scanf("%s",cmp2);

        bool result[MAXN];

        operation(cmp1,opr,cmp2,result,person_data,n,action_arr,action_num);

        // for (int j = 0; j < n; j++){
        //     if (result[j]){
        //         for (int k = 0; k < action_num; k++){
        //             PrintAction((person_data+j),action_arr[k]);
        //             printf("%c"," \n"[k == action_num - 1]);
        //         }
                
        //     }
        // }
    }
    
    return 0;
}
