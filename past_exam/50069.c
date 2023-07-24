#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXL 105
#define MAXGL 205
 
struct Hangman {
    char nowAns[MAXL];
    char TrueAns[MAXL];
    int G;
    int try_num;
};
typedef struct Hangman Hangman;
 
Hangman* newGame(char *answer, int G)
{

    Hangman *hangman = (Hangman *)malloc(sizeof(Hangman)); // 用malloc才可以return陣列的pointer
    int Name_len = strlen(answer);
    for (int i = 0; i < Name_len; i++){
        hangman->nowAns[i] = '*';
    }
    hangman->nowAns[Name_len] = '\0';
    hangman->G = G;
    strcpy(hangman->TrueAns, answer);
    hangman->try_num = 0;
    return hangman;
}
int guess(Hangman* hangman, char ch)
{
    int Name_len = strlen(hangman->nowAns);
    bool find = 0;
    for (int i = 0; i < Name_len; i++){
        if (hangman->TrueAns[i] == ch){
            hangman->nowAns[i] = ch;
            find = 1;
        }
    }

    if (!find){
        (hangman->try_num)++;
    }

    if (hangman->try_num >= hangman->G){
        return -1;
    }
    return find;

}
void printStatus(Hangman* hangman)
{
    printf("%s\n",hangman->nowAns);
    return;
}
int solved(Hangman* hangman)
{
    if (!strcmp(hangman->nowAns,hangman->TrueAns)){
        return 1;
    }
    return 0;
}


int main(void)
{
    int N;
    scanf("%d",&N);

    int G;
    char Ans[MAXL],Guess[MAXGL];
    for (int i = 0; i < N; i++){
        scanf("%s%d%s",Ans,&G,Guess);
        Hangman *hagnman = newGame(Ans,G);
        int G_len = strlen(Guess);

        bool fair = 1;
        for (int i = 0; i < G_len; i++){
            char ch = Guess[i];

            int ret = guess(hagnman, ch);

            printf("%d ",ret);
            printStatus(hagnman);

            if (ret == -1){
                free(hagnman);
                fair = 0;
                printf("You Lose\n");
                break;
            }

            if (solved(hagnman)){
                fair = 0;
                printf("You Win\n");
                free(hagnman);
                break;
            }
        }

        if (fair){
            free(hagnman);
            printf("You Quit\n");
        }
    }
    
    return 0;
}
