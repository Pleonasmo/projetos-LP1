#include "Empresa.hpp"

//Construtor vazio:
Empresa::Empresa(){
    faturamentoMensal = 0;
    nomeEmpresa = "Empresa";
    cnpj = "00000000000000";
}

//Construtor parametrizado:
Empresa::Empresa(float fm, std::string ne, std::string cn){
    faturamentoMensal = fm;
    nomeEmpresa = ne;
    cnpj = cn;
}

//Getters e Setters:
float Empresa::getFaturamentoMensal(){
    return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float fm){
    faturamentoMensal = fm;
}

std::string Empresa::getNomeEmpresa(){
    return nomeEmpresa;
}

void Empresa::setNomeEmpresa(std::string ne){
    nomeEmpresa = ne;
}

std::string Empresa::getCnpj(){
    return cnpj;
}

void Empresa::setCnpj(std::string cn){
    cnpj = cn;
}

//Getters do Dono e dos vetores:
Pessoa Empresa::getDono(){
    return dono;
}

std::vector<Asg> Empresa::getAsgs(){
    return asgs;
}

std::vector<Vendedor> Empresa::getVendedores(){
    return vendedores;
}

std::vector<Gerente> Empresa::getGerentes(){
    return gerentes;
}

