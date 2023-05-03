#ifndef HEADER_HPP
#define HEADER_HPP
#include <string.h>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

//Definição de funções usadas ao longo dos arquivos
void acessarCliente();
void acessarGerente();
bool validarGerente(string usuario, string senha);
vector<string> armazenaLinhas(string leitura, string arquivo_txt);
map<string, string> addCarrinho(map<string, string> carrinho, string item);

#endif