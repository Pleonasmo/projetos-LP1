#include <iostream>
#include <string.h>
#include "header.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int id_usuario;
    cout << "\n###### BOAS VINDAS AO SISTEMA DE CHIQUINHO LANCHES ######\n" << endl 
    << "Digite o ID de usuário que deseja acessar:\n" << endl 
    << "1 - Cliente" << endl
    << "2 - Gerente\n" << endl;
    cin >> id_usuario;

    if(id_usuario == 1)
        acessarCliente();
    else if(id_usuario == 2)
        acessarGerente();
    else
        cout << "\nTipo de usuário não é válido." << endl 
        << "Encerrando sistema ...\n" << endl;
    return 0;
}
