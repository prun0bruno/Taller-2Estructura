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
        int AI_play();

        //control
        bool preguntaGanando(char m);
    
        ~Tablero();

};