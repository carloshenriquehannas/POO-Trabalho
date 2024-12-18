/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <stack>
#include <queue>

bool comparar(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;

    return a.first < b.first;
}

std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores)
{
    std::vector<std::pair<std::string, int>> pontos;

    std::string j;
    int p;
    while (!jogadores.empty())
    {
        j = jogadores.front();
        p = 0;
        pontos.push_back(std::pair(j, p));
        jogadores.pop();
    }

    int pivot = 0, c = 0;
    while (!cartas.empty())
    {
        c = cartas.top();
        cartas.pop();

        pontos[pivot].second += c;
        pivot = (pivot + 1) % pontos.size();
    }

    for (size_t i = 0; i < pontos.size(); i++)
        for (size_t j = i; j < pontos.size() - 1; j++)
            if (comparar(pontos[i], pontos[j]))
                std::swap(pontos[i], pontos[j]);

    return pontos.back().first;
}

int main()
{
std::stack<int> c;
    std::queue<std::string> j;
    c.push(10);
    c.push(2);
    c.push(12);
    c.push(15);
    c.push(5);
    c.push(3);
    c.push(2);
    c.push(4);
    c.push(5);
    c.push(15);
    c.push(13);
    c.push(15);
    c.push(8);
    c.push(1);
    c.push(1);
    c.push(1);
    c.push(8);
    c.push(13);
    c.push(10);
    c.push(4);
    c.push(13);
    c.push(15);
    c.push(15);
    c.push(3);
    c.push(4);
    c.push(14);
    c.push(7);
    c.push(13);
    c.push(10);
    c.push(10);
    c.push(15);
    c.push(8);
    c.push(9);
    c.push(5);
    c.push(7);
    c.push(7);
    c.push(2);
    c.push(3);
    c.push(14);
    c.push(5);
    c.push(5);
    c.push(7);
    c.push(8);
    c.push(6);
    c.push(8);
    c.push(1);
    c.push(7);
    c.push(2);
    c.push(15);
    c.push(8);
    c.push(1);
    c.push(11);
    c.push(2);
    c.push(1);
    c.push(9);
    c.push(7);
    c.push(2);
    c.push(5);
    c.push(3);
    c.push(6);
    c.push(12);
    c.push(13);
    c.push(8);
    c.push(15);
    c.push(14);
    c.push(6);
    c.push(1);
    c.push(8);
    c.push(5);
    c.push(15);
    c.push(7);
    c.push(4);
    c.push(6);
    c.push(8);
    c.push(10);
    c.push(4);
    c.push(15);
    c.push(10);
    c.push(12);
    c.push(9);
    c.push(1);
    c.push(1);
    c.push(9);
    c.push(4);
    c.push(3);
    c.push(9);
    c.push(2);
    c.push(3);
    c.push(13);
    c.push(11);
    c.push(7);
    c.push(11);
    c.push(3);
    c.push(1);
    c.push(2);
    c.push(5);
    c.push(6);
    c.push(4);
    c.push(2);
    j.push("raquel");
    j.push("léo");
    j.push("josé");
    j.push("sra.");
    j.push("eduarda");
    j.push("hellena");
    j.push("yuri");
    j.push("lorenzo");
    j.push("igor");
    j.push("olivia");
    j.push("bernardo");
    j.push("lucas");
    j.push("natália");
    std::cout << jogo(c, j) << std::endl;
    return 0;
}
