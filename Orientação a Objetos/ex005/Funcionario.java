import java.util.Scanner;

public class Funcionario extends Pessoa {
    int salario;

    Funcionario(String nome, String cpf, Data nasc, char sexo, int salario) {
        super(nome, cpf, nasc, sexo);
        this.salario = salario;
    }

    Funcionario() {
        Scanner s = new Scanner(System.in);
        super();
        this.salario = Integer.parseInt(s.nextLine());
    }

    double bonificacao() {
        return this.salario * 0.1;
    }
}
