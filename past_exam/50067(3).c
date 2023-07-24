#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 16

int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);

    FILE *fp;
    fp = fopen(str,"rb");
    assert(fp != NULL);

    int type,parameter;
    while (!feof(fp)){
        fread(&type,sizeof(int),1,fp);

    //     // printf("type:%d\n",type);
        if (type == 0){
            fread(&parameter,sizeof(int),1,fp);
            printf("%d",parameter);
        }
        else if (type == 1){
            char ch;
            for(int i = 0; i < 4; i++){
                fread(&ch,sizeof(char),1,fp);
                if (ch == '\0'){
                    break;
                }
                printf("%c",ch);
            }
        }
        else if (type == 2){
            fread(&parameter,sizeof(int),1,fp);
            char ch;
            while (1){
                fread(&ch,sizeof(char),1,fp);
                if (ch == '\0'){
                    break;
                }
                printf("%c",ch);
            }
        }
        else if (type == 3){
            fread(&(parameter),sizeof(int),1,fp);
            fseek(fp,-(sizeof(int) * 2) + parameter,SEEK_CUR);
        }
        else if (type == 4){
            fread(&(parameter),sizeof(int),1,fp);
            fseek(fp,parameter,SEEK_SET);
        }
        else if (type == 5){
            fread(&(parameter),sizeof(int),1,fp);
            fseek(fp,parameter,SEEK_END);
        }
        else{
            printf("Seek end\n");
            break;
        }
        // printf("parameter:%d\n",parameter);

    }
    
    return 0;
}
