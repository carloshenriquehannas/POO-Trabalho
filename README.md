# POO
Repositório para atividades e trabalho da disciplina de graduação de Programação Orienteada a Objetos

## Trabalho
O repositório é organizado da seguinte forma: restaurant.cpp (arquivo principal da simulação), pasta header (armazena arquivos de extensão .hpp que implementam as classes), pasta source (armazena arquivos de extensão .cpp que implementam os métodos públicos da classe) e um Makefile. Abaixo a descrição de cada um desses itens:

1. restaurant.cpp: arquivo principal da simulacao
2. Pasta header
    1. cardapio.hpp: classe de cardápio
    2. cliente.hpp: classe de cliente
    3. funcionario.hpp: classe abstrata de funcionário e classes herdadas
    4. mesa.hpp: classe de mesa
    5. pagamento.hpp: classe de pagamento e classes herdadas
    6. pedido.hpp: classe de pedido
    7. reserva.hpp: classe de reserva
3. Pasta source:
    1. cardapio.cpp: implementacao dos métodos de cardápio
    2. cliente.cpp: implementacao dos métodos de cliente
    3. funcionario.cpp: implementacao dos métodos de funcionário
    4. mesa.cpp: implementacao dos métodos de mesa
    5. pagamento.cpp: implementacao dos métodos de pagamento
    6. pedido.cpp: implementacao dos métodos de pedido
    7. reserva.cpp: implementacao dos métodos de reserva
4. Makefile
    1. Comando clean: limpa os arquivos binários criado pelo comando make
    2. Comando run: executa o arquivo binário (executa a simulação)

Nesta prática, os comandos para compilar e executar o código ocorrem via terminal:

    Digite "make" no terminal para compilar o código
    Digite "make run" no terminal para executar o código

As informações de projeto e código, como a documentação, encontram-se no arquivo SCC0604-Trabalho01.pdf. Além disso utilizou-se, nesta prática:

    Compilador: gcc (GCC) 13.2.0
    Sistema Operacional (LINUX): Ubuntu 24.04.1 LTS.
