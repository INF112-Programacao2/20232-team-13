#include "jogador.h"
#include "jogos.h"
#include "blackjack.h"
#include <iostream>

int main() { 
    std::string Jogo;
    std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;
    

    std::cout << "Qual jogo voce quer jogar?: " << std::endl;
    std::cout << "1.Blackjack" << std::endl;
    std::cout << "2.PIF" << std::endl;
    std::cout << "3.Truco" << std::endl;
    std::cin >> Jogo;


    if(Jogo == "Blackjack"){
    Jogador A(2);
    Blackjack B;
    B.jogar(A);
    
    A.~Jogador();
    }




    return 0;
}