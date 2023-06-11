#ifndef ASG_HPP
#define ASG_HPP

#include "Util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Asg : public Pessoa, Funcionario{
    private:
        float adicionalInsalubridade;
    public:
        //Construtor vazio:
        Asg();

        //Construtor parametrizado:
        Asg(float ai);

        //Getter e Setter:
        float getAdicionalInsalubridade();
        void setAdicionalInsalubridade(float ia);

        //Metodos virtuais de Funcionario:
        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
};

#endif