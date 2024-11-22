/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Para compilar: g++ restaurant.cpp cliente.cpp mesa.cpp reserva.cpp -o simulation
    Para executar: ./simulation

    Arquivo principal da simulacao
*/

#include <iostream>
#include "cliente.cpp"
#include "mesa.cpp"
#include "reserva.cpp"

void displayDataHora(const std::tm& dataHora) 
{
    std::cout << "Data e Hora da Reserva: "  << std::put_time(&dataHora, "%d/%m/%Y %H:%M") << std::endl;
}

int main()
{

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

    //Instancia o objeto mesa1 e exibe informacoes
    Mesa mesa1(true, 4, 1);
    std::cout << "****** MESA 1 *******" << std::endl;
    std::cout << "Status: " << mesa1.getStatus() << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa1.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa1.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

    //Instancia o objeto mesa2 e exibe informacoes
    Mesa mesa2(false, 6, 2);
    std::cout << "****** MESA 2 *******" << std::endl;
    std::cout << "Status: " << mesa2.getStatus() << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa2.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa2.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

    // Define uma data e hora de exemplo para reserva
    std::tm dataHora = {};
    dataHora.tm_mday = 10;        // Dia 10
    dataHora.tm_mon = 11 - 1;     // Novembro (meses começam do 0)
    dataHora.tm_year = 2024 - 1900; // Ano (desde 1900)
    dataHora.tm_hour = 18;        // 18 horas
    dataHora.tm_min = 30;         // 30 minutos

    // Cria uma reserva
    Reserva reserva1(1, 4, true, "Carlos", dataHora);

    // Exibe detalhes da reserva
    std::cout << "***** RESERVA 1 *****" << std::endl;
    std::cout << "ID da Reserva: " << reserva1.getIdReserva() << std::endl;
    std::cout << "Nome do Cliente: " << reserva1.getNomeCliente() << std::endl;
    std::cout << "Quantidade de Pessoas: " << reserva1.getQuantidadePessoas() << std::endl;
    std::cout << "Status: " << (reserva1.getStatus() ? "Ativa" : "Inativa") << std::endl;
    displayDataHora(dataHora);
    std::cout << "*********************" << std::endl;

    return 0;
}