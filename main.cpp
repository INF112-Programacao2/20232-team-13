#include "jogador.h"
#include "jogos.h"
#include "blackjack.h"
#include <iostream>
#include "pif.h"

int main() { 
    std::string Jogo;
    std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;
    

    std::cout << "Qual jogo voce quer jogar?: " << std::endl;
    std::cout << "1.Blackjack" << std::endl;
    std::cout << "2.PIF" << std::endl;
    std::cout << "3.Truco" << std::endl;
    std::cin >> Jogo;


    if(Jogo == "Blackjack"){
    Jogador A(10);
    Blackjack B;
    B.jogar(A);
    
    A.~Jogador();
    }

    if(Jogo == "PIF"){
    Jogador A(6);
    Pif B;
    B.jogar(A);
    
    A.~Jogador();
    }




    return 0;
}