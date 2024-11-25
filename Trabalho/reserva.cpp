/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe de reserva
*/

#include <string>
#include <iomanip>
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
        Reserva(int idReserva, int quantidadePessoas, bool status, const std::string& nomeCliente, const std::tm& dataHora): _idReserva(idReserva), _quantidadePessoas(quantidadePessoas), _status(status), _nomeCliente(nomeCliente), _dataHora(dataHora) {}

        int getIdReserva() const                // Retorna o ID da reserva
        {
            return _idReserva;
        }

        int getQuantidadePessoas() const        // Retorna a quantidade de pessoas da reserva
        {
            return _quantidadePessoas;
        }

        bool getStatus() const                  // Retorna se a reserva esta ativa ou nao
        {
            return _status;
        }

        std::string getNomeCliente() const      // Retorna o nome do cliente que fez a reserva 
        {
            return _nomeCliente;
        }

        std::tm getDataHora() const             // Retorna a data e horario da reserva
        {
            return _dataHora;
        }
};
