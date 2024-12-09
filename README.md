# Taller-2Estructura
Maximiliano Pizarro, 21.776.433-5, maximiliano.pizarro@alumnos.ucn.cl, paralelo C2
Vincenzo Paolo Porzio Elgueta, 21.369.897-4, vincenzo.porzio@alumnos.ucn.cl, paralelo C2
Diego Ignacio Parga Meza, 21.621.105-7, diego.parga@alumnos.ucn.cl , paralelo C2

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
Dentro de cada turno (nodo) y su continuación (turno del oponente con todas sus posibles jugadas) se mantiene nota del resultado minimax, esto con una excepción: el algoritmo ahora toma un valor alfa y uno beta. En cada nodo estos valores serán llenados por el valor máximo entre los nodos hijos en alfa (si es un turno Max) y por el valor mínimo entre los nodos hijos en beta (si es un turno Min). Por cada revisión de los posibles valores Minimax que toman los nodos hijos se recolectan estos valores alfa y beta, y se comparan ambos dentro del mismo nodo. Una vez se cumple la condición de que un alfa obtenido sea mayor que el beta obtenido, se puede "podar" todas las ramas siguientes del árbol y dejar de iterar por los siguientes hijos del nodo, puesto que ninguno será capaz de ofrecer una mejor alternativa ya que alfa ya es mayor que beta y eso es suficiente para determinar que la jugada siguiendo ese camino es óptima y que las ramas restantes del nodo no cambiarán el resultado final. Esto es porque las decisiones tomadas por el oponente en las ramas restantes no pueden mejorar el resultado para el jugador actual.
## Análisis de complejidad antes y después de poda Alfa-Beta:
 
