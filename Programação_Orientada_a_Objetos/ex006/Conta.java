import java.util.Scanner;

public class Conta {
    protected String numero;
    protected Pessoa titular;
    protected Data criacao;
    protected double saldo;
    protected Gerente gerente;

    public Conta(String n, Pessoa t, Data d, Gerente g) {
        this.numero = n;
        this.titular = t;
        this.criacao = d;
        this.gerente = g;
        this.saldo = 0;
        System.out.println("Nova conta adicionada ao sistema.");
    }

    public Conta(Gerente g) {
        Scanner s = new Scanner(System.in);
        System.out.print("Digite o numero da conta: ");
        this.numero = s.nextLine();
        System.out.println("Titular da conta:");
        this.titular = new Pessoa();
        System.out.println("Data de criacao: ");
        this.criacao = new Data();
        this.gerente = g;
        this.saldo = 0;
        System.out.println("Nova conta adicionada ao sistema.");
    }

    public void depositar(double valor) {
        this.saldo += valor;
        System.out.println("Deposito de " + valor + " realizado. Novo saldo: " + this.saldo);
    }

    protected double disponivel() {
        return this.saldo;
    }

    public void extrato() {
        System.out.println("Conta: " + this.numero);
        System.out.println("Titular: " + this.titular.nome + " (CPF: " + this.titular.cpf + ")");
        System.out.println("Saldo disponível para saque: R$ " + this.disponivel());
    }

    public boolean sacar(double valor) {
        if (valor <= this.disponivel()) {
            this.saldo -= valor;
            System.out.println("Saque na conta " + this.numero + " realizado com sucesso. Novo saldo: " + this.saldo);
            return true;
        } else {
            System.out.println("ERRO: Saque na conta " + this.numero + " não foi realizado. Valor disponível: " + this.disponivel());
            return false;
        }
    }

    public boolean transferir(double valor, Conta destino) {
        if (this.sacar(valor)) {
            destino.depositar(valor);
            System.out.println("Transferencia de " + valor + " da conta " + this.numero + " para a conta " + destino.numero + " realizada com sucesso.");
            return true;
        }
        System.out.println("ERRO: Não foi possível transferir " + valor + " da conta " + this.numero + ".");
        return false;
    }
}