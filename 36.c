#include <stdio.h>
#include <stdbool.h>

bool leap_year(int Y)
{
    if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    int Y,M,D;
    scanf("%d%d%d",&Y,&M,&D);
    if (!(M > 12 || M < 1 || D > 6 || D < 0)){
            printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
            for (int i = 0 ; i < D ; i++){
                printf("   ");
            }
            int Max_day;
            switch (M)
            {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    Max_day = 31;
                    break;
                case 4:case 6:case 9:case 11:
                    Max_day = 30;
                    break;
                case 2:
                    if (leap_year(Y)){
                        Max_day = 29;
                    }
                    else{
                        Max_day = 28;
                    }
                    break;
            }

            for (int date = 1 ; date <= Max_day ; date++){
                if (D < 6 && date != Max_day){
                    printf("%3d",date);
                    D++;
                }
                else if (D == 6 && date != Max_day){
                    D = 0;
                    printf("%3d\n",date);
                }
                else if ( date == Max_day){
                    printf("%3d\n",date);
                }
            }
            printf("=====================\n");
    }
    else{
        printf("invalid\n");
    }
    
    return 0;
}
