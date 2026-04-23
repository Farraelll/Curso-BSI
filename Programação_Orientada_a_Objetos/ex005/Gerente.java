import java.util.Scanner;

public class Gerente extends Pessoa {
    String matricula, senha;

    Gerente() {
        super();
        Scanner s = new Scanner(System.in);
        System.out.print("Digite sua matricula: ");
        this.matricula = s.nextLine();
        this.senha = "123456"; // Senha padrão definida pelo eBook
    }

    Gerente(String n, Data d, char s, String c, String m, String p) {
        super();
        this.matricula = m;
        this.senha = p;
    }

    boolean validarAcesso(String s) {
        return this.senha.equals(s);
    }

    boolean validarAcesso() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite a senha: ");
        String ss = s.nextLine();
        return this.validarAcesso(ss);
    }
}