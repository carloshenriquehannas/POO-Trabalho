/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

/*
    Utilizei o seguinte link para implementar iterador. Contem operadores (++, != e *) e metodos begin/end:
    https://www.tecgraf.puc-rio.br/eda/EDA_08_aula-iteradores.pdf
*/

#include <iostream>
#include <fstream>
#include <string>

class Arquivo 
{
    private:
        std::ifstream conteudo_;

    public:
        Arquivo(const std::string& nomeArquivo) 
        {
            conteudo_.open(nomeArquivo);
        }

        ~Arquivo() 
        { 
            conteudo_.close();
        }

        std::string proxima_linha() 
        {
            std::string linha;
            std::getline(conteudo_, linha); 
            
            return linha;
        }

        class Iterador 
        {
            private:
                std::ifstream* arquivo_;
                std::string linha_;
                bool eof_;

            public:
                Iterador(std::ifstream* arquivo) : arquivo_(arquivo), eof_(false) 
                {

                        ++(*this);                                      // Leitura da primeira linha

                }

                const std::string& operator*() const                    // Retorna proxima linha
                { 
                    return linha_;
                }

                Iterador& operator++() 
                { 
                    if (arquivo_ && std::getline(*arquivo_, linha_))    // Faz a leitura e verifica se chegou ao final do arquivo
                        eof_ = false;                                   // Se leitura sucedida, nao esta no eof                    
                    else 
                        eof_ = true;                                    // Marca eof se nao houver mais leituras
                
                    return *this;
                }

                bool operator!=(const Iterador& finalArquivo) const     // Verifica se chegou ao final do arquivo
                { 
                    return eof_ != finalArquivo.eof_;           
                }
        };

    Iterador begin() 
    { 
        return Iterador(&conteudo_);
    }

    Iterador end() const 
    { 
        return Iterador(nullptr); 
    }

};

int main() 
{
    for (const auto& linha : Arquivo("ex3.cpp"))
        std::cout << linha << std::endl;

    return 0;
}
