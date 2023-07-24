#include <stdio.h>

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    if ((a == e && b == f && g >= c) || d == 0){
        printf("0");
    }
    else if (d >= g){
        int h = d + e*f*g/(a*b);
        printf("%d",h);        
    }
    else{
        if (g >= c){
            int h = a*b*d/(a*b - e*f);
                if (h >= c){
                    printf("%d",c);
                }
                else{
                    printf("%d",h);
                }
        }
        else{
            if (a*b*d + e*f*g >= a*b*c){
                printf("%d",c);
            }
            else {
                int h = (a*b*d + e*f*g) / (a*b);
                printf("%d",h);
            }
        }
        
        }

    return 0;
    }

