#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define NAME 100
#define MAXLINE 1024

int main(void)
{
    char FileName[NAME];
    scanf("%s",FileName);

    FILE *fp = fopen(FileName,"r");
    assert(fp != NULL);

    int byte = 0;
    while (fgetc(fp) != EOF){
        byte++;
    }
    rewind(fp);
    int line_num = 0;
    char line[MAXLINE];
    while (fgets(line,MAXLINE,fp) != NULL){
        line_num++;
    }
    rewind(fp);
    int word = 1;
    char prev = fgetc(fp);
    bool prev_type = isalpha(prev);
    while (!feof(fp)){
        char now = fgetc(fp);
        bool now_type = isalpha(now);
        if (now_type != prev_type){
            word++;
        }
        prev = now;
        prev_type = now_type;
    }
    printf("%d %d %d\n",line_num,word/2,byte);
    fclose(fp);
    
    return 0;
}
