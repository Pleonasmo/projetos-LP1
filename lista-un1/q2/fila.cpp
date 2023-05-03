#include <iostream>
#include <vector>
#include "header.hpp"

using namespace std;

vector<int> inserir_fila(vector<int> fila){
    int elemento;

    cout << "\nDigite o elemento que deseja inserir na fila:" << endl;
    cin >> elemento;
    fila.push_back(elemento);
    cout << "\nElemento inserido!\n" << endl;
    
    return fila;
}

vector<int> deletar_fila(vector<int> fila){
    cout << "\nDeletando elemento da fila...\n" << endl;
    fila.erase(fila.begin());
    cout << "Elemento deletado!\n" << endl;

    return fila;
}

void listar_fila(vector<int> fila){
    cout << "\nFila definida por:\n" << fila[0] << endl;
}

void interface_fila(){
    int escolha;
    vector<int> fila;

    while (true)
    {
        cout << "\nInicializando fila de inteiros...\n" << endl;
        cout << "1 - Inserir elemento na fila" << endl;
        cout << "2 - Deletar elemento da fila" << endl;
        cout << "3 - Listar elementos da fila" << endl;
        cout << "4 - Sair\n" << endl;
        cin >> escolha;

        if(escolha == 1)
            fila = inserir_fila(fila);
        else if(escolha == 2)
            fila = deletar_fila(fila);
        else if(escolha == 3)
            listar_fila(fila);
        else
            break;
    }
    
}