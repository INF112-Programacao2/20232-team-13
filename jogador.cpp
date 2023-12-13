#include "jogador.h"
#include <iostream>
#include <string>
#include <typeinfo>

Jogador::Jogador(int cartas){ 
    std::cout << "Qual a quantia desejada para deposito?" << std::endl;
    std::cin >> _carteira;
    if(_carteira==0) {
        throw std::invalid_argument("Digite somente numeros!");
    }
    _vitorias_seguidas = 0;
    _cartas = new std::pair<char,std::string>[cartas];
}

Jogador::~Jogador(){ 
    delete[] _cartas;
}

int Jogador::get_vitorias_seguidas() {
    return _vitorias_seguidas;
}

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

void Jogador::incrementaVitoriasSeguidas() {
    _vitorias_seguidas++;
}

void Jogador::incrementoCarteira(double aposta) {
    _carteira+=aposta;
}

double Jogador::get_carteira() {
    return _carteira;
}

void Jogador::decrescimoCarteira(double valor) {
    _carteira=-10;
}