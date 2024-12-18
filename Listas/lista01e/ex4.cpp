//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

//Funcao auxiliar para calculo do Fibonacci
void fibonacci(unsigned long long int n, int m, unsigned long long int *k1, unsigned long long int *k2){
  if(n == 1) {
      *k1 = 1;
      *k2 = 1;
  } else {
      fibonacci(n - 1, m, k1, k2);
      unsigned long long int aux = *k1;
      *k1 += *k2;
      *k1 %= m;
      *k2 = aux;
      *k2 %= m;
  }
}

int fib(unsigned long long int n, int m) {
    unsigned long long int k1, k2;

    fibonacci(n-1, m, &k1, &k2);

    return k1 % m;
}

int main() {
    unsigned long long int n, result;
    int m;

    std::cin >> n >> m;     //Entrada do usuario

    result = fib(n, m);     //Resultado: fib(n) % m

    std::cout << result << std::endl;

    return 0;
}