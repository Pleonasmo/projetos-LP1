#include <iostream>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Pessoa pedro;
    pedro.setNome("Pedro Rian");
    cout << "O nome da pessoa eh: " << pedro.getNome() << endl;

    Funcionario f1;
    cout << "A matricula do funcionario eh: " << f1.getMatricula() << endl;
    return 0;
}

