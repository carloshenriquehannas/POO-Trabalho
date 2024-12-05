/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de cliente
*/

#include "../header/cliente.hpp"

// Construtor
Cliente::Cliente(std::string nome, std::string contato, std::string endereco): _nome(nome), _contato(contato), _endereco(endereco) {}

std::string Cliente::getNome() const        // Retorna o nome do cliente
{
    return _nome;
}

std::string Cliente::getContato() const     // Retorna o contato do cliente
{
    return _contato;
}

std::string Cliente::getEndereco() const    // Retorna o endereco do cliente
{
    return _endereco;
}