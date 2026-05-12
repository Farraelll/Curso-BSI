public class ContaPoupanca extends Conta {

    ContaPoupanca(String n, Pessoa t, Data d, Gerente g) {
        super(n, t, d, g);
    }

    ContaPoupanca(Gerente g) {
        super(g);
    }

    void extrato() {
        System.out.println("*** EXTRATO DE POUPANCA ***");
        super.extrato();
    }

    void rendimentos(double juro) {
        this.saldo += this.saldo * (juro / 100.0);
    }
}