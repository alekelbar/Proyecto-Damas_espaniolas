#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctype.h>

using namespace std;
// definimos las propiedades de nuestro tablero
typedef string Tablero[8][8];
typedef string TableroVisual[8][8];

class Table
{
private:
    // configuracion

    // indica en que turno se esta
    bool isWhite = false;

    // cuanto dura el turno
    int time;

    // cuantos movimientos pueden realizarse
    int movements;

    // el jugador usa ¿blancas o negras?
    int jugadorPlayWith; // 0|1

    // el juego sigue?
    int playing = 1;

    // comida obligatoria
    bool hardmode = true;

    // contador de fichas blancas
    int whites = 0;

    //contador de fichas negras
    int blacks = 0;

    // el nombre del jugador
    string playerName;

    // movimiento invalido
    string badMovement = "MOVIMIENTO INVALIDO TURNO PERDIDO.... press ENTER\n";

    // le indica al jugador que puede mover otra ficha
    string anotherPlay = "Es posible mover otra ficha! \n";

    //titulos de stadistics.
    string data = "####################### DATA #######################\n\n";

    // texto de "presione 'x' para continuar"
    string contin = "PRESS ENTER...";

    // sistema de intercambio y marcado
    string aux1, aux2;

    //mensaje para una ficha equivocada
    string lossTurn = "ESTA MOVIENDO LA FICHA EQUIVOCADA. TURNO PERDIDO!";

    //mensaje de Hardmode
    string hardmodeMsj = "Desea usar el movimiento automatico 1/0\n";

    //mensaje para cuando no se usa el automatico en hard-mode
    string penalty = "Se ha soplado su ficha(comido)\n";

    // fichas
    string white = "[ b ]";
    string Black = "[ n ]";
    string blank = "[   ]";
    string crownW = "[ B ]";
    string crownB = "[ N ]";

    // tablero de juegos
    Tablero T = {{Black, blank, Black, blank, blank, Black, white, white},
                 {blank, blank, blank, white, white, white, Black, white},
                 {Black, blank, Black, blank, blank, blank, white, blank},
                 {blank, Black, white, blank, Black, white, blank, blank},
                 {Black, blank, Black, blank, Black, blank, blank, blank},
                 {blank, Black, Black, blank, blank, blank, blank, white},
                 {Black, blank, Black, blank, Black, blank, Black, blank},
                 {blank, Black, blank, white, blank, white, blank, white}};

    // coordenadas (horizontal(filas) y verticales(columnas))
    int filas1, colums1, filas2, colums2;

    // logica del juego
public:
    // mostrar los tableros de juego
    void toShow();

    // revisa constantemente si existe una dama
    void toCrown();

    // logica de movimiento de fichas negras
    bool blackMovement();

    // administra las repeticiones de turno negra.
    void blackTurn();

    // logica de movimiento de fichas blancas
    bool whiteMovement();

    // administra las repeticiones de turno blancas
    void whiteTurn();

    // logica del movimiento de una reina negra
    bool crownBMovement();

    // logica del movimiento de una reina negra
    bool crownWMovement();

    // valida los limites del arreglo
    bool validateLimits();

    // se encarga de comer fichas negras y si se puede comer otra repetir
    void canEatBlacks();

    // se encarga de comer fichas blancas y si es posible comer otra repetir
    void canEatWhites();

    // se encarga de comer fichas blancas y de administrar una posible repeticion de turno
    void cronwCanEatWhites();

    // se encarga de comer fichas blancas y de administrar una posible repeticion de turno
    void cronwCanEatBlacks();

    //bucle principal del juego
    void play();
};
