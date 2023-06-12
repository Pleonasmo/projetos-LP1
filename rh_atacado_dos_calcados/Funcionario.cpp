#include "Funcionario.hpp"

//Construtor vazio:
Funcionario::Funcionario(){
    matricula = "00000";
    salario = "0.0";
    ingressoEmpresa = {0, 0, 0};
}

//Constutor parametrizado:
Funcionario::Funcionario(std::string m, std::string s, Data ie){
    matricula = m;
    salario = s;
    ingressoEmpresa = ie;
}

//Getters e Setters:
std::string Funcionario::getMatricula(){
    return matricula;
};

void Funcionario::setMatricula(std::string m){
    matricula = m;
};

std::string Funcionario::getSalario(){
    return salario;
};

void Funcionario::setSalario(std::string s){
    salario = s;
};

Data Funcionario::getIngressoEmpresa(){
    return ingressoEmpresa;
};

void Funcionario::setIngressoEmpresa(Data ie){
    ingressoEmpresa = ie;
};

//Outros metodos:
float Funcionario::calcularSalario(int diasFaltas){
    return 0;
}

float Funcionario::calcularRecisao(Data delsigamento){
    return 0;
}