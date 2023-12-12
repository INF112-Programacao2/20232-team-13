#ifndef TRUCO_H
#define TRUCO_H

#include "jogos.h"

class Truco:public Jogos {

    public:
    Truco();
    ~Truco();
    
    void jogar(Jogador a) override;
    double vitoria(Jogador a) override;
    int valorCarta(std::pair<char,std::string> cartas);
    void distribuirCartas(Jogador a);
};
#endif