#include <iostream>

using namespace std;

//Função para realizar a soma do intervalo:
int somaRecursiva(int a, int b){
    if (a > b) 
        return 0; //Se o primeiro valor for menor que o último, o intervalo para soma não é definido.
    else if (a == b)
        return a; //A função retorna a soma quando os valores dos parâmetros forem iguais.
    else
        return a + somaRecursiva(a + 1, b); //A função incrementa recursivamente em 1 o primeiro valor até ser igual ao do segundo parâmetro.
}

//Interação com o usuário:
int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Digite dois valores para um intervalo: " << endl;
    cin >> a >> b;
    cout << "A soma dos valores entre " << a << " e " << b << " é igual a " << somaRecursiva(a, b) << endl;
    return 0;
}
