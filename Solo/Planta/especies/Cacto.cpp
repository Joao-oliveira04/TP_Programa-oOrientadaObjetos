#include "Cacto.h"
#include <sstream>

#include "../../../Settings/Settings.h"

Cacto::Cacto() : Planta(0,0), inst_excesso_agua(0), inst_falta_nutrientes(0){}

void Cacto::atua(Solo& solo)
{
    // Absorve 25% da agua do solo (é arredondado paa baixo ) e 5 nureientes
    int absorve_agua = (solo.getAgua() * Settings::Cacto::absorcao_agua_percentagem) / 100;
    int absorve_nutrientes = Settings::Cacto::absorcao_nutrientes;

    // Cacto absorve do solo - solo perde , cacto ganha (contudo na nossa modelacao apenas o solo é que muda)
    solo.addAgua(-absorve_agua);
    solo.addNutrientes(-absorve_nutrientes);
    this -> adicionaAgua(absorve_agua);
    this -> adicionaNutrientes(absorve_nutrientes);

    // atualiza counters de sobrevivenvia
    // Excesso de agua
    if (solo.getAgua() > Settings::Cacto::morre_agua_solo_maior)
        inst_excesso_agua++;
    else
        inst_excesso_agua =  0;


    // falta de nutrientes
    if (solo.getNutrientes() < Settings::Cacto::morre_nutrientes_solo_menor)
        inst_falta_nutrientes++;
    else
        inst_falta_nutrientes =  0;

    // verifica a sua morte
    if (inst_excesso_agua >= Settings::Cacto::morre_nutrientes_solo_instantes || inst_falta_nutrientes >= Settings::Cacto::morre_nutrientes_solo_instantes)
    {
        this -> matar();
    }

    this -> incrementaIdade(); // incrementamos sempre a idade a cada instante
}

char Cacto::simbolo() const
{
    return 'c';
}

std::string Cacto::descricao() const
{
    std::ostringstream oss;
    oss <<"[Cacto] Agua: " << this-> getAgua()
    << " Nutrientes: " << this-> getNutrientes()
    << " Idade: " << this-> getIdade()
    <<" Viva: " << (this-> estaViva() ? "sim" : "nao")
    << "ExcessoAgua: " << inst_excesso_agua
    << " FaltaNutrientes: " << inst_falta_nutrientes;

    return oss.str();
}