import java.util.Scanner;

public class Conta {
    String numero;
    Pessoa titular;
    Data criacao;
    double saldo;
    Gerente ger;

    Conta(String n, Pessoa t, Data d, Gerente g) {
        this.numero = n;
        this.titular = t;
        this.criacao = d;
        this.ger = g;
        this.saldo = 0;
        System.out.println("Nova conta adicionada ao sistema.");
    }

    Conta(Gerente g) {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o numero da conta: ");
        this.numero = s.nextLine();
        System.out.println("Titular da conta:");
        this.titular = new Pessoa();
        System.out.println("Data de criacao: ");
        this.criacao = new Data();
        this.ger = g;
        this.saldo = 0;
        System.out.println("Nova conta adicionada ao sistema.");
    }

    void depositar(double valor) {
        this.saldo += valor;
        System.out.println("Deposito de " + valor + " realizado. Novo saldo: " + this.saldo);
    }

    double disponivel() {
        return this.saldo;
    }

    void extrato() {
        System.out.println("Conta: " + this.numero);
        System.out.println("Titular: " + this.titular.nome + " (CPF: " + this.titular.cpf + ")");
        System.out.println("Saldo disponível para saque: R$ " + this.disponivel());
    }

    boolean sacar(double valor) {
        if (valor <= this.disponivel()) {
            this.saldo -= valor;
            System.out.println("Saque na conta " + this.numero + " realizado com sucesso. Novo saldo: " + this.saldo);
            return true;
        } else {
            System.out.println("ERRO: Saque na conta " + this.numero + " não foi realizado. Valor disponível: " + this.disponivel());
            return false;
        }
    }

    boolean transferir(double valor, Conta destino) {
        if (this.sacar(valor)) {
            destino.depositar(valor);
            System.out.println("Transferencia de " + valor + " da conta " + this.numero + " para a conta " + destino.numero + " realizada com sucesso.");
            return true;
        }
        System.out.println("ERRO: Não foi possível transferir " + valor + " da conta " + this.numero + ".");
        return false;
    }
}