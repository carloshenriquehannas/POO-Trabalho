/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>

std::vector<int> retorna_conjunto_sem_n(const std::vector<int> &v, int n)
{
    std::vector<int> retval;
    bool temZero = false;

    for (int i = 0; i < v.size(); i++)
    {
        bool existe = false;
        bool notN = v[i] != n;
        temZero |= v[i] == 0;

        for (int j = 0; j < retval.size(); j++)
        {
            existe |= (v[i] == retval[j]);
        }

        retval.push_back(v[i] * (!existe) * notN);
    }

    return retval;
}

void ordena_vetor(std::vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int trocar = v[i] > v[j];

            int aux = v[j];
            v[j] = aux * (!trocar) + v[i] * trocar;
            v[i] = v[i] * (!trocar) + aux * trocar;
        }
    }
}

void remove_zeros(std::vector<int> &v, int offset)
{
    bool primeiroZero = v[0 + offset] == 0;
    while (primeiroZero)
    {
        for (int i = offset; i < v.size() - 1; ++i)
        {
            v[i] = v[i + 1];
        }
        v.pop_back();
        primeiroZero = v[0 + offset] == 0;
    }
}

std::vector<int> retira(std::vector<int> v, int n)
{
    bool temZero = false;
    for (int i = 0; i < v.size(); i++)
    {
        temZero |= v[i] == 0;
    }

    std::vector<int> v_copia = retorna_conjunto_sem_n(v, n);
    ordena_vetor(v_copia);
    remove_zeros(v_copia, temZero);
    return v_copia;
}

int main()
{
    std::vector<int> v = {5, 1, 8, 4, 3, 5};
    for (auto e : retira(v, 8))
        std::cout << e << std::endl;
    return 0;
}