#ifndef JOGOS_H
#define JOGOS_H

#include <utility>
#include <string>
#include "jogador.h"

class Jogos{
    protected:
    double _odds;
    char _valor[13] = {'2','3','4','5','6','7','8','9','D','J','Q','K','A'};
    std::string _naipes[4] = {"Copas", "Ouro", "Paus", "Espadas"};
    std::pair<char,std::string> *_crupie ;
    std::pair<char,std::string> *_baralho ;

    public:
    Jogos(int crupie, int baralho);
    ~Jogos();
    double get_odds();
    char get_valor(int x);
    std::string get_naipes(int x);
    void set_odds(double odds);
    double apostar(double aposta);
    void embaralhar();
    virtual void jogar(Jogador a)=0;
    virtual void vitoria(Jogador a)=0;
};

#endif