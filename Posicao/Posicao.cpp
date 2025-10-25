#include "Posicao.h"

using namespace std;

Posicao::Posicao(int lin, int col) : linhas(lin), colunas(col){

}

bool Posicao::validaTamanho() const {
    if(linhas >= 0 && colunas >= 0){
        return true;
    }
    return false;
}

bool Posicao::converteLetras(const string &pos, Posicao &out) {
    if(pos.size() != 2)  //tem de ter exatamente 2 letras
        return false;

    char a = tolower(pos[0]); // converte 1ª letra para minúscula
    char b = tolower(pos[1]); // converte 2ª letra para minúscula

    // valida se ambas são letras entre 'a' e 'z'
    if (a < 'a' || a > 'z' || b < 'a' || b > 'z')
        return false;

    out.linhas = a - 'a';
    out.colunas = b - 'a';
    return true;
}

string Posicao::converteCoordenadas() const {

    if(!validaTamanho())
        return "??";

    // constrói string de duas letras
    string s = "";
    s = s + char('a' + linhas);
    s = s + char('a' + colunas);
    return s;
}
