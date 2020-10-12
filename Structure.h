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

    // si existe un ficha chocando al movimiento debemos saberlo
    bool ficha = false;

    // contador de fichas blancas
    int whites = 0;

    //contador de fichas negras
    int blacks = 0;

    // el nombre del jugador
    string playerName;

    // turno perdido
    string lossTurn = "** TURNO PERDIDO ** \n";

    // la ficha negra que movera
    string myBlack = "** coordenadas de su fichas negra **(a b) --> ";

    // ficha blanca que movera
    string myWhite = "** coordenadas de su fichas blanca **(a b) --> ";

    // donde se movera
    string objetive = "** coordenadas objetivo **(a b) --> ";

    // coordenada fuera del tablero.
    string outLimits = "** COORDENADA ** fuera del tablero.\n";

    // movimiento invalido
    string badMovement = "MOVIMIENTO INVALIDO TURNO PERDIDO.... press ENTER\n";

    // le indica al jugador que puede mover otra ficha
    string anotherPlay = "Es posible mover otra ficha! \n";

    //titulos de stadistics.
    string data = "@+@+@+@+@+@+@+@+ Datos de juego @+@+@+@+@+@+@+@+\n\n";

    // texto de "presione 'x' para continuar"
    string contin = "Presione ENTER...";

    // sistema de intercambio y marcado
    string aux1, aux2;

    //mensaje para una ficha equivocada
    string wrongTab = "** ESTA MOVIENDO LA FICHA EQUIVOCADA **";

    //mensaje de Hardmode
    string hardmodeMsj = "Desea usar el movimiento automatico 1/0\n";

    //mensaje para cuando no se usa el automatico en hard-mode
    string penalty = "Se ha soplado su ficha(comido)\n";

    // fichas
    string white = "( B )";
    string Black = "( N )";
    string blank = "(   )";
    string crownW = "(RBB)";
    string crownB = "(RNN)";

    // tablero de juegos
    Tablero T = {{crownB, crownW, Black, blank, blank, Black, crownW, blank},
                 {blank, blank, Black, white, white, Black, white, white},
                 {Black, blank, blank, blank, blank, blank, white, blank},
                 {blank, Black, white, blank, blank, white, blank, blank},
                 {Black, blank, blank, blank, blank, blank, blank, blank},
                 {blank, crownB, blank, blank, blank, blank, blank, white},
                 {Black, blank, Black, blank, Black, blank, white, blank},
                 {crownB, Black, blank, white, blank, white, blank, blank}};

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
    bool validateLimitsX();

    // valida los limites de la coordenada X
    bool validateLimitsY();

    // se encarga de comer fichas negras y si se puede comer otra repetir
    void canEatBlacks();

    // se encarga de el movimiento automatico de las fichas blancas
    void AutomaticPlayWhite(bool);

    // se encarga de comer fichas blancas y si es posible comer otra repetir
    void canEatWhites();

    // juego automatico en blancas
    void AutomaticPlayBlack(bool);

    // se encarga de comer fichas blancas y de administrar una posible repeticion de turno
    void cronwCanEatWhites();

    // se encarga de comer fichas blancas y de administrar una posible repeticion de turno
    void cronwCanEatBlacks();

    // se encarga de el movimiento automatica de las reinas negras
    void AutomaticPlayCronwB();

    // limpia la consola, informa de la perdida de turno, y requiere confirmacion para continuar
    void MessageIsABadMovement();

    // informa que se esta fuera de los limites
    void MessageIsOutLimits();

    //limpiar y mostrar
    void cleanToShow();

    // mensaje para continuar
    void MessageToContinue();

    // ficha equivocada
    void MessageWrongTab();

    // dar una pequeña pausa
    void pause();

    //bucle principal del juego
    void play();
};

//funcion valor absoluto
int absoluteValue(int x)
{
    if (x > 0)
        return x;
    else
        return x * (-1);
}