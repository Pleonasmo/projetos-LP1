#include <iostream>

using namespace std;

//Função recursiva para calcular uma potência:
int potencia(int base, int expoente){
    if(expoente == 0)
        return 1; //Se o expoente for zero, o valor retornado será 1.
    else if (expoente == 1)
        return base; //Se o expoente for um, o valor retornado será o da própria base.
    else
        return base * potencia(base, expoente-1); //Ademais, o expoente será incrementado em -1 recursivamente até ser igual a um.

}

//Interação com o usuário:
int main(int argc, char const *argv[])
{
    int base, expoente;
    cout << "Digite o valor da base: " << endl;
    cin >> base;
    cout << "Digite o valor do expoente: " << endl;
    cin >> expoente;
    cout << base << " elevado a " << expoente << " é igual a " << potencia(base, expoente) << endl;
    return 0;
}
