#include "Solo/Solo.h"
#include "Solo/Planta/especies/Cacto.h"
#include "Solo/Planta/especies/Roseira.h"
#include "Solo/Planta/especies/ErvaDaninha.h"
#include "jardim/Jardim.h"
#include <iostream>

int main() {
    // Cria um jardim 3x3
    Jardim jardim;
    jardim.inicializa(3, 3);

    // Planta um Cacto em (0,0), Roseira em (1,1), ErvaDaninha em (2,2)
    jardim.aceder(0, 0).setPlanta(new Cacto());
    jardim.aceder(1, 1).setPlanta(new Roseira());
    jardim.aceder(2, 2).setPlanta(new ErvaDaninha());

    // Mostra o estado inicial
    std::cout << "\nEstado inicial do jardim:\n";
    jardim.print();
    std::cout << "\nDescritivo das plantas:\n";
    std::cout << "Cacto: " << jardim.aceder(0,0).getPlanta()->descricao() << "\n";
    std::cout << "Roseira: " << jardim.aceder(1,1).getPlanta()->descricao() << "\n";
    std::cout << "ErvaDaninha: " << jardim.aceder(2,2).getPlanta()->descricao() << "\n";

    // Avança vários instantes, mostra evolução
    for (int instante = 1; instante <= 10; ++instante) {
        std::cout << "\nAvanca instante " << instante << ":\n";
        // Faz cada planta atuar no seu solo
        for (int l = 0; l < jardim.getLinhas(); ++l)
            for (int c = 0; c < jardim.getCols(); ++c) {
                if (jardim.aceder(l, c).getPlanta() != nullptr)
                    jardim.aceder(l, c).getPlanta()->atua(jardim.aceder(l, c).getSolo());
            }
        jardim.print();
        // Mostra o estado de cada planta
        std::cout << "Cacto: " << jardim.aceder(0,0).getPlanta()->descricao() << "\n";
        std::cout << "Roseira: " << jardim.aceder(1,1).getPlanta()->descricao() << "\n";
        std::cout << "ErvaDaninha: " << jardim.aceder(2,2).getPlanta()->descricao() << "\n";
    }
    return 0;
}
