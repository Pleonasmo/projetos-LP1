#include "Empresa.hpp"

Empresa::Empresa(){
    faturamentoMensal = 0;
    nomeEmpresa = "Empresa";
    cnpj = "00000000000000";
}

Empresa::Empresa(float fm, std::string ne, std::string cn){
    faturamentoMensal = fm;
    nomeEmpresa = ne;
    cnpj = cn;
}

