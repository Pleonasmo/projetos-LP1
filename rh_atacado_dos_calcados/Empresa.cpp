#include <fstream>
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

//Outros metodos de Empresa:
void Empresa::carregarFuncoes(){
    try{
        std::ifstream arquivo("dados/funcoes.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::cout << "Encontrou o arquivo" << std::endl;
            std::string linha;
            while (std::getline(arquivo, linha)) {
                if (linha == "carregarEmpresa()") {
                    carregarEmpresa();
                } else if (linha == "carregarAsg()") {
                    carregarAsg();
                } else if (linha == "carregarVendedor()") {
                    carregarVendedor();
                } else if (linha == "carregarGerente()") {
                    carregarGerente();
                } else if (linha == "carregarDono()") {
                    carregarDono();
                } else if (linha == "imprimeAsgs()") {
                    imprimeAsgs();
                } else if (linha == "imprimeVendedores()") {
                    imprimeVendedores();
                } else if (linha == "imprimeGerentes()") {
                    imprimeGerentes();
                } else if (linha == "imprimeDono()") {
                    imprimeDono();
                } else if (linha == "buscaFuncionario()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else if (linha == "calculaSalarioFuncionario()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else if (linha == "calculaTodosOsSalarios()") {
                    calculaTodosOsSalarios();
                } else if (linha == "calcularRecisao()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else {
                    std::cerr << "Função desconhecida: " << linha << std::endl;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    
}

void Empresa::carregarEmpresa(){
    std::vector<std::string> dadosEmpresa(3);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/empresa.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com #:
                if(primeiroChar != '#'){
                    dadosEmpresa[iterador] = linha;
                    iterador++;
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    //Carregando os dados na empresa:
    setNomeEmpresa(dadosEmpresa[0]);
    setCnpj(dadosEmpresa[1]);
    setFaturamentoMensal(stof(dadosEmpresa[2]));
}

void Empresa::carregarAsg(){
    std::cout << "carregarAsg" << std::endl;
}

void Empresa::carregarVendedor(){
    std::cout << "carregarVendedor" << std::endl;
}

void Empresa::carregarGerente(){
    std::cout << "carregarGerente" << std::endl;
}

void Empresa::carregarDono(){
    std::cout << "carregarDono" << std::endl;
}

void Empresa::imprimeAsgs(){
    std::cout << "imprimeAsgs" << std::endl;
}

void Empresa::imprimeVendedores(){
    std::cout << "imprimeVendedores" << std::endl;
}

void Empresa::imprimeGerentes(){
    std::cout << "imprimeGerentes" << std::endl;
}

void Empresa::imprimeDono(){
    std::cout << "imprimeDono" << std::endl;
}

void Empresa::buscaFuncionario(int matricula){
    std::cout << "buscaFuncionario" << std::endl;
}

void Empresa::calculaSalarioFuncionario(int matricula){
    std::cout << "calculaSalarioFuncionario" << std::endl;
}

void Empresa::calculaTodosOsSalarios(){
    std::cout << "calculaTodosOsSalarios" << std::endl;
}

void Empresa::calcularRecisao(int matricula, Data desligamento){
    std::cout << "calcularRecisao" << std::endl;
}