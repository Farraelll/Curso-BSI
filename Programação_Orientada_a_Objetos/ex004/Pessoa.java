public class Pessoa {
    String nome, cpf;
    Data dtNasc;
    char sexo;

    Pessoa(String nome, String cpf, Data dtNasc, char sexo) {
        this.nome = nome;
        this.cpf = cpf;
        this.dtNasc = dtNasc;
        this.sexo = sexo;
    }

    int calcularIdade(Data hoje) {
        int idade = hoje.ano - this.dtNasc.ano;
        if (hoje.mes < this.dtNasc.mes || (hoje.mes == this.dtNasc.mes && hoje.dia < this.dtNasc.dia)) {
            idade--;
        }
        return idade;
    }
}