/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

#include <iostream>
#include <math.h>
#include <random>

class Polinomio2
{
    private:
        int _a, _b, _c;

    public:
        Polinomio2(int a = 0, int b = 0, int c = 0): _a(a), _b(b), _c(c)    // Construtor da classe
        {
            if(a == 0)
            {
                a = 1;
                b = random();
                c = random();
            }
            else
            {
                _a = a;
                _b = b;
                _c = c;
            }
        } 

        // Metodo para calcular a quantidade de raizes e quais sao elas
        double *raizes()
        {
            double delta, *v;
            v = new double[3];

            delta = _b * _b - 4 * _a * _c;

            if(delta == 0)      // Se delta for igual a zero, ha uma raiz real
            {
                v[0] = 1;                                // Quantidade de raiz na posicao v[0]      
                v[1] = (-_b + sqrt(delta))/(2 * _a);     // Raiz na posicao v[1]
            }
            else if(delta > 0)  // Se delta positivo, ha duas raizes reais                          
            {
                v[0] = 2;                               // Quantidade de raizes na posicao v[0]      
                v[1] = (-_b - sqrt(delta))/(2 * _a);    // Raiz1 na posicao v[1]
                v[2] = (-_b + sqrt(delta))/(2 * _a);    // Raiz2 na posicao v[2]
            }
            else               // Se delta negativo, nao ha raizes reais
            {
                v[0] = 0;
            }

            return v;         // Vetor com quantidade de raizes e quais sao elas, se houver
        }

        // Metodo para calcular o resultado do polinomio, quando substitui-se 'x'
        double operator()(double x)
        {
            return _a * x * x + _b * x + _c;
        }
};

int main()
{

    Polinomio2 p(1050, 9988, -945);
    double *v = p.raizes();
    for(int i=0; i<=v[0]; i++) std::cout << v[i] << " " ;
    std::cout << p(2) << std::endl;
    
    return 0;
}