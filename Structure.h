#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
// definimos las propiedades de nuestro tablero
typedef string Tablero[8][8];
typedef string TableroVisual[8][8];

class Table
{
private:
    // configuracion

    // cuanto dura el turno
    int time;

    // cuantos movimientos pueden realizarse
    int movements;

    // el jugador usa ¿blancas o negras?
    int jugadorPlayWith; // 0|1

    // el juego sigue?
    int playing = 1;

    // comida obligatoria
    bool hardmode = false;

    // contador de fichas blancas
    int whites = 0;

    //contador de fichas negras
    int blacks = 0;

    // el nombre del jugador
    string playerName;

    // movimiento invalido
    string badMovement = "movimiento invalido\n";

    // le indica al jugador que puede mover otra ficha
    string anotherPlay = "Es posible mover otra ficha! \n";

    //titulos de stadistics.
    string data = "='='='='= DATA ='='='='=\n";

    // fichas
    string white = "[ b ]";
    string Black = "[ n ]";
    string blank = "[   ]";
    string crownW = "[ B ]";
    string crownB = "[ N ]";

    // tablero de juegos
    Tablero T = {{Black, blank, Black, blank, blank, blank, white, blank},
                 {blank, blank, blank, Black, blank, white, blank, white},
                 {Black, blank, Black, blank, white, blank, blank, blank},
                 {blank, Black, blank, blank, blank, blank, blank, white},
                 {Black, blank, Black, blank, Black, blank, white, blank},
                 {blank, Black, blank, white, blank, white, blank, blank},
                 {Black, blank, Black, blank, blank, blank, white, blank},
                 {blank, Black, blank, blank, blank, white, blank, white}};

    // coordenadas (altura(v) y largo(h))
    int filas1, colums1, filas2, colums2;

    // logica del juego
public:
    // mostrar los tableros de juego
    void toShow();

    // revisa constantemente si existe una dama
    void toCrown();

    // logica de movimiento de fichas negras
    bool blackMovement(int, int, int, int);

    // administra las repeticiones de turno negra.
    void blackTurn();

    // logica de movimiento de fichas blancas
    bool whiteMovement(int, int, int, int);

    // administra las repeticiones de turno blancas
    void whiteTurn();

    // logica del movimiento de una reina negra
    bool crownBMovement(int, int, int, int);
};
