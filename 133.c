#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

struct string_count {
  char seen[80];
  int count;
};

int cmp(const void *a, const void *b)
{
    struct string_count* ptr1 = (struct string_count*)a;
    struct string_count* ptr2 = (struct string_count*)b;

    if (ptr1->count > ptr2->count){
        return 1;
    }
    else if (ptr1->count < ptr2 ->count){
        return -1;
    }
    else if (ptr1->count == ptr2->count && strcmp(ptr1->seen,ptr2->seen) > 0){
        return 1;
    }
    return -1;
    

}

int compare_and_add(char *string, struct string_count strings[]) 
{
    int i = 0;
    while (strings[i].count != 0){
        if (!strcmp(strings[i].seen,string)){
            strings[i].count++;
            return 1;
        }
        i++;
    }
    strings[i].count = 1;
    strcpy(strings[i].seen,string);
    return 0;

}

void sort(struct string_count strings[]) 
{
    int count = 0;
    while (strings[count].count != 0){
        count++;
    }
    qsort(strings,count,sizeof(struct string_count),cmp);
    return;
}

void print(struct string_count strings[])
{
    int count = 0;
    while (strings[count].count != 0){
        printf("%d %s\n",strings[count].count,strings[count].seen);
        count++;
    }
    return;

}

int main() {
        struct string_count strings[20];
        int i;
        for( i=0 ; i<20 ; i++ )
                strings[i].count = 0;
        compare_and_add( "This", strings );
        compare_and_add( "is", strings );
        compare_and_add( "an", strings );
        compare_and_add( "apple,", strings );
        compare_and_add( "and", strings );
        compare_and_add( "this", strings );
        compare_and_add( "is", strings );
        compare_and_add( "a", strings );
        compare_and_add( "book.", strings );
        sort( strings );
        print( strings );
        return 0;
}