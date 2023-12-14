#include "../include/jogador.h"
#include "../include/jogos.h"
#include "../include/blackjack.h"
#include "../include/pif.h"
#include "../include/truco.h"
#include <iostream>
#include <exception>

int main() { 

    //Inicializando a variavel de escolha do que fazer no menu
    int Jogo=0;
    
    try {
        //Menu inicial do jogo
        std::cout << "Bem Vindo ao Cassino!!!!" << std::endl;
        Jogador A(10);
        
        std::cout << "------------------------" << std::endl;     
        std::cout << "Qual jogo voce quer jogar? (1, 2, 3, 4): " << std::endl;
        std::cout << "1.Blackjack" << std::endl;
        std::cout << "2.PIF" << std::endl;
        std::cout << "3.Truco" << std::endl;
        std::cout << "4.Sair" << std::endl;
        std::cout << "------------------------" << std::endl;     
        std::cin >> Jogo;
        std::cout << "------------------------" << std::endl;

        //Tratamento de excessao    
        if(Jogo>4||Jogo<=0)
            throw std::invalid_argument("Escolha uma das opcoes de 1 a 4!");
           
        //Testa qual das opções do menu foi escolhida
        while(Jogo!=4&&Jogo!=0) {
        
            //Inicializa o Blackjack
            if(Jogo == 1){
                A.set_numeroCartas(10);     
                Blackjack B;
                
                try {
                    B.jogar(A);
                } catch (std::invalid_argument &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            //Inicializa o PIF
            if(Jogo == 2){
                A.set_numeroCartas(6);
                Pif B;
                B.jogar(A);
            }

            //Inicializa o Truco
            if(Jogo == 3){
                A.set_numeroCartas(3);
                Truco B;

                try {
                    B.jogar(A);
                } catch (std::invalid_argument &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            //Mostra o menu novamente após jogar
            std::cout << "------------------------" << std::endl;     
            std::cout << "Qual jogo voce quer jogar? (1, 2, 3, 4): " << std::endl;
            std::cout << "1.Blackjack" << std::endl;
            std::cout << "2.PIF" << std::endl;
            std::cout << "3.Truco" << std::endl;
            std::cout << "4.Sair" << std::endl;
            std::cout << "------------------------" << std::endl;     
            std::cin >> Jogo;
            std::cout << "------------------------" << std::endl;

            //Tratamento de excessao
            try {
                if(Jogo>4||Jogo<=0)
                throw std::invalid_argument("Escolha uma das opcoes de 1 a 4!");
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }
        }

        //desaloca
        A.~Jogador();

    //Tratamento de excessao  
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Obrigado por jogar :))!" << std::endl;

    return 0;
}