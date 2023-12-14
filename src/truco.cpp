#include "../include/jogador.h"
#include "../include/truco.h"
#include "../include/jogos.h"
#include <iostream>
#include <string>
#include <exception>

//Variaveis Globais inicializadas
int aux = 7;

//Construtor
Truco::Truco() : Jogos(3,52) {}

//Destrutor
Truco::~Truco() {}


void Truco::jogar(Jogador a) { 
    //Reinicializacao de variavel
    aux = 7;

    //Distribui as cartas
    embaralhar();
    distribuirCartas(a);
    a.set_cartas(_baralho[6], 0);

    //Variaveis
    std::pair<char,std::string> carta;
    
    //Distribui as cartas para o jogador e crupie
    for(int i=0;i<3;i++) {
        carta.first=a.get_valorCartas(i);
        carta.second=a.get_naipeCartas(i);
        
        while(valorCarta(carta)==20) {
            carta.first=_baralho[aux+i].first;
            carta.second=_baralho[aux+i].second;
            aux++;
        }
       
        a.set_cartas(carta, i);
    }

    for(int i=3;i<6;i++) {
        carta.first=_crupie[i-3].first;
        carta.second=_crupie[i-3].second;
        
        while(valorCarta(carta)==20) {
            carta.first=_baralho[aux+i].first;
            carta.second=_baralho[aux+i].second;
            aux++;
        }
       
        _crupie[i-3].first=carta.first;
        _crupie[i-3].second=carta.second;  
    }

    //Variaveis incializadas
    int placar = 0;
    int rodada = 1;
    int escolha;

    //Imprime as cartas do jogador
    std::cout << "Suas Cartas: " << std::endl;
        for(int i=0;i<3;i++){
            carta.first = a.get_valorCartas(i);
            carta.second = a.get_naipeCartas(i);
            std::cout << i+1 << ") " << carta.first << " de " << carta.second << std::endl;
        }

    //Pede a jogada
    std::cout << "Faca sua jogada: " << std::endl;
    std::cin >> escolha;
    std::cout << std::endl;

    //Tratamento de excessao
    if(escolha>3||escolha<=0) {
        throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
    }    

    //Teste de todos os casos
    //Realiza o primeiro caso
    if((escolha==1)){

        carta.first = a.get_valorCartas(0);
        carta.second = a.get_naipeCartas(0);

        //Mostra a carta do jogador e a do crupie
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(0) << " de " << a.get_naipeCartas(0) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[0].first << " de " << _crupie[0].second << std::endl;

        //Compara qual carta mata a outra
        if(valorCarta(carta)>valorCarta(_crupie[0])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        //Zera a posição da carta escolhida
        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 0);

        std::cout << std::endl;

        //Pergunta a próxima escolha
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        //Tratamento de excessao
        if(escolha>3||escolha<=0)
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");


        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl; 

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste segundo caso
    if(escolha==2 && rodada==1){
        carta.first = a.get_valorCartas(1);
        carta.second = a.get_naipeCartas(1);

        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(1) << " de " << a.get_naipeCartas(1) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[0].first << " de " << _crupie[0].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[0])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 1);

            
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        if(escolha>3||escolha<=0)
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");


        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl;

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste terceiro caso
    if(escolha==3 && rodada==1){
        carta.first = a.get_valorCartas(2);
        carta.second = a.get_naipeCartas(2);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(2) << " de " << a.get_naipeCartas(2) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[0].first << " de " << _crupie[0].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[0])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 2);

            
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl;

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste quarto caso
    if(escolha==1 && rodada==2){
        carta.first = a.get_valorCartas(0);
        carta.second = a.get_naipeCartas(0);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(0) << " de " << a.get_naipeCartas(0) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[1].first << " de " << _crupie[1].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[1])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 1);

            
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        if(escolha>3||escolha<=0)
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl;

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
            
        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste quinto caso
    if(escolha==2 && rodada==2){
        carta.first = a.get_valorCartas(1);
        carta.second = a.get_naipeCartas(1);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(1) << " de " << a.get_naipeCartas(1) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[1].first << " de " << _crupie[1].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[1])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 1);

            
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl;

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste sexto caso
    if(escolha==3 && rodada==2){
        carta.first = a.get_valorCartas(2);
        carta.second = a.get_naipeCartas(2);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(2) << " de " << a.get_naipeCartas(2) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[1].first << " de " << _crupie[1].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[1])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 2);

            
        std::cout << "Qual sua proxima escolha?: " << std::endl;
        std::cin >> escolha;
        std::cout << std::endl;

        if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");

        while(a.get_valorCartas(escolha-1)==0||a.get_naipeCartas(escolha-1)=="vazio") {
            std::cout << "Carta ja escolhida, escolha novamente: " << std::endl;
            std::cin >> escolha;
            std::cout << std::endl;

            if(escolha>3||escolha<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
        }

        rodada++;
        std::cout << std::endl;
    }

    //Teste setimo caso
    if(escolha==1 && rodada==3){
        carta.first = a.get_valorCartas(0);
        carta.second = a.get_naipeCartas(0);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(0) << " de " << a.get_naipeCartas(0) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[2].first << " de " << _crupie[2].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[2])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 0);

        rodada++;
        std::cout << std::endl;
    }

    ////Teste oitavo caso
    if(escolha==2 && rodada==3){
        carta.first = a.get_valorCartas(1);
        carta.second = a.get_naipeCartas(1);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(1) << " de " << a.get_naipeCartas(1) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[2].first << " de " << _crupie[2].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[2])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 1);
                
        rodada++;
        std::cout << std::endl;
    }

    //Testa nono caso
    if(escolha==3 && rodada==3){
        carta.first = a.get_valorCartas(2);
        carta.second = a.get_naipeCartas(2);
        std::cout << "Sua carta: " << std::endl;
        std::cout << a.get_valorCartas(2) << " de " << a.get_naipeCartas(2) << std::endl;
        std::cout << "Carta do crupie: " << std::endl;
        std::cout << _crupie[2].first << " de " << _crupie[2].second << std::endl;
        if(valorCarta(carta)>valorCarta(_crupie[2])){
            placar++;
            std::cout << "Voce ganhou a rodada :)" << std::endl;
        }
        else
            std::cout << "Voce perdeu a rodada :(" << std::endl;

        carta.first = '0';
        carta.second = "vazio";
        a.set_cartas(carta, 2);
       
        rodada++;
        std::cout << std::endl;
    }

    //Testa para saber quem ganhou o jogo
    if(placar>=2){
        std::cout << "VOCE GANHOU! :)))" << std::endl;
    }
    else 
        std::cout << "VOCE PERDEU! :(((" << std::endl;
}

//Retorna o valor que cada carta representa no truco
int Truco::valorCarta(std::pair<char,std::string> cartas) {
    int valor;
    if(cartas.first=='4'&&cartas.second=="Paus"){
        return valor = 14;
    }
    if(cartas.first=='7'&&cartas.second=="Copas"){
        return valor = 13;
    }
    if(cartas.first=='A'&&cartas.second=="Espada"){
        return valor = 12;
    }
    if(cartas.first=='7'&&cartas.second=="Ouro"){
        return valor = 11;
    }
    if(cartas.first=='3'){
        return valor = 10;
    }
    if(cartas.first=='2'){
        return valor = 9;
    }
    if(cartas.first=='A'){
        return valor = 8;
    }
    if(cartas.first=='K'){
        return valor = 7;
    }
    if(cartas.first=='J'){
        return valor = 6;
    }
    if(cartas.first=='Q'){
        return valor = 5;
    }
    if(cartas.first=='7'){
        return valor = 4;
    }
    if(cartas.first=='6'){
        return valor = 3;
    }
    if(cartas.first=='5'){
        return valor = 2;
    }
    if(cartas.first=='4'){
        return valor = 1;
    }
    if(cartas.first=='D'){
        return valor = 20;
    }
    if(cartas.first=='9'){
        return valor = 20;
    }
    if(cartas.first=='8'){
        return valor = 20;
    }
    return 0;
}

//Funcao que distribui as cartas
void Truco::distribuirCartas(Jogador a) { 
    
    for(int i=0;i<3;i++) {
        a.set_cartas(_baralho[i], i);
        _crupie[i].first=_baralho[i+3].first;
        _crupie[i].second=_baralho[i+3].second;
    }
}