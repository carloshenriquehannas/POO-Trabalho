/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de mesa
*/

#include "mesa.hpp"

// Construtor da classe
Mesa::Mesa(bool status, int quantidadeCadeiras, int numeroMesa): _status(status), _quantidadeCadeiras(quantidadeCadeiras), _numeroMesa(numeroMesa) {}

bool Mesa::getStatus() const                // Retorna se a mesa esta disponivel ou nao
{
    return _status;
}

int Mesa::getQuantidadeCadeiras() const     // Retorna a quantidade de cadeiras da mesa 
{
    return _quantidadeCadeiras;
}

int Mesa::getNumeroMesa() const             // Retorna o numero da mesa
{
    return _numeroMesa;
}