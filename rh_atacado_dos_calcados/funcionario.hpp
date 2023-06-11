#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include "util.hpp"

class Funcionario{
    private:
        std::string matricula;
        std::string salario;
        Data ingressoEmpresa;
    public:
        //Contrutor vazio:
        Funcionario();

        //Construtor parametrizado:
        Funcionario(std::string m, std::string s, Data ie);

        //Getters e Setters:
        std::string getMatricula();
        void setMatricula(std::string m);
        std::string getSalario();
        void setSalario(std::string s);
        Data getIngressoEmpresa();
        void setIngressoEmpresa(Data ie);

        //Outros metodos:
        virtual float calcularSalario(int diasFaltas);
        virtual float calcularRecisao(Data desligamento);
};

#endif