#include <iostream>
#include <cstdlib>
#include "Tablero.h"



int main() {
    int opcion;
    int op1;

    std::cout << "--  TIC  TAC  TOE --"<<std::endl;
    std::cout << "ELIJA MODALIDAD DE JUEGO:"<< std::endl;
    std::cout << "PLAYERvPLAYER (0)" <<std::endl;
    std::cout << "PLAYERvIA (1)" <<std::endl;
    std::cout << "SALIR (2)" <<std::endl;
    do {
        std::cin >> op1;
        
        switch(op1){
            case 0:{
                Tablero tablero = Tablero();
                int turn = 0;
                bool win = false;
                int moves = 0;
                do{
                    
                    if(turn>1) turn =0;
                    tablero.mostrarTablero();
                    std::cout << "TURNO DE JUGADOR " << turn+1 <<". SELECCIONE NUMERO DEL 0 AL 8 PARA COLOCAR PIEZA" <<std::endl;
                    char m;
                    if(turn==0) {
                        m = 'X';
                    } else m = 'O';
                    //jugar
                    int choice;
                    std::cin >> choice;
                    while(!tablero.play(choice,m)) {
                        std::cout << "POSICION INVALIDA. SELECCIONE NUMERO VALIDO."<<std::endl;
                        int choice;
                        std::cin >> choice;
                        if(tablero.play(choice,m)) break;
                    }

                    win = tablero.preguntaGanando(m);
                    if(win) {
                        system("cls");
                        tablero.mostrarTablero();
                        std::cout << "GANA JUGADOR "<< turn+1 <<"."<<std::endl;
                        std::cout << std::endl;
                        break;
                    }

                    turn++;
                    moves++;
                    system("cls");
                    if(moves == 9 && !win) {
                        system("cls");
                        tablero.mostrarTablero();
                        std::cout <<"EMPATE"<< std::endl;
                        std::cout << std::endl;
                        break;
                    }

                } while(!win);
               
                break;
            }
            case 1:{
                Tablero tablero = Tablero();
                int turn = 0;
                bool win = false;
                int moves = 0;
                do{
                    
                    if(turn>1) turn =0;
                    tablero.mostrarTablero();
                    std::cout << "TURNO DE JUGADOR " << turn+1 <<". SELECCIONE NUMERO DEL 0 AL 8 PARA COLOCAR PIEZA" <<std::endl;
                    char m;
                    if(turn==0) {
                        m = 'X';
                        //jugar
                        int choice;
                        std::cin >> choice;
                        while(!tablero.play(choice,m)) {
                            std::cout << "POSICION INVALIDA. SELECCIONE NUMERO VALIDO."<<std::endl;
                            int choice;
                            std::cin >> choice;
                            if(tablero.play(choice,m)) break;
                        }




                    } else { //juega inteligencia artificial
                        m = 'O';
                        tablero.play(tablero.AI_play(),m);
                    }

                    win = tablero.preguntaGanando(m);
                    if(win) {
                        system("cls");
                        tablero.mostrarTablero();
                        std::cout << "GANA JUGADOR "<< turn+1 <<"."<<std::endl;
                        std::cout << std::endl;
                        break;
                    }

                    turn++;
                    moves++;
                    system("cls");
                    if(moves == 9 && !win) {
                        system("cls");
                        tablero.mostrarTablero();
                        std::cout <<"EMPATE"<< std::endl;
                        std::cout << std::endl;
                        break;
                    }

                } while(!win);
               
                break;
            }
            case 2:
            
                break;
            case 3:
                std::cout <<"GRACIAS POR JUGAR!" <<std::endl;
                break;

            default:
                std::cout << "OPCION NO VALIDA."<< std::endl;
                break;

        }
        std::cout << "    MENU" <<std::endl;
        std::cout << "PLAYERvPLAYER (0)" <<std::endl;
        std::cout << "PLAYERvIA (1)" <<std::endl;
        std::cout << "PLAYERvIA OPTIMIZADO (2)" <<std::endl;
        std::cout << "SALIR (3)" <<std::endl;

    } while(op1!=2);



    



    return 0;
}