#include <stdio.h>

void nr_cifre(int x, int cifre[]) //functie care numara de cate ori apare
{								  //fiecare cifra
	for (int i = 0; i <= 9; i++)
		cifre[i] = 0;

	while (x) {
		cifre[x % 10]++;
		x /= 10;
	}
}

int nr_cresc(int cifre[]) //functie care primeste ca param vectorul cu nr de
{						  //cifre si returneaza un nr cu acele cifre in ordine
	int x_cresc = 0;      //crescatoare
	for (int i = 1; i <= 9; i++) {	//ignor cifrele de 0
		for (int j = 1; j <= cifre[i]; j++)
			x_cresc = x_cresc * 10 + i;
	}

	return x_cresc;
}

int nr_desc(int cifre[]) //functie care primeste ca param vectorul cu nr de
{						 //cifre si returneaza un nr cu acele cifre in ordine
	int x_desc = 0;		 //descrescatoare
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cifre[i]; j++)
			x_desc = x_desc * 10 + i;
	}

	return x_desc;
}

int mai_apare(int x, int valori[], int nr_valori)	//Verifica daca se repeta x
{
	for (int i = 0; i < nr_valori; i++) {
		if (x == valori[i])
			return i;	//returneaza pozitia pe care se repeta
	}
	return -1;	//returneaza -1 daca nu se repeta
}

int main(void)
{
	int x, cifre[10] = {0}, x_cresc, x_desc;
	int valori[105] = {0}, nr_valori = 0, poz = -1;
	scanf("%d", &x);
	while (poz == -1) {	//repet algorimul cat timp nr nu se repeta
		nr_cifre(x, cifre);
		x_cresc = nr_cresc(cifre);
		x_desc = nr_desc(cifre);
		x = x_desc - x_cresc;
		poz = mai_apare(x, valori, nr_valori); //caut daca se repeta nr
		valori[nr_valori++] = x;
	}

	printf("%d\n", poz);
	for (int i = poz; i < nr_valori - 1; i++) //afisez nr care se repeta,
		printf("%d ", valori[i]);			  //retinute in vectorul valori
	printf("\n");

	return 0;
}
