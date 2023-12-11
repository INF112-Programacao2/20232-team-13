#include "blackjack.h"
#include "jogador.h"
#include <iostream>

int contcrupie = 2;
int cont = 2;

Blackjack::Blackjack() : 
Jogos(10,52) {}

Blackjack::~Blackjack() {}

int Blackjack::valorCarta(std::pair<char,std::string> cartas) { 
    int valorReal = 0;
    if(cartas.first=='2') 
        return valorReal = 2;
    if(cartas.first=='3') 
        return valorReal = 3;
    if(cartas.first=='4') 
        return valorReal = 4;
    if(cartas.first=='5') 
        return valorReal = 5;
    if(cartas.first=='6') 
        return valorReal = 6;
    if(cartas.first=='7') 
        return valorReal = 7;
    if(cartas.first=='8') 
        return valorReal = 8;
    if(cartas.first=='9') 
        return valorReal = 9;
    if(cartas.first=='D') 
        return valorReal = 10;
    if(cartas.first=='J') 
        return valorReal = 10;
    if(cartas.first=='Q') 
        return valorReal = 10;
    if(cartas.first=='K') 
        return valorReal = 10;
    if(cartas.first=='A') {
        std::cout << "Escreva o valor que voce deseja que seu As receba (1 ou 11) : " << std::endl;
        std::cin >> valorReal;
        return valorReal;
    }
    return 0;
}

void Blackjack::jogar(Jogador a) {
    embaralhar();
    distribuirCartas(a);
    std::pair<char,std::string> carta;
    int pontuacao = 0;
    int pontuacaoBot = 0;
    int contaux = 0;
    std::string decisao;


    while(true) {
        std::cout << "Suas Cartas: " << std::endl;
        for(int i=0;i<cont;i++){
            carta.first = a.get_valorCartas(i);
            carta.second = a.get_naipeCartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
            pontuacao += calcularValorDaMao(carta);
        }

        std::cout << "Carta do Crupie: " << std::endl;
        for(int i=0; i<1+contaux; i++){
        std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }

        if(pontuacao > 21) {
            std::cout << "Sua mao passou de 21! Voce perdeu :( !!" << std::endl;
            break;
            }
        
        std::cout << "Sua pontuacao: " << pontuacao << std::endl;
        std::cout << "Quer pegar mais uma carta? (Responda com sim ou nao!) : " << std::endl;
        std::cin >> decisao;


    if(decisao == "sim"){
        cont++;
    }

    pontuacaoBot = calcularValorCrupie();

    while(decisao == "sim" && pontuacaoBot<pontuacao){
        contcrupie++;
        contaux++;
    }
        

    if((decisao == "nao") && ((pontuacao > pontuacaoBot) || (pontuacaoBot > 21))) {
        std::cout << "Carta do Crupie: " << std::endl;
        for(int i=0; i<2+contaux; i++){
            std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }

        std::cout << "Voce ganhou! Parabens!! :)" << std::endl;
        break;
    }
    else if(decisao == "nao" && pontuacao == pontuacaoBot) {
        std::cout << "Empate! :|" << std::endl;
        break;
    } 
    else if(decisao == "nao" && pontuacao<pontuacaoBot){
        std::cout << "Voce perdeu! :(" << std::endl;
        break;
    }

    }

}

void Blackjack::vitoria() {

}

void Blackjack::distribuirCartas(Jogador a) { 
    for(int i=0;i<2+cont;i++){
        a.set_cartas(_baralho[i], i);
        _crupie[i].first = _baralho[i].first;
        _crupie[i].second = _baralho[i].second;
    }

}

int Blackjack::calcularValorDaMao(std::pair<char,std::string> cartas) {
    int valor = 0;
    for(int i=0; i<cont; i++){
        valor = valorCarta(cartas);
    }
    
    return valor;
}

int Blackjack::calcularValorCrupie() {
    int valor = 0;
    std::pair<char,std::string> aux;
    for(int i=0; i<contcrupie; i++) {
        aux = _crupie[i];
        valor += valorCarta(aux);
    }

    return valor;
}