#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int main(void)
{
    FILE *fp = fopen("test","rb");
    assert (fp != NULL);

    FILE *fp2 = fopen("test.enc","wb"); 
    assert (fp2 != NULL);

    
    int key;
    scanf("%d",&key);

    char n;
    while (fread(&n,1,1,fp) != 0){
        // printf("n:%c",n);
        n ^= key;
        fwrite(&n,1,1,fp2);
    }
    fclose(fp);
    fclose(fp2);
                                      
    // fscanf(fp,"%d",stdout);  
    
    return 0;
}
