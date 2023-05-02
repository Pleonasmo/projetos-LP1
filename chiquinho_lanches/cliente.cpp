#include <iostream>
#include <fstream>
#include <string.h>
#include "header.hpp"

using namespace std;

//função de acesso ao sistema do cliente
void acessarCliente(){
  int escolha; //int representando escolha do menu do sistema
  ifstream dados;
  string leitura;

  //laço while do menu do sistema do cliente
  while(true){
    cout << "\nAcessando sistema como cliente...\n" << endl;
    cout << "Qual das opções abaixo você deseja?\n" << endl;
    cout << "1 - Verficar cardápio de sanduíches" << endl;
    cout << "2 - Verficar cardápio de sucos" << endl;
    cout << "3 - Sair do sistema\n" << endl;
  
    cin >> escolha;
    
    if(escolha == 1){
      //Leitura do arquivo de sanduiches
      dados.open("sanduiches.txt");
      cout << "\nSanduíches disponiveis no cardápio: " << endl;
      while(getline(dados, leitura))
        cout << "- " << leitura << endl;
      dados.close();
    } else if(escolha == 2){
      //Leitura do arquivo de sucos
      dados.open("sucos.txt");
      cout << "\nSucos disponiveis no cardápio: " << endl;
      while(getline(dados, leitura))
        cout << "- " << leitura << endl;
      dados.close();
    } else if(escolha == 3){
      //Quebra do laço e saída do sistema
      cout << "\nSaindo do sistema...\n" << endl;
      break;
    }
  }
  
}