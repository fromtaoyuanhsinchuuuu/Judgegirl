#include <stdio.h>

int main(){
    int a,b,c,d;
    int size = 0;   // TLE
    while (scanf("%d%d%d%d",&a,&b,&c,&d) != EOF)
    {
        size += 1;
        int lcm = a;
        while (lcm%b != 0 || lcm%c != 0 || lcm%d != 0){
            lcm += a;
        }
        printf("%d\n",lcm/a);
    }
    return 0;
}