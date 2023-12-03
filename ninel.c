#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n, x1, x2, x3, nr_special = 0, copac_par = 0, copac_impar = 0;
	int xmax_impar = 0, xmin_par = INT_MAX;
	long suma = 0;
	double m_a;

	scanf("%d", &n);

	if (n <= 2) { //daca am mai putin de 2 copaci, nu exista copaci speciali
		for (int i = 0; i < n; i++)
			scanf("%d", &x1);
		printf("0\n0.0000000\n0\n0\n"); //afisez doar 0
	} else {
		scanf("%d %d", &x1, &x2); //primii 2 copaci ii citesc separat
		for (int i = 2; i < n; i++) {
			scanf("%d", &x3);
			if (x2 > x1 && x2 > x3) { //verific copacii pe masura ce ii citesc,
				suma += x2;			  //fiindca nu ii pot retine intr-un vector
				nr_special++;
				if ((i - 1) % 2) {
					copac_impar = 1;
					if (x2 > xmax_impar)
						xmax_impar = x2;
				} else {
					copac_par = 1;
					if (x2 < xmin_par)
						xmin_par = x2;
				}
			}
			x1 = x2; //folosesc aceleasi 3 variabile pentru toti copacii
			x2 = x3; //deci trebuie sa le reciclez
		}
	}

	m_a = (double)suma / (double)nr_special;

	if (copac_par == 0) //daca nu exista copaci pari sau impari speciali,
		xmin_par = -1;  //afisez -1
	if (copac_impar == 0)
		xmax_impar = -1;

	printf("%ld\n%.7lf\n%d\n%d\n", suma, m_a, xmax_impar, xmin_par);

	return 0;
}
