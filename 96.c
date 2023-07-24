#include <stdio.h>

int main()
{
    double const pi = 3.1415926;
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double A = 0.75 * pi * c * c;
    A += (c-b > 0)? 0.25 * pi * (c-b) * (c-b) : 0;
    A += (c-a > 0)? 0.25 * pi * (c-a) * (c-a) : 0;
    printf("%f",A);
    return 0;
}
