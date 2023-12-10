#ifndef PIF_H
#define PIF_H

#include "jogos.h"
#include "jogador.h"

class Pif:public Jogos {
    public:
    Pif();
    ~Pif();
    void jogar(Jogador a);
    void vitoria(Jogador a);
    void distribuirCartas(Jogador a);
    int valorCarta(std::pair<char,std::string> cartaa);
};
#endif