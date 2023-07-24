#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 11
#define MAXN 100

typedef struct {

    int min_distance;
    int id1;
    int id2;

} Edit_distance;

int abs(int a)
{
    return (a >= 0)? a: -a;
}

int min(int a,int b)
{
    return (a <= b)? a: b;
    
}

// int distance(char *str1,char *str2)
// {
//     printf("str1:%s str2:%s\n",str1,str2);
//     if (strlen(str1) == 0 || strlen(str2) == 0){
//         return abs(strlen(str1) - strlen(str2));
//     }

//     if (str1[0] == str2[0]){
//         return distance(str1 + 1, str2 + 1);
//     }

//     return min(distance(str1, str2 + 1),distance(str1 + 1, str2)) + 1;

// }

int distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dis_arr[len1 + 1][len2 + 1];
    for (int x = 0; x < len1 + 1; x++){
        for (int y = 0; y < len2 + 1; y++){ // x,y代表從str的尾端取幾個字
            if (x == 0 && y == 0){
                dis_arr[x][y] = 0;
            }
            else if (x == 0){
                dis_arr[x][y] = y;
            }
            else if (y == 0){
                dis_arr[x][y] = x;
            }
            else if (str1[len1 - x] == str2[len2 - y]){
                dis_arr[x][y] = dis_arr[x - 1][y - 1];
            }
            else{
                dis_arr[x][y] = 1 + min(dis_arr[x][y - 1],dis_arr[x - 1][y]);
            }
        }
    }
    // for (int i = 0; i < len1+ 1; i++){
    //     for (int j = 0; j < len2 + 1; j++){
    //         printf("%d%c",dis_arr[i][j]," \n"[j == len2]);
    //     }
    // }


    return dis_arr[len1][len2];
}

void min_dis(Edit_distance* Ans,int n,char str_arr[MAXN][MAXSTR])
{
    Ans->min_distance = 10000;
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            int now_dis = distance(str_arr[i],str_arr[j]);
            if (now_dis < Ans->min_distance || now_dis == Ans->min_distance && ((1000 * i + j) < (Ans->id1 * 1000 + Ans->id2))){
                Ans->min_distance = now_dis;
                Ans->id1 = i;
                Ans->id2 = j;
            }
        }
    }
}



int main(void)
{
    char str_arr[MAXN][MAXSTR];
    int n = 0;

    Edit_distance Answer;
    while (scanf("%s",str_arr[n + 1]) != EOF){
        n++;
    }

    // printf("n:%d\n",n);
    min_dis(&Answer,n,str_arr);
    printf("%d %d %d\n",Answer.min_distance,Answer.id1,Answer.id2);

    


    
    
    return 0;
}
