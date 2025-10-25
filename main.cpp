#include <iostream>
#include "Posicao/Posicao.h"
#include "jardim/Jardim.h"

using namespace std;

int main() {

    Jardim j;
    int linhas, colunas;

    std::cout << "Tamanho do jardim (linhas colunas): ";
    std::cin >> linhas >> colunas;

    if (!j.inicializa(linhas, colunas)) {
        std::cout << "Erro: dimensoes invalidas.\n";
        return 1;
    }

    j.print(); // mostra o jardim

}