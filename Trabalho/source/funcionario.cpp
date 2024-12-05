/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo source com a implementacao dos metodos publicos da classe de funcionario
*/

#include "../header/funcionario.hpp"

// Construtor da classe Funcionario
Funcionario::Funcionario(std::string nome, int matricula): _nome(nome), _matricula(matricula) {}

std::string Funcionario::getNome() const        // Retorna o nome do funcionario
{
    return _nome;
}

int Funcionario::getMatricula() const           // Retorna a matricula do funcionario
{
    return _matricula;
}

// Construtor da classe Recepcionista
Recepcionista::Recepcionista(std::string nome, int matricula, int idiomas): Funcionario(nome, matricula), _idiomas(idiomas) {}

void Recepcionista::realizarTarefa() const      // Retorna a atividade de recepcionista
{
    std::cout << "Recepcionista " << getNome() << " fala " << _idiomas << " idiomas.\n";
}

// Construtor da classe Garcom
Garcom::Garcom(std::string nome, int matricula, std::string rotaAtendimento): Funcionario(nome, matricula), _rotaAtendimento(rotaAtendimento) {}

void Garcom::realizarTarefa() const             // Retorna a atividade de garcom
{
    std::cout << "Garçom " << getNome() << " está servindo as mesas de " << _rotaAtendimento << ".\n";
}

// Construtor da classe ChefCozinha
ChefCozinha::ChefCozinha(std::string nome, int matricula, std::string especialidade): Funcionario(nome, matricula), _especialidade(especialidade) {}

void ChefCozinha::realizarTarefa() const        // Retorna a atividade de chef de cozinha
{
    std::cout << "Chef de cozinha " << getNome() << " tem especialidade nos pratos de " << _especialidade << ".\n";
}

// Construtor da classe Caixa
Caixa::Caixa(std::string nome, int matricula, int nivelAcesso): Funcionario(nome, matricula), _nivelAcesso(nivelAcesso) {}

void Caixa::realizarTarefa() const              // Retorna a atividade de caixa
{
    std::cout << "Caixa " << getNome() << " processa pagamentos no nível " << _nivelAcesso << " de acesso.\n";
}