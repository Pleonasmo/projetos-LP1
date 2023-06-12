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

//Metodos virtuais de Funcionario (PARA IMPLEMENTAR CALCULO ESPECIFICO):
float Vendedor::calcularSalario(int diasFaltas){
    return 2;
}

float Vendedor::calcularRecisao(Data desligamento){
    return 2;
}