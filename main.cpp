#include "jogador.h"
#include "jogos.h"
#include "blackjack.h"
#include <iostream>
#include "pif.h"
#include "truco.h"

int main() { 
    std::string Jogo;
    double carteira;

    std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;
    std::cout << "Qual a quantia desejada para deposito?" << std::endl;
    std::cin >> carteira;

    while(Jogo!="Parar") {    
        std::cout << "Qual jogo voce quer jogar? (Digite Parar para sair): " << std::endl;
        std::cout << "1.Blackjack" << std::endl;
        std::cout << "2.PIF" << std::endl;
        std::cout << "3.Truco" << std::endl;
        std::cin >> Jogo;


        if(Jogo == "Blackjack"){
            carteira-=10;
            Jogador A(10);
            Blackjack B;
            B.jogar(A);
    
            A.~Jogador();
        }

        if(Jogo == "PIF"){
            carteira-=10;
            Jogador A(6);
            Pif B;
            B.jogar(A);
    
            A.~Jogador();
        }


        if(Jogo == "Truco"){
            carteira-=10;
            Jogador A(3);
            Truco B;
            B.jogar(A);
            A.~Jogador();
        }
    }

    std::cout << "Saldo: " << carteira << std::endl;    

    return 0;
}