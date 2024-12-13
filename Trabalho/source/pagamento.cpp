/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de pagamento
*/

#include "../header/pagamento.hpp"

#include <iostream>
#include <iomanip>
#include <limits>

// Construtor da classe Pagamento
Pagamento::Pagamento(Pedido *p_in, Cardapio c_in, float total, int erro) : valorTotal(total), erro(erro), p(p_in), c(c_in) {}

void Pagamento::calcTotal()                             // Calcula o valor total da conta
{
    auto aux_pedido = p->getPedido();
    auto aux_cardapio = c.getCardapio();

    for (const auto &par_pedido : aux_pedido)
    {
        bool encontrado = false;

        for (const auto &par_cardapio : aux_cardapio)
        {
            if (par_pedido.first == par_cardapio.first)
            {
                encontrado = true;
                valorTotal += par_pedido.second * par_cardapio.second;
                break;
            }
        }

        if (!encontrado)                            // Tratamento para itens nao encontrados
        {
            std::cout << "O item " << par_pedido.first << " nao foi encontrado no cardapio." << std::endl;
            erro = 1;
        }
    }
}

void Pagamento::setDesconto()                           // Adiciona desconto ao preco 
{
    do
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "\nInsira o desconto a ser aplicado: R$ ";
            std::cin >> valorDesconto;
        } while (std::cin.fail());

        if (valorDesconto > getTotal())
            std::cout << "\nDesconto inserido invalido!\nValor maior que o total do pedido!" << std::endl;
    } while (valorDesconto > getTotal());
}

void Pagamento::semDesconto()                           // Pagamento final sem desconto
{
    valorFinal = valorTotal;
}

void Pagamento::setFinal()                              // Pagamento final com desconto
{
    valorFinal = valorTotal - valorDesconto;
}

double Pagamento::getFinal() const                      // Retorna o valor final 
{
    return valorFinal;
}

Pedido *Pagamento::getPedido() const                    // Retorna um ponteiro para o pedido
{
    return p;
}

Cardapio Pagamento::getCardapio() const                 // Retorna a classe do cardapio
{
    return c;
}

int Pagamento::getErro() const
{
    return erro;
}

float Pagamento::getTotal() const                       // Calcula o valor final
{
    return valorTotal;
}

// Construtor da classe Dinheiro
Dinheiro::Dinheiro(Pedido *p_in, Cardapio c_in, float total, int erro, int conf) : Pagamento(p_in, c_in, total, erro), confirmacao(conf) {}

void Dinheiro::pagarDinheiro()                          // Metodo interativo para realizar pagamento em dinheiro
{
    valorRecebido = 0;
    int realizado = 0;
    calcTotal();

    std::cout << "Pagamento em dinheiro selecionado." << std::endl;
    std::cout << "Total a ser pago: R$ " << getTotal() << std::endl;

    while (realizado == 0)                              // Enquanto o pagamento nao for realizado
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para aplicar desconto.\n" << "Digite 2 para continuar sem desconto." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());

        if (confirmacao == 1)                           // Se houver desconto
        {
            setDesconto();
            setFinal();
            std::cout << "Valor final a ser pago: R$ " << getFinal() << std::endl;
        }
        if (confirmacao == 2)                           // Se nao houver desconto
        {
            semDesconto();
            std::cout << "Valor final a ser pago: R$ " << getTotal() << std::endl;
        }
        if (confirmacao == 1 || confirmacao == 2)
            realizado = 1;
        else
            std::cout << "Valor invalido!" << std::endl;
    }

    while (valorRecebido < getFinal())                 // Processa pagamento do cliente, desde que seja maior ou igual ao valor final
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Insira a quantia paga pelo cliente: R$ ";
            std::cin >> valorRecebido;
        } while (std::cin.fail());

        if (valorRecebido < getFinal())
            std::cout << "Valor insuficiente!" << std::endl;
    }

    // Calculo de troco
    troco = valorRecebido - getFinal();
    std::cout << "Troco calculado: R$" << troco << std::endl;

    while (realizado == 1)
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para confirmar pagamento.\n" << "Digite 2 para cancelar proceso de pagamento." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());

        if (confirmacao == 1 || confirmacao == 2)
            realizado = 2;
        else
            std::cout << "Valor invalido!" << std::endl;
    }
}

int Dinheiro::getConfirmacao() const                // Retorna status da confirmacao
{
    return confirmacao;
}

double Dinheiro::getTroco() const                   // Retorna o valor do troco
{
    return troco;
}

double Dinheiro::getValor() const                   // Retorna o valor recebido pelo cliente
{
    return valorRecebido;
}

// Construtor da classe Pix
Pix::Pix(Pedido *p_in, Cardapio c_in, float total, int erro) : Pagamento(p_in, c_in, total, erro) {}

void Pix::pagarPix()                                // Metodo interativo para realizar pagamento via Pix
{
    int realizado = 0;
    calcTotal();

    std::cout << "Pagamento via Pix selecionado." << std::endl;
    std::cout << "Total a ser pago: R$ " << getTotal() << std::endl;

    while (realizado == 0)                          // Enquanto o pagamento nao for realizado
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para aplicar desconto.\n" << "Digite 2 para continuar sem desconto." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());

        if (confirmacao == 1)                       // Se houver desconto
        {
            setDesconto();
            setFinal();
            std::cout << "Valor final a ser pago: R$ " << getFinal() << std::endl;
        }
        if (confirmacao == 2)                       // Se nao houver desconto
        {
            semDesconto();
            std::cout << "Valor final a ser pago: R$ " << getFinal() << std::endl;
        }
        if (confirmacao == 1 || confirmacao == 2)
            realizado = 1;
        else
            std::cout << "Valor invalido!" << std::endl;
    }

    devedor = getPedido()->getCliente();

    std::cout << "Devedor: " << devedor << std::endl;
    std::cout << "Credor: " << credor << std::endl;
    std::cout << "Chave Pix: " << chave << std::endl;

    while (realizado == 1)
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para confirmar pagamento.\n" << "Digite 2 para cancelar proceso de pagamento." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());

        if (confirmacao == 1 || confirmacao == 2)
            realizado = 2;
        else
            std::cout << "Valor invalido!" << std::endl;
    }
}

int Pix::getConfirmacao() const                     // Retorna status da confirmacao
{
    return confirmacao;
}

void Pix::setCredor(const std::string &cred)        // Retorna o credor do Pix
{
    credor = cred;
}

void Pix::setChave(const std::string &ch)           // Retorna a chave Pix do credor
{
    chave = ch;
}

// Construtor da classe Cartao
Cartao::Cartao(Pedido *p_in, Cardapio c_in, float total, int erro) : Pagamento(p_in, c_in, total, erro) {}

void Cartao::pagarCartao()                          // Metodo interativo para realizar pagamento com cartao
{
    calcTotal();
    int realizado = 0;

    std::cout << "Pagamento via cartao selecionado." << std::endl;
    std::cout << "Total a ser pago: R$ " << getTotal() << std::endl;

    while (realizado == 0)                          // Enquanto o pagamento nao for realizado
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para aplicar desconto.\n" << "Digite 2 para continuar sem desconto." << std::endl;
            std:: cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());

        if (confirmacao == 1)                       // Se houver desconto
        {
            setDesconto();
            setFinal();
            std::cout << "Valor final a ser pago: R$ " << getFinal() << std::endl;
        }
        if (confirmacao == 2)                       // Se nao houver desconto
        {
            semDesconto();
            std::cout << "Valor final a ser pago: R$ " << getFinal() << std::endl;
        }

        if (confirmacao == 1 || confirmacao == 2)
            realizado = 1;
        else
            std::cout << "Valor invalido!" << std::endl;
    }

    do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite o nome do banco: ";
            std::getline(std::cin >> std::ws, banco);
        } while (std::cin.fail());
    
    while (realizado == 1)
    {  
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "\n";

            std::cout << "Digite 1 para pagamento no credito.\nDigite 2 para pagamento no debito." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> tipoPagamento;
        } while (std::cin.fail());

        if (tipoPagamento == 1 || tipoPagamento == 2)
            realizado = 2;
        else
            std::cout << "Valor invalido!" << std::endl;
    }
    if (tipoPagamento == 1)                         // Seleciona a opcao de pagamento no credito
        std::cout << "Credito selecionado.\n" << "Banco: " << banco << std::endl;

    if (tipoPagamento == 2)                         // Seleciona a opcao de pagamento no debito
        std::cout << "Debito selecionado.\n" << "Banco: " << banco << std::endl;

    while (realizado == 2)
    {
        do
        {
            if (std::cin.fail()) 
            {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada inválida
                std::cout << "\nEntrada invalida. Insira um numero.\n" << std::endl;
            }
            std::cout << "Digite 1 para confirmar pagamento.\n" << "Digite 2 para cancelar proceso de pagamento." << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> confirmacao;
        } while (std::cin.fail());
        
        if (confirmacao == 1 || confirmacao == 2)
        {
            realizado = 3;
        }
        else
            std::cout << "Valor invalido!" << std::endl;
    }
}

int Cartao::getConfirmacao() const                  // Retorna status da confirmacao
{
    return confirmacao;
}

int Cartao::getTipo() const                         // Retorna a opcao do tipo de pagamento
{
    return tipoPagamento;
}
