#include "../include/blackjack.h"
#include "../include/jogador.h"
#include <iostream>
#include <exception>

//Variaveis Globais inicializadas
int contcrupie = 2;
int cont = 2;
int cartasdadas = 5;
int pontuacao = 0;
int pontuacaoBot = 0;

//Construtor 
Blackjack::Blackjack() : 
Jogos(10,52) {}

//Destrutor
Blackjack::~Blackjack() {}

//Retorna o valor como um inteiro para cada carta
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
    //Reinicializacão de Variaveis
    pontuacao = 0;
    contcrupie = 2;
    cont = 2;
    cartasdadas = 5;
    pontuacaoBot = 0;

    //Distribui as cartas
    embaralhar();
    distribuirCartas(a);
    a.set_cartas(_baralho[4], 0);

    //Variaveis
    std::pair<char,std::string> carta;
    int contaux = 0;
    std::string decisao;
    bool estorou = false;

    //Looping do jogo
    while(true) {

        //Saida com as cartas
        std::cout << "------------" << std::endl;
        std::cout << "Suas Cartas: " << std::endl;
        
        for(int i=0;i<cont;i++){
            carta.first = a.get_valorCartas(i);
            carta.second = a.get_naipeCartas(i);
            std::cout << carta.first << " de " << carta.second << std::endl;
            pontuacao += calcularValorDaMao(carta);
        }

        //Saida das cartas do crupie
        std::cout << "------------" << std::endl;
        std::cout << "Carta do Crupie: " << std::endl;

        for(int i=0; i<1+contaux; i++){
            std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }
        
        //Mostra a pontuação e pergunta a decisao da rodada
        std::cout << "------------" << std::endl;
        std::cout << "Sua pontuacao: " << pontuacao << std::endl;
        std::cout << "Quer pegar mais uma carta? (Responda com sim ou nao!) : " << std::endl;
        std::cin >> decisao;

        //Tratamento de excessão
        if(decisao!="sim" && decisao!="nao") {
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 3!");
        }    

        //Distribui mais cartas se for o caso e testa se pode ganhar ou perder
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

        //Testa se estorou
        if(estorou)
            break;
    
        //Mostra cada carta que o crupie pegou
        std::cout << "------------" << std::endl;
        std::cout << "Carta do Crupie: " << std::endl;

        for(int i=0; i<contcrupie; i++){
         std::cout << _crupie[i].first << " de " << _crupie[i].second << std::endl;
        }

        //Calcula a pontuação do crupie
        pontuacaoBot = calcularValorCrupie();

        std::cout << "------------" << std::endl;
        std::cout << "Pontuacao do crupie: ";
        std::cout << pontuacaoBot << std::endl;

        //Obriga o crupie pegar uma carta para tentar ultrapassar a pontuação do jogador
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
    
        //Testes de casos em que o jogo acaba
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

//Função para distribuir cartas 
void Blackjack::distribuirCartas(Jogador a) { 
    for(int i=0;i<2;i++){
        a.set_cartas(_baralho[i], i);
        _crupie[i].first = _baralho[i+2].first;
        _crupie[i].second = _baralho[i+2].second;
    }
}

//Função que retorna o valor das Cartas
int Blackjack::calcularValorDaMao(std::pair<char,std::string> cartas) {
    return valorCarta(cartas);
}

//Função que retor o valor de cada carta do crupie
int Blackjack::calcularValorCrupie() {
    int valor = 0;
    std::pair<char,std::string> aux;
    for(int i=0; i<contcrupie; i++) {
        aux = _crupie[i];
        valor += valorCarta(aux);
    }

    return valor;
}