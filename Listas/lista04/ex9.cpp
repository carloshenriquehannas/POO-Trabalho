/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <vector>
#include <sstream>

std::vector<double> notas(std::string s)
{
    std::vector<double> notas;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, ','))
    {
        if (&item != nullptr && std::isdigit(item[0]))
        {
            notas.push_back(std::stod(item));
        }
    }
    return notas;
}

int main()
{
    std::string s = "Andre,10,Smaira,5";
    for (double n : notas(s))
        std::cout << n << std::endl;
    return 0;
}