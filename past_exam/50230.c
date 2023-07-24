#include <stdio.h>
#include <stdbool.h>
 
long long f_unction(long long k,long long S)
{
    long long C = (77 * k + 2222) % S;
    return C;
 
}
 
int main(void){
    long long S,C;
    scanf("%lld%lld",&S,&C);
    long long hash_table[S][C];
    long long n;
    for(long long i = 0 ; i < S ; i++){
        for (long long j = 0 ; j < C ; j++){
            hash_table[i][j] = 0;
        }
    }
 
 
    while (scanf("%lld",&n) != EOF){
        long long S_index = f_unction(n,S);
        for (long long C_index = 0 ; C_index < C ; C_index++){
            if (!(hash_table[S_index][C_index]) || hash_table[S_index][C_index] == n){
                if (hash_table[S_index][C_index] == n){
                    printf("%lld %lld\n",n,S_index);
                    for (int i = C_index ; i < C-1 ; i++){
                        hash_table[S_index][i] = hash_table[S_index][i+1];
                    }
                    hash_table[S_index][C-1] = 0;
                }
                else if (hash_table[S_index][C_index] == 0){
                    hash_table[S_index][C_index] = n;
                }
                break;
            }
        }
    }
    return 0;
}