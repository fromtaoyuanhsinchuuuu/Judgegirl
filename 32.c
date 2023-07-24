#include <stdio.h>
#include <stdbool.h>
#define MAXARRAY 100

bool is_single_palindrome(int arr[MAXARRAY],int i,int j)
{
    if (i == j){
        return 1;
    }
    else{
        for (int time = 0; time < (j-i) / 2 +1; time++){
            if (arr[i+time] != arr[j-time]){
                return 0;
            }
        }
        return 1;
    }
}

bool is_double_palindrome(int arr[MAXARRAY],int i,int j,int k)
{
    if (is_single_palindrome(arr,i,j) && is_single_palindrome(arr,j+1,k)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    int arr[MAXARRAY];
    int len = 0;
    while (scanf("%d",&(arr[len])) != EOF){
        len++;
    } 
    // len最後的值即為輸入的值的個數
    int maxlen = 0;
    int ans_arr[MAXARRAY];
    for (int i = 0; i < len - 1; i++){
        for (int j = i; j < len - 1; j++){
            for (int k = j + 1; k < len; k++){
                int now_len = k-i+1;
                if (is_double_palindrome(arr,i,j,k) && now_len >= maxlen){
                    maxlen = now_len;
                    for (int index = 0; index < now_len; index++){
                        ans_arr[index] = arr[i+index];
                    }
                }
            }
        }
    }
    for (int i = 0; i < maxlen; i++){
        printf("%d%c",ans_arr[i]," \n"[i == maxlen - 1]);
    }
    return 0;
}
