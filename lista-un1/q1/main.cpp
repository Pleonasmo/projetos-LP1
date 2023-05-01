#include <iostream>
#include <string.h>
#include "header.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    float area;
    if(strcmp(argv[1], "quadrado") == 0){
        area = areaQuadrado();
        cout << "A área do quadrado é " << area << endl;
    } else if(strcmp(argv[1], "retangulo")==0){
        area = areaRetangulo();
        cout << "A área do retangulo é " << area << endl;
    } else if(strcmp(argv[1], "circulo")==0){
        area = areaCirculo();
        cout << "A área do circulo é " << area << endl;
    } else if(strcmp(argv[1], "triangulo")==0){
        area = areaTriangulo();
        cout << "A área do triangulo é " << area << endl;
    }

    return 0;
}
