#ifndef TP_PROGRAMA_OORIENTADAOBJETOS_CACTO_H
#define TP_PROGRAMA_OORIENTADAOBJETOS_CACTO_H
#include "../Planta.h"
#include "../../../Settings/Settings.h"

class Cacto : public Planta {
    private:
    int inst_excesso_agua;
    int inst_falta_nutrientes;

    public:
    Cacto();
    void atua(Solo& solo) override;
    char simbolo() const override;
    std::string descricao() const override;

};


#endif //TP_PROGRAMA_OORIENTADAOBJETOS_CACTO_H