#include "../include/jogador.h"
#include <iostream>
#include <string>

//Construtor
Jogador::Jogador(int cartas){ 
    _cartas = new std::pair<char,std::string>[cartas];
}

//Destrutor
Jogador::~Jogador(){ 
    delete[] _cartas;
}

//Geters e Seters para as cartas
char Jogador::get_valorCartas(int x) {
    return _cartas[x].first;
}

std::string Jogador::get_naipeCartas(int x) {
    return _cartas[x].second;
}

void Jogador::set_cartas(std::pair<char,std::string> carta, int n) {
    _cartas[n]=carta;
}

void Jogador::set_numeroCartas(int cartas) {
    delete[] _cartas;
    _cartas = new std::pair<char,std::string>[cartas];
}
