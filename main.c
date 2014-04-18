#include <stdio.h>
#include <stdlib.h>
#include "calender.h"
int main(int argc, char **argv)
{
    int year, month, day, daysInMonth, startday;

    /* set present time*/
    GetToday(&month, &day, &year);

    if(argc>=2)/* there is "month" input*/
    month=atoi(argv[1]);

    if(argc>2)/* there are both "month year" input*/
    year=atoi(argv[2]);

    printArg(argc, argv);

    /* calculates # of days in the month*/
    daysInMonth=DaysInMonth(month, year);

    /* startday: 0 = Sunday, 1 = Monday, ... 6 = Saturday */
    startday=startingDayOfWeekOf(month, year);

    /* prints the calendar for the month and year, whose first day starts on startWday
    (0 = Sunday, 1 = Monday, .. 6 = Saturday; and the month has daysInMonth days.
    This is just a printing routine... it does not know how many days the month has,
    nor does it know what day of the week first day is. */
    PrintGenericCalendar(month, year, startday, daysInMonth);

    return 0;
}
