#include <stdio.h>

void select_sort(int nr_materii, int pc_ramas[]) //sortare prin selectie
{
	for (int i = 0; i < nr_materii - 1; i++) {
		for (int j = i + 1; j < nr_materii; j++) {
			if (pc_ramas[i] > pc_ramas[j]) { //interschimbarea cu XOR
				pc_ramas[i] = pc_ramas[i] ^ pc_ramas[j];
				pc_ramas[j] = pc_ramas[i] ^ pc_ramas[j];
				pc_ramas[i] = pc_ramas[i] ^ pc_ramas[j];
			}
		}
	}
}

int main(void)
{
	int nr_materii, note[105], pc[105], pc_ramas[105];
	int p_curent = 0, p_min, p_max = 0, nr_mariri;

	scanf("%d", &nr_materii); //citesc datele problemei
	for (int i = 0; i < nr_materii; i++)
		scanf("%d", &note[i]);
	for (int i = 0; i < nr_materii; i++)
		scanf("%d", &pc[i]);
	scanf("%d", &p_min);

	for (int i = 0; i < nr_materii; i++) { //calculez nr de puncte si
		p_curent += note[i] * pc[i];	   //construiesc vectorul cu pc ramase
		pc_ramas[i] = (10 - note[i]) * pc[i];
		p_max += 10 * pc[i];	//presupun ca a luat 10 la toate materiile
	}

	if (p_min > p_max) { //daca sunt prea putin puncte si cu nota 10 la toate
		printf("-1\n");  //materiile, pb nu are sol si afisez -1
	} else {
		select_sort(nr_materii, pc_ramas);
		//cat timp sunt prea putine puncte, adun ce ar mai putea obtine cu 10
		for (nr_mariri = nr_materii - 1; p_curent < p_min; nr_mariri--)
			p_curent += pc_ramas[nr_mariri];

		printf("%d\n", nr_materii - nr_mariri - 1);
	}

	return 0;
}
