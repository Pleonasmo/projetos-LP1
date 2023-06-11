#include <iostream>
#include "pessoa.hpp"

Pessoa::Pessoa(){
    nome = "sem_nome";
    cpf = "sem_cpf";
    dataNascimento = {0, 0, 0};
    enderecoPessoal = {"sem_cidade", "sem_bairro", "sem_rua", "sem_cep", 0};
    estadoCivil = "solteiro";
    qtdFilhos = 0;
}

//Construtor parametrizado:
Pessoa::Pessoa(std::string n, std::string c, Data dn, Endereco ep, std::string ec, int qf){
    nome = n;
    cpf = c;
    dataNascimento = dn;
    enderecoPessoal = ep;
    estadoCivil = ec;
    qtdFilhos = qf;
}

//Getters e Setters:
std::string Pessoa::getNome(){
    return nome;
}
void Pessoa::setNome(std::string n){
    nome = n;
}
std::string Pessoa::getCpf(){
    return cpf;
}
void Pessoa::setCpf(std::string c){
    cpf = c;
}
Data Pessoa::getDataNascimento(){
    return dataNascimento;
}
void Pessoa::setDataNascimento(Data dn){
    dataNascimento = dn;
}
Endereco Pessoa::getEnderecoPessoal(){
    return enderecoPessoal;
}
void Pessoa::setEnderecoPessoal(Endereco ep){
    enderecoPessoal = ep;
}

std::string Pessoa::getEstadoCivil(){
    return estadoCivil;
}
void Pessoa::setEstadoCivil(std::string ec){
    estadoCivil = ec;
}
int Pessoa::getQtdFilhos(){
    return qtdFilhos;
}
void Pessoa::setQtdFilhos(int qf){
    qtdFilhos = qf;
}