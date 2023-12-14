#include "../include/jogos.h"
#include <cstdlib>
#include <ctime>

//Construtor
Jogos::Jogos(int crupie, int baralho) {
    _crupie=new std::pair<char,std::string>[crupie];
    _baralho=new std::pair<char,std::string>[baralho];
    
    for(int i=0;i<52;i++) {
        _baralho[i].first='N';
    }
}

//Destrutor
Jogos::~Jogos() {
    delete[] _crupie;
}

//Geters e Seters 
char Jogos::get_valor(int x) {
    return _valor[x];
}

std::string Jogos::get_naipes(int x) {
    return _naipes[x];
}

//Função que embaralha as cartas
void Jogos::embaralhar() {
    
    srand(time(0));
    
    for(int j=0;j<4;j++) {
        for(int k=0;k<13;k++) {
            int aux=(rand()%52);

            while(_baralho[aux].first!='N') {
                aux=(rand()%52);
            }

            _baralho[aux].first=_valor[k];
            _baralho[aux].second=_naipes[j];
        }
    }
}