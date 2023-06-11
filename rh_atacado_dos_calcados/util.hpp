#ifndef UTIL_H
#define UTIL_H

#include <iostream>

using namespace std;

typedef struct{
    int ano,
        mes,
        dia;
} Data;

typedef struct{
    string cidade,
        bairro,
        rua,
        cep;
    int numero;
} Endereco;

#endif