#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100
#define MAXL 25


typedef struct {
    char book_title[MAXL], author[MAXL];
}BookAuthor;
 
typedef struct {
    char book_title[MAXL];
    int selling, date;
}BookSelling;

typedef struct {
    char book_title[MAXL], author[MAXL];
    int selling, date;
}BookInfo;

typedef struct {
    int num; // the number of BookInfo
    BookInfo books[MAXN];
}BookInfoList;

int cmp(const void *a, const void *b)
{
    BookInfo *ptr1 = (BookInfo *)a;
    BookInfo *ptr2 = (BookInfo *)b;

    if (strcmp(ptr1->book_title,ptr2->book_title)){
        return strcmp(ptr1->book_title,ptr2->book_title);
    }

    return (ptr1->date - ptr2->date);
}

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[])
{
    BookInfoList bookinfoList;
    bookinfoList.num = 0;
    for (int i = 0; i < M; i++){
        BookSelling nowSelling = sellingArr[i];
        for (int j = 0; j < N; j++){
            if(!strcmp(authorArr[j].book_title,nowSelling.book_title)){
                bookinfoList.books[bookinfoList.num].selling = nowSelling.selling;
                bookinfoList.books[bookinfoList.num].date = nowSelling.date;
                strcpy(bookinfoList.books[bookinfoList.num].author,authorArr[j].author);
                strcpy(bookinfoList.books[bookinfoList.num].book_title,nowSelling.book_title);
                bookinfoList.num++;
                break;
            }
        }
    }

    qsort(bookinfoList.books,bookinfoList.num,sizeof(BookInfo),cmp);

    return bookinfoList;

}

int main(){
    int N, M;
    BookAuthor authorArr[MAXN];
    BookSelling sellingArr[MAXN];
 
    assert(scanf("%d %d", &N, &M) == 2);
    for(int i = 0; i < N; i++)
        assert(scanf("%s %s", authorArr[i].book_title,
                              authorArr[i].author) == 2);
 
    for(int i = 0; i < M; i++)
        assert(scanf("%s %d %d", sellingArr[i].book_title,
                                 &sellingArr[i].selling,
                                 &sellingArr[i].date) == 3);
 
    BookInfoList result = merge(N, M, authorArr, sellingArr);
 
    for(int i = 0; i < result.num; i++)
        printf("%s %s %d %d\n", result.books[i].book_title,
                                result.books[i].author,
                                result.books[i].date, result.books[i].selling);
 
    return 0;
}
