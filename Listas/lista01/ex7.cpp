//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int an(int n, int k, int *ini) {

    if (n < k) {                                    //Caso em que n < k
        return ini[n];
    } else {                                        //Caso em que n >= k
        int result = 0;
        for (int i = n - k; i <= n - 1; i++) {
            result += ini[i] * ini[i];              //Somatorio
        }
        return result;
    }
}

int seq(int n, int k, int *ini) {
    int result;

    if (n >= k) {
        for (int i = k; i <= n; i++) {
            ini[i] = (an(i, k, ini));
            result = ini[i];
        }
    }

    return result;

}

int main() {
    int n, k, result;

    //Entrada do usuario: n e k
    std::cin >> n >> k;

    int ini[n + 1];

    //Entrada do usuario: termos da sequencia
    for (int i = 0; i < k; i++) {
        std::cin >> ini[i];
    }

    result = seq(n, k, ini);

    std::cout << result << std::endl;

    return 0;

}