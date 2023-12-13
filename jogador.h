#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <utility>

class Jogador {

    private:
    int _carteira;
    int _vitorias_seguidas;
    std::pair<char,std::string> *_cartas;
    
    public:
    Jogador(int cartas);
    ~Jogador();

    int get_vitorias_seguidas();
    void incrementaVitoriasSeguidas();
    char get_valorCartas(int x);
    std::string get_naipeCartas(int x);
    double get_carteira();
    void set_cartas(std::pair<char,std::string> cartas, int n);
    void set_numeroCartas(int cartas);
    void incrementoCarteira(double aposta);
    void decrescimoCarteira(double valor);
    
};

#endif