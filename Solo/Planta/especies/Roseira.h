#ifndef TP_PROGRAMA_OORIENTADAOBJETOS_ROSEIRA_H
#define TP_PROGRAMA_OORIENTADAOBJETOS_ROSEIRA_H

#include "../../../Settings/Settings.h"
#include "../Planta.h"

// Roseira: planta bonita, maior consumo e pode multiplicar-se
class Roseira : public Planta {
public:
    Roseira();

    void atua(Solo& solo) override;
    char simbolo() const override;
    std::string descricao() const override;
};

#endif //TP_PROGRAMA_OORIENTADAOBJETOS_ROSEIRA_H