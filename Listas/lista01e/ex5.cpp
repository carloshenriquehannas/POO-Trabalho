//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

/*
 * Para esse codigo, utilizei o seguinte link: https://noic.com.br/materiais-informatica/curso/math-04/
 * Nesse link ha uma explicacao de exponenciacao rapida, utilizando o algoritmo de divisao do expoente
*/

#include <iostream>

int pow(int b, unsigned long long int n, int m) {
    unsigned long long int result = 1;          //Variavel para armazenar o resultado da conta
    unsigned long long int base = b % m;        //Variavel auxiliar

    //Loop para calcular potencia enquanto n for maior que zero
    while (n > 0) {
        if (n % 2 == 1) {                       //Se n for impar, decompoe a base
            result = (result * base) % m;
        }
        base = (base * base) % m;               //Atualiza nova base
        n = n / 2;                              //Reduz n pela metade e faz uma nova interacao
    }

    return result;
}

int main() {
    int b, m, resultado;
    unsigned long long int n;

    //Entrada do usuario
    std::cin >> b >> n >> m;

    //Retorna o resultado de (b^n)%m
    resultado = pow(b, n, m);

    std::cout << resultado;

    return 0;
}