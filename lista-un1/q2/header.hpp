#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <vector>

//Funções do main
void interface_pilha();
void interface_fila();

//Funções da pilha
std::vector<int> inserir_pilha(std::vector<int> pilha);
std::vector<int> deletar_pilha(std::vector<int> pilha);
void listar_pilha(std::vector<int> pilha);

//Funções da fila
std::vector<int> inserir_fila(std::vector<int> pilha);
std::vector<int> deletar_fila(std::vector<int> pilha);
void listar_fila(std::vector<int> pilha);

#endif