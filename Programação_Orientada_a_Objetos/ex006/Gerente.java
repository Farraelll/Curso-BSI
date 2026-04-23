import java.util.Scanner;

public class Gerente extends Pessoa {
    private String matricula, senha;

    public Gerente() {
        super();
        Scanner s = new Scanner(System.in);
        System.out.print("Digite sua matricula: ");
        this.matricula = s.nextLine();
        this.senha = "123456";
    }

    public Gerente(String n, Data d, char s, String c, String m, String p) {
        super();
        this.matricula = m;
        this.senha = p;
    }

    public boolean validarAcesso(String s) {
        return this.senha.equals(s);
    }

    public boolean validarAcesso() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite a senha: ");
        String ss = s.nextLine();
        return this.validarAcesso(ss);
    }
    public void alterarSenha(String atual, String nova) {
        if (this.senha.equals(atual)) {
            this.senha = nova;
            System.out.println("Senha alterada com sucesso.");
        }
        else {
            System.out.println("A senha informada está incorreta.");
        }
    }
}