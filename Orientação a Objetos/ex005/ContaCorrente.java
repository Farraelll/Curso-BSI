import java.util.Scanner;

public class ContaCorrente extends Conta {
    double limite;

    ContaCorrente(String n, Pessoa t, Data d, Gerente g) {
        super(n, t, d, g);
        this.limite = 200.0;
    }

    ContaCorrente(Gerente g) {
        super(g);
        this.limite = 200.0;
    }

    void alterarLimite(String pwd, double l) {
        if (this.ger.validarAcesso(pwd)) {
            this.limite = l;
            System.out.println("Limite alterado com sucesso para: " + this.limite);
        } else {
            System.out.println("ERRO: Senha inválida.");
        }
    }

    void alterarLimite() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o novo limite: ");
        double l = s.nextDouble();
        if (this.ger.validarAcesso()) {
            this.limite = l;
            System.out.println("Limite alterado com sucesso para: " + this.limite);
        } else {
            System.out.println("ERRO: Senha inválida.");
        }
    }

    double disponivel() {
        return this.saldo + this.limite;
    }

    void extrato() {
        System.out.println("*** EXTRATO DE CONTA-CORRENTE ***");
        super.extrato();
    }

    void chequeEspecial(double juro) {
        if (this.saldo < 0) {
            this.saldo += this.saldo * (juro / 100.0);
        }
    }
}