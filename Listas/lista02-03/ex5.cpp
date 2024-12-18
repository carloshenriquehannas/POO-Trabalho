/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

/*
    Para determinar o melhor tipo do atributo e realizar a leitura de uma linha utilizei o seguinte link de apoio:
    https://medium.com/@joseveraldoaneto/manipula%C3%A7%C3%A3o-de-streams-em-c-984ef8c6edcb
*/

#include <iostream>
#include <fstream>
#include <string>

class Arquivo
{
    private:
        std::ifstream _conteudo;

    public:
        Arquivo(const std::string &arquivo)       // Construtor: abre o arquivo
        {
            _conteudo.open(arquivo);
        }
        ~Arquivo()                                 // Destruidor: fecha o arquivo
        {
            _conteudo.close();
        }
        std::string proxima_linha()
        {
            std::string linha;
            
            std::getline(_conteudo, linha);         // Leitura da linha armazenada na variavel "linha"

            return linha;               
        }
};

int main()
{
    Arquivo a ("arquivo.txt" );                     // Instanciacao do objeto: arquivo.txt

    //Exemplos de comandos de entrada
    std::cout << a.proxima_linha() << std::endl;
    std::cout << a.proxima_linha() << std::endl;

    return 0;
}



