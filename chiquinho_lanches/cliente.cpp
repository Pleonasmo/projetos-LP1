#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include "header.hpp"

using namespace std;

vector<string> armazenaLinhas(string leitura, string arquivo_txt){
  fstream dados;
  vector<string> itens_arquivo;
  dados.open(arquivo_txt);
  while(getline(dados, leitura))
    itens_arquivo.push_back(leitura);
  dados.close();

  return itens_arquivo;
}

map<string, string> addCarrinho(map<string, string> carrinho, string item){



  return carrinho;
}

//função de acesso ao sistema do cliente
void acessarCliente(){
  int escolha; //int representando escolha do menu do sistema
  fstream dados;
  string leitura;
  vector<string> itens_arquivo;
  map<string, string> carrinho;

  
  
  //laço while do menu do sistema do cliente
  while(true){
    cout << "\nAcessando sistema como cliente...\n" << endl;
    cout << "Qual das opções abaixo você deseja?\n" << endl;
    cout << "1 - Verficar cardápio de sanduíches" << endl;
    cout << "2 - Verficar cardápio de sucos" << endl;
    cout << "3 - Escolher sanduiche" << endl;
    cout << "4 - Escolher suco" << endl;
    cout << "5 - Ver carrinho" << endl;
    cout << "6 - Sair do sistema\n" << endl;
  
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
        itens_arquivo = armazenaLinhas(leitura, "sanduiches.txt");
        for(int i = 0; i < itens_arquivo.size(); i++)
          cout << itens_arquivo[i] << " - ";
        cout << "\n" << endl;
    } else if(escolha == 6){
        //Quebra do laço e saída do sistema
        cout << "\nSaindo do sistema...\n" << endl;
        break;
    }
  }
  
}