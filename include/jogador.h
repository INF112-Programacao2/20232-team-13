#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <utility>

class Jogador {
    //Atributos
    private:
    std::pair<char,std::string> *_cartas;
    
    //Construtor e Destrutor
    public:
    Jogador(int cartas);
    ~Jogador();

    //Metodos
    char get_valorCartas(int x);
    std::string get_naipeCartas(int x);
    void set_cartas(std::pair<char,std::string> cartas, int n);
    void set_numeroCartas(int cartas);

};

#endif