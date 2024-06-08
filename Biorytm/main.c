#include <stdio.h>
#include "datediff.h"
#include "biorytm.h"
#include "view.h"

int main()
{
    struct Biorytm biorytmy[4] = {
        [0].current_value = (double)0.0,[0].cycle_length = 1,
        [1].current_value = (double)0.0,[1].cycle_length = 1,
        [2].current_value = (double)0.0,[2].cycle_length = 1,
        [3].current_value = (double)0.0,[3].cycle_length = 1,
    };

    int datediff = 0;
    datediff = abs(datediff_days());

    build_biorhythms(datediff, &biorytmy);

    inspect_biorhythms(&biorytmy);
    draw_columns(&biorytmy);
    return 0;

    int next_cycle_values[4];

}
