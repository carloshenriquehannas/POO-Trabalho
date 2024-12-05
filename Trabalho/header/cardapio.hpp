/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de cardapio
*/

#ifndef CARDAPIO_HPP
#define CARDAPIO_HPP

#include <string>
#include <vector>
#include <utility> // Para usar o std::pair

class Cardapio 
{
    private:
        std::vector<std::pair<std::string, double>> _itens;

    public:
        // Construtor da classe
        Cardapio();  

        // Metodos da classe
        void adicionaItem(const std::string& item, double preco);  
        void exibirCardapio() const;  
        std::vector<std::pair<std::string, double>> getCardapio();  
};

#endif // CARDAPIO_HPP
