#include <iostream>

using namespace std;

int somaRecursiva(int a, int b, int soma){
    if(a == b)
        return a;
    else
        return b;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Digite dois valores para um intervalo:" << endl;
    cin >> a >> b;
    cout << "A soma dos valores entre " << a << " e " << b << " é igual a " << somaRecursiva(a, b, 0) << endl;
    return 0;
}
