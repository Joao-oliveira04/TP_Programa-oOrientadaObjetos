#ifndef POO_TP_JARDIM_H
#define POO_TP_JARDIM_H
#include <iostream>
#include "../Celula/Celula.h"

const int MAX_LINS = 26;
const int MAX_COLS = 26;

class Jardim {

    int lins;
    int cols;

    Celula* celulas; //array linear de tamanho lins*cols;

public:
    Jardim();
    ~Jardim();

    // Aloca exatamente l*c células; devolve true se OK
    bool inicializa(int l, int c);

    // Função auxiliar para converter (lins, cols) num índice linear
    int index(int l, int c) const;


    //Acesso à celula
    Celula& aceder(int l, int c);                //versão mutavel
    const Celula& aceder(int l, int c) const;    //versão constante

    int getLinhas() const{return lins;}
    int getCols() const {return cols;}

    void print() const;
};


#endif //POO_TP_JARDIM_H