/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de reserva
    Link de estudo sobre funcao std::tm: https://en.cppreference.com/w/cpp/chrono/c/tm
*/

#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include <ctime>

class Reserva
{
    private:
        int _idReserva;
        int _quantidadePessoas;
        bool _status;                           // True se reserva ativa; false se reserva inativa
        std::string _nomeCliente;
        std::tm _dataHora;

    public:
        // Construtor da classe
        Reserva(int idReserva, int quantidadePessoas, bool status, const std::string& nomeCliente, const std::tm& dataHora);

        // Metodos da classe
        int getIdReserva() const;
        int getQuantidadePessoas() const;
        bool getStatus() const;
        std::string getNomeCliente() const;
        std::tm getDataHora() const;
};

#endif // RESERVA_HPP
