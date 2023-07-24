#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c) != EOF){
        double root1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double root2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("%.20lf %.20lf\n",root1,root2);



    }
    
    
    return 0;
}
