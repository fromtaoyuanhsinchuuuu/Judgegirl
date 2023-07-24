#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};

struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};

struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

bool is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        return 1;
    }
    return 0;
}

int same_year_days_count(int year,int startmonth,int startdate,int endmonth,int enddate)
{
    int day = 0;
    if (endmonth == startmonth){
        return (enddate - startdate+1);
    }
    if (is_leap_year(year)){
        int day_arr[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for (int i = startmonth + 1; i <= endmonth - 1; i++){
            day += day_arr[i - 1];
        }
        day += day_arr[startmonth - 1] - startdate + 1 + enddate;

    }
    else{
        int day_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i = startmonth + 1; i <= endmonth - 1; i++){
            day += day_arr[i - 1];
        }
        day += day_arr[startmonth - 1] - startdate + 1 + enddate;
    }
    return day;
}

int bit_diff_count(unsigned int importance)
{
    while ((importance & 1) == 0){
        importance >>= 1;
    }
    int count = 0;
    importance >>= 1;
    while ((importance & 1) == 0){
        importance >>= 1;
        count++;
    }
    return count;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    /* count date diff */
    int day_diff = 0;
    for (int year = date_borrowed.year + 1; year < date_returned.year; year++){
        if (is_leap_year(year)){
            day_diff += 366;
        }
        else{
            day_diff += 365;
        }
    } 
    
    day_diff += (date_returned.year == date_borrowed.year)? same_year_days_count(date_borrowed.year,date_borrowed.month,date_borrowed.day,date_returned.month,date_returned.day) : same_year_days_count(date_borrowed.year,date_borrowed.month,date_borrowed.day,12,31) + same_year_days_count(date_returned.year,1,1,date_returned.month,date_returned.day);
    // printf("day_diff:%d\n",day_diff);
    int bit_diff = bit_diff_count(book.importance);
    int fine = 0;
    switch (book.type)
    {
        case NOVEL:
            if (day_diff <= 90){
                return 0;
            }
            else{
                return ((day_diff - 90) * bit_diff);
            }

        case COMICS:
            if (day_diff <= 10){
                return 0;
            }
            else{
                return ((day_diff - 10) * bit_diff);
            }

        case MANUAL:
            if (day_diff <= 100){
                return 0;
            }
            else{
                return ((day_diff - 100) * bit_diff);
            }

        case TEXTBOOK:
            if (day_diff <= 5){
                return 0;
            }
            else{
                return ((day_diff - 5) * bit_diff);
            }
    }
    return 0;
}

int main(void)
{
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 1999;
    date_borrowed.month = 12;
    date_borrowed.day   = 25;
    date_returned.year  = 2000;
    date_returned.month = 4;
    date_returned.day   = 2;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
    
    
    return 0;
}
