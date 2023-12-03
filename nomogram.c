#include <stdio.h>

void citire_matrice(int *pn, int *pm, int a[105][105],
					int linii[105][105], int coloane[105][105])
{
	scanf("%d %d", pn, pm);
	for (int i = 1; i <= *pn; i++) { //retin restrictiile pentru linii
		scanf("%d", &linii[i][0]);   //si coloane in 2 matrici
		for (int j = 1; j <= linii[i][0]; j++)
			scanf("%d", &linii[i][j]);
	}
	for (int i = 1; i <= *pm; i++) { //linii[k][0] si
		scanf("%d", &coloane[i][0]); //coloane[k][0] este mereu nr de grupuri
		for (int j = 1; j <= coloane[i][0]; j++)
			scanf("%d", &coloane[i][j]);
	}
	for (int i = 1; i <= *pn; i++) {
		for (int j = 1; j <= *pm; j++)
			scanf("%d", &a[i][j]);
	}
}

int verificare_linie(int i, int m, int linii[], int a[105][105])
{ //verific daca fiecare linie respecta restrictiile
	int grup_curent = 1, dim_grup = 0;
	for (int j = 1; j <= m; j++) {
		if (a[i][j] == 1) { //daca am 1 maresc dimensiunea grupului
			dim_grup++;
		} else { //daca am 0:
			if (j == 1) { //ignor daca este la inceput de linie
				continue;
			} else { //daca acel 0 este precedat de un 1 atunci este sfarsitul
				if (a[i][j - 1] == 1) { //unui grup si verific dimensiunea
					if (dim_grup != linii[grup_curent])
						return -1; //returnez -1 daca nu respecta
					grup_curent++; //reinitializez variabilele daca respecta
					dim_grup = 0;
				}
			}
		}
	}
	if (a[i][m] == 1) { //daca linia se termina cu 1, trebuie sa verific
		if (dim_grup != linii[grup_curent]) //din nou, la final
			return -1;
	}
	return 1;
}

int verificare_coloana(int n, int j, int coloane[], int a[105][105])
{ //functia este identica cu verificare_linie, dar verifica coloane
	int grup_curent = 1, dim_grup = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i][j] == 1) {
			dim_grup++;
		} else {
			if (i == 1) {
				continue;
			} else {
				if (a[i - 1][j] == 1) {
					if (dim_grup != coloane[grup_curent])
						return -1;
					grup_curent++;
					dim_grup = 0;
				}
			}
		}
	}
	if (a[n][j] == 1) {
		if (dim_grup != coloane[grup_curent])
			return -1;
	}
	return 1;
}

int main(void)
{
	int a[105][105], linii[105][105], coloane[105][105];
	int T, n, m, ok;

	scanf("%d", &T);
	for (int contor = 0; contor < T; contor++) {
		ok = 1; //semaforul trebuie reinitializat la fiecare pas
		citire_matrice(&n, &m, a, linii, coloane);
		for (int i = 1; i <= n && ok; i++) { //verific fiecare linie
			if (verificare_linie(i, m, linii[i], a) == -1) {
				printf("Eroare\n");
				ok = 0;
			}
		}
		for (int j = 1; j <= m && ok; j++) { //si fiecare coloana
			if (verificare_coloana(n, j, coloane[j], a) == -1) {
				printf("Eroare\n");
				ok = 0;
			}
		}
		if (ok)
			printf("Corect\n");
	}

	return 0;
}
