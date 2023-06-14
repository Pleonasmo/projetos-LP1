#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Gerente : public Pessoa, public Funcionario {
    private:
        float participacaoLucros;
    public:
        //Construtor vazio:
        Gerente();

        //Construtor parametrizado:
        Gerente(float pl);

        //Getter e Setter:
        float getParticipacaoLucros();
        void setParticipacaoLucros(float pl);

        //Metodos virtuais de Funcionario:
        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
};

#endif