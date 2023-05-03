#include <iostream>
#include <fstream>
#include <string.h>
#include "header.hpp"

using namespace std;

//Função de verificação de credenciais para acesso ao sistema
bool validarGerente(string usuario, string senha){
    if(usuario == "admin" && senha == "admin"){
        cout << "\nAcessando sistema como gerente...\n" << endl;
        return true;
    }
    else
        return false;
}

//Função de acesso ao sistema do gerente
void acessarGerente(){
    string usuario, senha, texto;

    //Interação com o usuário para inserção de credenciais
    
    cout << "\nDigite o usuario: ";
    cin >> usuario;
    cout << "Digite a senha: ";
    cin >> senha;

    //Condicional para verificar credenciais
    if(validarGerente(usuario, senha) == false)
        cout << "\nAcesso negado!" << endl;
    else{
        cout << "\nAcesso permitido!" << endl;
      
        int escolha; //int representando escolha do menu do sistema
        fstream dados;
        string leitura;

      //laço while do menu do sistema do gerente
        while(true){
          cout << "\nQual das opções abaixo você deseja?\n" << endl;
          cout << "1 - Listar sanduíches cadastrados" << endl;
          cout << "2 - Listar sucos cadastrados" << endl;
          cout << "3 - Cadastrar novo sanduíche" << endl;
          cout << "4 - Cadastrar novo suco" << endl;
          cout << "5 - Sair do sistema\n" << endl;
        
          cin >> escolha;
          
          if(escolha == 1){
            //Leitura do arquivo de sanduiches
            dados.open("sanduiches.txt");
            cout << "\n------------------------------------" << 
              "\nSanduíches disponiveis no cardápio: " << endl;
            while(getline(dados, leitura))
              cout << "- " << leitura << endl;
            dados.close();
            cout << "------------------------------------\n" << endl;
          } else if(escolha == 2){
              //Leitura do arquivo de sucos
              dados.open("sucos.txt");
              cout << "\n------------------------------------" <<
              "\nSucos disponiveis no cardápio: " << endl;
              while(getline(dados, leitura))
                cout << "- " << leitura << endl;
              dados.close();
              cout << "------------------------------------\n" << endl;
          } else if(escolha == 3){
              string sanduiche;
              dados.open("sanduiches.txt", ios::app);
              cout << "\n------------------------------------" <<
              "\nDigite o sanduiche e o preço (nome-do-sanduiche preço):" << endl;
              cin.ignore();
              getline(cin, sanduiche);
              dados << "\n";
              dados << sanduiche;
              cout << "\nSanduíche cadastrado!\n" << endl;
              dados.close();
              cout << "------------------------------------\n" << endl;
          } else if(escolha == 5){
              //Quebra do laço e saída do sistema
              cout << "\nSaindo do sistema...\n" << endl;
              break;
          }
        }
    }

};