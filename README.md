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
El juego base está implementado a través de la clase Tablero, la cual se inicia con un vector de caracteres de tamaño 9. Este tablero se modifica con ayuda del método play() que toma el índice que se quiere modificar y el caracter (X o O) del jugador que quiere hacer su movimiento. Esta función es booleana, por lo que si no es posible hacer el movimiento, el error se maneja en Main. También se utiliza el método preguntaGanando() que toma uno de los dos caracteres y analiza si se encuentran 3 en línea en algún punto del tablero.

### - Algoritmo Minimax:
El algoritmo Minimax orienta las decisiones de una "inteligencia artificial" al analizar todos los posibles movimientos que puede hacer la IA en sus respectivos turnos. En cada turno se genera una nueva llamada al algoritmo Minimax (recursivo) que toma un valor "Score".

La naturaleza de este algoritmo permite ponderar las distintas rutas posibles de 2 jugadores (uno max y uno min) en base a este puntaje que se inicia y que, a través de las llamadas recursivas buscará maximizarse o minimizarse, respectivamente. En este caso se analiza al jugador IA que buscará maximizar su puntaje al comparar entre las distintas ramas de posibilidades para luego, una vez terminadas todas las iteraciones recuperar el juego más conveniente en la forma de un índice que indicará su próximo movimiento. 

El output de la función es un puntaje que se va a comparar al inicio de la llamada recursiva para decidir si se toma el camino o no. Cualquier llamada retornará 10 menos la profundidad o iteración de llamada, en caso de que el algoritmo detecte que la jugada favorece (hace ganar) al jugador Max, y retornará la profundidad menos 10 en caso de que la jugada favorezca al jugador contrario. Si la jugada resulta en un empate, el valor retornado será 0.

### - Algoritmo de optimización poda Alfa-Beta:

## Análisis de complejidad antes y después de poda Alfa-Beta:
 
