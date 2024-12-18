/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <string>

std::string retira(std::string texto, char c)
{
    if (texto.empty())          // Situacao de texto vazio
    {
        return texto;
    }

    int next = texto.find(c);   // Procura primeira ocorrencia do caractere no texto
    while (next > -1)           // Enquanto encontrar o caractere, realizar o loop
    {
        texto.erase(next, 1);   // Apagar a ocorrencia do caractere
        next = texto.find(c);   // Procura proxima ocorrencia do caractere no texto
    }

    return texto;
}

int main()
{
    std::cout << retira("Testes", 'e') << std::endl;
    std::cout << retira("Testes", 'X') << std::endl;

    return 0;
}