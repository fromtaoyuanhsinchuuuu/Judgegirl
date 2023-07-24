#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 500

int main(void)
{
    int grade;
    int grade_arr[MAXN];

    int n = 0;
    int total = 0;
    while (scanf("%d",&grade_arr[n]) != EOF){
        total += grade_arr[n];
        n++;
    }

    #ifdef HUNDRED
    for (int i = 0; i < n; i++){

        printf("%d ",grade_arr[i]);

    }
    printf("%0.1f\n",total / (float)n);
    #endif

    #ifdef APLUS
    float rank_grade_total = 0.0;
    int oneHundread_grade = 0;
    for (int i = 0; i < n; i++){
        int now_grade = grade_arr[i];
        if (now_grade >= 90 && now_grade <= 100){
            printf("A+ ");
            rank_grade_total += 4.3;
            oneHundread_grade += 95;
        }
        else if (now_grade >= 85 && now_grade <= 89){
            printf("A ");
            rank_grade_total += 4.0;
            oneHundread_grade += 87;
        }
        else if (now_grade >= 80 && now_grade <= 84){
            printf("A- ");
            rank_grade_total += 3.7;
            oneHundread_grade += 82;
            
        }else if (now_grade >= 77 && now_grade <= 79){
            printf("B+ ");
            rank_grade_total += 3.3;
            oneHundread_grade += 78;
            
        }else if (now_grade >= 73 && now_grade <= 76){
            printf("B ");
            rank_grade_total += 3.0;
            oneHundread_grade += 75;
            
        }else if (now_grade >= 70 && now_grade <= 72){
            printf("B- ");
            rank_grade_total += 2.7;
            oneHundread_grade += 70;
            
        }else if (now_grade >= 67 && now_grade <= 69){
            printf("C+ ");
            rank_grade_total += 2.3;
            oneHundread_grade += 68;
            
        }else if (now_grade >= 63 && now_grade <= 66){
            printf("C ");
            rank_grade_total += 2.0;
            oneHundread_grade += 65;
            
        }else if (now_grade >= 60 && now_grade <= 62){
            printf("C- ");
            rank_grade_total += 1.7;
            oneHundread_grade += 60;
            
        }else if (now_grade >= 0 && now_grade <= 59){
            printf("F ");
            rank_grade_total += 0;
            oneHundread_grade += 50;
        }

    }
    printf("%0.1f %0.1f",rank_grade_total / n,oneHundread_grade / (float)n);
    #endif
    
    return 0;
}
