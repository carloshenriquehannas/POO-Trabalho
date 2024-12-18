/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> split_versao(const std::string &versao)
{
    std::vector<int> numeros;
    std::stringstream stream(versao);
    std::string parte;

    while (std::getline(stream, parte, '.'))
    {
        numeros.push_back(std::stoi(parte));
    }

    return numeros;
}

bool compara_versoes(const std::string &v1, const std::string &v2)
{
    std::vector<int> split_v1 = split_versao(v1);
    std::vector<int> split_v2 = split_versao(v2);

    for (size_t i = 0; i < std::min(split_v1.size(), split_v2.size()); ++i)
    {
        if (split_v1[i] != split_v2[i])
        {
            return split_v1[i] < split_v2[i];
        }
    }

    return split_v1.size() < split_v2.size();
}

void ordena_versoes(std::vector<std::string> &versoes)
{
    bool trocou;
    size_t n = versoes.size();

    do
    {
        trocou = false;
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (!compara_versoes(versoes[i], versoes[i + 1]))
            {
                std::swap(versoes[i], versoes[i + 1]);
                trocou = true;
            }
        }
        n--;
    } while (trocou);
}

int main()
{
    std::vector<std::string> vs = {"1.2.3", "1.2", "1.2.0", "3.0", "0"};
    ordena_versoes(vs);
    for (auto v : vs)
        std::cout << v << std::endl;
    return 0;
}