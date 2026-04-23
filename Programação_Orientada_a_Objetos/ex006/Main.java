class Banco {
    static void main(){

        // Criação dos objetos de teste
        Pessoa p1 = new Pessoa();
        Pessoa p2 = new Pessoa();
        Pessoa p3 = new Pessoa();
        Pessoa p4 = new Pessoa();

        Gerente g1 = new Gerente("Fernanda", new Data(1, 1, 1980), 'F', "8", "G01", "sddDela");
        Gerente g2 = new Gerente("Ricardo", new Data(2, 2, 1982), 'M', "9", "G02", "superou");

        ContaCorrente cc1 = new ContaCorrente("2", p1, new Data(1, 1, 2020), g1);
        ContaCorrente cc2 = new ContaCorrente("2", p2, new Data(2, 2, 2021), g2);

        ContaPoupanca cp1 = new ContaPoupanca("Yudi", p3, new Data(3, 3, 2022), g1);
        ContaPoupanca cp2 = new ContaPoupanca("PS2", p4, new Data(4, 4, 2023), g2);

        // Testes
        cc1.depositar(500);
        cc2.depositar(300);
        cp1.depositar(1000);
        cp2.depositar(200);

        cc1.sacar(150);
        cp1.sacar(50);

        cc1.transferir(100, cp2);
        cp2.transferir(50, cc2);

        cc1.alterarLimite("sddDela", 500);

        cc1.chequeEspecial(0.5);
        cp1.rendimentos(1.0);

        // Resultados
        cc1.extrato();
        System.out.println();
        cc2.extrato();
        System.out.println();
        cp1.extrato();
        System.out.println();
        cp2.extrato();
    }
}