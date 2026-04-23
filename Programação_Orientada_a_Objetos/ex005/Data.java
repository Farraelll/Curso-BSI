import java.util.Scanner;

public class Data{
    int dia, mes, ano;

    Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    Data() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o dia: ");
        this.dia = s.nextInt();
        System.out.print("Digite o mes: ");
        this.mes = s.nextInt();
        System.out.print("Digite o ano: ");
        this.ano = s.nextInt();
    }

    void imprimir() {
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }

    boolean maior(Data d2) {
        if (this.ano != d2.ano) {
            return this.ano > d2.ano;
        }
        if (this.mes != d2.mes) {
            return this.mes > d2.mes;
        }
        return this.dia > d2.dia;
    }
}