//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>
#include <math.h>

/*
 Pelo teorema da desigualdade de Cauchy e desigualdade de medias:
 media quadratica maior ou igual media aritmetica maior ou igual geometrica maior ou igual media harmonica
 Logo, basta calcular a media quadratica e harmonica para saber o maior e menor valor entre as medias
 */

int main() {
    double n1, n2, n3;
    double harmonica, quadratica;

    std::cin >> n1 >> n2 >> n3;

    harmonica = (3 * n1 * n2 * n3) / (n2 * n3 + n1 * n3 + n1 * n2);
    quadratica = pow((n1 * n1 + n2 * n2 + n3 * n3)/3, 0.5);

    std::cout << "Menor: " << harmonica << std::endl;
    std::cout << "Maior: " << quadratica << std::endl;

    return 0;
}