#include <stdio.h>

int main()
{
    int now_year,startday;
    scanf("%d%d",&now_year,&startday);
    int n;
    scanf("%d",&n);
    int M,D;
    int j;
    for (int i = 0 ; i < n ; i++){
        scanf("%d%d",&M,&D);
        if (M >= 13 || M <= 0){
            printf("-1\n");
        }
        else if (!(M >= 13 || M <= 0)){
            j = 0;
            switch (M)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if (!(D >= 1 && D <= 31)){
                        printf("-2\n");
                        j++;
                    }
                    break;
                
                case 4: case 6: case 9: case 11:
                    if (!(D >= 1 && D <= 30)){
                        printf("-2\n");
                        j++;
                    }
                    break;
                case 2:
                    if ((now_year % 4 == 0 && now_year % 100 != 0) || now_year % 400 == 0){
                        if (!(D >= 1 && D <= 29)){
                            printf("-2\n");
                            j++;
                        }
                    }
                    else{
                        if (!(D >= 1 && D <= 28)){
                            printf("-2\n");
                            j++;
                        }
                    }
                    break;
            }
            if (j == 0){
                int sum = ((M == 1)? D-1:D) + startday;
                switch (M-1)
                {
                    case 11:
                        sum += 30;
                    case 10:
                        sum += 31;
                    case 9:
                        sum += 30;
                    case 8:
                        sum += 31;
                    case 7:
                        sum += 31;
                    case 6:
                        sum += 30;
                    case 5:
                        sum += 31;
                    case 4:
                        sum += 30;
                    case 3:
                        sum += 31;
                    case 2:
                        if ((now_year % 4 == 0 && now_year % 100 != 0) || now_year % 400 == 0 ){
                            sum += 29;
                        }
                        else{
                            sum += 28;
                        }
                    case 1: 
                        sum += 30;
                    default:
                        break;
                }
                printf("%d\n",sum%7);
            }
        }
    }
    return 0;
}
