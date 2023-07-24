#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 100

typedef struct {
    int score;
    int Ans_arr[MAXM];
} Data;

int find_index(int arr[MAXM],int m)
{
    for (int i = 0; i < m; i++){
        if (arr[i]){
            return i;
        }
    }
    return m;

}

void subtract(Data *now_data,Data *data2,int M,int mul)
{
    
    for (int i = 0; i < M; i++){
        data2->Ans_arr[i] -= now_data->Ans_arr[i] * mul;
    }
    data2->score -= now_data->score * mul;
    return;
}

int main(void)
{

    int N,M;
    while (scanf("%d%d",&N,&M) != EOF){
        Data data_arr[MAXN];
        int Qus_arr[MAXM];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                scanf("%d",&(data_arr[i].Ans_arr[j]));
            }
            scanf("%d",&(data_arr[i].score));
        }

        for (int i = 0; i < M; i++){
            scanf("%d",&Qus_arr[i]);
        }

      
        bool cont = 1;
        /* 先由上往下消 */
        for (int i = 0; i < N - 1; i++){
            Data now_data = data_arr[i];
            int now_index = find_index(now_data.Ans_arr,M);
            if (now_index == M){
                if (now_data.score != 0){
                    printf("contradictory\n");
                    cont = 0;
                    break;
                }
                continue;
            }
            for (int j = i + 1; j < N; j++){
                if (data_arr[j].Ans_arr[now_index]){
                    int mul = data_arr[j].Ans_arr[now_index] / now_data.Ans_arr[now_index];
                    subtract(&now_data,data_arr + j,M,mul);
                }
            }
        }

        if (!cont){
            continue;
        }

        // for (int i = 0; i < N; i++){
        //     for (int j = 0; j < M; j++){
        //         printf("%d ",(data_arr + i)->Ans_arr[j]);
        //     }
        //     printf("%d\n",data_arr[i].score);
        // }


        

        /* 再由下往上消 */
        for (int i = N - 1; i > 0; i--){
            Data now_data = data_arr[i];
            int nowIndex = find_index(now_data.Ans_arr,M);
            // printf("nowIndex:%d, M:%d\n",nowIndex,M);
            if (nowIndex == M){
                // printf("dick\n");
                if (now_data.score != 0){
                    printf("contradictory\n");
                    cont = 0;
                    break;
                }
                continue;
            }
            for (int j = i - 1; j >= 0; j--){
                if (data_arr[j].Ans_arr[nowIndex]){
                    // printf("asd:%d\n",now_data.Ans_arr[nowIndex]);
                    int mul = data_arr[j].Ans_arr[nowIndex] / now_data.Ans_arr[nowIndex];
                    subtract(&now_data,data_arr + j,M,mul);
                }

            }

        }

        if (!cont){
            continue;
        }

        // for (int i = 0; i < N; i++){
        //     for (int j = 0; j < M; j++){
        //         printf("%d ",(data_arr + i)->Ans_arr[j]);
        //     }
        //     printf("%d\n",data_arr[i].score);
        // }

        int zero_count = 0;
        for (int i = 0; i < M; i++){
            if (!Qus_arr[i]){
                zero_count++;
            }
        }

        if (zero_count == M){
            printf("0\n");
            continue;
        }


      
        int score = 0;
        for (int i = 0; i < M && cont; i++){
            if (Qus_arr[i]){
                // printf("i:%d\n",i);
                bool find = 0;
                for (int j = 0; j < N && cont; j++){
                    if (data_arr[j].Ans_arr[i]){
                        // printf("j:%d\n",j);
                        find = 1;
                        cont = 1;
                        for (int k = 0; k < M; k++){
                            if (k != i && data_arr[j].Ans_arr[k]){
                                printf("not sure\n");
                                cont = 0;
                                break;
                            }
                        }
                        score += data_arr[j].score / data_arr[j].Ans_arr[i];
                        if (score <= 0){
                            printf("contradictory\n");
                            cont = 0;
                        }
                        break;
                   }
                }
                if (!find){
                    printf("not sure\n");   
                    cont = 0;
                    break;
                }
            }

        }

        // printf("\n");
        if (cont){
            printf("%d\n",score);
        }






       






    }


   
    
    return 0;
}
