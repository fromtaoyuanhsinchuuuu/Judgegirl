#include <stdio.h>
#include <stdbool.h>
#define pos 0
#define neg 1

int main(){
    int k;
    scanf("%d",&k);
    bool now_sequence = pos;
    int now_num = 0;  /* now_num須至少>=3*k才有需紀錄的可能 */
    int max_num = 0;
    int now_pattern_num = 0;
    bool continuee = 1;
    while (continuee){
        int n;
        scanf("%d",&n);
        switch (now_sequence){ 
            case pos: /* 若是以正太多作結束則直接使now_num=k，now_pattern_num=0，並換到neg */
            {
                if (n > 0){
                    now_num++;
                    now_pattern_num++;
                    if (now_pattern_num == k){
                        now_sequence = neg;
                        now_pattern_num = 0;
                    }
                }
                else{  /* n<0的情況 */
                    now_num -= (k+now_pattern_num);
                    if (now_num >= 3*k && now_num > max_num){
                        max_num = now_num;
                    }
                    now_num = 0;
                    now_pattern_num = 0;
                    if (n == 0){
                        continuee = 0;
                    }
                }
                
                break;
            }
            case neg: /* 在neg break掉，則將now_num-=now_pattern_num */
            {
                if (n < 0){
                    now_pattern_num++;
                    now_num++;
                    if(now_pattern_num == k){
                        now_sequence = pos;
                        now_pattern_num = 0;
                    }
                }
                else{ // n>0的情況
                    now_num -= now_pattern_num;
                    if (now_num >= 3*k && now_num > max_num){
                        max_num = now_num;
                    }
                    if (now_pattern_num != 0){
                        now_num = 1;
                        now_pattern_num = 1;
                        now_sequence = pos;
                    }
                    else{
                        now_num = k;
                        now_pattern_num = 0;
                    }
                    if (n == 0){
                        continuee = 0;
                    }
                }
                break;
            }
        }
    }
    printf("%d",max_num);
    return 0;
}