//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int main (){
  float qtd_balas;
  float preco_balas;
  float qtd_chocolate;
  float preco_chocolate;
  float preco_final;

  std::cin >> qtd_balas;
  std::cin >> preco_balas;
  std::cin >> qtd_chocolate;
  std::cin >> preco_chocolate;

  preco_final = qtd_balas * preco_balas + qtd_chocolate * preco_chocolate;

  std::cout << preco_final << std::endl;
  return 0;
}