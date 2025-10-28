#include "ErvaDaninha.h"
#include <sstream>

ErvaDaninha::ErvaDaninha() : Planta(Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes){}

void ErvaDaninha::atua(Solo& solo)
{
    // Absorve poua agua e nutrientes por ciclo
    solo.addAgua(-Settings::ErvaDaninha::absorcao_agua);
    solo.addNutrientes(-Settings::ErvaDaninha::absorcao_nutrientes);

    this->adicionaAgua(Settings::ErvaDaninha::absorcao_agua);
    this->adicionaNutrientes(Settings::ErvaDaninha::absorcao_nutrientes);

    // Morre após atingir limite de instantes
    this->incrementaIdade();
    if (this->getIdade() >= Settings::ErvaDaninha::morre_instantes)
        this->matar();

    // Opcional: multiplicação (só sinalizar para integração no Jardim)
    // Exemplo de trigger (não faz nada sozinho):
    // if (this->getIdade() % Settings::ErvaDaninha::multiplica_instantes == 0) {
    //     // Sinaliza multiplicação na grelha
    // }
}

char ErvaDaninha::simbolo() const
{
    return 'e';
}

std::string ErvaDaninha::descricao() const
{
    std::ostringstream oss;
    oss << "[ErvaDaninha] Agua: " << this->getAgua()
    << ", Nutrientes: " << this->getNutrientes()
    << ", Idade: " << this->getIdade()
    << " Viva: " << (this->estaViva() ? "sim" : "nao");
    return oss.str();
}


