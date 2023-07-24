#include <stdio.h>

int main()
{
    int k,L;
    scanf("%d%d",&k,&L);
    int n;
    int occupied_num = 0;
    int whether_to_change_line = 0;
    while (scanf("%d",&n) != EOF){
        if (n == 0){
            break;
        }
        int n_2 = n; // n_2 為了求n的位數而造的
        int n_mod_k = n%k; // 表需print的次數
        int digit_of_n = 1;
        while (n_2/10 > 0){
            n_2 /= 10;
            digit_of_n += 1;
        }
        if ((occupied_num + digit_of_n*n_mod_k) <= L){
            whether_to_change_line += 1;
            occupied_num += digit_of_n*n_mod_k;
            for ( int i = 0 ; i < n_mod_k ; i++){
                printf("%d",n);
            }
        }
        else{
            if (digit_of_n*n_mod_k <= L){
            printf("\n");
            occupied_num = 0;
            occupied_num += digit_of_n*n_mod_k;
            for ( int i = 0 ; i < n_mod_k ; i++){
                printf("%d",n);
            }
            }
            else{
                continue;
            }
        }
    }
    return 0;
}

