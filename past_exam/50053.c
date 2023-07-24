#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 52
#define MAXN 100

typedef struct {
    char author[MAXSTRING];
    char book[MAXSTRING];
    int selling;
} Author_and_book;


int main(void)
{
    Author_and_book data_arr[MAXN];
    int n;
    scanf("%d",&n);
    char author[MAXSTRING];
    char book[MAXSTRING]; 
    for (int i = 0; i < n; i++){
        scanf("%s %s ",data_arr[i].author,data_arr[i].book);
    }
    int selling;
    for (int i = 0; i < n; i++){
        scanf("%s %d",book,&selling);
        for (int i = 0; i < n; i++){
            if (!strcmp(data_arr[i].book,book)){
                data_arr[i].selling = selling;
                break;
            }
        }
    }

    int max_selling = data_arr[0].selling;
    char ans_author[MAXSTRING];
    char now_author[MAXSTRING];
    strcpy(ans_author,data_arr[0].author);
    for (int i = 0; i < n; i++){
        strcpy(now_author,data_arr[i].author);
        int selling = 0;
        for (int j = 0; j < n; j++){
            if (!strcmp(data_arr[j].author,now_author)){
                selling += data_arr[j].selling;
            }
        }
        if (selling > max_selling || selling == max_selling && strcmp(now_author,ans_author) < 0){
            strcpy(ans_author,now_author);
            max_selling = selling;
        }

    }

    printf("%s %d\n",ans_author,max_selling);
    
    return 0;
}
