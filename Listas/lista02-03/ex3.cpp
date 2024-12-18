/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

#include <iostream>
#include <math.h>

#define PI 3.1415

class Vetor
{
    private:
        int _x, _y;

    public:
    Vetor(int x = 0, int y = 0): _x(x), _y(y) {}                            //Construtor da classe: Valores default: '0' em x e '0' em y

    friend Vetor operator+(const Vetor &a, const Vetor &b);
    friend Vetor operator-(const Vetor &a, const Vetor &b);
    friend int operator*(const Vetor &a, const Vetor &b);
    friend int operator^(const Vetor &a, const Vetor &b);
    friend double operator<(const Vetor &a, const Vetor &b);
    friend std::ostream& operator<<(std::ostream &out, const Vetor &a);

    double abs() const
    {
        return sqrt(_x * _x + _y * _y);
    }                                                     
};

// Metodo de soma, para dois vetores
Vetor operator+(const Vetor &a, const Vetor &b)
{
    int soma_x, soma_y;

    soma_x = a._x + b._x;
    soma_y = a._y + b._y;;

    return Vetor(soma_x, soma_y);
    
}

// Metodo de subtracao, para dois vetores
Vetor operator-(const Vetor &a, const Vetor &b)
{
    int subtracao_x, subtracao_y;

    subtracao_x = a._x - b._x;
    subtracao_y = a._y - b._y;

    return Vetor(subtracao_x, subtracao_y);
    
}

// Metodo de produto escalar, para dois vetores
int operator*(const Vetor &a, const Vetor &b)
{
    int produto_escalar = a._x * b._x + a._y * b._y;

    return produto_escalar;
    
}

// Metodo de produto vetorial, para dois vetores
int operator^(const Vetor &a, const Vetor &b)
{
    int produto_vetorial = a._x * b._y - a._y * b._x;

    return produto_vetorial;
    
}

// Metodo para retornar o menor angulo entre os vetores
double operator<(const Vetor &a, const Vetor &b)
{
    double norma_a, norma_b, cosseno, angulo;
    int produto_escalar;
    
    // Calculo das normas dos vetores a e b
    norma_a = a.abs();
    norma_b = b.abs();

    produto_escalar = operator*(a, b);                                      // Produto escalar entre a e b                                  

    cosseno = produto_escalar / (norma_a * norma_b);                        // Calcula o cosseno do angulo

    angulo = acos(cosseno) * 180.0/PI;                                      // Calcula o angulo (em graus)

    return angulo;
}

// Metodo para impressao
std::ostream& operator<<(std::ostream &out, const Vetor &a)
{
    out << "(" << a._x << ", " << a._y << ")";

    return out;
}

int main() {

    Vetor v(51, -77);                                                       // Instanciacao do objeto

    // Exemplos de comandos de entrada
    std::cout << v.abs() << std::endl;
    v = v - Vetor(4, -14);
    std::cout << (v * Vetor(-77,74)) << std::endl;
    std::cout << v.abs() << std::endl;
    std::cout << v << std::endl;
    std::cout << v.abs() << std::endl;
    std::cout << (v * Vetor(-40,-51)) << std::endl;
    std::cout << v << std::endl;
    std::cout << (v ^ Vetor(-80,-70)) << std::endl;
    std::cout << (v < Vetor(33,18)) << std::endl;
    std::cout << (v ^ Vetor(-3,39)) << std::endl;
    std::cout << (v * Vetor(47,53)) << std::endl;
    v = v - Vetor(68, -66);
    std::cout << v << std::endl;
    v = v + Vetor(-11, 79);
    std::cout << v.abs() << std::endl;

    return 0;
}