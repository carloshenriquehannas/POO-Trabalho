/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de pedido
    Link de estudo sobre biblioteca utility e funcao pair: https://terminalroot.com.br/2021/08/cpp-pair-e-tuple.html
*/

#include "../header/pedido.hpp"

#include <iostream>

// Construtor da classe
Pedido::Pedido(std::string cliente, int mesa): _cliente(cliente), _mesa(mesa) {}

void Pedido::adicionaItem(const std::string& item, int quantidade)      // Adiciona o item e a quantidade do item ao pedido
{
    _itens.push_back(std::make_pair(item, quantidade));
}

void Pedido::exibirPedido() const                                       // Exibe o pedido do cliente
{
    std::cout << "Cliente: " << _cliente << std::endl;
    std::cout << "Mesa: " << _mesa << std::endl;
    std::cout << "Itens do Pedido:" << std::endl;
    for (const auto& item : _itens)
        std::cout << "- " << item.first << " (Quantidade: " << item.second << ")" << std::endl;
        
}

std::vector<std::pair<std::string, int>> Pedido::getPedido()            // Retorna itens do pedido  
{
    return _itens;
}

void Pedido::finalizaPedido()                                           // Finaliza o pedido
{
    _itens.clear();
}

std::string Pedido::getCliente()                                        // Retorna o nome do cliente qur fez o pedido
{
    return _cliente;
}