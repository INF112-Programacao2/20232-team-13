#ifndef JOGOS_H
#define JOGOS_H

#include <utility>
#include <string>
#include "jogador.h"

class Jogos{
    //Atributos
    protected:
    char _valor[13] = {'2','3','4','5','6','7','8','9','D','J','Q','K','A'};
    std::string _naipes[4] = {"Copas", "Ouro", "Paus", "Espadas"};
    std::pair<char,std::string> *_crupie ;
    std::pair<char,std::string> *_baralho ;

    //Construtor e Destrutor
    public:
    Jogos(int crupie, int baralho);
    ~Jogos();
    
    //Metodos
    char get_valor(int x);
    std::string get_naipes(int x);
    void embaralhar();
    virtual void jogar(Jogador a)=0;

};

#endif