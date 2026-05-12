public class ContaCorrente extends Conta {
    double lim;

    ContaCorrente(String numero, Pessoa titular, Data c, double l) {
        super(numero, titular, c);
        this.lim = l;
    }

    public ContaCorrente(String number, Pessoa p1, int i, Data criacao) {
        super(number, p1, criacao);
    }

    double disponivel() {
        return this.saldo + this.limite;
    }

    boolean sacar(int valor) {
        if (valor <= this.disponivel()) {
            this.saldo -= valor;
            System.out.println("Saque na conta " + this.numero + " realizado com sucesso. Novo saldo: " + this.saldo);
            return true;
        }
        else {
            System.out.println("ERRO: Saque na conta " + this.numero + " não foi realizado. Valor disponível: " + this.disponivel());
            return false;
        }
    }

    boolean transferir(int valor, Conta destino) {
        if (this.sacar(valor)) {
            destino.depositar(valor);
            System.out.println("Transferencia de " + valor + " da conta " + this.numero + " para a conta " + destino.numero + " foi realizado com sucesso.");
            return true;
        }
        System.out.println("ERRO: Não foi possível transferir " + valor + " da conta " + this.numero + " para a conta " + destino.numero + ". Valor disponível: " + this.disponivel());
        return false;
    }

    void extrato() {
        System.out.println("***EXTRATO DA CONTA***");
        System.out.println("Conta: " + this.numero);
        System.out.println("Titular:" + this.titular.cpf);
        System.out.println("Saldo disponível para saque:" + this.disponivel() );
    }

    void chequeEspecial(double juros) {
        if (this.saldo < 0) {
            this.saldo *=  (juros + 1);
        }
    }
}
