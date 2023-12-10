#include "jogador.h"
#include <iostream>

Jogador::Jogador(int cartas){ 
    std::cout << "Qual a quantia desejada para deposito?" << std::endl;
    std::cin >> _carteira;
    _vitorias_seguidas = 0;
    _cartas = new std::pair<char,std::string>[cartas];
}

Jogador::~Jogador() { 
    delete[] _cartas;
}

double Jogador::get_carteira() {
    return _carteira;
}

int Jogador::get_vitorias_seguidas() {
    return _vitorias_seguidas;
}


std::pair<char,std::string> Jogador::get_cartas(int x) {
    return _cartas[x];
}

void Jogador::atualizar_carteira() {
    int saldo;
    std::cout << "Qual a quantia desejada para deposito?" << std::endl;
    std::cin >> saldo;
    _carteira += saldo;
}

void Jogador::set_cartas(std::pair<char,std::string> cartas, int n) {
    _cartas[n].first=cartas.first;
    _cartas[n].second=cartas.second;
}

void Jogador::set_numeroCartas(int cartas) {
    delete[] _cartas;
    _cartas = new std::pair<char,std::string>[cartas];
}

void Jogador::incrementaVitoriasSeguidas() {
    _vitorias_seguidas++;
}

/* A definir
void Jogador::jogada() {

}
*/