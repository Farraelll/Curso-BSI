public class Conta {
    String numero;
    Pessoa titular;
    Data criacao;
    double saldo, limite;

    Conta(String numero, Pessoa titular, Data criacao) {
        this.numero = numero;
        this.titular = titular;
        this.saldo = 0;
        this.criacao = criacao;
        System.out.println("Nova conta adicionada ao sistema.");
    }

    void depositar(int valor) {
        this.saldo += valor;
    }
}

