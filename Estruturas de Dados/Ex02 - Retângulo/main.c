#include <stdio.h>
#include <math.h>


void calc_info_retangulo(double comp, double larg, double *area, double *per, double *diag)
{
    *area = comp * larg;
    *per = 2 * (comp + larg);
    *diag = sqrt((comp * comp) + (larg * larg));
};

int main()
{
    double comprimento;
    double largura;
    double area;
    double per;
    double diag;

    scanf("%lf", &comprimento);
    scanf("%lf", &largura);
    calc_info_retangulo(comprimento, largura, &area, &per, &diag);

    printf("Área: %lf\n", area);
    printf("Perímetro: %lf\n", per);
    printf("Diagonal: %lf\n", diag);
};
