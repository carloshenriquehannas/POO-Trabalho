/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe abstrata de funcionario
*/

#include <iostream>
#include <string>

class Funcionario                                   // Classe abstrata de funcionario  
{
    private:
        std::string _nome;
        int _matricula;
    
    public:
        // Construtor da classe
        Funcionario(std::string nome, int matricula): _nome(nome), _matricula(matricula) {}

        // Destrutor da classe
        virtual ~Funcionario() = default;

        virtual void realizarTarefa() const = 0;    // Metodo para classe abstrata de Funcionario

        std::string getNome() const                 // Retorna o nome do funcionario
        {
            return _nome;
        }

        int getMatricula() const                    // Retorna a matricula do funcionario
        {
            return _matricula;
        }
};

class Recepcionista : public Funcionario            // Classe herdada de funcionario
{
    private:
        int _idiomas;

    public:
        // Construtor da classe
        Recepcionista(std::string nome, int matricula, int idiomas): Funcionario(nome, matricula), _idiomas(idiomas) {}

        void realizarTarefa() const override        // Tarefa do recepcionista
        {
            std::cout << "Recepcionista "<< getNome() << " fala " << _idiomas << " idiomas.\n";
        }
};

class Garcom : public Funcionario                   // Classe herdada de funcionario
{
    private:
        std::string _rotaAtendimento;

    public:
        // Construtor da classe
        Garcom(std::string nome, int matricula, std::string rotaAtendimento): Funcionario(nome, matricula), _rotaAtendimento(rotaAtendimento) {}

        void realizarTarefa() const override        // Tarefa do garçom
        {
            std::cout << "Garçom "<< getNome() << " está servindo as mesas de " << _rotaAtendimento << ".\n";
        }
};

class ChefCozinha : public Funcionario              // Classe herdada de funcionario
{
    private:
        std::string _especialidade;
    
    public:
        // Construtor da classe
        ChefCozinha(std::string nome, int matricula, std::string especialidade): Funcionario(nome, matricula), _especialidade(especialidade) {}

        void realizarTarefa() const override        // Tarefa do chef de cozinha
        {
            std::cout << "Chef de cozinha "<< getNome() << " tem especialidade nos pratos de " << _especialidade << ".\n";
        }
};

class Caixa : public Funcionario                    // Classe herdada de funcionario
{
    private:
        int _nivelAcesso;
    
    public:
        // Construtor da classe
        Caixa(std::string nome, int matricula, int nivelAcesso): Funcionario(nome, matricula), _nivelAcesso(nivelAcesso) {}

        void realizarTarefa() const override        // Tarefa do caixa
        {
            std::cout << "Caixa "<< getNome() << " processa pagamentos no nível " << _nivelAcesso << " de acesso.\n";
        }

};