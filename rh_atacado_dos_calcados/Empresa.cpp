#include <fstream>
#include "Empresa.hpp"

//Construtor vazio:
Empresa::Empresa(){
    faturamentoMensal = 0;
    nomeEmpresa = "Empresa";
    cnpj = "00000000000000";
}

//Construtor parametrizado:
Empresa::Empresa(float fm, std::string ne, std::string cn){
    faturamentoMensal = fm;
    nomeEmpresa = ne;
    cnpj = cn;
}

//Getters e Setters:
float Empresa::getFaturamentoMensal(){
    return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float fm){
    faturamentoMensal = fm;
}

std::string Empresa::getNomeEmpresa(){
    return nomeEmpresa;
}

void Empresa::setNomeEmpresa(std::string ne){
    nomeEmpresa = ne;
}

std::string Empresa::getCnpj(){
    return cnpj;
}

void Empresa::setCnpj(std::string cn){
    cnpj = cn;
}

//Getters do Dono e dos vetores:
Pessoa Empresa::getDono(){
    return dono;
}

std::vector<Asg> Empresa::getAsgs(){
    return asgs;
}

std::vector<Vendedor> Empresa::getVendedores(){
    return vendedores;
}

std::vector<Gerente> Empresa::getGerentes(){
    return gerentes;
}

//Outros metodos de Empresa:
void Empresa::carregarFuncoes(){
    try{
        std::ifstream arquivo("dados/funcoes.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::cout << "Encontrou o arquivo" << std::endl;
            std::string linha;
            while (std::getline(arquivo, linha)) {
                if (linha == "carregarEmpresa()") {
                    carregarEmpresa();
                } else if (linha == "carregarAsg()") {
                    carregarAsg();
                } else if (linha == "carregarVendedor()") {
                    carregarVendedor();
                } else if (linha == "carregarGerente()") {
                    carregarGerente();
                } else if (linha == "carregarDono()") {
                    carregarDono();
                } else if (linha == "imprimeAsgs()") {
                    imprimeAsgs();
                } else if (linha == "imprimeVendedores()") {
                    imprimeVendedores();
                } else if (linha == "imprimeGerentes()") {
                    imprimeGerentes();
                } else if (linha == "imprimeDono()") {
                    imprimeDono();
                } else if (linha == "buscaFuncionario()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else if (linha == "calculaSalarioFuncionario()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else if (linha == "calculaTodosOsSalarios()") {
                    calculaTodosOsSalarios();
                } else if (linha == "calcularRecisao()") {
                    std::cout << "FUNCAO NAO IMPLEMENTADA" << std::endl;
                } else {
                    std::cerr << "Função desconhecida: " << linha << std::endl;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    
}

void Empresa::carregarEmpresa(){
    std::vector<std::string> dadosEmpresa(3);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/empresa.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com #:
                if(primeiroChar != '#'){
                    dadosEmpresa[iterador] = linha;
                    iterador++;
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    //Carregando os dados na empresa:
    setNomeEmpresa(dadosEmpresa[0]);
    setCnpj(dadosEmpresa[1]);
    setFaturamentoMensal(stof(dadosEmpresa[2]));

    std::cout << "Carregou empresa com sucesso." << std::endl;
}

void Empresa::carregarAsg(){
    std::vector<std::string> dadosAsg(20);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/asg.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com # e *:
                if(primeiroChar != '#' && primeiroChar != '*'){
                    dadosAsg[iterador] = linha;
                    iterador++;
                    if(iterador == 20){
                        Asg a;
                        a.setNome(dadosAsg[1]);
                        a.setCpf(dadosAsg[2]);
                        a.setQtdFilhos(std::stoi(dadosAsg[3]));
                        a.setEstadoCivil(dadosAsg[4]);
                        
                        //definindo endereço pessoal:
                        Endereco ep;
                        ep.cidade = dadosAsg[5];
                        ep.cep = dadosAsg[6];
                        ep.bairro = dadosAsg[7];
                        ep.rua = dadosAsg[8];
                        ep.numero = std::stoi(dadosAsg[9]);

                        a.setEnderecoPessoal(ep);

                        //definindo data de nascimento:
                        Data dn;
                        dn.ano = std::stoi(dadosAsg[10]);
                        dn.mes = std::stoi(dadosAsg[11]);
                        dn.dia = std::stoi(dadosAsg[12]);

                        a.setDataNascimento(dn);

                        a.setMatricula(dadosAsg[13]);
                        a.setSalario(dadosAsg[14]);
                        a.setAdicionalInsalubridade(std::stof(dadosAsg[15]));
                        //calculando e atualizando salario:
                        a.setSalario(std::to_string(a.calcularSalario(std::stof(dadosAsg[16]))));

                        //definindo data de ingresso na empresa:
                        Data di;
                        di.ano = std::stoi(dadosAsg[17]);
                        di.mes = std::stoi(dadosAsg[18]);
                        di.dia = std::stoi(dadosAsg[19]);

                        a.setIngressoEmpresa(di);

                        //incrementando asg lido no vetor de asgs:
                        asgs.push_back(a);

                        iterador = 0;
                    }
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "Carregou ASG com sucesso." << std::endl;
}

void Empresa::carregarVendedor(){
    std::vector<std::string> dadosVendedor(20);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/vendedor.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com # e *:
                if(primeiroChar != '#' && primeiroChar != '*'){
                    dadosVendedor[iterador] = linha;
                    iterador++;
                    if(iterador == 20){
                        Vendedor v;
                        v.setNome(dadosVendedor[1]);
                        v.setCpf(dadosVendedor[2]);
                        v.setQtdFilhos(std::stoi(dadosVendedor[3]));
                        v.setEstadoCivil(dadosVendedor[4]);
                        
                        //definindo endereço pessoal:
                        Endereco ep;
                        ep.cidade = dadosVendedor[5];
                        ep.cep = dadosVendedor[6];
                        ep.bairro = dadosVendedor[7];
                        ep.rua = dadosVendedor[8];
                        ep.numero = std::stoi(dadosVendedor[9]);

                        v.setEnderecoPessoal(ep);

                        //definindo data de nascimento:
                        Data dn;
                        dn.ano = std::stoi(dadosVendedor[10]);
                        dn.mes = std::stoi(dadosVendedor[11]);
                        dn.dia = std::stoi(dadosVendedor[12]);

                        v.setDataNascimento(dn);

                        v.setMatricula(dadosVendedor[13]);
                        v.setSalario(dadosVendedor[14]);
                        v.setTipoVendedor(dadosVendedor[15][0]);
                        //calculando e atualizando salario:
                        v.setSalario(std::to_string(v.calcularSalario(std::stof(dadosVendedor[16]))));

                        //definindo data de ingresso na empresa:
                        Data di;
                        di.ano = std::stoi(dadosVendedor[17]);
                        di.mes = std::stoi(dadosVendedor[18]);
                        di.dia = std::stoi(dadosVendedor[19]);

                        v.setIngressoEmpresa(di);

                        //incrementando asg lido no vetor de asgs:
                        vendedores.push_back(v);

                        iterador = 0;
                    }
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "Carregou Vendedor com sucesso." << std::endl;
}

void Empresa::carregarGerente(){
    std::vector<std::string> dadosGerente(20);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/gerente.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com # e *:
                if(primeiroChar != '#' && primeiroChar != '*'){
                    dadosGerente[iterador] = linha;
                    iterador++;
                    if(iterador == 20){
                        Gerente g;
                        g.setNome(dadosGerente[1]);
                        g.setCpf(dadosGerente[2]);
                        g.setQtdFilhos(std::stoi(dadosGerente[3]));
                        g.setEstadoCivil(dadosGerente[4]);
                        
                        //definindo endereço pessoal:
                        Endereco ep;
                        ep.cidade = dadosGerente[5];
                        ep.cep = dadosGerente[6];
                        ep.bairro = dadosGerente[7];
                        ep.rua = dadosGerente[8];
                        ep.numero = std::stoi(dadosGerente[9]);

                        g.setEnderecoPessoal(ep);

                        //definindo data de nascimento:
                        Data dn;
                        dn.ano = std::stoi(dadosGerente[10]);
                        dn.mes = std::stoi(dadosGerente[11]);
                        dn.dia = std::stoi(dadosGerente[12]);

                        g.setDataNascimento(dn);

                        g.setMatricula(dadosGerente[13]);
                        g.setSalario(dadosGerente[14]);
                        g.setParticipacaoLucros(stof(dadosGerente[15]));
                        //calculando e atualizando salario:
                        g.setSalario(std::to_string(g.calcularSalario(std::stof(dadosGerente[16]))));

                        //definindo data de ingresso na empresa:
                        Data di;
                        di.ano = std::stoi(dadosGerente[17]);
                        di.mes = std::stoi(dadosGerente[18]);
                        di.dia = std::stoi(dadosGerente[19]);

                        g.setIngressoEmpresa(di);

                        //incrementando asg lido no vetor de asgs:
                        gerentes.push_back(g);

                        iterador = 0;
                    }
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "Carregou Gerente com sucesso." << std::endl;
}

void Empresa::carregarDono(){
    std::vector<std::string> dadosDono(12);
    int iterador = 0;

    //Leitura das linhas de empresa.txt:
    try{
        std::ifstream arquivo("dados/dono.txt");
        if (!arquivo) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        } else {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                char primeiroChar = linha[0];
                //Ignorando linhas com # e *:
                if(primeiroChar != '#'){
                    dadosDono[iterador] = linha;
                    iterador++;
                    if(iterador == 12){
                        Pessoa d;
                        d.setNome(dadosDono[0]);
                        d.setCpf(dadosDono[1]);
                        d.setQtdFilhos(std::stoi(dadosDono[2]));
                        d.setEstadoCivil(dadosDono[3]);

                        Endereco ep;
                        ep.cidade = dadosDono[4];
                        ep.cep = dadosDono[5];
                        ep.bairro = dadosDono[6];
                        ep.rua = dadosDono[7];
                        ep.numero = std::stoi(dadosDono[8]);

                        d.setEnderecoPessoal(ep);

                        Data dn;
                        dn.ano = std::stoi(dadosDono[9]);
                        dn.mes = std::stoi(dadosDono[10]);
                        dn.dia = std::stoi(dadosDono[11]);

                        d.setDataNascimento(dn);

                        dono = d;
                        break;
                    }
                } else {
                    continue;
                }
            }
        }

        arquivo.close();
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "Carregou Dono com sucesso." << std::endl;

}

void Empresa::imprimeAsgs(){
    std::vector<Asg> listaAsgs = getAsgs();
    cout << "\n" << endl;
    for(int i = 0; i < listaAsgs.size(); i++) {
        cout << "ASG numero " << i << ":" << endl;
        cout << "Nome: " << listaAsgs[i].getNome() << endl;
        cout << "CPF: " << listaAsgs[i].getCpf() << endl;
        cout << "Data de nascimento: " << listaAsgs[i].getDataNascimento().dia << "/" << listaAsgs[i].getDataNascimento().mes << "/" << listaAsgs[i].getDataNascimento().ano << endl;
        cout << "Endereço: " << listaAsgs[i].getEnderecoPessoal().cidade << ", " << listaAsgs[i].getEnderecoPessoal().bairro << ", " << listaAsgs[i].getEnderecoPessoal().cep 
        << ", Rua " << listaAsgs[i].getEnderecoPessoal().rua << ", " << listaAsgs[i].getEnderecoPessoal().numero << endl;
        cout << "Estado civil:  " << listaAsgs[i].getEstadoCivil() << endl;
        cout << "Quantidade de filhos " << listaAsgs[i].getQtdFilhos() << endl;
        cout << "Matricula: " << listaAsgs[i].getMatricula() << endl;
        cout << "Salario: " << listaAsgs[i].getSalario() << endl;
        cout << "Data de ingresso: " << listaAsgs[i].getIngressoEmpresa().dia << "/" << listaAsgs[i].getIngressoEmpresa().mes << "/" << listaAsgs[i].getIngressoEmpresa().ano << endl;
        cout << "Adicional de insalubridade: " << listaAsgs[i].getAdicionalInsalubridade() << endl;
        cout << "\n" << endl;
    }
}

void Empresa::imprimeVendedores(){
    std::cout << "imprimeVendedores" << std::endl;
}

void Empresa::imprimeGerentes(){
    std::cout << "imprimeGerentes" << std::endl;
}

void Empresa::imprimeDono(){
    std::cout << "imprimeDono" << std::endl;
}

void Empresa::buscaFuncionario(int matricula){
    std::cout << "buscaFuncionario" << std::endl;
}

void Empresa::calculaSalarioFuncionario(int matricula){
    std::cout << "calculaSalarioFuncionario" << std::endl;
}

void Empresa::calculaTodosOsSalarios(){
    std::cout << "calculaTodosOsSalarios" << std::endl;
}

void Empresa::calcularRecisao(int matricula, Data desligamento){
    std::cout << "calcularRecisao" << std::endl;
}