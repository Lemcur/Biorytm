#include "biorytm.h"
#include <stdio.h>

void inspect_biorhythms(struct Biorytm(*biorytmy)[4]) {
	printf("Nazwa Biorytmu: ");
	for (int i = 0; i < 4; i++) {
		printf("%-20s", (*biorytmy)[i].type);
	}
	printf("\n");

	printf("Dlugosc cyklu:  ");
	for (int i = 0; i < 4; i++) {
		int space_length = 18;
		printf("%.2d", (*biorytmy)[i].cycle_length);
		for (int j = 0; j < space_length; j++) {
			printf(" ");
		}
	}
	printf("\n");

	printf("Obecna wartosc: ");
	for (int i = 0; i < 4; i++) {
		int space_length = (*biorytmy)[i].current_value < 0 ? 15 : 16;
		printf("%.1f", (*biorytmy)[i].current_value * 100);
		for (int j = 0; j < space_length; j++) {
			printf(" ");
		}
	}
	printf("\n");
}

void draw_columns(struct Biorytm(*biorytmy)[4]) {
	for (int i = 20; i > 0; i--) {
		int level = i * 10 - 100;
		printf("%.2d|      ", abs(level));
		for (int j = 0; j < 4; j++) {
			if ((*biorytmy)[j].current_value * 100 >= level) {
				int left_space, right_space;
				left_space = ((*biorytmy)[j].display_width / 2);
				right_space = (*biorytmy)[j].display_width - left_space - 1;

				for (int k = 0; k < left_space; k++) {
					printf(" ");
				}
				printf("X");
				for (int k = 0; k < right_space; k++) {
					printf(" ");
				}
			}
			else {
				for (int k = 0; k < (*biorytmy)[j].display_width; k++) {
					printf(" ");
				}
			}
			printf("  ");
		}
		printf("\n");
	}
	printf("_________________________________________________________\n");
	printf("Stopien, %s, %s, %s, %s\n", (*biorytmy)[0].type, (*biorytmy)[1].type, (*biorytmy)[2].type, (*biorytmy)[3].type);
}

void draw_biorhythm_chart(double** next_cycle_values, char* letters) {
	for (int i = 20; i > 0; i--) {
		int level = i * 10 - 100;
		printf("%.3d|", abs(level));
		for (int day = 0; day < 23; day++) {
			char letter_to_draw[4] = "    ";

			for (int biorhythm = 0; biorhythm < 4; biorhythm++) {
				int rounded_value = next_cycle_values[biorhythm][day] * 100;
				int remainder_of_ten = rounded_value % 10;
				if ((remainder_of_ten > 5 && rounded_value > 0) || (remainder_of_ten <= 5 && rounded_value < 0)) {
					rounded_value += 10 - remainder_of_ten;
				}
				else {
					rounded_value -= remainder_of_ten;
				}

				if (rounded_value == level) {
					letter_to_draw[biorhythm] = letters[biorhythm];
				}
			}

			for (int letter = 0; letter < 4; letter++) {
				printf("%c", letter_to_draw[letter]);
			}
		}

		printf("\n");
	}

	for (int i = 0; i < 23; i++) {
		if (i % 5 == 0) {
			printf("%d", i);
		}
		else if (i % 5 != 1) {
			printf(" ");
		}
	}
}