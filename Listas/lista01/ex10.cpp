//Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
//SCC0604 - POO

#define QTD_CEDULAS 13  //Quantidade de cedulas (e moedas) no Brasil
#define CONV_CENT 100   //Conversor para centavos

#include <iostream>
#include <iomanip>

//Funcao auxiliar para calcular as notas do troco
void calcula_notas(double preco, double pago, double troco) {
    int i;
    int centavos[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};                          //Cedulas tomando centavo como referencia
    double cedulas[] = {200.00, 100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01};    //Cedulas verdadeiras
    int quantidade[QTD_CEDULAS] = {0};

    //Verifica quantidade necessaria de cedulas para realizar o troco segundo as especificacoes
    for(i = 0; i < QTD_CEDULAS; i++) {
        quantidade[i] = troco / centavos[i];
        troco = troco - centavos[i] * quantidade[i];
    }

    //Print da quantidade de cada celula utilizada
    for(i = 0; i < QTD_CEDULAS; i++) {
        std::cout << quantidade[i] << " de R$ " << cedulas[i] << std::endl;
    }

}

int main() {
    double preco, pago, troco;

    std::cin >> preco >> pago;  //Entrada, em reais, para preco e pago

    troco = pago - preco;
    std::cout << "Troco: R$ " << std::fixed << std::setprecision(2) << troco << std::endl;

    //Conversao para centavos do preco, valor pago e troco (evitar erros de precisao)
    int preco_cent = static_cast<int>(preco * CONV_CENT + 0.5);
    int pago_cent = static_cast<int>(pago * CONV_CENT + 0.5);
    int troco_cent = pago_cent - preco_cent;

    calcula_notas(preco_cent, pago_cent, troco_cent); //Funcao para calcular as notas do troco

    return 0;
}