/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de pagamento
*/

#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

#include "pedido.hpp"
#include "cardapio.hpp"

#include <string>
#include <vector>

class Pagamento                         // Superclasse
{
    private:
        double valorTotal;
        double valorDesconto;
        double valorFinal;
        int erro;
        Pedido* p;                     // Ponteiro para Pedido
        Cardapio c;

    public:
        // Construtor e destrutor da classe
        Pagamento(Pedido* p_in, Cardapio c_in, float total = 0, int erro = 0);
        virtual ~Pagamento() = default;

        // Metodos da classe
        void calcTotal();
        void setDesconto();
        void semDesconto();
        void setFinal();
        double getFinal() const;
        Pedido* getPedido() const;
        Cardapio getCardapio() const;
        int getErro() const;
        float getTotal() const;
};

class Dinheiro : public Pagamento       // Classe herdada de pagamento
{
    private:
        int confirmacao;
        double valorRecebido;
        double troco;

    public:
        // Construtor da classe
        Dinheiro(Pedido* p_in, Cardapio c_in, float total = 0, int erro = 0, int conf = 0);

        // Metodos da classe
        void pagarDinheiro();
        int getConfirmacao() const;
        double getTroco() const;
        double getValor() const;
};

class Pix : public Pagamento            // Classe herdada de pagamento
{
    private:
        int confirmacao;
        std::string devedor;
        std::string credor;
        std::string chave;

    public:
        // Construtor da classe
        Pix(Pedido* p_in, Cardapio c_in, float total = 0, int erro = 0);

        // Metodos da classe
        void pagarPix();
        int getConfirmacao() const;
        void setCredor(const std::string& cred);
        void setChave(const std::string& ch);
};

class Cartao : public Pagamento         // Classe herdada de pagamento
{
    private:
        int confirmacao;
        int tipoPagamento;
        std::string banco;

    public:
        // Construtor da classe
        Cartao(Pedido* p_in, Cardapio c_in, float total = 0, int erro = 0);

        // Metodos da classe
        void pagarCartao();
        int getConfirmacao() const;
        int getTipo() const;
};

#endif // PAGAMENTO_HPP
