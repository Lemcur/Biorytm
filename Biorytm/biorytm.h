#pragma once

typedef struct Biorytm {
    int cycle_length;
    double current_value;
    char type[40];
    int display_width;
} Biorytm;

Biorytm* build_biorhythms(int days, struct Biorytm(*biorytmy)[4]);
int generate_chart_values_for_biorhythm(int cycle_length, int days);
