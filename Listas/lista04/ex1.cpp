/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <stack>

int elementok(std::stack<int>& pilha, int k)
{
    std::stack<int> pilhaAuxiliar = pilha;              // Cria uma copia da pilha
    int numeroPar[100];                                 // Vetor auxiliar (armazena os numeros pares)
    int contador = 0;

    while (!pilhaAuxiliar.empty())          
    {
        if(pilhaAuxiliar.top() % 2 == 0)                // Verifica os numeros pares
        {
            numeroPar[contador] = pilhaAuxiliar.top();
            contador++;                                 // Variavel auxiliar: verifica quantidade de numeros pares na pilha
        }
        pilhaAuxiliar.pop();
    }

    if(contador >= k)                                   // Verifica se ha numeros pares suficientes 
        return numeroPar[k - 1];
    else                                                // Se nao houver, deve retornar '-1'
        return -1;
    
}

int main()
{
    std::stack<int> p;
    p.push(354);
    p.push(383);
    p.push(-844);
    p.push(854);
    p.push(-989);
    p.push(97);
    p.push(-726);
    p.push(-77);
    p.push(-369);
    p.push(140);
    p.push(-77);
    p.push(21);
    p.push(-790);
    p.push(-896);
    p.push(38);
    p.push(-822);
    p.push(-921);
    p.push(238);
    p.push(715);
    p.push(-364);
    p.push(-269);
    p.push(-655);
    p.push(-474);
    p.push(975);
    p.push(-894);
    p.push(-821);
    p.push(34);
    p.push(374);
    p.push(899);
    p.push(-174);
    p.push(-596);
    p.push(553);
    p.push(-658);
    p.push(446);
    p.push(65);
    p.push(-194);
    p.push(-57);
    p.push(-188);
    p.push(680);
    p.push(-139);
    p.push(320);
    p.push(709);
    p.push(168);
    p.push(615);
    p.push(60);
    p.push(485);
    p.push(-918);
    p.push(-144);
    p.push(489);
    p.push(136);
    printf("%d\n", elementok(p, 90));
    printf("%d\n", elementok(p, 56));
    printf("%d\n", elementok(p, 41));
    printf("%d\n", elementok(p, 47));
    printf("%d\n", elementok(p, 77));
    printf("%d\n", elementok(p, 9));
    printf("%d\n", elementok(p, 64));
    printf("%d\n", elementok(p, 53));
    printf("%d\n", elementok(p, 88));
    printf("%d\n", elementok(p, 14));

    return 0;
}