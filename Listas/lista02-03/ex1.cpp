/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
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
        void liga();
        void desliga();
        void canal_cima();
        void canal_baixo();
        friend std::ostream& operator<<(std::ostream &out, const Televisao &tv);            // Metodo para imprimir estado da tv

};

// Metodo para ligar tv
void Televisao::liga()
{
    _ligada = true;
}

// Metodo para desligar tv
void Televisao::desliga()
{
    _ligada = false;
}

// Metodo para aumentar o canal
void Televisao::canal_cima()
{
    if(_ligada)
        _canal++;
}

// Metodo para diminuir o canal
void Televisao::canal_baixo()
{
    if(_ligada)
        _canal--;
}

// Metodo para impressao do status: se esta ligada ou nao e em qual canal
std::ostream& operator<<(std::ostream &out, const Televisao &tv)
{
    out << "(" << (tv._ligada ? "ligada" : "desligada") << ", " << tv._canal << ")"; 

    return out;
}

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