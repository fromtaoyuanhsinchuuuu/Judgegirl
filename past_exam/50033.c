#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define AGE 1
#define ZIPCODE 2

#define MAXNAME 1000
#define MAXN 100000 
 
typedef struct account {
    int balance;
    int accountNum;
    int zipcode;
    int age;
} Account;

int cmp_zipcode(const void *a,const void *b)
{
    Account *ptr1 = (Account *)a;
    Account *ptr2 = (Account *)b;

    if (ptr1->zipcode > ptr2->zipcode){
        return 1;
    }
    else if (ptr1->zipcode < ptr2->zipcode){
        return -1;
    }
    return 0;

}

int cmp_age(const void *a,const void *b)
{
    Account *ptr1 = (Account *)a;
    Account *ptr2 = (Account *)b;

    if (ptr1->age > ptr2->age){
        return 1;
    }
    else if (ptr1->age < ptr2->age){
        return -1;
    }
    return 0;
}

int cmp_account(const void *a,const void *b)
{
    Account *ptr1 = (Account *)a;
    Account *ptr2 = (Account *)b;

    if (ptr1->accountNum > ptr2->accountNum){
        return 1;
    }
    else if (ptr1->accountNum < ptr2->accountNum){
        return -1;
    }
    return 0;
}
int main(void)
{
    char FileName[MAXNAME];
    scanf("%s",FileName);

    FILE *fp = fopen(FileName,"rb");
    assert(fp != NULL);

    Account accounts[MAXN];

    printf("account, age, zipcode, balance\n");
    int n = 0;

    while (fread(&accounts[n],sizeof(Account),1,fp) == 1){
        n++;
    }

    qsort(accounts,n,sizeof(Account),cmp_account);
    for (int i = 0; i < n; i++){
        printf("%d, %d, %d, %d\n",(accounts + i)->accountNum,(accounts + i)->age,(accounts + i)->zipcode,(accounts + i)->balance);
    }

    #if (SORTBY == ZIPCODE)
    qsort(accounts,n,sizeof(Account),cmp_zipcode);
    printf("zipcode, sum_balance\n");
    int prev_zipcode = -69;
    int balance = 0;
    for (int i = 0; i < n; i++){
        int now_zipcode = accounts[i].zipcode;
        if (now_zipcode != prev_zipcode && balance != 0){
            printf("%d, %d\n",prev_zipcode,balance);
            balance = accounts[i].balance;
        }
        else if (now_zipcode != prev_zipcode){
            assert(prev_zipcode == -69);
            balance = accounts[i].balance;

        }
        else if (now_zipcode == prev_zipcode){
            balance += accounts[i].balance;
           
        }
        if (i == n - 1){
            printf("%d, %d\n",now_zipcode,balance);
        }
        prev_zipcode = now_zipcode;

    }
    #endif  

    #if (SORTBY == AGE)
    qsort(accounts,n,sizeof(Account),cmp_age);
    printf("age, sum_balance\n");
    int prev_age = -69;
    int balance = 0;
    for (int i = 0; i < n; i++){
        int now_age = accounts[i].age;
        if (now_age != prev_age && balance != 0){
            printf("%d, %d\n",prev_age,balance);
            balance = accounts[i].balance;
        }
        else if (now_age != prev_age){
            assert(prev_age == -69);
            balance = accounts[i].balance;

        }
        else if (now_age == prev_age){
            balance += accounts[i].balance;
            
        }
        if (i == n - 1){
            printf("%d, %d\n",now_age,balance);
        }
        prev_age = now_age;

    }
    #endif







    
    
    return 0;
}
