class Banco {
    public static void main(String[] args){
        Data hoje = new Data(11, 3, 2026);


        Pessoa p1 = new Pessoa("Renato", "123", new Data(15, 3, 2008), 'M');
        Pessoa p2 = new Pessoa("Carlos", "456", new Data(10, 8, 1990), 'M');


        System.out.print("Data de nascimento de " + p1.nome + ": ");
        p1.dtNasc.imprimir();


        System.out.println("Idade de " + p1.nome + " hoje: " + p1.calcularIdade(hoje) + " anos.");
        System.out.println("Idade de " + p2.nome + " hoje: " + p2.calcularIdade(hoje) + " anos.");


        Conta c1 = new Conta("1234", p1);
        Conta c2 = new Conta("5678", p2, 300);


        c1.extrato();
        c2.extrato();
        c1.sacar(150);
        c1.transferir(100, c2);
        c1.sacar(100);
        c1.depositar(100);
        c1.transferir(200, c2);

        for(int i = 1; i <= 120; i += 1) {
            c1.chequeEspecial(0.5);

            if (i % 30 == 0) {
                System.out.println("Saldo após " + i + " dias: " + c1.saldo);
            }
        }
    }
}
