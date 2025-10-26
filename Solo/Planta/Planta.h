#ifndef POO_TP_PLANTA_H
#define POO_TP_PLANTA_H
#include <string>
#include "../Solo.h"

class Planta {
private:
    int agua;
    int nutrientes;
    int idade;
    bool viva;

public:
    Planta(int a = 0, int n = 0);
    virtual ~Planta();

    virtual void atua(Solo& solo) = 0;
    virtual char simbolo() const = 0;
    virtual std::string descricao() const;

    int getAgua() const;
    int getNutrientes() const;
    int getIdade() const;
    bool estaViva() const;

    void adicionaAgua(int valor);
    void adicionaNutrientes(int valor);
    void incrementaIdade();
    void matar();
};

#endif // POO_TP_PLANTA_H
