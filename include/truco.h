#ifndef TRUCO_H
#define TRUCO_H

#include "jogos.h"

class Truco:public Jogos {
    //Construtor e Destrutor
    public:
    Truco();
    ~Truco();
    
    //Metodos
    void jogar(Jogador a) override;
    int valorCarta(std::pair<char,std::string> cartas);
    void distribuirCartas(Jogador a);
};
#endif