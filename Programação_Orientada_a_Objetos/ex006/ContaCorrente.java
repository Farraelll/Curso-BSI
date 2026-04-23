import java.util.Scanner;

public class ContaCorrente extends Conta {
    private double limite;

    public ContaCorrente(String n, Pessoa t, Data d, Gerente g) {
        super(n, t, d, g);
        this.limite = 200.0;
    }

    public ContaCorrente(Gerente g) {
        super(g);
        this.limite = 200.0;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(String senha , double l ) {
        if (this.gerente.validarAcesso(senha)) {
            this.limite = l;
        }
    }

    public void alterarLimite(String pwd, double l) {
        if (this.gerente.validarAcesso(pwd)) {
            this.limite = l;
            System.out.println("Limite alterado com sucesso para: " + this.limite);
        } else {
            System.out.println("ERRO: Senha inválida.");
        }
    }

    public void alterarLimite() {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o novo limite: ");
        double l = s.nextDouble();
        if (this.gerente.validarAcesso()) {
            this.limite = l;
            System.out.println("Limite alterado com sucesso para: " + this.limite);
        } else {
            System.out.println("ERRO: Senha inválida.");
        }
    }

    protected double disponivel() {
        return this.saldo + this.limite;
    }

    public void extrato() {
        System.out.println("*** EXTRATO DE CONTA-CORRENTE ***");
        super.extrato();
    }

    public void chequeEspecial(double juro) {
        if (this.saldo < 0) {
            this.saldo += this.saldo * (juro / 100.0);
        }
    }
}