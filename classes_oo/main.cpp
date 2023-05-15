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
            cout << "Construtor criado!" << endl;
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
            cout << "Construtor criado!" << endl;
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
        float setSalario(float salario) {
            cin >> salario;
        }
};

class Escola{
    private:
        string nomeEscola;
        string cnpj;
        vector<Funcionario> funcionarios[5];
        vector<Aluno> aluno[10];
    
    public:
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
        /*vector<Funcionario> getFuncionarios() {
            return funcionarios;
        }
        void setFuncionarios(vector<Funcionario>){
            cin >> funcionarios;
        }*/

};

int main(int argc, char const *argv[])
{
    cout << "RODOU!" << endl;
    return 0;
}
