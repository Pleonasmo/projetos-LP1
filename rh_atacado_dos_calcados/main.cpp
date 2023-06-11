#include <iostream>
#include "pessoa.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Pessoa pedro;
    pedro.setNome("Pedro Rian");
    cout << "O nome da pessoa eh: " << pedro.getNome() << endl;
    return 0;
}

