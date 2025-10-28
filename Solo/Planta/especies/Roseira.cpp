#include "Roseira.h"
#include <sstream>

Roseira::Roseira()
    : Planta(Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes){}

// Lógica de evolução da roseira a cada instante
void Roseira::atua(Solo& solo)
{
    // Perde 4 água + 4 nutrientes (internamente, assumimos "perde" = reduz variáveis da planta)
    this->adicionaAgua(-Settings::Roseira::perda_agua);
    this->adicionaNutrientes(-Settings::Roseira::perda_nutrientes);

    // Absorve 5 água + 8 nutrientes ao solo
    solo.addAgua(-Settings::Roseira::absorcao_agua);
    solo.addNutrientes(-Settings::Roseira::absorcao_nutrientes);

    this->adicionaAgua(Settings::Roseira::absorcao_agua);
    this->adicionaNutrientes(Settings::Roseira::absorcao_nutrientes);

    // Morre se água <= 0, nutrientes <= 0, nutrientes >= 200
    if (this->getAgua() <= Settings::Roseira::morre_agua_menor ||
        this->getNutrientes() <= Settings::Roseira::morre_nutrientes_menor ||
        this->getNutrientes() > Settings::Roseira::morre_nutrientes_maior)
    {
        this->matar();
    }
    this->incrementaIdade();
}

char Roseira::simbolo() const
{
    return 'r';
}

std::string Roseira::descricao() const
{
    std::ostringstream oss;
    oss << "[Roseira] Agua: " << this->getAgua()
        << " Nutrientes: " << this->getNutrientes()
        << " Idade: " << this->getIdade()
        << " Viva: " << (this->estaViva() ? "sim" : "não");
    return oss.str();
}