//
// Created by jpbol on 28/10/2025.
//

#ifndef TP_PROGRAMA_OORIENTADAOBJETOS_ERVADANINHA_H
#define TP_PROGRAMA_OORIENTADAOBJETOS_ERVADANINHA_H

#include "../../../Settings/Settings.h"
#include "../Planta.h"


class ErvaDaninha : public Planta
{
    public:
    ErvaDaninha();

    void atua(Solo& solo) override;
    char simbolo() const override;
    std::string descricao() const override;
};

#endif //TP_PROGRAMA_OORIENTADAOBJETOS_ERVADANINHA_H