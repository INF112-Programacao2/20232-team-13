#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <utility>
#include <string>
#include "jogos.h"
#include "jogador.h"

class Blackjack:public Jogos {
    //Construtor e Destrutor
    public:
    Blackjack();
    ~Blackjack();
    
    //Metodos
    void jogar(Jogador a) override;
    int valorCarta(std::pair<char,std::string> cartas);
    void distribuirCartas(Jogador a);
    int calcularValorDaMao(std::pair<char,std::string> cartas);
    int calcularValorCrupie();

};

#endif