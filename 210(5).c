#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

inline bool satisfiesCondition(Person *person, char *field, char *opr, char *cmp) {
    if (field[0] == 'l') {
        if (strcmp(opr, "==") == 0) {
            return strcmp(person->lastname, cmp) == 0;
        } else if (strcmp(opr, "!=") == 0) {
            return strcmp(person->lastname, cmp) != 0;
        }
    } else if (field[0] == 'f') {
        if (strcmp(opr, "==") == 0) {
            return strcmp(person->firstname, cmp) == 0;
        } else if (strcmp(opr, "!=") == 0) {
            return strcmp(person->firstname, cmp) != 0;
        }

    } else if (field[0] == 'I') {
        if (strcmp(opr, "==") == 0) {
            return strcmp(person->ID, cmp) == 0;
        } else if (strcmp(opr, "!=") == 0) {
            return strcmp(person->ID, cmp) != 0;
        }

    } else if (field[0] == 's') {
        if (strcmp(opr, "==") == 0) {
            return person->salary == atoi(cmp);
        } else if (strcmp(opr, ">") == 0) {
            return person->salary > atoi(cmp);
        }
        else if (strcmp(opr, "<") == 0){
            return person->salary < atoi(cmp);
        }
        // ...
    } else if (field[0] == 'a') {
        if (strcmp(opr, "==") == 0) {
            return person->age == atoi(cmp);
        } else if (strcmp(opr, ">") == 0) {
            return person->age > atoi(cmp);
        }
        else if (strcmp(opr, "<") == 0){
            return person->age < atoi(cmp);
        }
    }

    return false;
}

inline void PrintAction(Person *person, char *action) {
    if (strcmp(action, "lastname") == 0) {
        printf("%s ", person->lastname);
    } else if (strcmp(action, "firstname") == 0) {
        printf("%s ", person->firstname);
    } else if (strcmp(action, "ID") == 0) {
        printf("%s ", person->ID);
    } else if (strcmp(action, "salary") == 0) {
        printf("%d ", person->salary);
    } else if (strcmp(action, "age") == 0) {
        printf("%d ", person->age);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    Person person_data[MAXN];

    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %d %d",
              person_data[i].lastname, person_data[i].firstname,
              person_data[i].ID, &person_data[i].salary, &person_data[i].age);
    }

    int m;
    scanf("%d", &m);

    char select[MAXNAME], actions[MAXACTION][MAXNAME];
    char field[MAXNAME], opr[MAXNAME], cmp[MAXNAME];

    for (int i = 0; i < m; i++) {
        scanf("%s", select);

        int action_num = 0;
        while (scanf("%s", actions[action_num]) == 1 && actions[action_num][0] != 'w') {
            action_num++;
        }

        scanf("%s %s %s", field, opr, cmp);

        for (int j = 0; j < n; j++) {
            if (satisfiesCondition(&person_data[j], field, opr, cmp)) {
                for (int k = 0; k < action_num; k++) {
                    PrintAction(&person_data[j], actions[k]);
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}
