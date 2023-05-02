#include <iostream>
#include <string.h>
#include "header.hpp"

using namespace std;

bool validarGerente(string usuario, string senha){
    if(usuario == "admin" && senha == "admin")
        return true;
    else
        return false;
}

void acessarGerente(){
    string usuario, senha;

    cout << "\nAcessando sistema como gerente...\n" << endl;
    cout << "Digite o usuario: ";
    cin >> usuario;
    cout << "Digite a senha: ";
    cin >> senha;

    if(validarGerente(usuario, senha) == false)
        cout << "\nAcesso negado!" << endl;
    else{
        cout << "\nAcesso permitido!\n" << endl;
    }

};