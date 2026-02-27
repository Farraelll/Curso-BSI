public static void main(String[] args) {
    Pessoa p1 = new Pessoa();
    p1.nome = "Joao";
    p1.idade = 32;
    p1.sexo = 'M';
    p1.cpf = "111.222.333-44";

    Pessoa p2 = new Pessoa();
    p2.nome = "Carlos";
    p2.idade = 23;
    p2.sexo = 'M';
    p2.cpf = "555.666.777-88";

    Conta c1 = new Conta();
    c1.numero = "0";
    c1.titular = p1;
    c1.saldo = 9999;
    c1.limite = 0;

    Conta c2 = new Conta();
    c2.numero = "1";
    c2.titular = p2;
    c2.saldo = 0;
    c2.limite = 1000;

    System.out.println(c1.saldo);
    System.out.println(c1.titular.nome);
    System.out.println("Saldo da conta " + c2.numero + ": " + c2.saldo);
}
