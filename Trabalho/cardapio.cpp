/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe do cardapio
    Link de estudo sobre biblioteca utility e funcao pair: https://terminalroot.com.br/2021/08/cpp-pair-e-tuple.html
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility> 

class Cardapio {
    private:
        std::vector<std::pair<std::string, std::string>> _itens;                // Armazena par de string no vetor: item e preco

    public:
        // Construtor da classe
        Cardapio() {}

        void adicionaItem(const std::string& item, const std::string& preco)   // Adiciona um item e seu preco
        {
            _itens.push_back(std::make_pair(item, preco));
        }

        void exibirCardapio() const                                             // Exibe o cardapio
        {
            std::cout << "Cardápio:\n";
            for (const auto& par : _itens) {
                std::cout << "Item: " << par.first << ". Preço: " << par.second << std::endl;
            }
        }

        std::vector<std::pair<std::string, std::string>> getCardapio(){
            return _itens;
        }
};
