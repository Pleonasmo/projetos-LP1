#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <vector>
#include "Asg.hpp"
#include "Vendedor.hpp"
#include "Gerente.hpp"

class Empresa{
    private:
        float faturamentoMensal;
        std::string nomeEmpresa;
        std::string cnpj;
        Pessoa dono;
        std::vector<Asg> asgs;
        std::vector<Vendedor> vendedores;
        std::vector<Gerente> gerentes;
    public:
        //Construtor vazio:
        Empresa();

        //Construtor parametrizado:
        Empresa(float fm, std::string ne, std::string cn);

        //Getters e Setters:
        float getFaturamentoMensal();
        void setFaturamentoMensal(float fm);
        std::string getNomeEmpresa();
        void setNomeEmpresa(std::string ne);
        std::string getCnpj();
        void setCnpj(std::string cn);

        //Getters do dono e dos vetores:
        Pessoa getDono();
        std::vector<Asg> getAsgs();
        std::vector<Vendedor> getVendedores();
        std::vector<Gerente> getGerentes();

        //Outros metodos da Empresa:
        void carregarFuncoes();
        void carregarEmpresa();
        void carregarAsg();
        void carregarVendedor();
        void carregarGerente();
        void carregarDono();
        void imprimeAsgs();
        void imprimeVendedores();
        void imprimeGerentes();
        void imprimeDono();
        void buscaFuncionario(int matricula);
        void calculaSalarioFuncionario(int matricula);
        void calculaTodosOsSalarios();
        void calcularRecisao(int matricula, Data desligamento);
};

#endif