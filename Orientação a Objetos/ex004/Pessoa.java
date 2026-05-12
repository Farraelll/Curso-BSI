public class Pessoa {
    String nome, cpf;
    Data nasc;
    char sexo;

    Pessoa(String nome, String cpf, Data dtNasc, char sexo) {
        this.nome = nome;
        this.cpf = cpf;
        this.nasc = dtNasc;
        this.sexo = sexo;
    }

    int idade(Data hoje) {
        int idade = hoje.ano - this.nasc.ano;
        if (hoje.mes < this.nasc.mes || (hoje.mes == this.nasc.mes && hoje.dia < this.nasc.dia)) {
            idade--;
        }
        return idade;
    }
}