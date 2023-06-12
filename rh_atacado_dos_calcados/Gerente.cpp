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

//Metodos virtuais de Funcionario (PARA IMPLEMENTAR CALCULO ESPECIFICO):
float Gerente::calcularSalario(int diasFaltas){
    return 3;
}

float Gerente::calcularRecisao(Data desligamento){
    return 3;
}