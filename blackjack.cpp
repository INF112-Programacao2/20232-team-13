#include "blackjack.h"
#include "jogador.h"
#include <iostream>
#include <exception>

int contcrupie = 2;
int cont = 2;
int cartasdadas = 5;
int pontuacao = 0;
int pontuacaoBot = 0;


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
        return valorReal = 1;
    }
    return 0;
}

void Blackjack::jogar(Jogador a) {

    embaralhar();
    distribuirCartas(a);
    a.set_cartas(_baralho[4], 0);

    std::pair<char,std::string> carta;
    int contaux = 0;
    std::string decisao;
    bool estorou = false;

    while(true) {

        std::cout << "------------" << std::endl;
        std::cout << "Suas Cartas: " << std::endl;
        
        for(int i=0;i<cont;i++){
            carta.first = a.get_valorCartas(i);
            carta.second = a.get_naipeCartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
            pontuacao += calcularValorDaMao(carta);
        }

        std::cout << "------------" << std::endl;
        std::cout << "Carta do Crupie: " << std::endl;

        for(int i=0; i<1+contaux; i++){
            std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }
        
        
        std::cout << "------------" << std::endl;
        std::cout << "Sua pontuacao: " << pontuacao << std::endl;
        std::cout << "Quer pegar mais uma carta? (Responda com sim ou nao!) : " << std::endl;
        std::cin >> decisao;

        if(decisao!="sim" && decisao!="nao") {
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
        }    

        while(decisao=="sim"){

            pontuacao = 0;
            cont++;
            a.set_cartas(_baralho[cartasdadas], cont-1);

            std::cout << "------------" << std::endl;
            std::cout << "Suas Cartas: " << std::endl;

            for(int i=0;i<cont;i++){
                carta.first = a.get_valorCartas(i);
                carta.second = a.get_naipeCartas(i);
                std::cout << carta.first << " de " << carta.second << std::endl;
                pontuacao += calcularValorDaMao(carta);
            }

            std::cout << "------------" << std::endl;
            std::cout << "Sua pontuacao: " << pontuacao << std::endl;

            if(pontuacao > 21) {
                std::cout << "Sua mao passou de 21! Voce perdeu :( !!" << std::endl;
                estorou = true;
                break;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Quer pegar mais uma carta? (Responda com sim ou nao!) : " << std::endl;
            std::cin >> decisao;
            cartasdadas++;
        }

        if(estorou)
            break;
    
        std::cout << "------------" << std::endl;
        std::cout << "Carta do Crupie: " << std::endl;

        for(int i=0; i<contcrupie; i++){
         std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }

        pontuacaoBot = calcularValorCrupie();

        std::cout << "------------" << std::endl;
        std::cout << "Pontuacao do crupie: ";
        std::cout << pontuacaoBot << std::endl;

        while(pontuacaoBot<pontuacao){
        
            _crupie[contcrupie].first = _baralho[cartasdadas].first;
            _crupie[contcrupie].second = _baralho[cartasdadas].second;
            cartasdadas++;

            for(int i=0; i<contcrupie; i++){
                std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
            }

            contcrupie++;
            pontuacaoBot = 0;
            pontuacaoBot = calcularValorCrupie();

            std::cout << "------------" << std::endl;
            std::cout << "Pontuacao do crupie: ";
            std::cout << pontuacaoBot << std::endl;
        }
    
        if((decisao == "nao") && ((pontuacao > pontuacaoBot) || (pontuacaoBot > 21))) {

            std::cout << "------------" << std::endl;
            std::cout << "Suas Cartas: " << std::endl;

            for(int i=0;i<cont;i++){
                carta.first = a.get_valorCartas(i);
                carta.second = a.get_naipeCartas(i);
                std::cout << carta.first << " de " << carta.second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Carta do Crupie: " << std::endl;

            for(int i=0; i<contcrupie; i++){
                std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Pontuacao do Crupie: " << pontuacaoBot << std::endl;
            std::cout << "Sua pontuacao: " << pontuacao << std::endl;
            std::cout << "------------" << std::endl;
            std::cout << "Voce ganhou! Parabens!! :)" << std::endl;
            vitoria(a);
            break;
        }

        else if(decisao == "nao" && pontuacao == pontuacaoBot) {

            std::cout << "------------" << std::endl;
            std::cout << "Suas Cartas: " << std::endl;

            for(int i=0;i<cont;i++){
                carta.first = a.get_valorCartas(i);
                carta.second = a.get_naipeCartas(i);
                std::cout << carta.first << " de " << carta.second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Carta do Crupie: " << std::endl;

            for(int i=0; i<contcrupie; i++){
                std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Pontuacao do Crupie: " << pontuacaoBot << std::endl;
            std::cout << "Sua pontuacao: " << pontuacao << std::endl;
            std::cout << "------------" << std::endl;
            std::cout << "Empate! :|" << std::endl;

            break;
        } 

        else if(decisao == "nao" && pontuacao<pontuacaoBot){

            std::cout << "------------" << std::endl;
            std::cout << "Suas Cartas: " << std::endl;

            for(int i=0;i<cont;i++){
                carta.first = a.get_valorCartas(i);
                carta.second = a.get_naipeCartas(i);
                std::cout << carta.first << " de " << carta.second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Carta do Crupie: " << std::endl;

            for(int i=0; i<contcrupie; i++){
                std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
            }

            std::cout << "------------" << std::endl;
            std::cout << "Pontuacao do Crupie: " << pontuacaoBot << std::endl;
            std::cout << "Sua pontuacao: " << pontuacao << std::endl;
            std::cout << "------------" << std::endl;
            std::cout << "Voce perdeu! :(" << std::endl;

            break;
        }

    }

}

void Blackjack::vitoria(Jogador a) {
    a.incrementaVitoriasSeguidas();
    a.decrescimoCarteira(10.0);
    a.incrementoCarteira(apostar(10.0));
}

void Blackjack::distribuirCartas(Jogador a) { 
    for(int i=0;i<2;i++){
        a.set_cartas(_baralho[i], i);
        _crupie[i].first = _baralho[i+2].first;
        _crupie[i].second = _baralho[i+2].second;
    }
}

int Blackjack::calcularValorDaMao(std::pair<char,std::string> cartas) {
    return valorCarta(cartas);
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