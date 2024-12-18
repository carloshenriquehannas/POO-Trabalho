//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

#define MAX 1000000

//Funcao auxiliar para encontrar numeros iguais no vetor
int contains(int pos, int* vec, int lenght)
{
    for (int i = 0; i < lenght; i++)                    //Percorre o vetor
    {
        if (vec[i] == vec[pos] && i != pos)             //Se o valor for igual a um existente, retorna a posicao
            return i;
    }

    return -1;                                          //Se nao ha repeticao de numeros, retorna -1
}

int main()
{
    int numbers[MAX];                                   //Vetor com o numero maximo de elementos

    int lenght = 0;
    while (std::cin >> numbers[lenght++]);              //Entrada do usuario
    lenght--;                                           //Define o novo tamanho do vetor: quantidade de numeros da entrada

    //Remocao de numeros replicados, percorrendo o vetor
    for (int i = 0; i < lenght; i++)
    {
        int j = contains(i, numbers, lenght);
        if (j >= 0)                                 //Caso em que ha valores repetidos
        {
            if (j == lenght - 1)                    //Repeticao na ultima posicao
                numbers[i] = numbers[lenght - 2];
            else if (j == lenght - 2)               //Repeticao na penultima posicao
                numbers[i] = numbers[lenght - 1];
            else
            {
                numbers[i] = numbers[lenght - 1];   //Numero duplicado vai para a ultima posicao
                numbers[j] = numbers[lenght - 2];   //Penultimo numero para a posicao que estava duplicada
            }

            lenght -= 2;
            i = 0;                                  //Flag para reiniciar o processo de verificacao de duplicata
        }
    }

    if (lenght)
        std::cout << numbers[0] << std::endl;       //Imprime o valor restante
    else
        std::cout << 0 << std::endl;                //Imprime '0' se nao houver numero

    return 0;
}