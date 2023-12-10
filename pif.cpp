#include "pif.h"
#include "jogador.h"
#include <string>
#include <iostream>

Pif::Pif() :
Jogos(6,52) {}

Pif::~Pif() {}

void Pif::jogar(Jogador a) {
embaralhar();
distribuirCartas(a);
std::pair<char,std::string> descarte;
int cont=12;
int aux,aux1;
std::string pergunta;

for(int i=0;i<6;i++) {
std::pair<char,std::string> carta=a.get_cartas(i);
std::cout << carta.first << " de " << carta.second << std::endl;
}

while(true) {
    aux=rand()%6;
    descarte.first=_crupie[aux].first;
    descarte.second=_crupie[aux].second;
    _crupie[aux].first=_baralho[cont].first;
    _crupie[aux].second=_baralho[cont].second;
    cont++;
    std::cout << descarte.first << " de " << descarte.second << std::endl;
    std::cout << "Quer comprar do descarte ou do baralho de compra?(sim ou nao)" << std::endl;
    std::cin >> pergunta;
    if(pergunta=="sim") {
        std::cout << "Qual carta quer descartar?(posicao de 1 a 6)" << std::endl;
        for(int i=0;i<6;i++) {
            std::pair<char,std::string> carta=a.get_cartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
        }
        std::cin >> aux1;
        a.set_cartas(descarte, aux1);
    }
    else {
        std::cout << "Proxima carta do baralho de compra: " << _baralho[cont].first << " de " << _baralho[cont].second << std::endl;
        std::cout << "Qual carta quer descartar?(posicao de 1 a 6)" << std::endl;
        for(int i=0;i<6;i++) {
            std::pair<char,std::string> carta=a.get_cartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
        }
        std::cin >> aux1;
        a.set_cartas(descarte, aux1);
        cont++;
    }
    
    std::cout << "Quer bater?(sim ou nao)" << std::endl;
    std::cin >> pergunta;
    if(pergunta=="sim") {
        int ordem[6];
        std::cout << "Digite as duas trincas/sequencias da sua mao (posicao de 1 a 6)" << std::endl;
        for(int i=0;i<6;i++) {
            std::pair<char,std::string> carta=a.get_cartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
        }
        for(int i=0;i<6;i++) 
            std::cin >> ordem[i];
        
            bool teste1=0,teste2=0;
            std::pair<char,std::string> carta1;
            std::pair<char,std::string> carta2;
            std::pair<char,std::string> carta3;
            carta1=a.get_cartas(ordem[0]);
            carta2=a.get_cartas(ordem[1]);
            carta3=a.get_cartas(ordem[2]);
            if((valorCarta(carta1)==(valorCarta(carta2)-1)&&valorCarta(carta2)==(valorCarta(carta3)-1)&&carta1.second==carta2.second&&carta2.second==carta3.second)||(valorCarta(carta1)==valorCarta(carta2)&&valorCarta(carta2)==valorCarta(carta3)))
                teste1=true;
            carta1=a.get_cartas(ordem[3]);
            carta2=a.get_cartas(ordem[4]);
            carta3=a.get_cartas(ordem[5]);
            if((valorCarta(carta1)==(valorCarta(carta2)-1)&&valorCarta(carta2)==(valorCarta(carta3)-1)&&carta1.second==carta2.second&&carta2.second==carta3.second)||(valorCarta(carta1)==valorCarta(carta2)&&valorCarta(carta2)==valorCarta(carta3)))
                teste2=true;
                

            if(teste1&&teste2) {
                std::cout << "Ganhou!!!" << std::endl;
                a.incrementaVitoriasSeguidas();
                break;
            }
            else {
                std::cout << "Blefe, perdeu!" << std::endl;
                break;
            }
    }
            if(cont==52) {
                std::cout << "Acabou o baralho, perdeu!" << std::endl;
                break;
            }
        
    }

}



void Pif::vitoria(Jogador a) {

}

void Pif::distribuirCartas(Jogador a) {
    for(int i=0;i<6;i++) {
        a.set_cartas(_baralho[i], i);
        _crupie[i].first=_baralho[i+6].first;
        _crupie[i].second=_baralho[i+6].second;
}
}

int Pif::valorCarta(std::pair<char,std::string> cartas) { 
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
        return valorReal = 11;
    if(cartas.first=='Q') 
        return valorReal = 12;
    if(cartas.first=='K') 
        return valorReal = 13;
    if(cartas.first=='A') {
        return valorReal =1;
    }

}