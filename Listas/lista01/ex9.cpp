//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>
#include <iomanip>
#include <math.h>

//Funcao auxiliar: (a - b)^2
double dif_square(double a, double b){
  double difference, result;

  difference = a - b;                 //Diferenca entre os valores em um eixo
  result = difference * difference;   //Quadrado da diferenca

  return result;
}

int main (){
  double x1, x2, y1, y2;
  double aux1, aux2, distancia;

  //Entrada do usuario dos valores de x1, y1, x2 e y2
  std::cin >> x1 >> y1 >> x2 >> y2;

  aux1 = dif_square(x1, x2);    //Calcula: (x1 - x2)^2
  aux2 = dif_square(y1, y2);    //Calcula: (y1 - y2)^2

  distancia = sqrt(aux1 + aux2);  //Calcula: sqrt(aux1 + aux2)

  std::cout << std::fixed << std::setprecision(4); //Fixa resultado com 4 casas decimais
  std::cout << distancia << std::endl; //Print do resultado

  return 0;
}