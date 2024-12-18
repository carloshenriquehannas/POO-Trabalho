//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int pow(int b, int e, int m) {
    int result = 1; //Variavel auxiliar de resultado

    //Calculo da potencia: b^e
    for(int i = 0; i < e; i++) {
        result = result * b;
    }

    result = result % m; //Resto da divisao entre result e m

    return result;
}

int main() {
    int b, e, m;
    int resultado;

    //Entrada do usuario
    std::cin >> b >> e >> m;

    resultado = pow(b, e, m);

    std::cout << resultado;

    return 0;
}
