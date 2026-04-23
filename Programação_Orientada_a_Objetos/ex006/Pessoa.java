import java.util.Scanner;

public class Pessoa {
    protected String nome, cpf;
    protected Data nasc;
    protected char sexo;

    public Pessoa(String nome, String cpf, Data nasc, char sexo) {
        this.nome = nome;
        this.nasc = nasc;
        this.sexo = sexo;
        this.cpf = cpf;
    }

    public Pessoa() {
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

    public int idade(Data hoje) {
        int idade = hoje.getAno() - this.nasc.getAno();
        if (hoje.getMes() < this.nasc.getMes() || (hoje.getMes() == this.nasc.getMes() && hoje.getDia() < this.nasc.getDia())) {
            idade--;
        }
        return idade;
    }
}