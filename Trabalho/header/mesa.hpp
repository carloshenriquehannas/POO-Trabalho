/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de mesa
*/

#ifndef MESA_HPP
#define MESA_HPP

class Mesa
{
    private:
        bool _status;               // True se mesa disponivel; false se mesa indisponivel         
        int _quantidadeCadeiras;
        int _numeroMesa;

    public:
        // Construtor da classe
        Mesa(bool status, int quantidadeCadeiras, int numeroMesa);
        
        // Metodos da classe
        bool getStatus() const;
        int getQuantidadeCadeiras() const;
        int getNumeroMesa() const;
};

#endif // MESA_HPP