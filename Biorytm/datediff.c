#include <time.h>
#include <math.h>
#include <stdio.h>

#define BASE_YEAR 1900
#define BASE_MONTH 1

int datediff_days() {
    double dt = difftime(build_today(), build_birthday());
    int days = round(dt / 86400);

    return days;
}

int build_today() {
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    today.tm_year = today.tm_year;
    today.tm_mon = today.tm_mon;
    today.tm_hour = today.tm_min = today.tm_sec = 0;
    time_t today_time = mktime(&today);

    return today_time;
}

int build_birthday() {
    struct tm birthday = { 0 };
    int year, month, day;

    printf("Podaj date w formacie YYYY-MM-DD (Po roku 1970)\n");
    if (scanf_s("%d-%d-%d", &year, &month, &day) < 3) {
        printf("Zly format\n");
        return -1;
    }

    birthday.tm_year = year - BASE_YEAR;
    birthday.tm_mon = month - BASE_MONTH;
    birthday.tm_mday = day;
    birthday.tm_hour = birthday.tm_min = birthday.tm_sec = 0;
    birthday.tm_isdst = -1;

    time_t birthday_time = mktime(&birthday);

    if (birthday_time == -1 || (birthday.tm_mon != (month - BASE_MONTH) && birthday.tm_mday != day)) {
        printf("Data poza mozliwymi miesiacami/dniami\n");
        return -1;
    }
    return birthday_time;
}
