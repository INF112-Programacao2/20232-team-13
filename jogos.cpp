#include "jogos.h"
#include <cstdlib>
#include <ctime>


Jogos::Jogos(int crupie, int baralho) {
_odds=2.0;
_crupie=new std::pair<char,std::string>[crupie];
_baralho=new std::pair<char,std::string>[baralho];
for(int i=0;i<sizeof(_baralho)/sizeof(std::pair<char,std::string>);i++) {
    for(int j=0;j<13;j++) {
        _baralho[i+j].second="vazio";
        
    }
}
}

Jogos::~Jogos() {
    delete[] _crupie;
}

double Jogos::get_odds() {
    return _odds;
}

char Jogos::get_valor(int x) {
    return _valor[x];
}

std::string Jogos::get_naipes(int x) {
    return _naipes[x];
}

void Jogos::set_odds(double odds) {
    _odds=odds;
}

double Jogos::apostar(double aposta) {
    return aposta*_odds;
}

void Jogos::embaralhar() {
srand(time(0));
    for(int j=0;j<4;j++) {
        for(int k=0;k<13;k++) {
            int aux=(rand()%(sizeof(_baralho)/sizeof(std::pair<char,std::string>)));
            while(_baralho[aux].second!="vazio") {
                aux++;
            }
            _baralho[aux].first=_valor[k];
            _baralho[aux].second=_naipes[j];
            
        }
    }
}