#include "calender.h"
#include <time.h>
void printArg(int argc, char **argv){
    printf("argc= %d\n", argc);/*print argc*/

    int i;/*print argv[i], i<argc*/
    for(i=0;i<=argc-1;i++)
        printf("argv[%i]= %s\n", i,argv[i]);
}

void GetToday(int *month, int *day, int *year) {
  time_t result;
  struct tm *tr;
  time(&result);
  tr = localtime(&result);
  *month = tr->tm_mon + 1;
  *day = tr->tm_mday;
  *year = tr -> tm_year + 1900;
}


int isLeapYear(int year){
    /* returns 1 if the year is a leap year, 0 if not */
    int leap=(year%4==0&&year%100!=0)||year%400==0? 1:0;
    return leap;
}

int numberOfDaysInYear(int year){
    int days;
    /*if leap year days=366, else days=365*/
     days=(isLeapYear(year)==1)? 366: 365;
    return days;
}

/* returns the starting day of the week of the month and year.
0 = Sunday, 1 = Monday, ... 6 = Saturday */
int startingDayOfWeekOf(int month, int year){
    int i=1753, j=1, days=0;

    for(i=1753;i<year;i++){
    days+=numberOfDaysInYear(i);
    /*if leap year Days+=366, else Days+=365*/
    }

    for(j=1;j<month;j++){
        if(j==2){
         days+=isLeapYear(year) ? 29: 28;
         /*if leap year days+=29, else days+=28*/
        }
            else if(j==4||j==6||
                    j==9||j==11){
            days+=30;/*if little month days+=30*/
            }
                else
                days+=31;/*if big month days+=31*/
    }

    int StartingDay=(days+1)%7;
    /*"1753/1/1" is Monday(starting day:days=0),therefore set"days+1",Mon=1;Sun=0*/

    return StartingDay;
}

void PrintMonth(int m){
(m==1)?printf("January"):
    (m==2)?printf("February"):
        (m==3)?printf("March"):
            (m==4)?printf("April"):
                (m==5)?printf("May"):
                    (m==6)?printf("June"):
                        (m==7)?printf("July"):
                            (m==8)?printf("August"):
                                (m==9)?printf("September"):
                                    (m==10)?printf("October"):
                                        (m==11)?printf("November"):
                                            (m==12)?printf("December"):printf("Error");
}

int DaysInMonth(int month, int year){
    int days=0;
    if(month==2){/*February*/
         days=isLeapYear(year)? 29 : 28;/*if leap year February=29, else February=28*/
    }

    else if(month==4||month==6||
            month==9||month==11){/*little month*/
            days=30;
        }

    else/*big month*/
            days=31;

    return days;
}

/* prints the calendar for the month and year, whose first day starts on startWday
  (0 = Sunday, 1 = Monday, .. 6 = Saturday; and the month has daysInMonth days.
  This is just a printing routine... it does not know how many days the month has,
  nor does it know what day of the week first day is. */
void PrintGenericCalendar(int month, int year, int startWday, int daysInMonth){
    printf("\n         ");
        PrintMonth(month);/*prints this month*/
            printf(" %d\n", year);/*prints this year*/

    printf(" Sun Mon Tue Wed Thu Fri Sat\n");/*print headline*/

    int i,j;
    for(i=0;i<=5;i++){/*i=number of row*/
       /*j=date,while colum=1~6*/
       for(j=1+(7*i-startWday);j<7+(7*i-startWday);j++){
            if(j<=0)
                printf("%4c", ' ');/*(j=date)<=0,print null*/
            else if(j<=daysInMonth)
                printf("%4d", j);/*daysInMonth>=(j=date)>0,print j*/
            else
                printf("%4c", ' ');/*(j=date)>daysInMonth,print null*/
        }
        if(j>daysInMonth)
            break;
        printf("%4d\n", j);/*j=date,while colum=7*/
    }

};


