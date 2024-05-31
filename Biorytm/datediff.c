#include <time.h>
#include <math.h>

#define BASE_YEAR 1900
#define BASE_MONTH 1

// use structs from sanitized input?
int datediff_days(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day) {
    struct tm tm1 = { 0 };
    struct tm tm2 = { 0 };

    /* date 1: 2022-09-25 */
    tm1.tm_year = end_year - BASE_YEAR;
    tm1.tm_mon = end_month - BASE_MONTH;
    tm1.tm_mday = end_day;
    tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
    tm1.tm_isdst = -1;

    /* date 2: 1990-10-02 */
    tm2.tm_year = start_year - BASE_YEAR;
    tm2.tm_mon = start_month - BASE_MONTH;
    tm2.tm_mday = start_day;
    tm2.tm_hour = tm2.tm_min = tm2.tm_sec = 0;
    tm2.tm_isdst = -1;

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    double dt = difftime(t1, t2);
    int days = round(dt / 86400);

    return days;
}
/*
struct tm build_today() {
    tm1.tm_year = end_year - BASE_YEAR;
    tm1.tm_mon = end_month - BASE_MONTH;
    tm1.tm_mday = end_day;
    tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
    tm1.tm_isdst = -1;
}
*/