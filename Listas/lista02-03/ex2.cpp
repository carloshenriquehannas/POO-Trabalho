/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

/*
    Neste codigo, implementei o algoritmo de mdc, no metodo reduz(), utilizando o seguinte link:
    https://www.clubedohardware.com.br/forums/topic/1529256-exerc%C3%ADcio-de-mdc-linguagem-c-c/
*/

// ARRUMAR: CASO EM QUE HA ENTRADA EXTREMAMENTE PEQUENA

#include <iostream>


// Criacao da classe
class Fracao
{
    private:                                    
        long long int _numerador, _denominador;
        void reduz()                                                           // Simplifica a fracao pelo metodo de mdc
        {
            long long int a, b, mdc;
            a = _numerador;
            b = _denominador;

            while (b != 0)
            {
                long long int aux = b;
                b = a % b;
                a = aux;
            }

            mdc = a;

            _numerador /= mdc;
            _denominador /= mdc;

            if(_denominador < 0)
            {
                _numerador = -_numerador;
                _denominador = -_denominador;
            }
        }

    public:                                                                    
        Fracao(long long int num, long long den): _numerador(num), _denominador(den)
        {
            reduz();    
        }
        Fracao(double x = 0, double eps = 1): _numerador(x), _denominador(eps) // Construtor da classe. Default: '0' no numerador e '1' para denominador
        {
            if (x < eps && x > eps)
            {
                _numerador = 0;
                _denominador = 1;
            }
            else
            {
                _denominador = 10;
                _numerador = x * 10;
                while((_numerador - (long long int) _numerador) != 0.0)
                {
                    _numerador *= 10;
                    _denominador *= 10;
                }
            }
            reduz();                                                           // Simplifica a fracao instanciada
        }   

        friend Fracao operator+(const Fracao &a, const Fracao &b);
        friend Fracao operator-(const Fracao &a, const Fracao &b);
        friend Fracao operator*(const Fracao &a, const Fracao &b);
        friend Fracao operator/(const Fracao &a, const Fracao &b);
        friend std::ostream& operator<<(std::ostream &out, const Fracao &a);

        operator double()                                                      // Conversao para double
        {
            return static_cast<double> (_numerador)/_denominador;
        }
        
};

// Metodo de soma, para duas fracoes
Fracao operator+(const Fracao &a, const Fracao &b)
{
    long long int numerador, denominador;

    numerador = a._numerador * b._denominador + b._numerador * a._denominador;
    denominador = a._denominador * b._denominador;

    return Fracao(numerador, denominador);
    
}

// Metodo de subtracao, para duas fracoes
Fracao operator-(const Fracao &a, const Fracao &b)
{
    long long int numerador, denominador;

    numerador = a._numerador * b._denominador - b._numerador * a._denominador;
    denominador = a._denominador * b._denominador;

    return Fracao(numerador, denominador);
    
}

// Metodo de multiplicacao, para duas fracoes
Fracao operator*(const Fracao &a, const Fracao &b)
{
    long long int numerador, denominador;

    numerador = a._numerador * b._numerador;
    denominador = a._denominador * b._denominador;

    return Fracao(numerador, denominador);
    
}

// Metodo de divisao, para duas fracoes
Fracao operator/(const Fracao &a, const Fracao &b)
{
    long long int numerador, denominador;

    numerador = a._numerador * b._denominador;
    denominador = a._denominador * b._numerador;

    return Fracao(numerador, denominador);
    
}

// Metodo para impressao
std::ostream& operator<<(std::ostream &out, const Fracao &a)
{
    if (a._denominador == 1) {                                                 // Caso especial de impressao quando denominador for '1'
        out << a._numerador; 
    } else {
        out << a._numerador << "/" << a._denominador;                          // Caso contrario, imprime a fracao completa
    }
    return out;
}

int main()
{
    Fracao f;                                                                  // Instancia um objeto

    // Exemplos de comandos de entrada 
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(-78LL, 70LL);
    f = f - Fracao(-55LL, 91LL);
    f = f + Fracao(15LL, 78LL);
    f = f - Fracao(76LL, 91LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f * Fracao(39LL, 26LL);
    f = f - Fracao(-28LL, 12LL);
    f = f * Fracao(2LL, 5LL);
    f = f - Fracao(-35LL, 5LL);
    std::cout << f << " " << double(f) << std::endl;

return 0;
}