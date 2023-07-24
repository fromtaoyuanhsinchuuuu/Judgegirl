#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 50

typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time)
{
    time->hour = 0;
    time->minute = 0;
    time->second = 0;
    return;

}
void setTime(Time *time, int hour, int minute, int second)
{
    time->hour = hour;
    time->minute = minute;
    time->second = second;
    assert(minute < 60 && second < 60 && hour < 24);
    return;

}
void addTime(Time *time, int hour, int minute, int second)
{
    time->hour += hour;
    time->minute += minute;
    time->second += second;
    time->minute += (time->second / 60);
    time->second %= 60;
    time->hour += (time->minute / 60);
    time->minute %= 60;
    time->hour %= 24;
    return;

}
void printTime(Time *time)
{
    #ifdef H24
    printf("%02d:%02d:%02d\n",time->hour,time->minute,time->second);

    #endif
    
    #ifndef H24
    if (time->hour != 12 && time->hour != 00){
        if (time->hour / 12 == 1){
            printf("%02dpm:%02d:%02d\n",time->hour % 12,time->minute,time->second);
        }
        else{
            assert(time->hour / 12 == 0);
            printf("%02dam:%02d:%02d\n",time->hour % 12,time->minute,time->second);
        }
    }
    else{
        if (time->hour == 12){
            printf("%02dpm:%02d:%02d\n",time->hour,time->minute,time->second);
        }
        else{
            printf("12am:%02d:%02d\n",time->minute,time->second);
        }
    }
    #endif



}

int main(void)
{
    Time times[MAXN];

    int n;
    scanf("%d",&n);

    char cmd;
    while (scanf("%c",&cmd) != EOF){
        if (cmd == 'i'){
            int index;
            scanf("%d",&index);
            initTime(&times[index]);
        }
        else if (cmd == 'a'){
            int index,hour,min,second;
            scanf("%d%d%d%d",&index,&hour,&min,&second);
            addTime(&times[index],hour,min,second);
        }
        else if (cmd == 'p'){
            int index;
            scanf("%d",&index);
            printTime(&times[index]);
        }
        else if (cmd == 's'){
            int index,hour,min,second;
            scanf("%d%d%d%d",&index,&hour,&min,&second);
            setTime(&times[index],hour,min,second);
        }
    }


    
    
    return 0;
}
