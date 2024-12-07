#pragma once
#include <iostream>
#include <vector>
#include <limits>

class Tablero {
    private:
        std::vector<char> board;
    public:
        Tablero();
        //mostrar el estado actual del juego para el jugador
        void mostrarTablero(); 

        //funciones/acciones de juego
        bool play(int m,char n); //m será el indice donde poner el caractert
        void AI_play();
        int minimax(int depth, bool maximiza);

        //OPTIMIZACION
        void AI_playOptimized();
        int minimaxOptimized(int depth, bool maximiza,int alpha, int beta); //poda de alfa beta

        //control
        bool preguntaGanando(char m);
    
        ~Tablero();

};