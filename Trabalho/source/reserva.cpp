/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de reserva
    Link de estudo sobre funcao std::tm: https://en.cppreference.com/w/cpp/chrono/c/tm
*/

#include "../header/reserva.hpp"

// Construtor da classe
Reserva::Reserva(int idReserva, int quantidadePessoas, bool status, const std::string& nomeCliente, const std::tm& dataHora): _idReserva(idReserva), _quantidadePessoas(quantidadePessoas), _status(status), _nomeCliente(nomeCliente), _dataHora(dataHora) {}

int Reserva::getIdReserva() const               // Retorna o ID da reserva 
{
    return _idReserva;
}

int Reserva::getQuantidadePessoas() const       // Retorna a quantidade de pessoas da reserva
{
    return _quantidadePessoas;
}

bool Reserva::getStatus() const                 // Retorna se a reserva esta ativa ou nao
{
    return _status;
}

std::string Reserva::getNomeCliente() const     // Retorna o nome do cliente que fez a reserva
{
    return _nomeCliente;
}

std::tm Reserva::getDataHora() const            // Retorna a data e horario da reserva
{
    return _dataHora;
}

