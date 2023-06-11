#include <iostream>
#include "Asg.hpp"

//Construtor vazio:
Asg::Asg(){
    adicionalInsalubridade = 0;
}

//Construtor parametrizado:
Asg::Asg(float ai){
    adicionalInsalubridade = ai;
}

//Getter e Setter:
float Asg::getAdicionalInsalubridade(){
    return adicionalInsalubridade;
}

void Asg::setAdicionalInsalubridade(float ai){
    adicionalInsalubridade = ai;
}

//Metodos virtuais de Funcionario (PARA IMPLEMENTAR CALCULO ESPECIFICO):
float Asg::calcularSalario(int diasFaltas){
    return 1;
}

float Asg::calcularRecisao(Data desligamento){
    return 1;
}