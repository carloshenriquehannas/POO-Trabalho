/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2e)
*/

#include <iostream>

// Criacao da classe
class Televisao
{
    private:
        bool _ligada;
        int _canal;
    public:
        Televisao(bool ligada = false, int canal = 1) : _ligada(ligada), _canal(canal) {}   // Construtor. Default desligada em canal 1
        void liga()                                                                         // Metodo para ligar tv
        {
            _ligada = true;
        }

        void desliga()                                                                      // Metodo para desligar tv
        {
            _ligada = false;
        }

        void canal_cima()                                                                   // Metodo para aumentar o canal
        {
            _canal = (_canal % 100) + _ligada;                                  // Se _canal for maior que 100, voltar para _canal 1

        }

        void canal_baixo()                                                                  // Metodo para diminuir o canal
        {
            _canal = (101 + _canal - _ligada -(_ligada && _canal == 1)) % 101;  // Se _canal for menor que 1, voltar para _canal 100
        }

        friend std::ostream& operator<<(std::ostream &out, const Televisao &tv)             // Metodo para imprimir estado da tv
        {
            out << "(" << (tv._ligada ? "ligada" : "desligada") << ", " << tv._canal << ")"; 

           return out;
        }

};

int main()
{
    Televisao tv;                   // Instanciacao do objeto   

    //Exemplos de comandos de entrada 
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.liga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.desliga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;      

    return 0;
}