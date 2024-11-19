/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Para compilar: g++ restaurant.cpp cliente.cpp mesa.cpp -o simulation
    Para executar: ./simulation

    Arquivo principal da simulacao;
*/

#include <iostream>
#include "cliente.cpp"
#include "mesa.cpp"

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
    std::cout << "***** MESA 1 *****" << std::endl;
    std::cout << "Status: " << mesa1.getStatus() << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa1.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa1.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

        //Instancia o objeto mesa2 e exibe informacoes
    Mesa mesa2(false, 6, 2);
    std::cout << "***** MESA 2 *****" << std::endl;
    std::cout << "Status: " << mesa2.getStatus() << std::endl;
    std::cout << "Quantidade de Cadeiras: " << mesa2.getQuantidadeCadeiras() << std::endl;
    std::cout << "Numero da mesa: " << mesa2.getNumeroMesa() << std::endl;
    std::cout << "*********************" << std::endl;

    return 0;
}