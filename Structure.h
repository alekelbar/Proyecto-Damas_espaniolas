#include <cmath>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <ctime>

using namespace std;
// definimos las propiedades de nuestro tablero
typedef string Tablero[8][8];
typedef string TableroVisual[8][8];

class Table
{
private:
    // configuracion

    // cuanto dura el turno
    int timeOfTurn;

    // tiempo de juego en segundos
    int timeOf = (60 * 10);

    // implementacion de cronometro
    time_t t0, t1 = 0;

    //horas default
    int hours = 0;

    // minutos default
    int minutes = 10;

    // segundos default
    int seconds = 0;

    // auxiliare temporales
    int hAux, mAux, sAux;

    // cuantos movimientos pueden realizarse default
    int movements = 20;

    // el jugador usa ¿blancas o negras?
    int jugadorPlayWith; // 0|1

    // el juego sigue?
    int playing = 1;

    // comida obligatoria
    bool hardmode = true;

    // si existe un ficha chocando al movimiento debemos saberlo
    bool ficha = false;

    // multijugador
    bool multiplayer = true;

    // contador de fichas blancas
    int whites = 12;

    //contador de fichas negras
    int blacks = 12;

    // tiempo para moverse
    int timeToMovement = 15;

    // el nombre del jugador
    string playerName;
    //TODO: CAMBIAR

    // turno perdido
    string lossTurn = "** TURNO PERDIDO ** \n";

    // la ficha negra que movera
    string myBlack = "TURNO NEGRO: \nHORIZONTAL DE SU FICHA ==()=> ";

    // la ficha negra que movera
    string myBlack2 = "TURNO NEGRO: \nVERTICAL DE SU FICHA ==()=> ";

    // ficha blanca que movera
    string myWhite = "TURNO BLANCO: \nHORIZONTAL DE SU FICHA ==()=> ";

    // ficha blanca que movera
    string myWhite2 = "TURNO BLANCO: \nVERTICAL DE SU FICHA ==()=> ";

    // donde se movera
    string objetive = "HORIZONTAL DE SU ESPACIO OBJETIVO ==()=> ";

    // donde se movera
    string objetive2 = "VERTICAL DE SU ESPACIO OBJETIVO ==()=> ";

    // coordenada fuera del tablero.
    string outLimits = "ESA FICHA ESTA FUERA DEL TABLERO !! U.U \n";

    // movimiento invalido
    string badMovement = " PERO!! SI, ESO ES UN MOVIMIENTO INVALIDO!( >.<)'\n";

    // le indica al jugador que puede mover otra ficha
    string anotherPlay = "HEY! PUEDE CONTINUAR COMIENDO (-.-') \n";

    //titulos de stadistics.
    string data = "+-+- ^_^ Damas Espaniolas ^_^ -+-+-\n\n";

    // texto de "presione 'x' para continuar"
    string contin = "TOCA ENTER PARA CONTINUAR !! (^_^)\n";

    // sistema de intercambio y marcado
    string aux1, aux2;

    //mensaje para una ficha equivocada
    string wrongTab = " UY! >.<! pero, SI ESA NO ES TU FICHA! ";

    //mensaje de Hardmode
    string hardmodeMsj = "MODO CON REGLAS: **activo** ¿lo usara? (1/0) -- > ";

    //mensaje para cuando no se usa el automatico en hard-mode
    string penalty = "Hemos soplado su ficha (>.<)\n";

    // mensaje de desea comer otra
    string wantToEatAnother = "¿Desea comer otra? (1/0) ---> ";

    //mensaje cuando las alternativas a comer son identicas
    string identicalOptions = "TUS OPCIONES SON IDENTICAS, vamos!! Elige tu :D \n";

    // mensaje de existe una ficha en medio!
    string tabinthemiddle = "Oye, Oye! hay fichas en el camino\n";

    //mensaje para un obstaculo
    string blocking = "Mirala, esta ahi -> ";

    // error al configurar
    string configureError = "OYE! ¿pero que haz puesto ahi? vamos, intentalo de nuevo\n\n";

    //con lo que juega el cpu
    string cpu;
    // TODO: cambiar

    // nombre del segundo jugador
    string playerName2;

    // opciones identicas jugando con negras
    string youDecide = "superior(1) o inferior(2) : ";

    // error de datos
    string coorError = "\nESE DATO ES INVALIDO (O.O) El tiempo corre amiguito!! \n";

    // note: juegue con esto!
    // fichas
    string white = "[ B ]";
    string Black = "[ N ]";
    string blank = "(   )";
    string crownW = "[#B#]";
    string crownB = "[$N$]";

    // tablero de juego
    Tablero T = {{Black, crownW, Black, blank, blank, Black, blank, white},
                 {Black, white, Black, white, Black, white, Black, white},
                 {Black, blank, blank, blank, blank, blank, blank, blank},
                 {blank, Black, white, white, white, white, blank, white},
                 {Black, blank, crownB, blank, blank, blank, blank, blank},
                 {blank, blank, blank, blank, blank, blank, blank, white},
                 {Black, white, Black, blank, Black, blank, Black, blank},
                 {crownB, Black, blank, blank, blank, white, blank, white}};

    // coordenadas (horizontal(filas) y verticales(columnas))
    int filas1, colums1, filas2, colums2;

    // logica del juego
public:
    // mostrar los tableros de juego
    void toShow();

    // revisa constantemente si existe una dama y en caso de exitir la corona
    void toCrown();

    // logica de movimiento de fichas negras
    bool blackMovement();

    // administra el turno negra.
    void blackTurn();

    // logica de movimiento de fichas blancas
    bool whiteMovement();

    // administra el turno de fichas blancas
    void whiteTurn();

    // logica del movimiento de una reina negra
    bool crownBMovement();

    // logica del movimiento de una reina blanca
    bool crownWMovement();

    // valida los limites del arreglo
    bool validateLimitsX();

    // valida los limites de la coordenada X
    bool validateLimitsY();

    // se encarga de comer fichas negras y si se puede comer otra repetir
    void canEatBlacks();

    // se encarga de el movimiento automatico de las fichas blancas
    void AutomaticPlayWhite();

    // se encarga de comer fichas blancas y si es posible comer otra repetir
    void canEatWhites();

    // juego automatico en blancas
    void AutomaticPlayBlack();

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

    // mensaje de existe una ficha en medio
    void MessageTabInTheMiddle();

    // mensaje para un obstaculo
    void MessageToBlocking(int, int); // coordenadas del bloqueo

    // dar una pequeña pausa
    void pause();

    //bucle principal del juego
    void play();

    // movimiento automatico de las reinas negras
    void automaticPlayCronwBMovement();

    // movimiento automatico de las reinas blancas
    void automaticPlayCronwWMovement();

    // pantalla de acerca de
    void aboutItscreen();

    // verfica si las fichas pueden continuar
    bool ICanFollow();

    // tranforma el tiempo dado en horas, minutos y segundos a solo segundos
    void ToSeconds();

    // transforma segundos a horas, minutos y segundos
    void ToHours();

    // pantalla de configuracion del juego
    void screenConfig();

    // seleccion de ficha
    void tagSelecction();

    // menu de seleccion
    void Menu();

    // limpiar y mostrar el menu
    void cleanToShowMenu();

    // configuracion del juego
    void configure();

    // validar datos
    bool ValidateData(string);
};

//funcion valor absoluto
int absoluteValue(int x)
{
    if (x > 0)
        return x;
    else
        return x * (-1);
}