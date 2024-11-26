/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe de pedido
    Link de estudo sobre biblioteca utility e funcao pair: https://terminalroot.com.br/2021/08/cpp-pair-e-tuple.html
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Pedido
{
    private:
        std::string _cliente;
        int _mesa;
        std::vector<std::pair<std::string, int>> _itens;                // Armazena par de string no vetor: item e quantidade
        
    public:
        // Construtor da classe
        Pedido(std::string cliente, int mesa): _cliente(cliente), _mesa(mesa) {}

        void adicionaItem(const std::string& item, int quantidade)      // Adiciona o item e a quantidade do item ao pedido
        {
            _itens.push_back(std::make_pair(item, quantidade));
        }

        void exibirPedido() const                                       // Exibe o pedido do cliente
        {
            std::cout << "Cliente: " << _cliente << std::endl;
            std::cout << "Mesa: " << _mesa << std::endl;
            std::cout << "Itens do Pedido:" << std::endl;
            for (const auto& item : _itens) {
                std::cout << "- " << item.first << " (Quantidade: " << item.second << ")" << std::endl;
            }
        }

};