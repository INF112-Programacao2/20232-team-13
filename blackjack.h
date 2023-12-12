#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <utility>
#include <string>
#include "jogos.h"
#include "jogador.h"

class Blackjack:public Jogos {

    public:
    Blackjack();
    ~Blackjack();
    
    void jogar(Jogador a) override;
    double vitoria(Jogador a) override;
    int valorCarta(std::pair<char,std::string> cartas);
    void distribuirCartas(Jogador a);
    int calcularValorDaMao(std::pair<char,std::string> cartas);
    int calcularValorCrupie();

};

#endif