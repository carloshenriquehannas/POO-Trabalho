/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2e)
*/

#include <iostream>
#include <math.h>
#include <random>
#include <stdio.h>

class Trio
{
    public:
        int a, b, c;
        Trio(int a, int b, int c): a(a), b(b), c(c) {}                      // Construtor da classe
};

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
        double *raizes() const
        {
            double delta, *v;
            v = new double[3];

            delta = _b * _b - 4 * _a * _c;

            if(delta == 0)      // Se delta for igual a zero, ha uma raiz real
            {
                v[0] = 1;                                // Quantidade de raiz na posicao v[0]      
                v[1] = (-_b + sqrt(delta))/(2 * _a);     // Raiz1 na posicao v[1]
                v[2] = (-_b + sqrt(delta))/(2 * _a);     // Raiz2 na posicao v[2]: Raiz1 = Raiz2
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
                v[1] = -1.0 * _b / _a;
                v[2] = 1.0 * _c / _a;

            }

            return v;         // Vetor com quantidade de raizes e quais sao elas, se houver
        }

        // Metodo para calcular o resultado do polinomio, quando substitui-se 'x'
        double operator()(double x) const
        {
            return _a * x * x + _b * x + _c;
        }
};

// Funcao que retorna os coeficientes do Polinomio2
Trio coeficientes(const Polinomio2& p)
{
    double a, b, c;    
    double x1, x2;

    double *v = p.raizes();

    if(v[0] == 0)                   // Se houver raizes complexas
    {
        a = p(0) / v[2];
        b = -v[1] * a;
        c = v[2] * a;
    }
    else                            // Se houver raizes reais
    {
        x1 = v[1];
        x2 = v[2];

        a = p(0) / (x1 * x2);       // Coeficiente a: calculdo pela forma fatorada do polinomio
        b = -(x1 + x2) * a;         // Coeficiente b: calculado pela soma das raizes
        c = x1 * x2 * a;            // Coeficiente c: calculado pelo produto das raizes

    }

    return Trio(a, b, c);
}

int main()
{
    double *v;
    Polinomio2 p1(578, -79, -1768);
    Trio t = coeficientes(p1);
    std::cout << t.a << " " << t.b << " " << t.c << '\n' ;

    Polinomio2 p2(754, 1652, -497);
    t = coeficientes(p2);
    std::cout << t.a << " " << t.b << " " << t.c << '\n' ;

    Polinomio2 p3(52, 1955, -1219);
    t = coeficientes(p3);
    std::cout << t.a << " " << t.b << " " << t.c << '\n' ;
    
    return 0;
}