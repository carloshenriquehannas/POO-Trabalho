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
#include <locale.h>

class Pagamento
{
private:      
    double valorTotal;
    double valorDesconto;
    double valorFinal;
    int erro;
    Pedido *p; // Objeto pedido o tipo ponteiro para poder ser finalizado ao efetuar o pagamento
    Cardapio c;

public:
    Pagamento(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : valorTotal(total), erro(erro), p(p_in), c(c_in){}
    ~Pagamento() = default;
    void calcTotal() {
        std::vector<std::pair<std::string, int>> aux_pedido = p->getPedido();
        std::vector<std::pair<std::string, double>> aux_cardapio = c.getCardapio();
        
        for (const auto& par_pedido : aux_pedido) {
            bool encontrado = false;

            for (const auto& par_cardapio : aux_cardapio) {
                if (par_pedido.first == par_cardapio.first) {
                    encontrado = true;
                    valorTotal += par_pedido.second * par_cardapio.second;
                    break;
                }
            }

            if (!encontrado) {
                std::cout << "O item " << par_pedido.first << " nao foi encontrado no cardapio." << std::endl;
                erro = 1; // Flag de erro.
            }
        }
    }

    void setDesconto(){
        std::cout<<"insira o desconto a ser aplicado: R$";
        std::cin>>valorDesconto;
        std::cout<<std::endl;
    }

    void semDesconto(){
        valorFinal = valorTotal;
    }

    void setFinal(){
        valorFinal = valorTotal - valorDesconto;
    }

    double getFinal(){
        return valorFinal;
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
        return valorTotal;
    }

};

class Dinheiro : public Pagamento
{
private:
    int confirmacao;    //flag utilizada para verificar se o pedido foi pago com sucesso ou se houve problema.
    double valorRecebido;
    double troco;
public:
    // Construtor
    Dinheiro(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0, int conf = 0) : Pagamento(p_in, c_in, total, erro), confirmacao(conf){};
    // Destrutor
    ~Dinheiro() = default;

    void pagarDinheiro(){       
        valorRecebido = 0;
        int realizado = 0;
        calcTotal();
        std::cout<<"Pagamento em dinheiro selecionado."<<std::endl;
        std::cout<<"Total a ser pago: R$ "<<getTotal()<<std::endl;
        while(realizado == 0){
            std::cout<<"Digite 1 para aplicar desconto."<<std::endl<<"Digite 2 para continuar sem desconto."<<std::endl;
            std::cin>>confirmacao;
            if (confirmacao == 1){
                setDesconto();
                setFinal();
                std::cout<<"Valor final a ser pago: R$ "<<getFinal()<<std::endl;
            }
            if (confirmacao == 2){
                semDesconto();
                std::cout<<"Valor final a ser pago: R$ "<<getTotal()<<std::endl;
            }
            if(confirmacao == 1 || confirmacao == 2) realizado = 1;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
        while(valorRecebido < getFinal()){
            std::cout<<"Insira a quantia paga pelo cliente: R$ ";
            std::cin>>valorRecebido;
            if(valorRecebido < getFinal()){
                std::cout<<"Valor insuficiente!"<<std::endl;
            }
        }
        troco = valorRecebido - getFinal();
        std::cout<<"Troco calculado: R$"<<troco<<std::endl;
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

    double getTroco(){
        return troco;
    }

    double getValor(){
        return valorRecebido;
    }
};

class Pix : public Pagamento
{
private:
    int confirmacao;     //flag utilizada para retornar se o pedido foi pago com sucesso ou se houve problema.
    std::string devedor, credor, chave;
public:
    // Construtor
    Pix(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : Pagamento(p_in, c_in, total, erro){};
    // Destrutor
    ~Pix() = default;
    void pagarPix(){   
        int realizado = 0;    
        std::cout<<"Pagamento via Pix selecionado."<<std::endl;
        calcTotal();
        while(realizado == 0){
            std::cout<<"Digite 1 para aplicar desconto."<<std::endl<<"Digite 2 para continuar sem desconto."<<std::endl;
            std::cin>>confirmacao;
            if (confirmacao == 1){
                setDesconto();
                setFinal();
                std::cout<<"Valor final a ser pago: R$ "<<getFinal()<<std::endl;
            }
            if (confirmacao == 2){
                semDesconto();
                std::cout<<"Valor final a ser pago: R$ "<<getFinal()<<std::endl;
            }
            if(confirmacao == 1 || confirmacao == 2) realizado = 1;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
        devedor = getPedido()->getCliente();
        std::cout<<"Devedor: "<<devedor<<std::endl;
        std::cout<<"Credor: "<<credor<<std::endl;
        std::cout<<"Chave pix: "<<chave<<std::endl;
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

    void setCredor(std::string cred){
        credor = cred;
    }

    void setChave(std::string ch){
        chave = ch;
    }
};

class Cartao : public Pagamento
{
private:
    int confirmacao;    //flag utilizada para retornar se o pedido foi pago com sucesso ou se houve problema.
    int tipoPagamento;
    std::string banco;
public:
    // Construtor
    Cartao(Pedido *p_in, Cardapio c_in, float total = 0, int erro = 0) : Pagamento(p_in, c_in, total, erro){};

    //Destrutor
    ~Cartao() = default;

    void pagarCartao(){        
        calcTotal();
        int realizado = 0;
        std::cout<<"Pagamento via cartao selecionado."<<std::endl;
        std::cout<<"Total a ser pago: R$ "<<getTotal()<<std::endl;
        while(realizado == 0){
            std::cout<<"Digite 1 para aplicar desconto."<<std::endl<<"Digite 2 para continuar sem desconto."<<std::endl;
            std::cin>>confirmacao;
            if (confirmacao == 1){
                setDesconto();
                setFinal();
                std::cout<<"Valor final a ser pago: R$ "<<getFinal()<<std::endl;
            }
            if (confirmacao == 2){
                semDesconto();
                std::cout<<"Valor final a ser pago: R$ "<<getFinal()<<std::endl;
            }
            if(confirmacao == 1 || confirmacao == 2) realizado = 1;
            else std::cout<<"Valor invalido!"<<std::endl;
        }
        while(realizado == 1){
            std::cout<<"Digite o nome do banco: ";
            std::getline(std::cin>>std::ws, banco);
            std::cout<<"\nDigite 1 para credito ou 2 para debito:";
            std::cin>>tipoPagamento;
            if(tipoPagamento == 1 || tipoPagamento == 2) realizado = 2;
            else std::cout<< "Valor invalido!"<<std::endl;
        }
        if(tipoPagamento == 1) std::cout<<"Credito selecionado."<<std::endl<<"Pagamento pelo banco: "<<banco<<std::endl;
        if(tipoPagamento == 2) std::cout<<"Debito selecionado."<<std::endl<<"Pagamento pelo banco: "<<banco<<std::endl;
        while(realizado == 2){
            std::cout<<"Digite 1 para confirmar pagamento."<<std::endl<<"Digite 2 para cancelar proceso de pagamento."<<std::endl;
            std::cin>>confirmacao;
            if(confirmacao == 1 || confirmacao == 2){
                realizado = 3;
            } 
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

