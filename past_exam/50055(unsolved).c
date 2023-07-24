#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXM 1000000

int min_counter_index(int counter[MAXN],int N)
{
    int min = counter[0];
    int min_index = 0;
    for (int i = 0; i < N; i++){
        if (counter[i] == 0){
            return i;
        }
        else if (counter[i] < min){
            min_index = i;
            min = counter[i];
        }
    }
    return min_index;

}

int max(int a,int b)
{
    return (a >= b)? a: b;
}



int main(void)
{
    int N,M;
    scanf("%d%d",&N,&M); // 每個在隊伍中的總時長

    int t,s;
    int time = 0;
    int head = 0;
    int tail = 0;
    static int queue[MAXM][2];
    int counter[MAXN] = {}; // 尚須等待的時間
    for (int i = 0; i < M; i++){
        scanf("%d%d",&queue[i][0],&queue[i][1]);
        tail++;
    }
    while (head != tail){
        int counter_index = min_counter_index(counter,N);
        if (queue[head][0] - time > counter[counter_index]){
            for (int i = 0; i < N; i++){
                counter[i] = (counter[i] + time - queue[head][0] > 0)? counter[i] + time - queue[head][0]: 0;
            }
            time += (queue[head][0] - time);
            counter[counter_index] = queue[head][1];

            
            head++;
        }
        else if (queue[head][0] - time < counter[counter_index]){
            time += counter[counter_index];
            for (int i = 0; i < N; i++){
                counter[i] -= counter[counter_index];
            }
            assert (counter[counter_index] == 0);
            counter[counter_index] = queue[head][1];
            head++;
        }
        else {
            counter[counter_index] = queue[head][1];
            head++;
        }
        printf("head:%d time:%d\n",head,time);
        printf("counter:\n");
        for (int i = 0; i < N; i++){
            printf("%d%c",counter[i]," \n"[i == N - 1]);
        }
    }

    printf("%d",time);



    
    
    return 0;
}
