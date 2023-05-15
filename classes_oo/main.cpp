#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Aluno{
    string nomeCompleto;
    string cpf;
    string idade;
    string serie;
    long int matricula;


};

class Funcionario{
    string nomeCompleto;
    string cpf;
    string idade;
    string cargo;
    long int matricula;
    float salario;

    
};

class Escola{
    string nomeEscola;
    string cnpj;
    vector<Funcionario> funcionarios[5];
    vector<Aluno> aluno[10];
    
};

int main(int argc, char const *argv[])
{
    return 0;
}
