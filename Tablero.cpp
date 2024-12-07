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
        m = m-1;
        if(board[m]==' ') {
            board[m] = n;
            return true;
        }
        
        return false;
    }
    void Tablero::AI_play() { //algoritmo usando minimax no optimizado
        int bestMove = -1;
        int bestScore = -10000; //el puntaje de la ia es muy bajo para poder maximizarlo aplicando minimax
        
        for(int i = 0; i<9; i++) {
            if(board[i]==' ') {
                board[i] = 'O';
                int newScore = minimax(0,false);
                if(bestScore<newScore) {
                    bestScore = newScore;
                    bestMove = i;
                }
                board[i] = ' ';
            }
        }
        play(bestMove+1,'O'); //la función play del tablero toma indices visuales (1 al 9)
        return;
    }
    int Tablero::minimax(int depth, bool maximiza) {
        //reviso si hay algun ganador o un empate. O es la IA
        if(preguntaGanando('O')) return 10-depth;
        if(preguntaGanando('X')) return depth-10;
        int blankCount = 0;
        for(int i = 0; i<9; i++) {
            if(board[i]==' ') blankCount++;
        }
        if(blankCount==0) return 0; //empate, no quedan espacios en blanco

        if(maximiza) { // es la IA la que está intentando simular maximizar su puntaje para ganar
            int bestScore = -100000;
            for(int i = 0; i<9; i++) {
                if(board[i]==' ') {
                    board[i] = 'O';

                    int newScore = minimax(depth+1,false);
                    if(bestScore<newScore) {
                        bestScore = newScore;
                    }
                    board[i] = ' ';
                }
            }
            return bestScore;

        } else {
            int bestScore = 100000;
            for(int i = 0; i<9; i++) {
                if(board[i] == ' ') {
                    board[i] = 'X';

                    int newScore = minimax(depth+1,true);
                    if(bestScore>newScore) { //AQUI EL JUGADOR X HIPOTETICO QUIERE MINIMIZAR SU PUNTAJE
                        bestScore = newScore;
                    }
                    board[i] = ' ';
                }

            }
            return bestScore;
        }

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