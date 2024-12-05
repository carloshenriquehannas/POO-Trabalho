/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo header com a declaracao da classe de funcionario
*/

#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <string>

class Funcionario                               // Classe abstrata Funcionario
{
    private:
        std::string _nome;
        int _matricula;

    public:
        // Construtor e destrutor da classe
        Funcionario(std::string nome, int matricula);
        virtual ~Funcionario() = default;

        // Metodos da classe
        virtual void realizarTarefa() const = 0;
        std::string getNome() const;
        int getMatricula() const;
};

class Recepcionista : public Funcionario    // Classe herdada de funcionario
{
    private:
        int _idiomas;

    public:
        // Construtor da classe
        Recepcionista(std::string nome, int matricula, int idiomas);

        // Metodo da classe
        void realizarTarefa() const override;
};

class Garcom : public Funcionario           // Classe herdada de funcionario
{
    private:
        std::string _rotaAtendimento;

    public:
        // Construtor da classe
        Garcom(std::string nome, int matricula, std::string rotaAtendimento);

        // Metodo da classe
        void realizarTarefa() const override;
};

class ChefCozinha : public Funcionario      // Classe herdada de funcionario
{
    private:
        std::string _especialidade;

    public:
        // Construtor da classe
        ChefCozinha(std::string nome, int matricula, std::string especialidade);

        // Metodo da classe
        void realizarTarefa() const override;
};

class Caixa : public Funcionario            // Classe herdada de funcionario
{
    private:
        int _nivelAcesso;

    public:
        // Construtor da classe
        Caixa(std::string nome, int matricula, int nivelAcesso);

        // Metodo da classe
        void realizarTarefa() const override;
};

#endif // FUNCIONARIO_HPP