/*
    SCC0604 - Programacao Orientada a Objetos
    TRABALHO PRATICO FINAL

    INTEGRANTES:
        Carlos Henrique Hannas de Carvalho  NUSP: 11965988
        Henrique Carobolante Parro          NUSP: 11917987
        Lucca Tommaso Monzani               NUSP: 5342324

    Arquivo com os atributos privados e metodos publicos da classe de mesa
*/

class Mesa
{
    private:
        bool _status;                           // True se mesa disponivel; false se mesa indisponivel
        int _quantidadeCadeiras;
        int _numeroMesa;
        
    public:
        // Construtor da classe
        Mesa(bool status, int quantidadeCadeiras, int _numeroMesa): _status(status), _quantidadeCadeiras(quantidadeCadeiras), _numeroMesa(_numeroMesa) {}

        bool getStatus() const                  // Retorna se a mesa esta disponivel ou nao
        {
            return _status;
        }

        int getQuantidadeCadeiras() const       // Retorna a quantidade de cadeiras da mesa
        {
            return _quantidadeCadeiras;
        }

        int getNumeroMesa() const               // Retorna o numero da mesa
        {
            return _numeroMesa;
        }
};