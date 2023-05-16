#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Aluno{
    private:
        //Atributos de Aluno:
        string nomeCompleto;
        string cpf;
        string idade;
        string serie;
        long int matricula;

    public:
        //Construtor de Aluno:
        Aluno(){
            nomeCompleto = "aluno";
            cpf = "000.000.000-00";
            idade = "00";
            serie = "0";
            matricula = 0;
        }

        //Construtor parametrizado de Aluno:
        Aluno(string nomeCompleto_in, string cpf_in, string idade_in, string serie_in, long int matricula_in){
            nomeCompleto = nomeCompleto_in;
            cpf = cpf_in;
            idade = idade_in;
            serie = serie_in;
            matricula = matricula_in;
        }

        //Getters e Setters:
        string getNomeCompleto() {
             return nomeCompleto;
        }
        void setNomeCompleto(string nomeCompleto) {
            cin >> nomeCompleto;
        }
        string getCpf() {
             return cpf;
        }
        void setCpf(string cpf) {
            cin >> cpf;
        }
        string getIdade() {
             return idade;
        }
        void setIdade(string idade) {
            cin >> idade;
        }
        string getSerie() {
             return serie;
        }
        void setSerie(string serie) {
            cin >> serie;
        }
        long int getMatricula() {
             return matricula;
        }
        void setMatricula(int matricula) {
            cin >> matricula;
        }
};

class Funcionario{
    private:
        //Atributos de Funcionario:
        string nomeCompleto;
        string cpf;
        string idade;
        string cargo;
        long int matricula;
        float salario;

    public:
        //Construtor de Funcionario:
        Funcionario(){
            nomeCompleto = "funcionario";
            cpf = "000.000.000-00";
            idade = "00";
            cargo = "cargo";
            matricula = 0;
            salario = 0.0;
        }

        //Construtor parametrizado de Funcionario:
        Funcionario(string nomeCompleto_in, string cpf_in, string idade_in, string cargo_in, long int matricula_in, float salario_in){
            nomeCompleto = nomeCompleto_in;
            cpf = cpf_in;
            idade = idade_in;
            cargo = cargo_in;
            matricula = matricula_in;
            salario = salario_in;
        }

        //Getters e Setters:
        string getNomeCompleto() {
             return nomeCompleto;
        }
        void setNomeCompleto(string nomeCompleto) {
            cin >> nomeCompleto;
        }
        string getCpf() {
             return cpf;
        }
        void setCpf(string cpf) {
            cin >> cpf;
        }
        string getIdade() {
             return idade;
        }
        void setIdade(string idade) {
            cin >> idade;
        }
        string getCargo() {
             return cargo;
        }
        void setCargo(string cargo) {
            cin >> cargo;
        }
        long int getMatricula() {
             return matricula;
        }
        void setMatricula(int matricula) {
            cin >> matricula;
        }
        float getSalario() {
            return salario;
        }
        void setSalario(float salario) {
            cin >> salario;
        }
};

class Escola{
    private:
        //Atributos da escola:
        string nomeEscola;
        string cnpj;
        Funcionario *funcionarios = new Funcionario[5];
        Aluno alunos[10];
    
    public:
        //Getters e Setters da escola:
        string getNomeEscola() {
             return nomeEscola;
        }
        void setNomeEscola(string nomeEscola) {
            cin >> nomeEscola;
        }
        string getCnpj() {
             return cnpj;
        }
        void setCnpj(string cpf) {
            cin >> cnpj;
        }
        Funcionario* getFuncionarios() {
            return funcionarios;
        }
        void setFuncionarios(Funcionario funcionario, int iterator) {
            if(iterator < sizeof(funcionarios))
                funcionarios[iterator] = funcionario;
        }
        Aluno* getAlunos() {
            return alunos;
        }
        void setAlunos(Aluno aluno, int iterator) {
            if(iterator < sizeof(alunos))
                alunos[iterator] = aluno;
        }
    
    //Funções da Escola:
    void listarAlunos(){
        Aluno *alunos_escola = getAlunos();
        for(int i = 0; i < sizeof(alunos_escola); i++){
            cout << alunos_escola[i].getNomeCompleto() << endl; 
        }
        cout << endl;
    }

    void listarFuncionarios(){
        Funcionario* funcionarios_escola = getFuncionarios();
        for(int i = 0; i < sizeof(funcionarios_escola); i++) {
            cout << funcionarios_escola[i].getNomeCompleto() << endl;
        }
        cout << endl;
    }

    void adicionarAluno(string nomeCompleto, string cpf, string idade, string serie, long int matricula, int iterator){
        Aluno aluno_escola;
        aluno_escola.setNomeCompleto(nomeCompleto);
        aluno_escola.setCpf(cpf);
        aluno_escola.setIdade(idade);
        aluno_escola.setSerie(serie);
        aluno_escola.setMatricula(matricula);

        setAlunos(aluno_escola, iterator);
    }

    void adicionarFuncionario(string nomeCompleto, string cpf, string idade, string cargo, long int matricula, float salario, int iterator){
        Funcionario funcionario_escola;
        funcionario_escola.setNomeCompleto(nomeCompleto);
        funcionario_escola.setCpf(cpf);
        funcionario_escola.setIdade(idade);
        funcionario_escola.setCargo(cargo);
        funcionario_escola.setMatricula(matricula);
        funcionario_escola.setSalario(salario);

        setFuncionarios(funcionario_escola, iterator);
    }

    float somarSalarioFuncionarios(Funcionario *funcionarios){
        float soma = 0;
        for(int i = 0; i < sizeof(funcionarios); i++){
            soma += funcionarios[i].getSalario();
        }

        return soma;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
