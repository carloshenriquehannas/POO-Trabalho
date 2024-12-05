/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de cliente
*/

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

class Cliente 
{
    private:
        std::string _nome;
        std::string _contato;
        std::string _endereco;

    public:
        // Construtor da classe
        Cliente(std::string nome, std::string contato, std::string endereco);
        
        // Metodos da classe
        std::string getNome() const;
        std::string getContato() const;
        std::string getEndereco() const;
};

#endif // CLIENTE_HPP
