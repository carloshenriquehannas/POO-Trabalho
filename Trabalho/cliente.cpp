/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe do cliente
*/

#include <string>

class Cliente
{
    private:
        std::string _nome;
        std::string _contato;
        std::string _endereco;
    public:
        // Construtor da classe
        Cliente(std::string nome, std::string contato, std::string endereco): _nome(nome), _contato(contato), _endereco(endereco) {}
        
        std::string getNome() const         // Retorna o nome do cliente     
        {
            return _nome;
        }
        std::string getContato() const      // Retorna o contato do cliente
        {
            return _contato;
        }
        std::string getEndereco() const     // Retorna o endereco do cliente
        {
            return _endereco;
        }
};