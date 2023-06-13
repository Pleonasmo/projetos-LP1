#include "Gerente.hpp"

//Construtor vazio:
Gerente::Gerente(){
    participacaoLucros = 0;
}

//Construtor parametrizado:
Gerente::Gerente(float pl){
    participacaoLucros = pl;
}

//Getter e Setter:
float Gerente::getParticipacaoLucros(){
    return participacaoLucros;
}

void Gerente::setParticipacaoLucros(float pl){
    participacaoLucros = pl;
}

//Metodos virtuais de Funcionario:
float Gerente::calcularSalario(int diasFaltas){
    float salario_gerente;
    try{
        salario_gerente = stof(getSalario());
    } catch(const std::invalid_argument e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_gerente = 0;
    } catch(const std::out_of_range e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_gerente = 0;
    }

    //Salario por dia trabalhado:
    float salarioPorDia = salario_gerente/30;

    //Calculo de salario:
    float descontoFaltas = diasFaltas*salarioPorDia;
    float adicionalFilhos = getQtdFilhos()*100;
    float salarioFinal = salario_gerente + adicionalFilhos + getParticipacaoLucros() - descontoFaltas;
}

float Gerente::calcularRecisao(Data desligamento){
    return 3;
}