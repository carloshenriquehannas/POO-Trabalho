/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de cardapio
    Link de estudo sobre biblioteca utility e funcao pair: https://terminalroot.com.br/2021/08/cpp-pair-e-tuple.html
*/

#include "cardapio.hpp"
#include <iostream>

// Construtor
Cardapio::Cardapio() {}

void Cardapio::adicionaItem(const std::string& item, double preco)      // Adiciona item e preco ao cardapio
{
    _itens.push_back(std::make_pair(item, preco));
}

void Cardapio::exibirCardapio() const                                   // Exibe o cardapio
{
    std::cout << "Cardápio:\n";
    for (const auto& par : _itens)
        std::cout << "Item: " << par.first << ". Preço: R$ " << par.second << std::endl;
}

std::vector<std::pair<std::string, double>> Cardapio::getCardapio()     // Retorna o cardapio
{
    return _itens;
}
