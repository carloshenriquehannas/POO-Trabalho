/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 4)
*/

#include <iostream>
#include <string>
#include <regex>

class Pessoa
{
    private:
        std::string nome;
        int idade;
        std::string cidade;
        std::string estado;
        std::string pais;

    public:
        Pessoa(std::string texto)
        {
            std::regex mascara("(.+) tem (\\d+) anos e mora em (.+)-(.+), (.+)");
            std::smatch res;

            std::regex_match(texto, res, mascara);
            nome = res[1].str();
            idade = std::stoi(res[2].str());
            cidade = res[3].str();
            estado = res[4].str();
            pais = res[5].str();
        }

        friend std::ostream &operator<<(std::ostream &os, const Pessoa &pessoa)
        {
            os << pessoa.nome << std::endl
            << pessoa.idade << std::endl
            << pessoa.cidade << std::endl
            << pessoa.estado << std::endl
            << pessoa.pais << std::endl;
            return os;
        }
};

int main()
{
    std::cout << Pessoa("André Smaira tem 34 anos e mora em São Carlos-SP, Brasil");

    return 0;
    
}