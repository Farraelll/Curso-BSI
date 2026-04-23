import java.util.Scanner;

public class Data{
    private int dia, mes, ano;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public Data() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o dia: ");
        this.dia = s.nextInt();
        System.out.print("Digite o mes: ");
        this.mes = s.nextInt();
        System.out.print("Digite o ano: ");
        this.ano = s.nextInt();
    }

    public int getDia(){
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public int getAno() {
        return ano;
    }

    public void imprimir() {
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }

    public boolean maior(Data d2) {
        if (this.ano != d2.ano) {
            return this.ano > d2.ano;
        }
        if (this.mes != d2.mes) {
            return this.mes > d2.mes;
        }
        return this.dia > d2.dia;
    }
}