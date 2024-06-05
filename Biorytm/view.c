#include "biorytm.h"
#include <stdio.h>

void draw_columns(struct Biorytm(*biorytmy)[4]) {
	for (int i = 20; i > 0; i--) {
		printf("%.3d|     ", abs(i*10 - 100));
		for (int j = 0; j < 4; j++) {
			if ((*biorytmy)[j].current_value * 100 > i * 10 - 100) {
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
	printf("Stopien, %s, %s, %s, %s", (*biorytmy)[0].type, (*biorytmy)[1].type, (*biorytmy)[2].type, (*biorytmy)[3].type);
}
