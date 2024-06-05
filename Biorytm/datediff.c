#include <time.h>
#include <math.h>
#include <stdio.h>

#define BASE_YEAR 1900
#define BASE_MONTH 1

int datediff_days() {
    int start_date = build_birthday();
    if (start_date < 1) {
        return -1;
    }
    int end_date = build_end_date();
    if (end_date < 1) {
        return -1;
    }
    double dt = difftime(end_date, start_date);
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
int build_end_date() {
    struct tm end_date = { 0 };
    int year, month, day;

    printf("Podaj date w formacie YYYY-MM-DD (Po roku 1970). Wpisz cokolwiek by uzyskac dzisiejsze wyniki\n");
    if (scanf_s("%d-%d-%d", &year, &month, &day) < 3) {
        return build_today();
    }

    end_date.tm_year = year - BASE_YEAR;
    end_date.tm_mon = month - BASE_MONTH;
    end_date.tm_mday = day;
    end_date.tm_hour = end_date.tm_min = end_date.tm_sec = 0;
    end_date.tm_isdst = -1;

    time_t end_date_time = mktime(&end_date);

    if (end_date_time == -1 || (end_date.tm_mon != (month - BASE_MONTH) && end_date.tm_mday != day)) {
        printf("Data poza mozliwymi miesiacami/dniami\n");
        return -1;
    }
    return end_date_time;
}

int build_birthday() {
    struct tm birthday = { 0 };
    int year, month, day;

    printf("Podaj date urodzenia w formacie YYYY-MM-DD (Po roku 1970)\n");
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
