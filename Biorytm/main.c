#include <stdio.h>
#include "datediff.h"
#include "biorytm.h"
#include "view.h"

int main()
{
    struct Biorytm biorytmy[4] = { 0 };

    int datediff = datediff_days();
    if (datediff == -1) {
        printf("Wprowadzono niepoprawne daty. Koniec programu.\n");
        return 1;
    }

    datediff = abs(datediff);

    build_biorhythms(datediff, &biorytmy);

    inspect_biorhythms(&biorytmy);
    draw_columns(&biorytmy);

    double** next_cycle_values[4] = {
        [0] = generate_chart_values_for_biorhythm(biorytmy[0].cycle_length, datediff),
        [1] = generate_chart_values_for_biorhythm(biorytmy[1].cycle_length, datediff),
        [2] = generate_chart_values_for_biorhythm(biorytmy[2].cycle_length, datediff),
        [3] = generate_chart_values_average_biorhythm(next_cycle_values, biorytmy[2].cycle_length),
    };

    char letters[4];
    for (int i = 0; i < 4; i++) {
        letters[i] = biorytmy[i].type[0];
    }

    draw_biorhythm_chart(&next_cycle_values, &letters);

    for (int i = 0; i < 4; i++) {
        free(next_cycle_values[i]);
    }
    return 0;
}
