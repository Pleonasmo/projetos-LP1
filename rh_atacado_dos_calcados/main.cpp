#include <iostream>
#include "Empresa.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Empresa *atacado_dos_alcados = new Empresa(156289.56, "Atacado dos Calçados", "40.101.588/0001-98");
    atacado_dos_alcados->carregarFuncoes();
    cout << "Deu bom!" << endl;
    return 0;
}

