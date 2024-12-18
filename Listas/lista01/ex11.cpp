//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

std::string raizes(double a, double b, double c) {
    double delta, raiz1, raiz2;
    std::ostringstream result;

    //Caso em que ha equacao quadratica
    if (a != 0) {
        delta = b * b - 4 * a * c;                  //Calculo do delta

        if (delta > 0) {                            //Caso em que ha duas raizes reais (delta > 0)
            raiz1 = (-b - sqrt(delta)) / (2 * a);
            raiz2 = (-b + sqrt(delta)) / (2 * a);
            //Organiza saida de menor raiz para maior raiz
            if (raiz1 < raiz2) {
                result << raiz1 << " e " << raiz2;
            }else {
                result << raiz2 << " e " << raiz1;
            }
        }
        else if (delta == 0) {                      //Caso em que ha uma raiz real (delta == 0)
            raiz1 = (-b) / (2 * a);
            result << raiz1;
        }
        else {                                      //Caso em que nao ha raizes reais (delta < 0)
            result << "Nenhuma";
        }
    }
    //Caso em que ha equacao linear
    else if(b != 0) {
        raiz1 = -c/b;                                //Calculo da raiz

        result << raiz1;
    }
    //Caso em que nao ha equacao
    else if(c != 0) {
        result << "Nenhuma";
    }
    //Caso em que 0 == 0
    else {
        result << "Infinitas";
    }

    return result.str();
}

int main() {
    double a, b, c;

    std::cin >> a >> b >> c;

    std::string result = raizes(a, b, c);
    std::cout << result << std::endl;

    return 0;
}