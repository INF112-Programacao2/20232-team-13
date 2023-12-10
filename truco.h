#ifndef TRUCO_H
#define TRUCO_H

#include "jogos.h"

class Truco:public Jogos {
    public:
    Truco();
    ~Truco();
    void jogar();
    void vitoria();
};
#endif