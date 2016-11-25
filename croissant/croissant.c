#include <stdio.h>
#include <stdlib.h>

int main() {
	int tab[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d", &tab[i]);
	}

	int count = 0;
	int i = 0;
	// croissant, decroissant, egal, aleatoire
	for (; i < 9; i++) {
		if (tab[i] < tab [i + 1]) {
			if (count < 0) {
				printf("Aleatoire\n");
				i = 10;
			}
			count++; // croissant
		}
		if (tab[i] > tab [i + 1]) {
			if (count > 0) {
				printf("Aleatoire\n");
				i = 10;
			}
			count--;
		}
	}

	if (i != 11) {
		if (count == 0)
			printf("Egaux\n");
		if (count > 0)
			printf("Croissant\n");
		if (count < 0)
			printf("Decroissant\n");
	}
}