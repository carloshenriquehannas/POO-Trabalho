//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

//Funcao para calcular o tamanho do ciclo de Fibonacci
unsigned long long int len(int m,  unsigned long long int *k1, unsigned long long int *k2, unsigned long long int i) {
    //Caso em que os numeros formam a sequencia inicial
    if (*k1 == 0 && *k2 == 1) {
        return i + 1;   //Comprimento do ciclo
    } else {
        //Calculo do proximo numero da sequencia
        unsigned long long int aux = *k1;
        *k1 += *k2;
        *k1 %= m;
        *k2 = aux;
        *k2 %= m;
        i++;

        return len(m, k1, k2, i);
    }
}

void fibonacci(unsigned long long int n, int m, unsigned long long int *k1, unsigned long long int *k2){
    if(n == 1) {    //Caso para definir os primeiros termos da sequencia
        *k1 = 1;
        *k2 = 1;
    } else {
        //Caso para calcular o termo n-1 da sequencia
        fibonacci(n - 1, m, k1, k2);
        unsigned long long int aux = *k1;
        *k1 += *k2;
        *k1 %= m;
        *k2 = aux;
        *k2 %= m;
    }
}

int fib(unsigned long long int n, int m) {
    unsigned long long int k1 = 1, k2 = 1;

    unsigned long long int l = len(m, &k1, &k2, 1);  //Comprimento do ciclo, para mod m
    fibonacci((n-1) % l, m, &k1, &k2);              //Calcula o termo n-1, com mod m, ajustado pelo tamanho de ciclo

    return k1;
}

int main() {
    unsigned long long int n, result;
    int m;

    std::cin >> n >> m;     //Entrada do usuario de n termos da sequencia, pelo mod m

    result = fib(n, m);     //Retorna fib(n) % m

    std::cout << result << std::endl;

    return 0;
}