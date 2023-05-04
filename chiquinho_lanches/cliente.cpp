#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include "header.hpp"

using namespace std;

//Função para armazenar linhas do arquivo em um vector:
vector<string> armazenaLinhas(string leitura, string arquivo_txt){
  fstream dados;
  vector<string> itens_arquivo;

  dados.open(arquivo_txt);
  while(getline(dados, leitura))
    itens_arquivo.push_back(leitura);
  dados.close();

  return itens_arquivo;
}

//Função para separar nome do sanduiche do preço re-armazenar no vector:
vector<string> divideString(vector<string> itens_arquivo){
  vector<string> palavras;
  string palavra;

  for(int i = 0; i < itens_arquivo.size(); i++){
    string linha = itens_arquivo[i];
    istringstream separar(linha);
    while(getline(separar, palavra, ' '))
      palavras.push_back(palavra);
  }
  

  return palavras;
}



map<string, string> addCarrinho(map<string, string> carrinho){



  return carrinho;
}

//função de acesso ao sistema do cliente
void acessarCliente(){
  int escolha; //int representando escolha do menu do sistema
  fstream dados;
  string leitura;
  vector<string> itens_arquivo; //Vetor com os itens dos arquivos de texto
  map<string, string> carrinho;
  map<string, string>::iterator it;

  
  
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
        //Seleção de sanduiche do arquivo sanduiches.txt
        string sanduiche_escolhido;
        cout << "\nDigite corretamente o nome do sanduiche que deseja adicionar ao carrinho: \n" << endl;
        cin >> sanduiche_escolhido;
        itens_arquivo = armazenaLinhas(leitura, "sanduiches.txt");
        itens_arquivo = divideString(itens_arquivo);
        cout << "\n" << endl;
        for(int i = 0; i < itens_arquivo.size(); i++){
          if(itens_arquivo[i] == sanduiche_escolhido){
            carrinho.insert(make_pair(itens_arquivo[i],itens_arquivo[i+1]));
          }
        }
        for(it=carrinho.begin(); it!=carrinho.end(); ++it){
          cout << it->first << " => " << it->second << '\n';
        }
          
    } else if(escolha == 4){
        //Seleção de suco do arquivo sucos.txt
        string suco_escolhido;
        cout << "\nDigite corretamente o nome do suco que deseja adicionar ao carrinho: \n" << endl;
        cin >> suco_escolhido;
        itens_arquivo = armazenaLinhas(leitura, "sucos.txt");
        itens_arquivo = divideString(itens_arquivo);
        cout << "\n" << endl;
        for(int i = 0; i < itens_arquivo.size(); i++){
          if(itens_arquivo[i] == suco_escolhido){
            carrinho.insert(make_pair(itens_arquivo[i],itens_arquivo[i+1]));
          }
        }
        for(it=carrinho.begin(); it!=carrinho.end(); ++it){
          cout << it->first << " => " << it->second << '\n';
        }
    } else if(escolha == 5){
        //Quebra do laço e saída do sistema
        
    } else if(escolha == 6){
        //Quebra do laço e saída do sistema
        cout << "\nSaindo do sistema...\n" << endl;
        break;
    }
  }
  
}