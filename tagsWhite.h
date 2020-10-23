#include "tagsBlak.h"

// NOTE: juego con las blancas

// se encarga de las comidas de las fichas coronadas blancas
void Table::cronwCanEatBlacks()
{
    bool band = false; // mimsma funciones que las demas banderas
    ficha = false;
    // no se esta saltando nada?
    int c = 1;

    // siendo que la reina presenta  la movilidad tando de fichas negras como blancas, y elimina restricciones
    //  esta sera compuesta por una estructura casi identica a la de las fichas individuales, pero con los cambios
    // de movilidad necesarios para la total libertad de movilidad de la reina.

    // primero vamos a definir la direccion diagonal del movimiento

    // direccion: diagonal superior derecha
    if (colums1 < colums2 && filas1 > filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 + 1][colums2 - 1] == Black || T[filas2 + 1][colums2 - 1] == crownB)
        {
            for (int i = 0; i < absoluteValue(colums2 - colums1) - 2; i++)
            {

                if (T[filas1 - c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 + c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                T[filas2 + 1][colums2 - 1] = blank;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
                blacks--;
                if (!automaticPlayCronwWMovement())
                    return;
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 - c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 + c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
            }
        }
    }

    // direccion: diagonal inferior derecha
    if (colums1 < colums2 && filas1 < filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 - 1][colums2 - 1] == Black || T[filas2 - 1][colums2 - 1] == crownB)
        {
            // verifico que no este saltando nada
            for (int i = 0; i < absoluteValue(colums2 - colums1) - 2; i++)
            {
                if (T[filas1 + c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 + c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                T[filas2 - 1][colums2 - 1] = blank;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
                blacks--;
                if (!automaticPlayCronwWMovement())
                    return;
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 + c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 + c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
            }
        }
    }

    // direccion: diagonal superior izquierda
    if (colums1 > colums2 && filas1 > filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 + 1][colums2 + 1] == Black || T[filas2 + 1][colums2 + 1] == crownB)
        {
            // verifico que no este saltando nada
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 2; i++)
            {
                if (T[filas1 - c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 - c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                T[filas2 + 1][colums2 + 1] = blank;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
                blacks--;
                if (!automaticPlayCronwWMovement())
                    return;
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 - c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 - c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
            }
        }
    }

    // direccion: diagonal inferior izquierda
    if (colums1 > colums2 && filas1 < filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 - 1][colums2 + 1] == white || T[filas2 - 1][colums2 + 1] == crownW)
        {
            // verifico que no este saltando nada
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 2; i++)
            {
                if (T[filas1 + c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 - c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                T[filas2 - c][colums2 + c] = blank;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
                blacks--;
                if (!automaticPlayCronwWMovement())
                    return;
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 + c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 - c));
                    sleep(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownW;
                band = true;
                MessageToCpuWIsMovement();
                cleanToShow();
            }
        }
    }
    if (!ficha)
    {
        movements--;
    }
}

// se encarga del movimiento automatico de las fichas blancas
bool Table::automaticPlayCronwWMovement()
{
    int c = 1;
    // despues de 20 minutos de analis se concluye que la maxima cantidad de fichas consecutivas que se pueden comer son 2

    // primera ficha
    int filaAux = 0, columnaAux = 0;
    int filaAux2 = 0, columnaAux2 = 0;
    // comeremos de uno en uno, para evitar ambiguedad

    // esto esta mal, se debe cambiar, pues las reinas no solo comen a corta distancia

    /* 
		evaluara cada diagonal y remitira una accion en la diagonal con mas 
		posibilidades a comer
	*/

    // varibles de analisis diagonal
    // se usara para saber cual es la opcion mas viable a comer en una cuestion de cantidad
    int diagonalSuperiorDerecha = 0, diagonalInferiorDerecha = 0, diagonalSuperiorIzquierda = 0, diagonalInferiorIzquierda = 0;

    // note --> Analisis: diagonal superior derecha
    for (int i = 1; i < 8 && filas2 - (i + 1) >= 0 && colums2 + (i + 1) < 8; i++)
    {
        if (T[filas2 - i][colums2 + i] == white)
        {
            break;
        }

        if ((T[filas2 - i][colums2 + i] == Black || T[filas2 - i][colums2 + i] == crownB) && T[filas2 - (i + 1)][colums2 + (i + 1)] == blank)
        {
            diagonalSuperiorDerecha++;
            c += 2;
        }
        else
        {
            c++;
        }
    }

    // note --> Analisis: diagonal inferior derecha
    // recordar delimitar los limites
    for (int i = 1; i < 8 && colums2 + (i + 1) < 8 && filas2 + (i + 1) < 8; i++)
    {
        if (T[filas2 + i][colums2 + i] == white)
        {
            break;
        }

        if ((T[filas2 + i][colums2 + i] == Black || T[filas2 + i][colums2 + i] == crownB) && T[filas2 + (i + 1)][colums2 + (i + 1)] == blank)
        {
            diagonalInferiorDerecha++;
            c += 2;
        }
        else
        {
            c++;
        }
    }

    // note --> Analisis: diagonal superior izquierda
    for (int i = 1; i < 8 && filas2 - (i + 1) >= 0 && colums2 - (i + 1) >= 0; i++)
    {
        if (T[filas2 - i][colums2 - i] == white)
        {
            break;
        }

        if ((T[filas2 - i][colums2 - i] == Black || T[filas2 - i][colums2 - i] == crownB) && T[filas2 - (i + 1)][colums2 - (i + 1)] == blank)
        {
            diagonalSuperiorIzquierda++;
            c += 2;
        }
        else
        {
            c++;
        }
    }

    // note --> Analisis: diagonal inferior izquierda
    for (int i = 1; i < 8 && filas2 + (i + 1) < 8 && colums2 - (i + 1) >= 0; i++)
    {
        if (T[filas2 + i][colums2 - i] == white)
        {
            break;
        }

        if ((T[filas2 + i][colums2 - i] == Black || T[filas2 + i][colums2 - i] == crownB) && T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
        {
            diagonalInferiorIzquierda++;
            c += 2;
        }
        else
        {
            c++;
        }
    }
    /* 
	dwriripcion del problema: debo verificar el mayor de 4 valores.
	posible solucion: identificar los valores por separado y establecer un mayor
	
	note: si existen dos valores iguales cualquiera es valido, asi que se tomara el primero
	*/
    int diagonales[4] = {diagonalSuperiorDerecha,
                         diagonalInferiorDerecha,
                         diagonalSuperiorIzquierda,
                         diagonalInferiorIzquierda};

    // empezamos definiendo que por omision el primer valor es el mayor
    int mayor = diagonales[0];
    for (int i = 1; i < 4; i++)
    // como el primer valor es por omision el mayor, omitimos su comparacion
    {
        // en caso de haber otro mayor, sera desplazado
        // ¿es menor a su siguiente valor?
        if (mayor < diagonales[i])
        {
            // si lo es. Entonces lo desplazamos
            mayor = diagonales[i];
        }
    }

    // en este punto tenemos el valor de mayor magnitud, o al menos a quien le represente en caso de haber dos iguales
    if (diagonalSuperiorDerecha != 0 || diagonalInferiorDerecha != 0 || diagonalSuperiorIzquierda != 0 || diagonalInferiorIzquierda != 0)
    {
        if (cpu != "blancas")
        {
            movements--;
        }

        if (hardmode || cpu == "blancas")
        {
            int opc;

            opc = validateANumber(hardmodeMsj, configureError);

            if (opc)
            {

                if (diagonalSuperiorDerecha == mayor)
                // evaluamos a ver cual resulto mayor, y extraemos la posicion
                {
                    for (int i = 1; i < 8 && filas2 - (i + 1) >= 0 && colums2 + (i + 1) < 8; i++)
                    {
                        if (T[filas2 - i][colums2 + i] == white)
                        {
                            break;
                        }

                        // localizo los indices
                        if ((T[filas2 - i][colums2 + i] == Black || T[filas2 - i][colums2 + i] == crownB) && T[filas2 - (i + 1)][colums2 + (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 - i][colums2 + i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 - (i + 1)][colums2 + (i + 1)] = crownW; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 -= (i + 1);
                            colums2 += (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuWIsMovement();

                            cleanToShow();
                            automaticPlayCronwWMovement();
                        }
                        else
                        {
                            c++;
                        }
                    }
                }
                // planteamos para la diagonal inferior derecha
                else if (diagonalInferiorDerecha == mayor)
                {
                    for (int i = 1; i < 8 && colums2 + (i + 1) < 8 && filas2 + (i + 1) < 8; i++)
                    {
                        if (T[filas2 + i][colums2 + i] == white)
                        {
                            break;
                        }

                        if ((T[filas2 + i][colums2 + i] == Black || T[filas2 + i][colums2 + i] == crownB) && T[filas2 + (i + 1)][colums2 + (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 + i][colums2 + i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 + (i + 1)][colums2 + (i + 1)] = crownW; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 += (i + 1);
                            colums2 += (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuWIsMovement();
                            cleanToShow();
                            automaticPlayCronwWMovement();
                        }
                        else
                        {
                            c++;
                        }
                    }
                }
                else if (diagonalSuperiorIzquierda == mayor)
                {
                    for (int i = 1; i < 8 && filas2 - (i + 1) >= 0 && colums2 - (i + 1) >= 0; i++)
                    {
                        if (T[filas2 - i][colums2 - i] == white)
                        {
                            break;
                        }

                        if ((T[filas2 - i][colums2 - i] == Black || T[filas2 - i][colums2 - i] == crownB) && T[filas2 - (i + 1)][colums2 - (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 - i][colums2 - i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 - (i + 1)][colums2 - (i + 1)] = crownW; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 -= (i + 1);
                            colums2 -= (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuWIsMovement();
                            cleanToShow();
                            automaticPlayCronwWMovement();
                        }
                        else
                        {
                            c++;
                        }
                    }
                }
                else if (diagonalInferiorIzquierda == mayor)
                {
                    for (int i = 1; i < 8 && filas2 + (i + 1) < 8 && colums2 - (i + 1) >= 0; i++)
                    {
                        if (T[filas2 + i][colums2 - i] == white)
                        {
                            break;
                        }

                        if ((T[filas2 + i][colums2 - i] == Black || T[filas2 + i][colums2 - i] == crownB) && T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 + i][colums2 - i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 + (i + 1)][colums2 - (i + 1)] = crownW; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 += (i + 1);
                            colums2 -= (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuWIsMovement();
                            cleanToShow();
                            automaticPlayCronwWMovement();
                        }
                        else
                        {
                            c++;
                        }
                    }
                }

            } // si no uso el modo automatico se sopla la ficha
            else
            {
                cout << penalty;
                T[filas2][colums2] = blank;
                cleanToShow();
                return 0;
            }

            // si no esta activo el hardmode
        }
        else
        {
            int opc;
            opc = validateANumber(wantToEatAnother, configureError); // que ficha comes ahora!
            if (opc)
            {
                whiteTurn();
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

// logica necesaria para comer fichas negras
void Table::canEatBlacks()
{

    // sirve para saber si accedio en una condicion
    bool band = false;
    if (colums2 + 1 != colums1)
    {
        // la coordenada aciende

        if (filas2 < filas1)
        {
            // Se movio mas de una posicion. Ahora se analiza si es valido.
            // si lo es se elimina la ficha enemiga.
            if (T[filas1 - 1][colums1 - 1] == Black ||
                T[filas1 - 1][colums1 - 1] == crownB)
            {
                T[filas1 - 1][colums1 - 1] = blank;
                T[filas2][colums2] = white;
                T[filas1][colums1] = blank;
                MessageToCpuWIsMovement();
                band = true;
                blacks--;
                cleanToShow();

                if (!AutomaticPlayWhite())
                    return;
            }
            // si esta bajando
        }
        else if (filas2 > filas1)
        {
            if (T[filas1 + 1][colums1 - 1] == Black ||
                T[filas1 + 1][colums1 - 1] == crownB)
            {
                T[filas1 + 1][colums1 - 1] = blank;
                T[filas2][colums2] = white;
                T[filas1][colums1] = blank;
                MessageToCpuWIsMovement();
                band = true;
                blacks--;
                cleanToShow();

                if (!AutomaticPlayWhite())
                    return;
            }
        }
        if (!band)
        {
            movements--;
            MessageIsABadMovement();
            sleep(2);
            cleanToShow();
            return;
        }
    }
    else if (colums2 + 1 == colums1 && absoluteValue(filas1 - filas2) == 1)
    {
        T[filas2][colums2] = white;
        T[filas1][colums1] = blank;
        MessageToCpuWIsMovement();
        cleanToShow();
    }
    else
    {
        movements--;
        MessageIsABadMovement();
        sleep(2);
        cleanToShow();
    }
}

//administra el turno automatico de las fichas blancas
bool Table::AutomaticPlayWhite()
{
    int opc;
    // existe otra ficha que comer?
    if ((filas2 - 1 >= 0 && colums2 - 2 >= 0) &&
            ((T[filas2 - 1][colums2 - 1] == Black ||
              T[filas2 - 1][colums2 - 1] == crownB) &&
             T[filas2 - 2][colums2 - 2] == blank) ||

        (filas2 + 1 < 8 && colums2 - 2 >= 0) &&
            ((T[filas2 + 1][colums2 - 1] == Black ||
              T[filas2 + 1][colums2 - 1] == crownB) &&
             T[filas2 + 2][colums2 - 2] == blank))
    {
        cout << anotherPlay;

        if (hardmode || cpu == "blancas")
        {
            int superior = 0, inferior = 0;
            if (cpu != "blancas")
            {
                cout << "HARMODE: Activo, turno automatico.\n";
            }

            // diagonal superior izquierda
            for (int i = 1; i <= 3 && filas2 - (i + 1) >= 0 && colums2 - (i + 1) >= 0; i += 2)
            {

                if ((T[filas2 - i][colums2 - i] == Black ||
                     T[filas2 - i][colums2 - i] == crownB) &&
                    (T[filas2 - (i + 1)][colums2 - (i + 1)] == blank))
                {
                    superior++;
                    // ZONA DE DEBUG
                    // cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
                    // cout << "valor del iterador: " << i << endl;
                    // cout << "primera condicion: "
                    // 	 << (T[filas2 - i][colums2 - i] == Black) << endl;
                    // cout << "segunda condicion: "
                    // 	 << (T[filas2 - (i + 1)][colums2 - (i + 1)] == blank) << endl;

                    // cout << "primera condicion grafica: "
                    // 	 << (T[filas2 - i][colums2 - i]) << endl;
                    // cout << "segunda condicion grafica: "
                    // 	 << (T[filas2 - (i + 1)][colums2 - (i + 1)]) << endl;
                    // cout << "se les va restar: " << (i + 1) << endl;

                    // cout << "valor de superior: " << superior << endl;
                    // ZONA DE DEBUG
                }
            }
            // diagonal inferior izquierda
            for (int i = 1; i <= 3 && filas2 + (i + 1) < 8 && colums2 - (i + 1) >= 0; i += 2)
            {
                if ((T[filas2 + i][colums2 - i] == Black ||
                     T[filas2 + i][colums2 - i] == crownB) &&
                    T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
                {
                    inferior++;
                    // ZONA DE DEBUG
                    // cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
                    // cout << "valor del iterador: " << i << endl;
                    // cout << "primera condicion: "
                    // 	 << (T[filas2 + i][colums2 - i] == Black) << endl;
                    // cout << "segunda condicion: "
                    // 	 << (T[filas2 + (i + 1)][colums2 - (i + 1)] == blank) << endl;

                    // cout << "primera condicion grafica: "
                    // 	 << (T[filas2 + i][colums2 - i]) << endl;
                    // cout << "segunda condicion grafica: "
                    // 	 << (T[filas2 + (i + 1)][colums2 - (i + 1)]) << endl;
                    // cout << "se les va restar: " << (i + 1) << endl;

                    // cout << "valor de inferior: " << inferior << endl;
                    // ZONA DE DEBUG
                }
            }
            if (inferior == superior && (superior != 0 && inferior != 0))
            {
                if (cpu == "blancas")
                {
                    srand(time(0));
                    opc = 1 + rand() % (3 - 1);
                    filas1 = filas2;
                    colums1 = colums2;
                    MessageToCpuWIsMovement();
                }
                else
                {
                    // ¿existe la misma cantidad de fichas en ambas diagonales?
                    cout << identicalOptions; // las opciones a comer son identicas
                    // defino mi punto de partida
                    filas1 = filas2;
                    colums1 = colums2;
                    // ahora eligirada donde se movera
                    opc = validateANumber(youDecide, configureError);
                }
                if (opc == 1)
                {
                    filas2 = filas1 - 2;
                    colums2 = colums1 + 2;
                    blackMovement();
                }
                else if (opc == 2)
                {
                    filas2 = filas1 + 2;
                    colums2 = colums1 + 2;
                    blackMovement();
                }
                else
                {
                    cout << "opcion invalidad\n";
                    cout << lossTurn;
                    cout << penalty;
                    T[filas1][colums1] = blank;
                    whites--;
                    cleanToShow();
                    sleep(2);
                    return 0;
                }
            }
            else if (superior > inferior)
            {
                int opc;
                if (cpu == "blancas")
                {
                    opc = 1;
                    MessageToCpuWIsMovement();
                }
                else
                {
                    opc = validateANumber(hardmodeMsj, configureError);
                }
                if (opc)
                {
                    // una diagonal en blanco, dos es donde cae mi ficha, y de
                    // donde partio, en blanco.
                    T[filas2 - 1][colums2 - 1] = blank;
                    T[filas2 - 2][colums2 - 2] = white;
                    T[filas2][colums2] = blank;
                    blacks--;

                    // vuelvo a revisar
                    cleanToShow();
                    filas2 -= 2;
                    colums2 -= 2;
                    AutomaticPlayWhite();
                }
                else
                {
                    cout << penalty;
                    T[filas2][colums2] = blank;
                    blacks--;
                }
            }
            else
            {
                int opc;
                if (cpu == "blancas")
                {
                    MessageToCpuWIsMovement();
                    opc = 1;
                }
                else
                {
                    opc = validateANumber(hardmodeMsj, configureError);
                }

                if (opc)
                {

                    // una diagonal en blanco, dos es donde cae mi ficha, y de
                    // donde partio, en blanco.
                    T[filas2][colums2] = blank;
                    T[filas2 + 1][colums2 - 1] = blank;
                    T[filas2 + 2][colums2 - 2] = white;
                    blacks--;

                    // vuelvo a revisar
                    filas2 += 2;
                    colums2 -= 2;
                    cleanToShow();
                    AutomaticPlayWhite();
                }
                else
                {
                    cout << penalty;
                    T[filas2][colums2] = blank;
                    blacks--;
                }
            }
        }
        else
        {
            int opc;
            validateANumber(wantToEatAnother, configureError); // que ficha comes ahora!
            if (opc)
            {
                whiteTurn();
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

// logica necesaria para mover una ficha blanca coronada
bool Table::crownWMovement()
{
    toCrown();
    // filas1,colums1 cual muevo
    // filas2,colums2 donde la muevo

    /* debe ser una reina blanca, moverse en diagonal, y donde se mueva,
  debe de esta vacio, siempre.*/
    if (T[filas1][colums1] == crownW && filas2 != filas1 &&
        T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) == absoluteValue(colums1 - colums2))
    { // formas de movimiento

        cronwCanEatBlacks();
    }
    else
    {
        movements--;
        MessageIsABadMovement();
        sleep(2);
        cleanToShow();
    }

    return false;
}

// logica necesaria para efectuar el turno de las fichas blacas
void Table::whiteTurn()
{
    cleanToShow();
    if (cpu == "blancas")
    {
        cpuWhiteMovement();
        cleanToShow();
    }
    else if (!eatRestricctionWhite())
    {
        time_t star, end;
        star = time(0);

        string numero;
        bool isvalidate = false; // parto de que no es un numero valido
        // verificar si es posible coronar
        toCrown();

        // mostrar los datos
        cleanToShow();

        // filas
        // recoleccion de datos.
        while (!isvalidate)
        {
            try
            {
                cout << myWhite;
                cin >> numero;
                isvalidate = ValidateData(numero);

                if (!isvalidate)
                {
                    throw numero;
                }
            }
            catch (string e)
            {
                cout << coorError;
                sleep(2);
                cleanToShow();
            }
        }
        cin.clear();

        filas1 = atoi(numero.c_str());

        // recoleccion de datos

        isvalidate = false;
        while (!isvalidate)
        {
            try
            {

                cout << myWhite2;
                cin >> numero;
                isvalidate = ValidateData(numero);

                if (!isvalidate)
                {
                    throw numero;
                }
            }
            catch (string e)
            {
                cout << coorError;
                sleep(2);
                cleanToShow();
            }
        }

        cin.clear();
        colums1 = atoi(numero.c_str());

        // verificamos que este dentro del tablero
        if (validateLimitsY())
        {
            aux1 = T[filas1][colums1];
            T[filas1][colums1] = "[i'm]";
        }
        // si no esta dentro del tablero
        else
        {
            MessageIsOutLimits();
            sleep(2);
            return;
        }

        // actualizamos los datos
        cleanToShow();

        // recoleccion de datos
        isvalidate = false;
        while (!isvalidate)
        {
            try
            {

                cout << objetive;
                cin >> numero;
                isvalidate = ValidateData(numero);

                if (!isvalidate)
                {
                    throw numero;
                }
            }
            catch (string e)
            {
                cout << coorError;
                sleep(2);
                cleanToShow();
            }
        }

        cin.clear();
        filas2 = atoi(numero.c_str());

        isvalidate = false;
        while (!isvalidate)
        {
            try
            {

                cout << objetive2;
                cin >> numero;
                isvalidate = ValidateData(numero);

                if (!isvalidate)
                {
                    throw numero;
                }
            }
            catch (string e)
            {
                cout << coorError;
                sleep(2);
                cleanToShow();
            }
        }

        cin.clear();
        colums2 = atoi(numero.c_str());

        // verificamos limites del tablero
        if (validateLimitsX())
        {
            // en caso de que quiera moverse donde esta
            if (filas1 == filas2 && colums1 == colums2)
            {
                T[filas1][colums1] = aux1;
                MessageIsABadMovement();
                sleep(2);
                return;
            }
            //else simbolico
            aux2 = T[filas2][colums2];
            T[filas2][colums2] = "[Igo]";
        }
        else
        {
            MessageIsOutLimits();
            sleep(2);
            return;
        }

        cleanToShow();

        // usamos las tags, auxiliares
        T[filas1][colums1] = aux1;
        T[filas2][colums2] = aux2;

        // ¿mueve la ficha correcta?

        end = time(0) - star;
        if (end < timeToMovement)
        {
            // fichas normales
            if (T[filas1][colums1] == white)
            {
                whiteMovement();
            }
            //fichas coronadas
            else if (T[filas1][colums1] == crownW)
            {
                crownWMovement();
            }
            // ficha incorrecta
            else
            {
                movements--;
                MessageWrongTab();
                sleep(2);
            }
        }
        else
        {
            movements--;
            cleanToShow();
            cout << timeIsUp;
            sleep(2);
        }
    }
}

// maneja la logica de movimiento de fichas blancas
bool Table::whiteMovement()
{

    toCrown();
    // filas1,colums1 cual muevo
    // filas2,colums2 donde la muevo

    // donde estoy: debe ser una ficha blanca, debe moverse en diagonal y hacia su
    // frente. donde voy: debe estar vacio
    if (T[filas1][colums1] == white && filas1 != filas2 && colums2 < colums1 &&
        T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) < 3)
    {
        // se encarga de comer fichas y si existe la posibilidad de comer otra
        // repetir turno
        canEatBlacks();
    }
    else
    {
        movements--;
        MessageIsABadMovement();
        sleep(2);
        cleanToShow();
    }
    return true;
}

// restriccion al comer
bool Table::eatRestricctionWhite()
{
    if (!hardmode)
    {
        return false;
    }
    time_t restricted, restricted2;
    int count = 0;
    int opc = 0;
    int posibles = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // revisamos las blancas
            if (T[i][j] == white)
            {
                // diagonal inferior izquierda

                if (((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
                {
                    // cout << "en1: " << i << j << endl;
                    // cout << "blancas\n";
                    posibles++;
                }

                //diagonal superior derecha

                if (((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
                {
                    // cout << "en2: " << i << j << endl;
                    // cout << "blancas\n";
                    posibles++;
                }
            }

            if (T[i][j] == crownW)
            {
                int c = 1;

                // diagonal superior derecha
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i - c][j + c] == white || T[i - c][j + c] == crownW)
                    {
                        break;
                    }
                    if ((T[i - c][j + c] == Black || T[i - c][j + c] == crownB) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRsr\n";
                        posibles++;
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal inferior derecha
                for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j + c < 8; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i + c][j + c] == white || T[i + c][j + c] == crownW)
                    {
                        break;
                    }
                    if ((T[i + c][j + c] == Black || T[i + c][j + c] == crownB) && T[i + (c + 1)][j + (c + 1)] == blank && i + (c + 1) < 8 && j + (c + 1) < 8)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRif\n";
                        posibles++;
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal superior izquierda
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j - c >= 0; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i - c][j - c] == white || T[i - c][j - c] == crownW)
                    {
                        break;
                    }
                    if ((T[i - c][j - c] == Black || T[i - c][j - c] == crownB) && T[i - (c + 1)][j - (c + 1)] == blank && i - (c + 1) >= 0 && j - (c + 1) >= 0)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRsi\n";
                        posibles++;
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal inferior izquierda
                for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j - c >= 0; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i + c][j - c] == white || T[i + c][j - c] == crownW)
                    {
                        break;
                    }
                    if ((T[i + c][j - c] == Black || T[i + c][j - c] == crownB) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRii\n";
                        posibles++;
                        break;
                    }
                    c++;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // revisamos las blancas
            if (T[i][j] == white)
            {
                // diagonal inferior izquierda

                if (((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
                {
                    // cout << "en1: " << i << j << endl;
                    // cout << "blancas\n";
                    count++;
                    if (count <= posibles)
                    {
                        restricted = time(0);
                        cout << "Mueve de: " << (i) << "," << (j) << " a " << (i + 2) << "," << (j - 2) << endl;
                        opc = validateANumber("(0/1) -->", configureError);
                        restricted2 = time(0);
                        if (opc && (restricted - restricted2) < timeToMovement)
                        {
                            filas1 = i;
                            colums1 = j;
                            filas2 = i + 2;
                            colums2 = j - 2;
                            cleanToShow();
                            whiteMovement();
                            cleanToShow();
                            return true;
                        }
                        else
                        {
                            if ((restricted - restricted2) > timeToMovement)
                            {
                                cout << timeIsUp;
                                sleep(2);
                                cleanToShow();
                                movements--;
                                return true;
                            }
                            else if (count == posibles)
                            {
                                cout << penalty;
                                sleep(2);
                                T[i][j] = blank;
                                whites--;
                                return true;
                            }
                        }
                    }
                }

                //diagonal superior derecha

                if (((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
                {
                    // cout << "en2: " << i << j << endl;
                    // cout << "blancas\n";
                    count++;
                    if (count <= posibles)
                    {
                        restricted = time(0);
                        cout << "Mueve de: " << (i) << "," << (j) << " a " << (i - 2) << "," << (j - 2) << endl;
                        opc = validateANumber("(0/1) -->", configureError);
                        restricted2 = time(0);
                        if (opc && (restricted - restricted2) < timeToMovement)
                        {
                            filas1 = i;
                            colums1 = j;
                            filas2 = i - 2;
                            colums2 = j - 2;
                            cleanToShow();
                            whiteMovement();
                            cleanToShow();
                            return true;
                        }
                        else
                        {
                            if ((restricted - restricted2) > timeToMovement)
                            {
                                cout << timeIsUp;
                                sleep(2);
                                cleanToShow();
                                movements--;
                                return true;
                            }
                            else if (count == posibles)
                            {
                                cout << penalty;
                                sleep(2);
                                T[i][j] = blank;
                                whites--;
                                return true;
                            }
                        }
                    }
                }
            }

            if (T[i][j] == crownW)
            {
                int c = 1;

                // diagonal superior derecha
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i - c][j + c] == white || T[i - c][j + c] == crownW)
                    {
                        break;
                    }
                    if ((T[i - c][j + c] == Black || T[i - c][j + c] == crownB) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRsr\n";
                        count++;
                        if (count <= posibles)
                        {
                            restricted = time(0);
                            cout << "Mueve de: " << (i) << "," << (j) << " a " << (i - 2) << "," << (j + 2) << endl;
                            opc = validateANumber("(0/1) -->", configureError);
                            restricted2 = time(0);
                            if (opc && (restricted - restricted2) < timeToMovement)
                            {
                                filas1 = i;
                                colums1 = j;
                                filas2 = i - 2;
                                colums2 = j + 2;
                                cleanToShow();
                                crownWMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    sleep(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    sleep(2);
                                    T[i][j] = blank;
                                    whites--;
                                    return true;
                                }
                            }
                        }
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal inferior derecha
                for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j + c < 8; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i + c][j + c] == white || T[i + c][j + c] == crownW)
                    {
                        break;
                    }
                    if ((T[i + c][j + c] == Black || T[i + c][j + c] == crownB) && T[i + (c + 1)][j + (c + 1)] == blank && i + (c + 1) < 8 && j + (c + 1) < 8)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRif\n";
                        count++;
                        if (count <= posibles)
                        {
                            restricted = time(0);
                            cout << "Mueve de: " << (i) << "," << (j) << " a " << (i + 2) << "," << (j + 2) << endl;
                            opc = validateANumber("(0/1) -->", configureError);
                            restricted2 = time(0);
                            if (opc && (restricted - restricted2) < timeToMovement)
                            {
                                filas1 = i;
                                colums1 = j;
                                filas2 = i + 2;
                                colums2 = j + 2;
                                cleanToShow();
                                crownWMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    sleep(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    sleep(2);
                                    T[i][j] = blank;
                                    whites--;
                                    return true;
                                }
                            }
                        }
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal superior izquierda
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j - c >= 0; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i - c][j - c] == white || T[i - c][j - c] == crownW)
                    {
                        break;
                    }
                    if ((T[i - c][j - c] == Black || T[i - c][j - c] == crownB) && T[i - (c + 1)][j - (c + 1)] == blank && i - (c + 1) >= 0 && j - (c + 1) >= 0)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRsi\n";
                        count++;
                        if (count <= posibles)
                        {
                            restricted = time(0);
                            cout << "Mueve de: " << (i) << "," << (j) << " a " << (i - 2) << "," << (j - 2) << endl;
                            opc = validateANumber("(0/1) -->", configureError);
                            restricted2 = time(0);
                            if (opc && (restricted - restricted2) < timeToMovement)
                            {
                                filas1 = i;
                                colums1 = j;
                                filas2 = i - 2;
                                colums2 = j - 2;
                                cleanToShow();
                                crownWMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    sleep(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    sleep(2);
                                    T[i][j] = blank;
                                    whites--;
                                    return true;
                                }
                            }
                        }
                        break;
                    }
                    c++;
                }
                c = 1;
                // se puede mover

                // diagonal inferior izquierda
                for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j - c >= 0; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i + c][j - c] == white || T[i + c][j - c] == crownW)
                    {
                        break;
                    }
                    if ((T[i + c][j - c] == Black || T[i + c][j - c] == crownB) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "blancasRii\n";
                        count++;
                        if (count <= posibles)
                        {
                            restricted = time(0);
                            cout << "Mueve de: " << (i) << "," << (j) << " a " << (i + 2) << "," << (j - 2) << endl;
                            opc = validateANumber("(0/1) -->", configureError);
                            restricted2 = time(0);
                            if (opc && (restricted - restricted2) < timeToMovement)
                            {
                                filas1 = i;
                                colums1 = j;
                                filas2 = i + 2;
                                colums2 = j - 2;
                                cleanToShow();
                                crownWMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    sleep(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    sleep(2);
                                    T[i][j] = blank;
                                    whites--;
                                    return true;
                                }
                            }
                        }
                        break;
                    }
                    c++;
                }
            }
        }
    }
    return false;
}