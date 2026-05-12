public class ContaPoupanca extends Conta {

    public ContaPoupanca(String n, Pessoa t, Data d, Gerente g) {
        super(n, t, d, g);
    }

    public ContaPoupanca(Gerente g) {
        super(g);
    }

    public void extrato() {
        System.out.println("*** EXTRATO DE POUPANCA ***");
        super.extrato();
    }

    public void rendimentos(double juro) {
        this.saldo += this.saldo * (juro / 100.0);
    }
}