//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int main (){
  int n;

  std::cin >> n; //Entrada do usuario

  for (int i = 1; i <= n; i++) { //Laco de repeticao entre 1 ate n
    if(i % 3 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0 && i % 17 == 0) { //Multiplos de 3,5,7,11 e 17 simultaneamente
      std::cout << i << std::endl;
    }
  }

  return 0;
}
