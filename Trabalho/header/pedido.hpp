/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de pedido
    Link de estudo sobre biblioteca utility e funcao pair: https://terminalroot.com.br/2021/08/cpp-pair-e-tuple.html
*/

#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <vector>
#include <utility>

class Pedido
{
    private:
        std::string _cliente;
        int _mesa;
        std::vector<std::pair<std::string, int>> _itens;

    public:
        // Construtor da classe
        Pedido(std::string cliente, int mesa);

        // Metodos da classe
        void adicionaItem(const std::string& item, int quantidade);
        void exibirPedido() const;
        std::vector<std::pair<std::string, int>> getPedido();
        void finalizaPedido();
        std::string getCliente();
};

#endif // PEDIDO_HPP
