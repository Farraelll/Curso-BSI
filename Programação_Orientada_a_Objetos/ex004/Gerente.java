import java.security.cert.TrustAnchor;

public class Gerente extends Pessoa{
    String matricula, senha;

    Gerente(String nome, String cpf, Data nasc, char sexo, String matricula, String senha) {
        super(nome, cpf, nasc, sexo);
        this.matricula = matricula;
        this.senha = senha;
    }
    boolean validarAcesso(String s) {
        return this.senha.equals(s);
    }
}
