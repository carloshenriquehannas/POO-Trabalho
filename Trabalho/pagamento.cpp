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
#include <iomanip>

class Pagamento
{
private:      
    float total;
    int erro;
    Pedido *p; // Objeto pedido o tipo ponteiro para poder ser finalizado ao efetuar o pagamento
    Cardapio c;

public:
    Pagamento(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : total(total), erro(erro), p(p_in), c(c_in){}
    ~Pagamento() = default;
    void calcTotal() {
        std::vector<std::pair<std::string, int>> aux_pedido = p->getPedido();
        std::vector<std::pair<std::string, double>> aux_cardapio = c.getCardapio();
        
        for (const auto& par_pedido : aux_pedido) {
            bool encontrado = false;

            for (const auto& par_cardapio : aux_cardapio) {
                if (par_pedido.first == par_cardapio.first) {
                    encontrado = true;
                    total += par_pedido.second * par_cardapio.second;
                    break;
                }
            }

            if (!encontrado) {
                std::cout << "O item " << par_pedido.first << " nao foi encontrado no cardapio." << std::endl;
                erro = 1; // Flag de erro.
            }
        }
    }

    Pedido * getPedido(){
        return p;
    }

    Cardapio getCardapio(){
        return c;
    }

    int getErro(){
        return erro;
    }

    float getTotal(){
        return total;
    }

};

class Dinheiro : public Pagamento
{
private:
    int confirmacao;    //flag utilizada para verificar se o pedido foi pago com sucesso ou se houve problema.
public:
    // Construtor
    Dinheiro(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0, int conf = 0) : Pagamento(p_in, c_in, total, erro), confirmacao(conf){};
    // Destrutor
    ~Dinheiro() = default;

    void pagarDinheiro(){       
        float dinheiro = 0, troco, realizado = 0;
        calcTotal();
        std::cout<<"Pagamento em dinheiro selecionado."<<std::endl;
        std::cout<<"Total a ser pago: R$ "<<getTotal()<<std::endl;
        while(dinheiro < getTotal()){
            std::cout<<"Insira a quantia paga pelo cliente: R$ ";
            std::cin>>dinheiro;
            if(dinheiro < getTotal()){
                std::cout<<"Valor insuficiente!"<<std::endl;
            }
        }
        std::cout<<"Troco calculado: "<<dinheiro - getTotal()<<std::endl;
        while(realizado == 0){
            std::cout<<"Digite 1 para confirmar pagamento."<<std::endl<<"Digite 2 para cancelar proceso de pagamento."<<std::endl;
            std::cin>>confirmacao;
            if(confirmacao == 1 || confirmacao == 2) realizado = 1;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
    }

    int getConfirmacao(){
        return confirmacao;
    }
};

class Pix : public Pagamento
{
private:
    int confirmacao;     //flag utilizada para retornar se o pedido foi pago com sucesso ou se houve problema.
public:
    // Construtor
    Pix(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : Pagamento(p_in, c_in, total, erro){};
    // Destrutor
    ~Pix() = default;
    void pagarPix(){   
        int realizado = 0;    
        calcTotal();
        std::cout<<"Pagamento via Pix selecionado."<<std::endl;
        std::cout<<"Total a ser pago: R$ "<<getTotal()<<std::endl<<"Forneça a chave pix ao cliente."<<std::endl;
        while(realizado == 0){
            std::cout<<"Digite 1 para confirmar pagamento."<<std::endl<<"Digite 2 para cancelar proceso de pagamento."<<std::endl;
            std::cin>>confirmacao;
            if(confirmacao == 1 || confirmacao == 2) realizado = 1;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
    }

    int getConfirmacao(){
        return confirmacao;
    }
};

class Cartao : public Pagamento
{
private:
    int confirmacao;    //flag utilizada para retornar se o pedido foi pago com sucesso ou se houve problema.
    int tipoPagamento;
public:
    // Construtor
    Cartao(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : Pagamento(p_in, c_in, total, erro){};

    //Destrutor
    ~Cartao() = default;

    void pagarCartao(){        
        calcTotal();
        int realizado = 0;
        std::cout<<"Pagamento via cartão selecionado."<<std::endl;
        std::cout<<"Total a ser pago: R$ "<<getTotal()<<std::endl;
        while(realizado == 0){
            std::cout<<"Digite 1 para credito ou 2 para debito:";
            std::cin>>tipoPagamento;
            if(tipoPagamento == 1 || tipoPagamento == 2) realizado = 1;
            else std::cout<< "Valor invalido!"<<std::endl;
        }
        if(tipoPagamento == 1) std::cout<<"Credito selecionado."<<std::endl;
        if(tipoPagamento == 2) std::cout<<"Debito selecionado."<<std::endl;
        while(realizado == 1){
            std::cout<<"Digite 1 para confirmar pagamento."<<std::endl<<"Digite 2 para cancelar proceso de pagamento."<<std::endl;
            std::cin>>confirmacao;
            if(confirmacao == 1 || confirmacao == 2) realizado = 2;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
    }

    int getConfirmacao(){
        return confirmacao;
    }

    int getTipo(){
        return tipoPagamento;
    }
};

