#include "Tablero.h"
#include <vector>

    Tablero::Tablero() : board(9, ' ') { }

    void Tablero::mostrarTablero() {
        std::cout<< "ESTADO DEL TABLERO" << std::endl;
        std::cout <<std::endl;
    for (int i = 0; i<9; i++) {
        std::cout << " " << board[i];
        if ((i+1) % 3 == 0){
            std::cout <<std::endl;
            if((i+1)<9) {
                std::cout << "___ ___ ___"<< std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << " |";
    }
    std::cout <<std::endl;
    }

    bool Tablero::play(int m, char n) {
        if(board[m]==' ') {
            board[m] = n;
            return true;
        }
        
        return false;
    }
    int Tablero::AI_play() { //algoritmo usando minimax no optimizado
        return 1;
    }

    bool Tablero::preguntaGanando(char m) {

        //filas
        for (int i = 0; i<9; i+=3) {
        if (board[i]==m && board[i+1]==m && board[i+2]==m)
            return true;
        }
        //columnas
        for (int i = 0; i<3; i++) {
            if (board[i]==m && board[i+3]==m && board[i+6]==m)
                return true;
        }
        //diagonales
        if ((board[0]==m && board[4]==m && board[8]==m) || (board[2]==m && board[4]==m && board[6]==m)) {
            return true;
        }
        return false;
    }


    Tablero::~Tablero() {

    }