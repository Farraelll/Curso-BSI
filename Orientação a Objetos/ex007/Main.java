void main() {
	
	// Criação dos objetos de teste
	ArrayList<Pessoa> p = new ArrayList<>();
	
	for (int i = 0; i < 4; i++) {
		p.add(new Pessoa());
	}
	
	Gerente g1 = new Gerente("Fernanda", new Data(1, 1, 1980), 'F', "8", "G01", "sddDela");
	Gerente g2 = new Gerente("Ricardo", new Data(2, 2, 1982), 'M', "9", "G02", "superou");
	
	Corrente cc1 = new Corrente("2", p.get(0), new Data(1, 1, 2020), g1);
	Corrente cc2 = new Corrente("2", p.get(1), new Data(2, 2, 2021), g2);
	
	Poupanca cp1 = new Poupanca("Yudi", p.get(2), new Data(3, 3, 2022), g1);
	Poupanca cp2 = new Poupanca("PS2", p.get(3), new Data(4, 4, 2023), g2);
	
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