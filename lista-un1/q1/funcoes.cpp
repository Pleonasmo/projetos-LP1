//Escopo das funções usadas no programa:
#include <iostream>
#include "header.hpp"
#define PI 3.14

using namespace std;

float areaQuadrado(){
    float lado, area;
    cout << "Insira o lado do quadrado: " << endl;
    cin >> lado;
    area = lado * lado;
    return area;
}

float areaRetangulo(){
    float base, altura, area;
    cout << "Insira a base do retangulo: " << endl;
    cin >> base;
    cout << "Insira a altura do retangulo: " << endl;
    cin >> altura;
    area = base * altura;
    return area;
}

float areaCirculo(){
    float raio, area;
    cout << "Insira o raio do circulo: " << endl;
    cin >> raio;
    area = PI * raio * raio;
    return area;
}

float areaTriangulo(){
    float base, altura, area;
    cout << "Insira a base do triangulo: " << endl;
    cin >> base;
    cout << "Insira a altura do triangulo: " << endl;
    cin >> altura;
    area = (base * altura)/2;
    return area;
}