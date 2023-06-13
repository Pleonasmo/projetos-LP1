#include "Asg.hpp"

//Construtor vazio:
Asg::Asg(){
    adicionalInsalubridade = 0;
}

//Construtor parametrizado:
Asg::Asg(float ai){
    adicionalInsalubridade = ai;
}

//Getter e Setter:
float Asg::getAdicionalInsalubridade(){
    return adicionalInsalubridade;
}

void Asg::setAdicionalInsalubridade(float ai){
    adicionalInsalubridade = ai;
}

//Metodos virtuais de Funcionario:
float Asg::calcularSalario(int diasFaltas){
    float salario_asg;
    try{
        salario_asg = stof(getSalario());
    } catch(const std::invalid_argument e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_asg = 0;
    } catch(const std::out_of_range e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_asg = 0;
    }
    
    //definindo adicionalInsalubridade:
    setAdicionalInsalubridade(5/100 * salario_asg);

    //Salario por dia trabalhado:
    float salarioPorDia = salario_asg/30;

    //Calculo de salario:
    float descontoFaltas = diasFaltas*salarioPorDia;
    float adicionalFilhos = getQtdFilhos()*100;
    float salarioFinal = salario_asg + adicionalFilhos + getAdicionalInsalubridade() - descontoFaltas;

    return salarioFinal;
}

float Asg::calcularRecisao(Data desligamento){
    float salario_asg;
    try{
        salario_asg = stof(getSalario());
    } catch(const std::invalid_argument e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_asg = 0;
    } catch(const std::out_of_range e){
        std::cout << "O salario passado é inválido!" << endl;
        salario_asg = 0;
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
    float recisao = salario_asg * diasTrabalhados/360;

    return recisao;
}