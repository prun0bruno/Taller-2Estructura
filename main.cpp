#include <iostream>
#include <cstdlib>
#include "Tablero.h"



int main() {
    int opcion;
    int op1;
    system("cls");
    std::cout << "--  TIC  TAC  TOE --"<<std::endl;

    do {
        std::cout << "ELIJA MODALIDAD DE JUEGO:" <<std::endl;
        std::cout << "PLAYERvPLAYER (1)" <<std::endl;
        std::cout << "PLAYERvIA (2)" <<std::endl;
        std::cout << "PLAYERvIA OPTIMIZADO (3)" <<std::endl;
        std::cout << "SALIR (4)" <<std::endl;
        std::cin >> op1;
        
        switch(op1){
            case 1:{
                Tablero tablero = Tablero();
                int turn = 0;
                bool win = false;
                int moves = 0;
                do{
                    
                    if(turn>1) turn =0;
                    tablero.mostrarTablero();
                    std::cout << "TURNO DE JUGADOR " << turn+1 <<". SELECCIONE NUMERO DEL 1 AL 9 PARA COLOCAR PIEZA" <<std::endl;
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
            case 2:{
                Tablero tablero = Tablero();
                int turn = 0;
                bool win = false;
                int moves = 0;
                do{
                    
                    if(turn>1) turn = 0;
                    tablero.mostrarTablero();
                    if(turn==0) {std::cout << "TURNO DE JUGADOR " << turn+1 <<". SELECCIONE NUMERO DEL 0 AL 8 PARA COLOCAR PIEZA" <<std::endl;}
                    if(turn==1) {std::cout << "TURNO DE JUGADOR " << turn+1 <<std::endl;}
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
                        tablero.AI_play();
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
            case 3:

                break;
            case 4:
                std::cout <<"GRACIAS POR JUGAR!" <<std::endl;
                break;

            default:
                std::cout << "OPCION NO VALIDA."<< std::endl;
                break;

        }

    } while(op1!=4);
    return 0;
}