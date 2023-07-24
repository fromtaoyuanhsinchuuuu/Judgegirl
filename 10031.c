#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 1000

typedef unsigned long long ull;

void reverse_str(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++){
        char c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
    }

    return;
}

void reverse_int(int str[],int len)
{

    for (int i = 0; i < len / 2; i++){
        // printf("change! index:%d index:%d\n",i,len - 1 - i);
        int c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
    }

    return;
}

int big_num_mul(char a[],char b[],int ret[])
{
    int a_len = strlen(a);
    int b_len = strlen(b);

    reverse_str(a);
    reverse_str(b);

    // printf("a:%s\n",a);
    // printf("b:%s\n",b);


    int ret_index = 0;
    int ret_num;

    for (int i = 0; i < a_len; i++){
        for (int j = 0; j < b_len; j++){
            ret[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = 0; i < a_len + b_len - 1; i++){
        ret[i + 1] += ret[i] / 10;
        ret[i] %= 10;
    }

    int check_index = a_len + b_len - 1;
    while (ret[check_index] >= 10){
        ret[check_index + 1] += ret[check_index] / 10;
        ret[check_index] %= 10;
        check_index++;
    }

    // printf("%d",check_index + 1);

    reverse_int(ret,check_index + 1);
    return check_index + 1;
}

ull calc(int ret[MAXSTR],ull n,int len)
{
    ull ans = 0;
    for (int i = 0; i < len; i++){
        if (i == 0 && ret[i] == 0){
            continue;
        }
        ans *= 10;
        ans += ret[i];
        ans %= n;
    }
    return ans;
}




int main(void)
{
    char a[MAXSTR],b[MAXSTR];
    ull n;

    char a_mul_b_ret[MAXSTR];
    while (scanf("%s%s%lld",a,b,&n) != EOF){

        int ret[MAXSTR] = {};
        int len = big_num_mul(a,b,ret);
        // for (int i = 0; i < len; i++){
            
        //     printf("%d",ret[i]);
        // }

        printf("%lld\n",calc(ret,n,len));




    







    }
   
    
    return 0;
}
