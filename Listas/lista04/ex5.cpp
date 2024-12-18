/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>
#include <map>

typedef std::map<std::pair<int, int>, int> Matriz;

Matriz soma(const Matriz &A, const Matriz &B)
{
    Matriz retval;

    for (const auto &[k, v] : A)
        retval[k] = v;

    for (const auto &[k, v] : B)
        if (k != std::make_pair(-1, -1))
            retval[k] = v;

    return retval;
}

int main()
{
    Matriz A = {
        {{-1, -1}, 2},
        {{0, 0}, 1}};

    Matriz B = {
        {{-1, -1}, 2},
        {{1, 0}, 5}};
    Matriz C = soma(A, B);
    for (const auto &[k, v] : C)
        std::cout << k.first << " " << k.second << " "
                  << v << std::endl;
    return 0;
}
