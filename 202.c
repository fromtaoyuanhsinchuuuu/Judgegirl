#include <stdio.h>

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g); 
    b = (a>0?a*c+b:a*c-b);
    f = (e>0?e*g+f:e*g-f);
    int c_new = c;
    int g_new = g;
    int h = 0;
    while ((c_new % g_new) != 0 )         
    {
        int temp =  g_new;
        g_new = c_new % g_new;
        c_new = temp;
    }
    int gcd_c_and_g = g_new;
    int i;
    int j = c*g/gcd_c_and_g; // j為最小公倍數
    switch (d)
    {
    case 0:{
        i = (b*g)/gcd_c_and_g + (f*c)/gcd_c_and_g;
        break;
    }
    case 1:{
        i = (b*g)/gcd_c_and_g - (f*c)/gcd_c_and_g;
        break;
    }
    case 2:{
        i = b * f;
        j = g*c;
        break;
    }
    case 3:{
        i = b * g;
        j = f * c;
        break;
    }
    default:
        break;
    }
    h += i/j;
    i %= j;
    if (i == 0){
        printf("%d\n%d\n%d",h,i,1);
    }
    else{
        int i_new = i;
        int j_new = j;
        while ( (i_new % j_new) != 0)
        {
            int temp =  j_new;
            j_new = i_new % j_new;
            i_new = temp;
        }
        j /= j_new;
        i /= j_new;
        if(i<0 && j<0){
        printf("%d\n%d\n%d",h,-i,-j);
        }
        else if(i<0 && j>0){
           printf("%d\n%d\n%d",h,-i,j);
        }
        else if (i>0 && j<0){
           printf("%d\n%d\n%d",h,i,-j);
        }
        else{
            printf("%d\n%d\n%d",h,i,j);
        }
    }
    return 0;
}

