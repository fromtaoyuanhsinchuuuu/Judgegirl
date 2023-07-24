#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define FILENAME 80

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

void structure_into_html(Student *a,char HTML_file[FILENAME])
{
    sprintf(HTML_file, "<tr><td>%s</td><td>%d</td><td>%s</td><td>%f, %f, %f, %f</td><td>%d, %d, %d</td></tr>\n",a->name,a->id,a->phone,a->grade[0],a->grade[1],a->grade[2],a->grade[3],a->birth_year,a->birth_month,a->birth_day);
    return;
}

int main(void)
{
    char bin_file[FILENAME],HTML_file[FILENAME];
    scanf("%s %s",bin_file,HTML_file);

    FILE *fp = fopen(bin_file,"rb");
    assert(fp != NULL);

    FILE *fp2 = fopen(HTML_file,"wt");
    assert(fp2 != NULL);

    char non_sense_words[] = "<table border=\"1\">\n<tbody>\n";
    // printf("%s",non_sense_words);
    fputs(non_sense_words,fp2);
    // fwrite(non_sense_words,sizeof(non_sense_words),1,fp2);

    Student a;

    // printf("name:%s\n",a.name);
    while(fread(&a,sizeof(Student),1,fp) == 1){
        // fwrite(&a,sizeof(Student),1,fp2);
        sprintf(HTML_file, "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n",a.name,a.id,a.phone,a.grade[0],a.grade[1],a.grade[2],a.grade[3],a.birth_year,a.birth_month,a.birth_day);
        fputs(HTML_file,fp2);
        // fwrite(HTML_file,sizeof(HTML_file),1,fp2);
    }

    fclose(fp);
    char non_sense_word[] = "</tbody>\n</table>\n";

    // fwrite(non_sense_word,sizeof(non_sense_word),1,fp2);
    fputs(non_sense_word,fp2);
    // fwrite(non_sense_word,sizeof(non_sense_word),1,fp2);
    fclose(fp2);

    // printf("%s",non_sense_word);

    
    return 0;
}
