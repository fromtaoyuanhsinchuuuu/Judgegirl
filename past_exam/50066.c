#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef struct RoomStatus {
    int capacity;
    struct Reservation *reservation;
} RoomStatus;
 
typedef struct Reservation {
    int nP;
    int StartTime;
    int EndTime;
    struct Reservation *next;
} Reservation;

Reservation *GenResv(int nP,int StartTime,int Endtime,Reservation *next)
{
    Reservation *resv = (Reservation *)malloc(sizeof(Reservation));
    resv->nP = nP;
    resv->StartTime = StartTime;
    resv->EndTime = Endtime;
    resv->next = next;
    return resv;
}

Reservation *Insert__resv(RoomStatus *nowRoom,int StartTime,int EndTime,int nP)
{
    Reservation *head = nowRoom->reservation;
    if (head == NULL){
        return GenResv(nP,StartTime,EndTime,NULL);
    }

    Reservation *prev_Resv = NULL;
    Reservation *now_Resv = head;

    while (1){
        if (now_Resv == head && prev_Resv == NULL && now_Resv->StartTime >= EndTime){
            return GenResv(nP, StartTime, EndTime, now_Resv);
        }
        else if ( 
            prev_Resv != NULL && now_Resv == NULL && prev_Resv->EndTime <= StartTime){
            prev_Resv->next = GenResv(nP, StartTime, EndTime, NULL);
            return head;
        }
        else if (prev_Resv != NULL && prev_Resv->StartTime >= StartTime){
            return NULL;
        }
        else if (prev_Resv != NULL && now_Resv != NULL && prev_Resv->EndTime <= StartTime && EndTime <= now_Resv->StartTime){
            prev_Resv->next = GenResv(nP, StartTime, EndTime, now_Resv);
            return head;
        }

        if (now_Resv == NULL){
            return NULL;
        }
        prev_Resv = now_Resv;
        now_Resv = now_Resv->next;
    } 

    assert(0);
    return NULL;



}
 
int ReserveRoom(RoomStatus list[], int n, int nP, int StartTime, int EndTime)
{
    // int room_index = -1;
    for (int i = 0; i < n; i++){
        if (list[i].capacity >= nP){
            /* 以i做嘗試 */
            // RoomStatus nowRoom = list[i];
            Reservation *tmp = Insert__resv(&list[i], StartTime, EndTime, nP);
            if (tmp == NULL){
                // printf("Null!\n");
                continue;
            }

            list[i].reservation = tmp;

            // printf("start_time:%d end_time:%d\n",list[i].reservation->StartTime,list[i].reservation->EndTime);
            return 1;
        }
    }
    return 0;
}

int main(){
    int n = 3;
    RoomStatus list[n];
    for(int i=0; i < n; i++){
        list[i].capacity = i+2;
        list[i].reservation = NULL;
    }
    int nP, sTime, eTime;
    while(scanf("%d %d %d", &nP, &sTime, &eTime)!=EOF)
        printf("%d", ReserveRoom(list, n, nP, sTime, eTime));
    puts("");
    printf("---Room Status List---\n");
    for(int i=0; i<n; i++){
        printf("%d ---", list[i].capacity);
        for(Reservation *tmp = list[i].reservation; tmp!=NULL; tmp=tmp->next)
            printf("->(%d:%d, %d)", tmp->nP, tmp->StartTime, tmp->EndTime);
        puts("");
    }
    printf("---      End       ---\n");
    return 0;
}
