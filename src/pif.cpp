#include "../include/jogador.h"
#include "../include/pif.h"
#include <string>
#include <iostream>

//Construtor
Pif::Pif() :
Jogos(6,52) {}

//Destrutor
Pif::~Pif() {}


void Pif::jogar(Jogador a) {

//Distribui o baralho
embaralhar();
distribuirCartas(a);
a.set_cartas(_baralho[12], 0);

//Variaveis
std::pair<char,std::string> descarte;
int cont=12;
int aux,aux1;
std::string pergunta;
std::pair<char,std::string> carta;

//Imprime as cartas do jogador
for(int i=0;i<6;i++) {
    carta.first=a.get_valorCartas(i);
    carta.second=a.get_naipeCartas(i);
    std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
}

//Looping do jogo
while(true) {

    //Jogada do Crupie
    aux=rand()%6;
    descarte.first=_crupie[aux].first;
    descarte.second=_crupie[aux].second;
    _crupie[aux].first=_baralho[cont].first;
    _crupie[aux].second=_baralho[cont].second;
    cont++;

    //Mostra Descarte e pergunta o que fazer
    std::pair<char,std::string> carta;
    std::cout << "Carta no descarte: " << descarte.first << " de " << descarte.second << std::endl;
    std::cout << "Quer comprar do descarte ?(sim ou nao)" << std::endl;
    std::cin >> pergunta;
    std::cout << std::endl;

    //Quando compra do descarte
    if(pergunta=="sim") {
        std::cout << "Qual carta quer descartar?(posicao de 1 a 6)" << std::endl;
        for(int i=0;i<6;i++) {
            carta.first=a.get_valorCartas(i);
            carta.second=a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }

        //Muda a carta do jogador
        std::cout << std::endl;
        std::cin >> aux1;
        std::cout << std::endl;
        a.set_cartas(descarte, aux1-1);

        //Imprime as cartas do jogador novamente
        for(int i=0;i<6;i++) {
            carta.first=a.get_valorCartas(i);
            carta.second=a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }

        std::cout << std::endl;
    }

    //Caso o jogador queira comprar do baralho de compras
    else {
        std::cout << "Proxima carta do baralho de compra: " << _baralho[cont].first << " de " << _baralho[cont].second << std::endl;
        std::cout << "Qual carta quer descartar?(posicao de 1 a 6)" << std::endl;

        //Imprime novamente
        for(int i=0;i<6;i++) {
            carta.first=a.get_valorCartas(i);
            carta.second=a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }

        //Recebe qual posicao descartar
        std::cout << std::endl;
        std::cin >> aux1;
        std::cout << std::endl;

        //Efetua a troca de cartas
        a.set_cartas(_baralho[cont], aux1-1);
        cont++;

        //Imprime novamente
        for(int i=0;i<6;i++) {
            carta.first=a.get_valorCartas(i);
            carta.second=a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }

        std::cout << std::endl;
    }
    
    //Pergunta se quer bater e realiza a opção selecionada
    std::cout << "Quer bater?(sim ou nao)" << std::endl;
    std::cin >> pergunta;
    std::cout << std::endl;

    if(pergunta=="sim") {

        //Pede a ordem das trincas/sequencias
        int ordem[6];
        std::cout << "Digite as duas trincas/sequencias da sua mao (posicao de 1 a 6)" << std::endl;
        for(int i=0;i<6;i++) {
            carta.first=a.get_valorCartas(i);
            carta.second=a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }
        std::cout << std::endl;

        for(int i=0;i<6;i++) 
            std::cin >> ordem[i];

            std::cout << std::endl;

        //Testa se realmente as trincas/sequencias foram feitas
        for(int i=0;i<6;i++) 
            ordem[i]--;
        
            bool teste1=false;
            bool teste2=false;
            std::pair<char,std::string> carta1;
            std::pair<char,std::string> carta2;
            std::pair<char,std::string> carta3;

            carta1.first=a.get_valorCartas(ordem[0]);
            carta1.second=a.get_naipeCartas(ordem[0]);
            carta2.first=a.get_valorCartas(ordem[1]);
            carta2.second=a.get_naipeCartas(ordem[1]);
            carta3.first=a.get_valorCartas(ordem[2]);
            carta3.second=a.get_naipeCartas(ordem[2]);
            

            if(((valorCarta(carta1)==(valorCarta(carta2)-1))&&(valorCarta(carta2)==(valorCarta(carta3)-1))&&(carta1.second==carta2.second)&&(carta2.second==carta3.second))||((valorCarta(carta1)==valorCarta(carta2))&&(valorCarta(carta2)==valorCarta(carta3))))
                teste1=true;
                                  
            carta1.first=a.get_valorCartas(ordem[3]);
            carta1.second=a.get_naipeCartas(ordem[3]);
            carta2.first=a.get_valorCartas(ordem[4]);
            carta2.second=a.get_naipeCartas(ordem[4]);
            carta3.first=a.get_valorCartas(ordem[5]);
            carta3.second=a.get_naipeCartas(ordem[5]);

            if(((valorCarta(carta1)==(valorCarta(carta2)-1))&&(valorCarta(carta2)==(valorCarta(carta3)-1))&&(carta1.second==carta2.second)&&(carta2.second==carta3.second))||((valorCarta(carta1)==valorCarta(carta2))&&(valorCarta(carta2)==valorCarta(carta3))))
                teste2=true;

            //Teste se ganhou                  
            if(teste1&&teste2) {
                std::cout << "Parabens, voce ganhou!!!" << std::endl;
                break;
            }
            //Testa se perdeu
            if(teste1==false||teste2==false) {
                std::cout << "Blefe, perdeu!" << std::endl;
                break;
            }
    }       //Caso o baralho acaba
            if(cont==52) {
                std::cout << "Acabou o baralho, perdeu!" << std::endl;
                break;
            }
        
    }

}

//Distribui as cartas
void Pif::distribuirCartas(Jogador a) {
    for(int i=0;i<6;i++) {
        a.set_cartas(_baralho[i], i);
        _crupie[i].first=_baralho[i+6].first;
        _crupie[i].second=_baralho[i+6].second;
}
}

//Retorna o valor de cada carta
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
    return valorReal;
}