//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

//Funcao auxiliar para verificar se o numero eh divisel por 3, 5, 7, 11 e 17 simultaneamente
int check_div(int n) {
    return (n % 3 == 0 && n % 5 == 0 && n % 7 == 0 && n % 11 == 0 && n % 17 == 0);
}

int main() {
    int n;

    std::cin >> n;                          //Entrada do usuario

    for(int i = 1; i <= n; i++) {           //Percorre os numeros de 1 ate n
        int resultado = check_div(i);       //Verifica se i eh divisivel

        while(resultado) {                  //Se divisivel, imprimir na tela
            std::cout << i << std::endl;
            resultado = 0;                  //Condicao para sair do laco e verificar o proximo i divisivel
        }
    }

    return 0;
}