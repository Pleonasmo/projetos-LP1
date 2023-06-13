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

//Metodos virtuais de Funcionario sobrescritos para Gerente:
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

    return salarioFinal;
}

float Gerente::calcularRecisao(Data desligamento){
    //Conversão de tipo do salario:
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

    //Calculo de dias trabalhados na empresa:
    Data dataInicio = getIngressoEmpresa();
    Data dataFim = desligamento;

    int diferencaAnos = dataFim.ano - dataInicio.ano;
    int diferencaMeses = dataFim.mes - dataInicio.mes;
    int diferencaDias = dataFim.dia - dataInicio.dia;

    if(diferencaMeses < 0){
        diferencaMeses += 12;
    } if(diferencaDias < 0){
        diferencaDias += 30;
    }

    int diasTrabalhados = diferencaAnos*360 + diferencaMeses*30 + diferencaDias;

    //Calculo da recisão:
    float recisao = salario_gerente * diasTrabalhados/360;

    return recisao;
}