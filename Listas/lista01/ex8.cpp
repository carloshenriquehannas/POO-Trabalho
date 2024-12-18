//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#include <fstream>
#include <iostream>
#include <string>

std::string conteudo(std::string & file) {
    std::ifstream arquivo(file);    //Abertura do arquivo
    std::string texto;              //String auxiliar para armazenar a leitura
    char c;

    //Enquanto c receber um caractere do arquivo, armazenar na string texto
    while(arquivo.get(c)) {
        texto += c;
    }

    arquivo.close();            //Fechamento do arquivo

    return texto;
}

int main() {
    std::string arquivo = "arquivo.txt";
    std::string texto;

    texto = conteudo(arquivo);      //String com o conteudo do arquivo

    std::cout << texto << std::endl;   //Print do conteudo

    return 0;
}