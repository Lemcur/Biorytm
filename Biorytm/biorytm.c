#include "biorytm.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Biorytm* build_biorhythms(int days, struct Biorytm (*biorytmy)[4]) {
	(*biorytmy)[0].cycle_length = 23;
	(*biorytmy)[0].current_value = sin((double)(days) / (double)((*biorytmy)[0].cycle_length) * 2.0 * M_PI);//biorhythm_current_value(days, (*biorytmy)[0].cycle_length);
	strcpy((*biorytmy)[0].type, "Fizyczny");
	(*biorytmy)[0].display_width = sizeof("Fizyczny") - 1;

	(*biorytmy)[1].cycle_length = 28;
	(*biorytmy)[1].current_value = sin((double)(days) / (double)((*biorytmy)[1].cycle_length) * 2.0 * M_PI);
	strcpy((*biorytmy)[1].type, "Emocjonalny");
	(*biorytmy)[1].display_width = sizeof("Emocjonalny") - 1;

	(*biorytmy)[2].cycle_length = 33;
	(*biorytmy)[2].current_value = sin((double)(days) / (double)((*biorytmy)[2].cycle_length) * 2.0 * M_PI);
	strcpy((*biorytmy)[2].type, "Intelektualny");
	(*biorytmy)[2].display_width = sizeof("Intelektualny") - 1;

	(*biorytmy)[3].cycle_length = 1;
	(*biorytmy)[3].current_value = ((*biorytmy)[0].current_value + (*biorytmy)[1].current_value + (*biorytmy)[2].current_value) / 3;
	strcpy((*biorytmy)[3].type, "Usredniony");
	(*biorytmy)[3].display_width = sizeof("Usredniony") - 1;


	return *biorytmy;
}

double biorhythm_current_value(int days, int cycle_length) {
	double result;
	result = sin((double)(days) / (double)(cycle_length) * 2.0 * M_PI);
	printf("biorytm %d: %f \n", cycle_length, result);
	//return result;
	return sin(2 * M_PI * days / cycle_length);
}

/*
int generate_chart_values_for_biorhythm(int cycle_length, int days) {
	double *sin_values = malloc(cycle_length * sizeof(sin_values));
	for (int i = 0; i< cycle_length; i++) {
		sin_values[i] = sin((double)(days + 2 * i) / (double)(cycle_length) * 2.0 * M_PI);
	}

	return sin_values;
}
*/
