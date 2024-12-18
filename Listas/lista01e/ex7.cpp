//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

/*
 * Para esse codigo, utilizei o seguinte link: https://pt.stackoverflow.com/questions/462432/criar-um-algoritmo-em-js-para-listar-todos-os-n%C3%BAmeros-primos-menores-ou-igual
 * Nesse link ha uma explicacao da logica em se encontrar numeros primos
*/

#include <iostream>

//Funcao para verificar se um numero eh primo ou nao
bool numero_primo(int numero)
{
    for (int i = 3; i * i <= numero; i += 2)
    {
        if(numero % i == 0)             //Se tiver outros divisores, nao eh primo
        {
            return false;
        }
    }

    return true;                       //Nao ha divisores alem do proprio numero: eh primo
}

int *primos(int N)
{
    int i, indice = 1;
    int *vetor_primos = new int[N];

    vetor_primos[0] = 2;                //Aloca o unico primo par na primeira posicao
    for(i = 3; i <= N; i += 2)          //Verifica se apenas os numeros impares sao primos
    {
        if(numero_primo(i)){            
            vetor_primos[indice] = i;   //Se for primo, aloca no vetor
            indice++;
        }
    }
    vetor_primos[indice] = 0;           //Encerra o vetor com o indice '0'

    return vetor_primos;
}

int main()
{
    int N, i = 0;
    std::cin >> N;                      //Leitura do usuario

    int *numeros_primos = primos(N);

    //Imprime os indices da lista enquanto nao encontrar '0'
    while(numeros_primos[i] != 0)
    {
        std::cout << numeros_primos[i] << " ";
        i++;
    }
    
    delete[] numeros_primos;

    return 0;
}
