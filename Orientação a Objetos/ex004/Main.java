class Banco {
    static void main(){
        Data hoje = new Data(11, 3, 2026);


        Pessoa p1 = new Pessoa("Renato", "123", new Data(15, 3, 2008), 'M');
        Pessoa p2 = new Pessoa("Carlos", "456", new Data(10, 8, 1990), 'M');
        Gerente g1 = new Gerente("Carlos", "000", new Data(13, 13, 1313), 'F', "senha");

        System.out.print("Data de nascimento de " + p1.nome + ": ");
        p1.nasc.imprimir();


        System.out.println("Idade de " + p1.nome + " hoje: " + p1.idade(hoje) + " anos.");
        System.out.println("Idade de " + p2.nome + " hoje: " + p2.idade(hoje) + " anos.");


        ContaCorrente cc1 = new ContaCorrente("1234", p1, 200, new Data(12, 12, 1212));
        ContaPoupanca cp1 = new ContaPoupanca("5678", p2, new Data(21, 21, 21));


        cc1.extrato();
        cp1.extrato();
        cc1.sacar(150);
        cp1.sacar(10);
        cc1.transferir(100, cp1);
        cc1.sacar(100);
        cc1.depositar(100);
        cc1.transferir(200, cp1);

        for(int i = 1; i <= 120; i += 1) {
            cc1.chequeEspecial(0.5);

            if (i % 30 == 0) {
                System.out.println("Saldo após " + i + " dias: " + cc1.saldo);
            }
        }
        for(int i = 1; i <= 120; i += 1) {
            cp1.rendimentos(0.5);

            if (i % 30 == 0) {
                System.out.println("Saldo após " + i + " dias: " + cc1.saldo);
            }
        }
    }
}
