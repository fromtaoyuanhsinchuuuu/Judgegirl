#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXL 11
#define MAXN 50
#define GROUP 3

void bubble_sort(char Leadrs[GROUP][MAXL])
{
    for (int i = 0; i < GROUP; i++){
        for (int j = 0; j < GROUP - 1; j++){
            if (strcmp(Leadrs[j],Leadrs[j+1]) > 0){
                char temp[MAXL];
                strcpy(temp,Leadrs[j]);
                strcpy(Leadrs[j],Leadrs[j+1]);
                strcpy(Leadrs[j+1],temp);
            }
        }
    }
}

int abs(int a)
{
    return (a >= 0)? a: -a;
}

int dist(char str1[MAXL],char str2[MAXL])
{
    int len = strlen(str1);
    assert(len == strlen(str2));

    int distance = 0;
    for (int i = 0; i < len; i++){
        distance += abs(str1[i] - str2[i]);
    }
    return distance;
}

int small_leader(char Leaders[GROUP][MAXL],char now_member[MAXL])
{
    int smallet_distance = dist(Leaders[0],now_member);
    // printf("dick");
    char ans_leader[MAXL];
    strcpy(ans_leader,Leaders[0]);
    int ans_index = 0;
    for (int i = 0; i < GROUP; i++){
        if (dist(now_member,Leaders[i]) < smallet_distance || dist(now_member,Leaders[i]) == smallet_distance && strcmp(Leaders[i],ans_leader) < 0){
            strcpy(ans_leader,Leaders[i]);
            smallet_distance = dist(now_member,Leaders[i]);
            ans_index = i;
        }
    }
    return ans_index;

}


int main(void)
{
    int N,L,R;
    scanf("%d%d%d",&N,&L,&R);
    char Leaders[GROUP][MAXL];
    char group[GROUP][MAXN][MAXL];
    char str_arr[MAXN][MAXL];
    int count_arr[GROUP] = {};
    for (int i = 0; i < GROUP; i++){
        scanf("%s",Leaders[i]);
    }
    for (int i = 0; i < N - GROUP; i++){
        scanf("%s",str_arr[i]);
    }

    for (int it = 0; it < R; it++){
        /* 根據與leader的dist來決定加入哪個group */
        for (int i = 0; i < GROUP; i++){
            strcpy(group[i][0],Leaders[i]);
            count_arr[i]++;
        }
        int group_index = 0;
        for (int i = 0; i < N - GROUP; i++){
            char now_member[MAXL];
            strcpy(now_member,str_arr[i]);
            int Group_index = small_leader(Leaders,now_member);
            strcpy(group[Group_index][count_arr[Group_index]],now_member);
            count_arr[Group_index]++;
        }
        /* 最後要將三位leader設定好，將無關的排到列隊中，並將count全部變1*/
        for (int i = 0; i < GROUP; i++){
            char means_arr[MAXL]; // 一個group算完mean後直接決定leader
            int mean = 0;
            for (int arr_index = 0; arr_index < L; arr_index++){
                int sum = 0;
                for (int n = 0; n < count_arr[i]; n++){
                    sum += group[i][n][arr_index];
                }
                mean = sum / count_arr[i];
                means_arr[arr_index] = mean;
            }
            means_arr[L] = '\0';
            int smallest_distance = dist(group[i][0],means_arr);
            int ans_index = 0;
            char ans_member[MAXL];
            strcpy(ans_member,group[i][0]);
            for (int j = 0; j < count_arr[i]; j++){
                char now_member[MAXL];
                strcpy(now_member,group[i][j]);
                if (dist(now_member,means_arr) < smallest_distance || smallest_distance == dist(now_member,means_arr) && strcmp(now_member,ans_member) < 0){
                    strcpy(ans_member,now_member);
                    ans_index = j;
                    smallest_distance = dist(now_member,means_arr);
                }
            }

            strcpy(Leaders[i],group[i][ans_index]);
            for (int j = 0; j < count_arr[i]; j++){
                if (strcmp(group[i][j],Leaders[i])){
                    strcpy(str_arr[group_index],group[i][j]);
                    group_index++;
                }
            }
        }
        assert (group_index == N - GROUP);
        for (int i = 0; i < GROUP; i++){
            count_arr[i] = 0;
        }
    }
    bubble_sort(Leaders);
    for (int i = 0; i < GROUP; i++){
        printf("%s\n",Leaders[i]);
    }
    
    return 0;
}
