#include "jogador.h"
#include "jogos.h"
#include "blackjack.h"
#include <iostream>
#include "pif.h"
#include "truco.h"
#include <exception>

int main() { 
    int Jogo=0;
    
    try {
    
    Jogador A(10);
        
    std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;
    std::cout << "Saldo: " << A.get_carteira() << std::endl;       
    std::cout << "Qual jogo voce quer jogar? (1, 2, 3, 4): " << std::endl;
    std::cout << "1.Blackjack" << std::endl;
    std::cout << "2.PIF" << std::endl;
    std::cout << "3.Truco" << std::endl;
    std::cout << "4.Sair" << std::endl;
    std::cin >> Jogo;
    std::cout << std::endl;
            
    if(Jogo>4||Jogo<=0)
        throw std::invalid_argument("Escolha uma das opcoes de 1 a 4!");
           
    while(Jogo!=4&&Jogo!=0) {
        
        if(Jogo == 1){
            A.set_numeroCartas(10);     
            Blackjack B;
            try {
            B.jogar(A);
            }
            catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }

        if(Jogo == 2){
            A.set_numeroCartas(6);
            Pif B;
            B.jogar(A);
        }

        std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;

        if(Jogo == 3){
            A.set_numeroCartas(3);
            Truco B;
            try {
            B.jogar(A);
            }
            catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }

        std::cout << "Saldo: " << A.get_carteira() << std::endl;       
        std::cout << "Qual jogo voce quer jogar? (1, 2, 3, 4): " << std::endl;
        std::cout << "1.Blackjack" << std::endl;
        std::cout << "2.PIF" << std::endl;
        std::cout << "3.Truco" << std::endl;
        std::cout << "4.Sair" << std::endl;
        std::cin >> Jogo;

        try {
        if(Jogo>4||Jogo<=0)
        throw std::invalid_argument("Escolha uma das opcoes de 1 a 4!");
        }
        catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    }


    A.~Jogador();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}