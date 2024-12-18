//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <iostream>

int main ()
{
    int n;
    int i;

    std::cin >> n; //Entrada do usuario

    for(i = 0; i <= 2*n; i++) //Laco entre 0 e 2*n
    {
        if(i != 2*n)
        {
            std::cout << i << ", "; //Situacao de print se i diferente de 2*n
        }
        else
        {
            std::cout << i << std::endl; //Situacao de print se i for igual ao 2*n
        }
    }

return 0;
}
