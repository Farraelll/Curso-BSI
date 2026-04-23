import java.util.Scanner;

public class Pessoa {
    String nome, cpf;
    Data nasc;
    char sexo;

    Pessoa(String nome, String cpf, Data nasc, char sexo) {
        this.nome = nome;
        this.nasc = nasc;
        this.sexo = sexo;
        this.cpf = cpf;
    }

    Pessoa() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o nome: ");
        this.nome = s.nextLine();
        System.out.print("Digite o cpf: ");
        this.cpf = s.nextLine();
        System.out.println("Data de nascimento: ");
        this.nasc = new Data();
        System.out.print("Informe o sexo (M/F): ");
        this.sexo = s.next().charAt(0);
    }

    int idade(Data hoje) {
        int idade = hoje.ano - this.nasc.ano;
        if (hoje.mes < this.nasc.mes || (hoje.mes == this.nasc.mes && hoje.dia < this.nasc.dia)) {
            idade--;
        }
        return idade;
    }
}