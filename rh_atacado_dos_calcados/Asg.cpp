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
    
    //Salario por dia trabalhado:
    float salarioPorDia = salario_asg/30;

    //Calculo de salario:
    float descontoFaltas = diasFaltas*salarioPorDia;
    float adicionalFilhos = getQtdFilhos()*100;
    float salarioFinal = salario_asg + adicionalFilhos + getAdicionalInsalubridade() - descontoFaltas;

    return salarioFinal;
}

float Asg::calcularRecisao(Data desligamento){
    return 1;
}