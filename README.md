# Taller-2Estructura


## Compilación e Instalación

### Requisitos
- MinGW o cualquier compilador `g++` que pueda ejecutarse en su entorno de desarrollo.
- Alternativamente, puede utilizar **Codespaces** en GitHub.

### Compilación
Utilizando MinGW:
1. Tener MinGW instalado. Instrucciones en: [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)
2. Abrir la terminal y navegar al directorio donde está el código fuente del proyecto.
3. Compilar el proyecto con el siguiente comando:

   ```bash
   g++ Tablero.cpp main.cpp -o main
4. Ejecutar el programa:
   
   ```bash
   ./main
 
## Instrucciones de juego:
Se trata de un juego de gato o Tic-Tac-Toe. Al ejecutar el programa, se muestra un menú con 3 opciones:
1. Jugar de a 2 jugadores, por turnos.
2. Jugar contra la máquina o IA (esto utiliza un algoritmo Minimax, explicado en la siguiente sección).
3. Jugar contra la IA, optimizada (esto a través de una poda alfa-beta, también explicada a continuación).

Al seleccionar una opción, se iniciará el juego. En cada turno, el jugador podrá elegir una posición en el tablero del 1 al 9, de izquierda a derecha y desde la fila superior hasta la inferior:
###  1 | 2 | 3
###  4 | 5 | 6
###  7 | 8 | 9

## Explicación teórica del algoritmo Minimax y la poda alfa-beta.

### - Algoritmo de juego básico:

### - Algoritmo Minimax:

### - Algoritmo de optimización poda Alfa-Beta:

## Análisis de complejidad antes y después de poda Alfa-Beta:
 
