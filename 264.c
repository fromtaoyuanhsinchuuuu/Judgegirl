#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXSTRING 200
#define NBYTE 4
#define NUMBYTE 2
#define ARRSIZE 70000

int main(void)
{
    char file_name[MAXSTRING];
    scanf("%s",file_name);

    FILE *fp = fopen(file_name,"rb");
    assert (fp != NULL);

    int n;
    fread(&n,NBYTE,1,fp);

    // fclose(fp);
    // printf("n:%d\n",n);

    int count[ARRSIZE] = {};

    short int num;
    for (int i = 0; i < n; i++){
        fread(&num,NUMBYTE,1,fp);
        // printf("num:%d\n",num);
        count[num + 32768]++;
    }

    fclose(fp);

    int max = 0;
    int ans = 0;
    for (int i = 0; i < ARRSIZE; i++){
        if (max <= count[i]){
            max = count[i];
            ans  = i - 32768;
        }
    }
    printf("%d\n%d",ans,max);

    // int time = (n[0] << 24) + (n[1] << 16) + (n[2] << 8) + n[3];
    // printf("%d %d %d %d\n",n[0],n[1],n[2],n[3]);
    // printf("time:%d\n",time);

    



    
    
    return 0;
}
