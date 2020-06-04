#include "CP_DATA.h"
#include <stdio.h>


void main_menu(int n) {
	printf("**************************************************** CESTOVNY PORIADOK *************************************************\n\n\n\n");
	printf("				   	            CISLO ZASTAVKY: %d\n\n", n);
	printf("				   	    1.        ZOBRAZENIE CP\n\n");
	printf("				   	    2.  ZOBRAZENIE NAJBLIZSIEHO SPOJA\n\n");
	printf("				   	    3.           KONIEC\n\n\n");
	printf("				   	               TVOJA VOLBA:");
}

void start_menu() {
	printf("**************************************************** CESTOVNY PORIADOK *************************************************\n\n\n\n");
	printf("				   	    1.     VYBER CISLO ZASTAVKY:  ");

}

void print_time(int n, int delta, int prvy_spoj_H, int prvy_spoj_M, int posled_spoj_H, int rano_start, int rano_end, int poobede_start, int poobede_end, int interval_normal, int interval_rano, int interval_poobede) {
	int M = prvy_spoj_M + (n - 1) * delta;
	int H = prvy_spoj_H + (M / 60);
	if (M >= 60) 
		M = M - (M / 60) * 60;

	while (H <= posled_spoj_H) {
		if (M < 60)
			printf("						%02d | ", H);

		while (H < rano_start) {
			if (M < 60)
				printf("%02d ", M);
			M = M + interval_normal;
			if (M >= 60) {
				M = M - 60;
				H++;
				printf("\n");
				printf("						%02d | ", H);
			}
		}
		while (H >= rano_start && H <= rano_end) {
			printf("%02d ", M);
			M = M + interval_rano;
			if (M >= 60) {
				M = M - 60;
				H++;
				printf("\n");
				printf("						%02d | ", H);
			}
		}
		while (H > rano_end && H < poobede_start) {
			printf("%02d ", M);
			M = M + interval_normal;
			if (M >= 60) {
				M = M - 60;
				H++;
				printf("\n");
				printf("						%02d | ", H);
			}
		}
		while (H >= poobede_start && H <= poobede_end) {
			printf("%02d ", M);
			M = M + interval_poobede;
			if (M >= 60) {
				M = M - 60;
				H++;
				printf("\n");
				printf("						%02d | ", H);
			}
		}
		while (H > poobede_end && H <= posled_spoj_H) {
			printf("%02d ", M);
			M = M + interval_normal;
			if (M >= 60) {
				M = M - 60;
				H++;
				printf("\n");
				if (H < posled_spoj_H + 1)
					printf("						%02d | ", H);
			}
		}

	}
}


void main() {
	int choice, n, findH, findM;

	while (TRUE) {
		CLEAR_SCREEN();
		start_menu();
		scanf("%d", &n);
		while (n < 1) {
			CLEAR_SCREEN();
			start_menu();
			scanf("%d", &n);
		}
		CLEAR_SCREEN();
		main_menu(n);
		scanf("%d", &choice);
		while (choice != 1 && choice != 2 && choice != 3)
			scanf("%d", &choice);

		switch (choice) {
		case 1: {
			CLEAR_SCREEN();
			printf("************************************************** CP ZASTAVKY CISLO %d **********************************************\n\n\n", n);
			print_time(n, DELTA, PRVY_SPOJ_H, PRVY_SPOJ_M, POSLED_SPOJ_H, RANO_START, RANO_END, POOBEDE_START, POOBEDE_END, INTERVAL_NORMAL, INTERVAL_RANO, INTERVAL_POOBEDE);
			break;
		}
		case 2: {
			CLEAR_SCREEN();
			printf("******************************************* NAJBLIZSI SPOJ ZO ZASTAVKY CISLO %d ***************************************\n\n\n", n);
			printf("						   Hodina: < %02d ; %02d > : ", PRVY_SPOJ_H, POSLED_SPOJ_H);
			scanf("%d", &findH);
			printf("						   Minuta: ");
			scanf("%d", &findM);
			///find_next(findH, findM, n, DELTA, PRVY_SPOJ_H, PRVY_SPOJ_M, POSLED_SPOJ_H, RANO_START, RANO_END, POOBEDE_START, POOBEDE_END, INTERVAL_NORMAL, INTERVAL_RANO, INTERVAL_POOBEDE);
			break;
		}
		case 3:
			return;
		}
		getchar(); getchar();
	}
}
