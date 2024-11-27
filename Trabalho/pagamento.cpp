/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe do cliente
*/
#include <string>
#include <vector>
#include "pedido.cpp"
#include "cardapio.cpp"

class Pagamento
{
private:
    float total;
    int erro;
    Pedido *p; // Objeto pedido o tipo ponteiro para poder ser finalizado ao efetuar o pagamento
    Cardapio c;
public:
    Pagamento(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : total(total), erro(erro), p(p_in), c(c_in){}
    void calcTotal(){
        std::vector<std::pair<std::string, int>> aux_pedido = p->getPedido();
        std::vector<std::pair<std::string, std::string>> aux_cardapio = c.getCardapio();

        for (const auto& par_pedido : aux_pedido){
            for (const auto& par_cardapio : aux_cardapio){
                if (par_pedido.first == par_cardapio.first){
                    total = total + par_pedido.second * std::stof(par_cardapio.second);
                }
                else{
                    std::cout<<"O item "<<par_pedido.first<<" não foi encontrado no cardapio."<<std::endl;
                    erro = 1; // flag de erro se o item não é encontrado no cardápio.
                }
            }
        }
    }

    void pagarDinheiro(){
        float dinheiro, troco;
        calcTotal();
        std::cout<<"Total a ser pago: "<<total<<std::endl;
        std::cout<<"Insira a quantia paga pelo cliente: "<<std::endl;
        std::cin>>dinheiro;
        std::cout<<std::endl;
        std::cout<<"Troco calculado: "<<dinheiro - total<<std::endl;
        std::cout<<"Pedido pago com sucesso!"<<std::endl;
        p->finalizaPedido();
    }

    void pagarPix(){
        
    }

    void pagarCartao(){

    }
};

