#include "Solo.h"
#include <sstream>

using namespace std;

Solo::Solo(int a, int n) : agua(a), nutrientes(n){

}

void Solo::addAgua(int valor) {
    agua += valor;
    if(agua < 0)
        agua = 0;

}

void Solo::addNutrientes(int valor) {
    nutrientes += valor;
    if(nutrientes < 0)
        nutrientes = 0;
}

string Solo::descricao() const{

    ostringstream oss;

    oss << "Agua: " << agua << " Nutrientes" << nutrientes;

    return oss.str();
}
