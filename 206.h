#include <stdio.h>

void shuffle(int *deck[])
{   
    int length = 0;
    for (int i = 0 ; i < 10000 ; i++){
        if (deck[i] != NULL){
            length++;
        }
        else{
            break;
        }
    }
    // printf("le:%d\n",length);
    int first_deck_length = length/2 +1;
    int second_deck_length = length - first_deck_length;
    // printf("%d %d",first_deck_length,second_deck_length);
    int index = 1;
    int deck_2[10000];
    for (int i = 0 ; i < 10000 ; i++){
        if (deck[i] != NULL){
            deck_2[i] = *deck[i];
        }
        else{
            break;
        }
    }
    for (int i = 1 ; i <= second_deck_length ; i++){
        *deck[2*i-1] = deck_2[i+second_deck_length];
        *deck[2*i] = deck_2[i];
    }
}

void print(int *deck[])
{
    int i = 0;
    while (deck[i] != NULL)
    {
        printf("%d ",*deck[i]);
        i++;
    }
}

 
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}