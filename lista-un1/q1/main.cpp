#include "funcoes.cpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char * argv[]) {
  int figura;
  std::cout << "Selecione a figura para qual deseja calcular a área:\n1 - "
               "Quadrado\n2 - Retângulo\n3 - Círculo\n4 - Triângulo\n\n";

  std::cin >> figura;

  if (figura == 1) {
    areaQuadrado(1);
  } else if(figura == 2){
    
  } else if(figura == 3){
    
  } else if(figura == 4){
    
  } else{
    std::cout << "O valor informado não é válido!\n";
  }
}