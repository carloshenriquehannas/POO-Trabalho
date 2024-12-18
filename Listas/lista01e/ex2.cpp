//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

/*
 * Para esse codigo, utilizei o seguinte link: https://pt.stackoverflow.com/questions/124964/teste-de-paridade-em-c
 * Nesse link ha uma explicacao da logica em opearadores de bit com XOR
*/

#include <iostream>

int main() {
    int numero;
    int resultado = 0;

    //Leitura de números do usuário
    while (std::cin >> numero) 
    {
        resultado ^= numero; //Aplica XOR no numero lido
    }

    //Exibe o resultado
    if (resultado != 0) 
    {
        std::cout << resultado << std::endl; //Imprime o resultado se encontrou
    } else {
        std::cout << 0 << std::endl; //Se nao encontrou, exibe '0'
    }

    return 0;
}
