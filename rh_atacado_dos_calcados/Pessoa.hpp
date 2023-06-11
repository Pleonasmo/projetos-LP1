#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include "Util.hpp"

class Pessoa{
    private:
        std::string nome;
        std::string cpf;
        Data dataNascimento;
        Endereco enderecoPessoal;
        std::string estadoCivil;
        int qtdFilhos;
    
    public:
        //Construtor vazio:
        Pessoa();

        //Construtor parametrizado:
        Pessoa(std::string n, std::string c, Data dn, Endereco ep, std::string ec, int qf);

        //Getters e Setters:
        std::string getNome();
        void setNome(std::string n);
        std::string getCpf();
        void setCpf(std::string c);
        Data getDataNascimento();
        void setDataNascimento(Data dn);
        Endereco getEnderecoPessoal();
        void setEnderecoPessoal(Endereco ep);
        std::string getEstadoCivil();
        void setEstadoCivil(std::string ec);
        int getQtdFilhos();
        void setQtdFilhos(int qf);
};

#endif