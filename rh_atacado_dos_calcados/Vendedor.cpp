#include "Vendedor.hpp"

//Construtor vazio:
Vendedor::Vendedor(){
    tipoVendedor = 'C';
}

//Construtor parametrizado:
Vendedor::Vendedor(char tv){
    tipoVendedor = tv;
}

//Getter e Setter:
char Vendedor::getTipoVendedor(){
    return tipoVendedor;
}

void Vendedor::setTipoVendedor(char tv){
    tipoVendedor = tv;
}

//Metodos virtuais de Funcionario:
float Vendedor::calcularSalario(int diasFaltas){
    float salario_vendedor;
    try{
        salario_vendedor = stof(getSalario());
    } catch(const std::invalid_argument e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_vendedor = 0;
    } catch(const std::out_of_range e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_vendedor = 0;
    }

    float gratificacao;

    //calculo da gratificacao do vendedor com base no tipo:
    if(getTipoVendedor() == 'A'){
        gratificacao = (25/100) * salario_vendedor;
    } else if(getTipoVendedor() == 'B'){
        gratificacao = (10/100) * salario_vendedor;
    } else if(getTipoVendedor() == 'C'){
        gratificacao = (5/100) * salario_vendedor;
    }

    //Salario por dia trabalhado:
    float salarioPorDia = salario_vendedor/30;

    //Calculo de salario:
    float descontoFaltas = diasFaltas*salarioPorDia;
    float adicionalFilhos = getQtdFilhos() * 100;

    float salarioFinal = salario_vendedor + adicionalFilhos + gratificacao - descontoFaltas;

    return salarioFinal;
}

float Vendedor::calcularRecisao(Data desligamento){
    float salario_vendedor;
    try{
        salario_vendedor = stof(getSalario());
    } catch(const std::invalid_argument e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_vendedor = 0;
    } catch(const std::out_of_range e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_vendedor = 0;
    }

    //Calculo de dias trabalhados na empresa:
    Data dataInicio = getIngressoEmpresa();
    Data dataFim = desligamento;

    int diferencaAnos = dataFim.ano - dataInicio.ano;
    int diferencaMeses = dataFim.mes - dataInicio.mes;
    int diferencaDias = dataFim.dia - dataInicio.dia;

    if(diferencaMeses < 0){
        diferencaMeses += 12;
    } if(diferencaDias < 0){
        diferencaDias += 30;
    }

    int diasTrabalhados = diferencaAnos*360 + diferencaMeses*30 + diferencaDias;

    //Calculo da recisão:
    float recisao = salario_vendedor * diasTrabalhados/360;

    return recisao;
}