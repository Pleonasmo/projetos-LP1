#include <iostream>
#include <vector>
#include "header.hpp"

using namespace std;

vector<int> inserir_pilha(vector<int> pilha){
    int elemento;

    cout << "\nDigite o elemento que deseja inserir na pilha:" << endl;
    cin >> elemento;
    pilha.push_back(elemento);
    cout << "\nElemento inserido!\n" << endl;
    
    return pilha;
}

vector<int> deletar_pilha(vector<int> pilha){
    cout << "\nDeletando elemento da pilha...\n" << endl;
    pilha.pop_back();
    cout << "Elemento deletado!\n" << endl;

    return pilha;
}

void listar_pilha(vector<int> pilha){
    cout << "\nPilha definida por:\n" << pilha.back() << "\n" << endl;

}

void interface_pilha(){
    int escolha;
    vector<int> pilha;

    while (true)
    {
        cout << "\nInicializando pilha de inteiros...\n" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Deletar elemento" << endl;
        cout << "3 - Listar elementos" << endl;
        cout << "4 - Sair\n" << endl;
        cin >> escolha;

        if(escolha == 1)
            pilha = inserir_pilha(pilha);
        else if(escolha == 2)
            pilha = deletar_pilha(pilha);
        else if(escolha == 3)
            listar_pilha(pilha);
        else
            break;
    }
    
}