//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int soma(float x, float y){
  int res = x + y;

  return res;
}

int main(){

  float x, y;
  int resultado;

  std::cin >> x;
  std::cin >> y;

  resultado = soma(x,y);
  std::cout << resultado << std::endl;

  return 0;
}
