#ifndef CALENDER_H_INCLUDED
#define CALENDER_H_INCLUDED

void printArg(int argc, char **argv);
/* check argc and argv*/

void GetToday(int *month, int *day, int *year) ;
/* set present time*/

int isLeapYear(int year);
/* returns 1 if the year is a leap year, 0 if not */

int numberOfDaysInYear(int year);
/* returns the number of days (365 or 366) the year has */

int startingDayOfWeekOf(int month, int year);
/* returns the starting day of the week of the month and year.
0 = Sunday, 1 = Monday, ... 6 = Saturday */

void PrintMonth(int m);
/* 1 = Jan, ...,12=Dec */

int DaysInMonth(int year, int month);
/* # of days in the month */

void PrintGenericCalendar(int month, int year, int startWday, int daysInMonth);
/*print calender */

#endif // CALENDER_H_INCLUDED
