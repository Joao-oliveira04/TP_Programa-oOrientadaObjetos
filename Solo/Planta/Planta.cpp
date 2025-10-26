#include "Planta.h"
#include <sstream>
using namespace std;

Planta::Planta(int a, int n) : agua(a), nutrientes(n), idade(0), viva(true) {}
Planta::~Planta() {}

int Planta::getAgua() const { return agua; }
int Planta::getNutrientes() const { return nutrientes; }
int Planta::getIdade() const { return idade; }
bool Planta::estaViva() const { return viva; }

void Planta::adicionaAgua(int valor) {
    agua += valor;
    if (agua < 0) agua = 0;
}
void Planta::adicionaNutrientes(int valor) {
    nutrientes += valor;
    if (nutrientes < 0) nutrientes = 0;
}
void Planta::incrementaIdade() { idade++; }
void Planta::matar() { viva = false; }

string Planta::descricao() const {
    ostringstream oss;
    oss << "Planta genérica - água: " << agua
        << ", nutrientes: " << nutrientes
        << ", idade: " << idade
        << ", viva: " << (viva ? "sim" : "nao");
    return oss.str();
}
