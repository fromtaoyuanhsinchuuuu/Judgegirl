#include <stdio.h>
int main(){
    int a[10];
    printf("%ld\n",sizeof(a[0]));
    printf("%d\n",a);
    printf("%d\n",&(a[0]));
    for (int i = 0 ; i < 10 ; i++){
        printf("%p\n",&(a[i]));
    }
}