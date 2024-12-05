/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Para compilar via terminal digite: make
    Para executar via terminal digite: make run
    Para limpar arquivos criados pelo Makefile via terminal digite: make clean

    Arquivo principal da simulacao
*/

#include "header/cardapio.hpp"
#include "header/cliente.hpp"
#include "header/funcionario.hpp"
#include "header/mesa.hpp"
#include "header/pagamento.hpp"
#include "header/pedido.hpp"
#include "header/reserva.hpp"

#include <iostream>
#include <iomanip>
#include <locale.h>

// Funcao auxiliar para exibir data e hora em formato tradicional: dia/mes/ano hora:minuto
void displayDataHora(const std::tm& dataHora) 
{
    std::cout << "Data e Hora da Reserva: "  << std::put_time(&dataHora, "%d/%m/%Y %H:%M") << std::endl;
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    //Instancia o objeto cliente1 e exibe informacoes
    Cliente cliente1("Maria", "12345", "Rua 1");
    std::cout << "***** CLIENTE 1 *****" << std::endl;
    std::cout << "Nome: " << cliente1.getNome() << std::endl;
    std::cout << "Contato: " << cliente1.getContato() << std::endl;
    std::cout << "Endereco: " << cliente1.getEndereco() << std::endl;
    std::cout << "*********************" << std::endl;

    //Instancia o objeto cliente2 e exibe informacoes
    Cliente cliente2("Joao", "67890", "Rua 2");
    std::cout << "***** CLIENTE 2 *****" << std::endl;
    std::cout << "Nome: " << cliente2.getNome() << std::endl;
    std::cout << "Contato: " << cliente2.getContato() << std::endl;
    std::cout << "Endereco: " << cliente2.getEndereco() << std::endl;
    std::cout << "*********************" << std::endl;

    std::cout << "\n";

    //Instancia o objeto mesa1 e exibe informacoes
    Mesa mesa1(true, 4, 1);
    std::cout << "****** MESA 1 *******" << std::endl;
    std::cout << "Status: " << (mesa1.getStatus() ? "Disponivel" : "Indisponivel") << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa1.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa1.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

    //Instancia o objeto mesa2 e exibe informacoes
    Mesa mesa2(false, 6, 2);
    std::cout << "****** MESA 2 *******" << std::endl;
    std::cout << "Status: " << (mesa2.getStatus() ? "Disponivel" : "Indisponivel") << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa2.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa2.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

    std::cout << "\n";

    // Define uma data e hora de exemplo para reserva
    std::tm dataHora = {};
    dataHora.tm_mday = 10;        
    dataHora.tm_mon = 11 - 1;    
    dataHora.tm_year = 2024 - 1900; 
    dataHora.tm_hour = 18;        
    dataHora.tm_min = 30;         

    // Instancia o objeto reserva1 e exibe detalhes da reserva
    Reserva reserva1(1, 4, true, "Joao", dataHora);
    std::cout << "***** RESERVA 1 *****" << std::endl;
    std::cout << "ID da Reserva: " << reserva1.getIdReserva() << std::endl;
    std::cout << "Nome do Cliente: " << reserva1.getNomeCliente() << std::endl;
    std::cout << "Quantidade de Pessoas: " << reserva1.getQuantidadePessoas() << std::endl;
    std::cout << "Status: " << (reserva1.getStatus() ? "Ativa" : "Inativa") << std::endl;
    displayDataHora(dataHora);
    std::cout << "*********************" << std::endl;

    std::cout << "\n";

    // Instancia o objeto de cardapio, adiciona e exibe itens/precos
    Cardapio cardapio;
    std::cout << "*********************" << std::endl;
    cardapio.adicionaItem("Pizza Margherita", 25.0);
    cardapio.adicionaItem("Hamburguer", 18.0);
    cardapio.adicionaItem("Suco de Laranja", 8.0);
    cardapio.exibirCardapio();
    std::cout << "*********************" << std::endl;

    std::cout << "\n";

    // Instancia objetos de funcionarios e exibe as tarefas
    Recepcionista recepcionista("Ana", 101, 3);
    std::cout << "*** RECEPCIONISTA ***" << std::endl;
    std::cout << "Nome: " << recepcionista.getNome() << std::endl;
    std::cout << "Matricula: " << recepcionista.getMatricula() << std::endl;
    recepcionista.realizarTarefa();
    std::cout << "*********************" << std::endl;

    Garcom garcom("Paulo", 102, "Rota A");
    std::cout << "****** GARÇOM *******" << std::endl;
    std::cout << "Nome: " << garcom.getNome() << std::endl;
    std::cout << "Matricula: " << garcom.getMatricula() << std::endl;
    garcom.realizarTarefa();
    std::cout << "*********************" << std::endl;

    ChefCozinha chefe("Beatriz", 103, "Cozinha Italiana");
    std::cout << "** CHEF DE COZINHA **" << std::endl;
    std::cout << "Nome: " << chefe.getNome() << std::endl;
    std::cout << "Matricula: " << chefe.getMatricula() << std::endl;
    chefe.realizarTarefa();
    std::cout << "*********************" << std::endl;

    Caixa caixa("Lucas", 104, 5);
    std::cout << "******* CAIXA *******" << std::endl;
    std::cout << "Nome: " << caixa.getNome() << std::endl;
    std::cout << "Matricula: " << caixa.getMatricula() << std::endl;
    caixa.realizarTarefa();
    std::cout << "*********************" << std::endl;

    std::cout << "\n";


    // Instancia objeto de um pedido e exibe as informacoes
    std::cout << "*********************" << std::endl;
    Pedido pedido1("Joao", 1);
    pedido1.adicionaItem("Pizza Margherita", 2);
    pedido1.adicionaItem("Suco de Laranja", 3);
    pedido1.exibirPedido();
    std::cout << "*********************" << std::endl;

    std::cout << "\n";

    // Instancia objetos para pagamento e interage com o usuario para processar o pagamento do objeto pedido1
    std::cout << "*********************" << std::endl;
    int formaPagamento, realizado = 0; // Valor para escolha da forma de pagaento e flag para indicar que o pagamento foi realizado 
    while(realizado == 0){
        std::cout << "Digite 1 para pagar com dinheiro. \nDigite 2 para pagar via Pix. \ndigite 3 para pagar com Cartão."<<std::endl;
        std::cin>>formaPagamento;
        switch (formaPagamento)
        {
        case 1: {
            Dinheiro pagamento1(&pedido1, cardapio);
            pagamento1.pagarDinheiro();
            if(pagamento1.getConfirmacao() == 1){
                pagamento1.getPedido()->finalizaPedido();
                std::cout<<"Pagamento realizado com sucesso!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() == 2){
                std::cout<<"Pagamento cancelado!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() != 1 && pagamento1.getConfirmacao() != 2){
                std::cout<<"Valor invalido inserido, processo de pagamento reiniciado"<<std::endl;
            }
            break;
        }
        case 2: {
            Pix pagamento1(&pedido1, cardapio);
            pagamento1.setChave("restaurante@gmail.com");
            pagamento1.setCredor("Restaurante");
            pagamento1.pagarPix();
            if(pagamento1.getConfirmacao() == 1){
                pagamento1.getPedido()->finalizaPedido();
                std::cout<<"Pagamento realizado com sucesso!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() == 2){
                std::cout<<"Pagamento cancelado!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() != 1 && pagamento1.getConfirmacao() != 2){
                std::cout<<"Valor invalido inserido, processo de pagamento reiniciado"<<std::endl;
            }
            break;
        }
        case 3: {
            Cartao pagamento1(&pedido1, cardapio);
            pagamento1.pagarCartao();
            if(pagamento1.getConfirmacao() == 1){
                pagamento1.getPedido()->finalizaPedido();
                std::cout<<"Pagamento realizado com sucesso!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() == 2){
                std::cout<<"Pagamento cancelado!"<<std::endl;
                realizado = 1;
            }
            if(pagamento1.getConfirmacao() != 1 && pagamento1.getConfirmacao() != 2){
                std::cout<<"Valor invalido inserido, processo de pagamento reiniciado"<<std::endl;
            }
            break;
        }
        default:
            break;
        }
    }
    std::cout << "*********************" << std::endl;
    return 0;
}