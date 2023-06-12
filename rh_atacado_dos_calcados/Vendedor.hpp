#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Vendedor : public Pessoa, Funcionario {
    private:
        char tipoVendedor;
    public:
        //Contrutor vazio:
        Vendedor();
        
        //Construtor parametrizado:
        Vendedor(char tv);

        //Getter e Setter:
        char getTipoVendedor();
        void setTipoVendedor(char tv);

        //Metodos virtuais de Funcionario:
        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
};

#endif