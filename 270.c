#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXNAME 8
#define MAXN 100
#define MAXLINE 1000
#define MAXLEN 50

typedef struct {
    char Name[MAXNAME];
    int value;
} Var_Name_Value;

int from_name_find_VAR_index(char opd[MAXNAME],Var_Name_Value Var[MAXN],int n)
{
    for (int i = 0; i < n; i++){
        if (!strcmp(opd,Var[i].Name)){
            return i;
        }
    }
    assert(0);
}

void processIF(char* line,Var_Name_Value Var[MAXN],int n,int *line_num)
{
    char opd1[MAXNAME],opr[MAXNAME],opd2[MAXNAME];
    strcpy(opd1,line + 3);
    strcpy(opr,line + 3 + strlen(opd1) + 1);
    strcpy(opd2,line + 3 + strlen(opd1) + 1 + strlen(opr) + 1);
    int val1 = Var[from_name_find_VAR_index(opd1,Var,n)].value;
    int val2 = Var[from_name_find_VAR_index(opd2,Var,n)].value;

    bool state_ment;
    if (!strcmp(opr,"==")){
        state_ment = (val1 == val2);
    }
    else if (!strcmp(opr,"!=")){
        state_ment = (val1 != val2);
    }
    else if (!strcmp(opr,">")){
        state_ment = (val1 > val2);
    }
    else if (!strcmp(opr,"<")){
        state_ment = (val1 < val2);
    }
    else if (!strcmp(opr,">=")){
        state_ment = (val1 >= val2);
    }
    else if (!strcmp(opr,"<=")){
        state_ment = (val1 <= val2);
    }

    char linenum[MAXNAME];
    if (state_ment){
        strcpy(linenum,line + 3 + strlen(opd1) + 1 + strlen(opr) + 1 + 1 + strlen(opd2) + 4 + 1);
        *line_num = atoi(linenum);
        return;
    }
    (*line_num)++;
    return;
}

void processGOTO(char *line,int *line_num)
{
    char linenum[MAXN];
    strcpy(linenum,line + 5);
    *line_num = atoi(linenum);
    return;

}

void processAssign(char *line,Var_Name_Value Var[MAXN],int n)
{
    char variable[MAXNAME];
    strcpy(variable,line);
    char var1[MAXNAME],opr[MAXNAME],var2[MAXNAME];
    strcpy(var1,line + strlen(variable) + 1 + 2);
    strcpy(opr,line + strlen(variable) + 3 + 1 + strlen(var1));
    strcpy(var2,line + strlen(variable) + 3 + 1 + strlen(var1) + 1 + strlen(opr));
    var2[strlen(var2)] = '\0';

    if (!strcmp(opr,"+")){
        Var[from_name_find_VAR_index(variable,Var,n)].value = Var[from_name_find_VAR_index(var1,Var,n)].value + Var[from_name_find_VAR_index(var2,Var,n)].value;
    }
    else if (!strcmp(opr,"-")){
        Var[from_name_find_VAR_index(variable,Var,n)].value = Var[from_name_find_VAR_index(var1,Var,n)].value - Var[from_name_find_VAR_index(var2,Var,n)].value;
    }
    else if (!strcmp(opr,"*")){
        Var[from_name_find_VAR_index(variable,Var,n)].value = Var[from_name_find_VAR_index(var1,Var,n)].value * Var[from_name_find_VAR_index(var2,Var,n)].value;
    }
    else if (!strcmp(opr,"/")){
        Var[from_name_find_VAR_index(variable,Var,n)].value = Var[from_name_find_VAR_index(var1,Var,n)].value / Var[from_name_find_VAR_index(var2,Var,n)].value;
    }
    else{
        Var[from_name_find_VAR_index(variable,Var,n)].value = Var[from_name_find_VAR_index(var1,Var,n)].value % Var[from_name_find_VAR_index(var2,Var,n)].value;
    }
    return;
}

void processPrint(char *line,Var_Name_Value Var[MAXN],int n)
{
    printf("%d\n",Var[from_name_find_VAR_index(line + 6,Var,n)].value);

}

int main(void)
{
    /* read var */
    char str[MAXNAME];
    Var_Name_Value Var[MAXN];

    int n = 0;
    while (1){
        scanf("%s",str);
        if (!strcmp(str,"END")){
            break;
        }
        int value;
        char assign[MAXNAME];
        scanf(" %s %d",assign,&value);
        strcpy(Var[n].Name,str);
        Var[n].value = value;
        n++;
    }

    /* store code */
    int line = 0;
    char code[MAXLINE][MAXLEN];
    char *codePtr[MAXLINE];

    while (fgets(code[line],MAXLEN,stdin) != NULL){
        codePtr[line] = code[line];
        line++;
    }
    line--;
    
    /* init Code */
    for (int i = 1; i <= line; i++){
        int len = strlen(codePtr[i]);
        for (int j = 0; j <= len; j++){
            if (*(codePtr[i] + j) == ' ' || *(codePtr[i] + j) == '\n'){
                *(codePtr[i] + j) = '\0';
            }
        }
    }

    int nowline = 1;
    while (strcmp(codePtr[nowline],"STOP")){
        // printf("nowline:%d\n",nowline);
        if (!strcmp(codePtr[nowline],"IF")){
            processIF(codePtr[nowline],Var,n,&nowline);
            continue;
        }
        else if (!strcmp(codePtr[nowline],"GOTO")){
            processGOTO(codePtr[nowline],&nowline);
        }
        else if (!strcmp(codePtr[nowline],"PRINT")){
            processPrint(codePtr[nowline],Var,n);
            nowline++;
            continue;
        }
        else{
            processAssign(codePtr[nowline],Var,n);
            nowline++;
        }
    }
    return 0;
}
