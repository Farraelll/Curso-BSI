#include <stdio.h>
#include <math.h>

void calc_info_retangulo(double comp, double larg, double* area, double* per, double* diag) {
	*area = comp * larg;
	*per = 2 * (comp + larg);
	*diag = sqrt((comp * comp) + (larg * larg));
}

int main() {
	double comprimento;
	double largura;
	double area;
	double per;
	double diag;

	printf("Digite o comprimento: ");
	if (scanf(" %lf", &comprimento) != 1) {
		printf("Entrada inválida para o comprimento.\n");
		return 1;
	}

	printf("Digite a largura: ");
	if (scanf(" %lf", &largura) != 1) {
		printf("Entrada inválida para a largura.\n");
		return 1;
	}

	calc_info_retangulo(comprimento, largura, &area, &per, &diag);

	printf("Área: %lf\n", area);
	printf("Perímetro: %lf\n", per);
	printf("Diagonal: %lf\n", diag);

	return 0;
}
