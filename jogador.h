#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <utility>

class Jogador {
    private:
    double _carteira;
    int _vitorias_seguidas;
    std::pair<char,std::string> *_cartas;
    
    public:
    Jogador(int cartas);
    ~Jogador();

    double get_carteira();
    int get_vitorias_seguidas();
    void incrementaVitoriasSeguidas();
    std::pair<char,std::string> get_cartas(int x);
    void atualizar_carteira();
    void jogada();
    void set_cartas(std::pair<char,std::string> cartas, int n);
    void set_numeroCartas(int cartas);
};

#endif