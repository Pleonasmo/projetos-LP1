#include <iostream>
#include <vector>
#include "header.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int escolha;
    cout << "Com qual estrutura você deseja trabalhar?\n" << endl;
    cout << "1 - Pilha" << endl;
    cout << "2 - Fila\n" << endl;
    cin >> escolha;

    if(escolha == 1)
        interface_pilha();
    else if(escolha == 2)
        interface_fila();
    else
        cout << "\nOpção digitada é inválida!" << endl;

    return 0;
}
