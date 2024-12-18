/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool comparar(const std::string &a, const std::string &b)
{
    if (a.size() == b.size())                       // Se tamanhos iguais, ordena por ordem alfabetica decrescente
    {
        return a > b;
    }

    return a.size() < b.size();                     // Se tamanhos diferentes, ordena em ordem crescente de tamanho
}

void ordena_strings(std::vector<std::string> &vetor)
{
    sort(vetor.begin(), vetor.end(), comparar);     // Ordena as strings
}

int main()
{
    std::vector<std::string> v;
    v.push_back("aaaaaaaaaaa");
    v.push_back("zzzzzzzzzzz");
    v.push_back("test");
    v.push_back("testando");
    v.push_back("testados");
    v.push_back("teste");
    ordena_strings(v);
    for (auto s : v)
    {
        std::cout << s << std::endl;
    }

    return 0;
}