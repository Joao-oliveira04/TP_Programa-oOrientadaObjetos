#include "Solo/Planta/especies/Cacto.h"
#include "Solo/Solo.h"
#include <iostream>

int main() {
    // Criar um solo com valores acima e abaixo dos limites para testar as regras do Cacto
    Solo solo(110, 4); // Exemplo: 110 água (excesso), 4 nutrientes

    Cacto c;

    // Simular vários instantes e mostrar o estado do Cacto
    for (int i = 0; i < 5; ++i) {
        std::cout << "Instante " << i << ": " << c.descricao() << "\n";
        c.atua(solo);
    }

    if (!c.estaViva())
        std::cout << "O cacto morreu!\n";
    else
        std::cout << "O cacto sobreviveu aos 5 instantes.\n";

    return 0;
}
