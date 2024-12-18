/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> Matriz;

bool comparar(const std::vector<int> &a, const std::vector<int> &b)
{
    int aCnt = 0, bCnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 == 0)
            aCnt++;
            
        if (b[i] % 2 == 0)
            bCnt++;
    }

    if (aCnt == bCnt)
    {
        int i = 0;
        while (a[i] == b[i])
            i++;

        return a[i] < b[i];
    }

    return aCnt < bCnt;
}

void ordena_par(Matriz &M)
{
    sort(M.begin(), M.end(), comparar);
}

int main()
{
    int nl = 3, nc = 3;
    // std::cin >> nl >> nc;
    Matriz m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ordena_par(m);
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}