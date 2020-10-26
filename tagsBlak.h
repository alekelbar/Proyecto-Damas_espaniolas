#include "Structure.h"

// movimiento automatico de las reinas negras
bool Table::automaticPlayCronwBMovement()
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
        if (T[filas2 - i][colums2 + i] == Black)
        {
            break;
        }

        if (((T[filas2 - i][colums2 + i] == white || T[filas2 - i][colums2 + i] == crownW) && T[filas2 - (i + 1)][colums2 + (i + 1)] == blank))
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
        if (T[filas2 + i][colums2 + i] == Black)
        {
            break;
        }

        if ((T[filas2 + i][colums2 + i] == white || T[filas2 + i][colums2 + i] == crownW) && T[filas2 + (i + 1)][colums2 + (i + 1)] == blank)
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
        if (T[filas2 - i][colums2 - i] == Black)
        {
            break;
        }

        if ((T[filas2 - i][colums2 - i] == white || T[filas2 - i][colums2 - i] == crownW) && T[filas2 - (i + 1)][colums2 - (i + 1)] == blank)
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
        if (T[filas2 + i][colums2 - i] == Black)
        {
            break;
        }

        if ((T[filas2 + i][colums2 - i] == white || T[filas2 + i][colums2 - i] == crownW) && T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
        {
            diagonalInferiorIzquierda++;
            c += 2;
        }
        else
        {
            c++;
        }
    }

    // cout << "la diagonal superior derecha tiene: " << diagonalSuperiorDerecha << endl;
    // cout << "la diagonal inferior derecha tiene: " << diagonalInferiorDerecha << endl;
    // cout << "la diagonal superior izquierda tiene: " << diagonalSuperiorIzquierda << endl;
    // cout << "la diagonal inferior izquierda tiene: " << diagonalInferiorIzquierda << endl;
    // pause();
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
        if (!hardmode && cpu == "blancas")
        {
            int opc;
            cout << "Puede repetir turno! " << endl;
            opc = validateANumber("repite turno(0/1) --> ", configureError);
            if (opc)
            {
                blackTurn();
            }
            return 1;
        }
        if (hardmode || cpu == "negras")
        {
            int opc;
            if (cpu == "negras")
            {
                opc = 1;
            }
            else
            {

                opc = validateANumber(hardmodeMsj, configureError);
            }
            if (opc)
            {

                if (diagonalSuperiorDerecha == mayor)
                // evaluamos a ver cual resulto mayor, y extraemos la posicion
                {
                    for (int i = 1; i < 8 && filas2 - (i + 1) >= 0 && colums2 + (i + 1) < 8; i++)
                    {
                        if (T[filas2 - i][colums2 + i] == Black)
                        {
                            break;
                        }

                        // localizo los indices
                        if ((T[filas2 - i][colums2 + i] == white || T[filas2 - i][colums2 + i] == crownW) && T[filas2 - (i + 1)][colums2 + (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 - i][colums2 + i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 - (i + 1)][colums2 + (i + 1)] = crownB; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 -= (i + 1);
                            colums2 += (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuBIsMovement();

                            cleanToShow();
                            automaticPlayCronwBMovement();
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
                        if (T[filas2 + i][colums2 + i] == Black)
                        {
                            break;
                        }

                        if ((T[filas2 + i][colums2 + i] == white || T[filas2 + i][colums2 + i] == crownW) && T[filas2 + (i + 1)][colums2 + (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 + i][colums2 + i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 + (i + 1)][colums2 + (i + 1)] = crownB; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 += (i + 1);
                            colums2 += (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuBIsMovement();
                            cleanToShow();
                            automaticPlayCronwBMovement();
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
                        if (T[filas2 - i][colums2 - i] == Black)
                        {
                            break;
                        }

                        if ((T[filas2 - i][colums2 - i] == white || T[filas2 - i][colums2 - i] == crownW) && T[filas2 - (i + 1)][colums2 - (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 - i][colums2 - i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 - (i + 1)][colums2 - (i + 1)] = crownB; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 -= (i + 1);
                            colums2 -= (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuBIsMovement();
                            cleanToShow();
                            automaticPlayCronwBMovement();
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
                        if (T[filas2 + i][colums2 - i] == Black)
                        {
                            break;
                        }

                        if ((T[filas2 + i][colums2 - i] == white || T[filas2 + i][colums2 - i] == crownW) && T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
                        {
                            // limpio donde estoy
                            T[filas2][colums2] = blank;

                            // donde esta la ficha a comer
                            T[filas2 + i][colums2 - i] = blank; // vacio

                            // donde me voy a mover
                            T[filas2 + (i + 1)][colums2 - (i + 1)] = crownB; // mi ficha

                            // ahora a replantear la situacion de mayor cantidad por diagonal

                            filas2 += (i + 1);
                            colums2 -= (i + 1);

                            // de esta manera simulo la capacidad de razonar a diferentes situaciones en contexto de la posicion
                            MessageToCpuBIsMovement();
                            cleanToShow();
                            automaticPlayCronwBMovement();
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
                dormir(2);
                cleanToShow();
                T[filas2][colums2] = blank;
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
                blackTurn();
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

// maneja la logica del movimiento de fichas negras.
bool Table::blackMovement()
{

    toCrown();
    // filas1,colums1 representa la ficha que sera movida.
    // filas2,colums2 representa la posicion objetivo de mi ficha.

    // Mediante un analisis definimos caracteristicas de juego repetitivas y esencialmente logicas.
    // unicamente puedo mover fichas negras, va contra las reglas retroceder en direccion a donde
    // parten mis fichas, y los movimientos solo puede realizarse en diagonal, es decir, las columnas
    // pueden tanto incrementar como decrementar, pero no ambas.
    if (T[filas1][colums1] == Black && filas1 != filas2 && colums1 < colums2 &&
        T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) < 3)
    {
        canEatWhites();
    }

    // si las condiciones logicas no se dan, el movimiento debe ser deslegitimado sin ninguna transformacion.
    else
    {
        movements--;
        MessageIsABadMovement();
        dormir(2);
        cleanToShow();
    }
    return true;
}

// administra el turno de fichas negras.
void Table::blackTurn()
{
    cleanToShow();
    if (cpu == "negras")
    {
        cpuBlackMovement();
        cleanToShow();
    }

    else if (!eatRestricctionBlack())
    {
        time_t star, end;
        // toma el tiempo de inicio de la decicion de ficha
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
                cout << myBlack;
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
                dormir(2);
                cleanToShow();
            }
        }
        cin.clear();

        filas1 = atoi(numero.c_str());

        // columnas
        isvalidate = false;
        // recoleccion de datos.
        while (!isvalidate)
        {
            try
            {
                cout << myBlack2;
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
                dormir(2);
                cleanToShow();
            }
        }
        cin.clear();

        colums1 = atoi(numero.c_str());
        // validacion de limites del tablero

        // si los limtes son validos
        if (validateLimitsY())
        {
            if (T[filas1][colums1] == Black || T[filas1][colums1] == crownB)
            {
                aux1 = T[filas1][colums1];
                T[filas1][colums1] = "[i'm]";
            }
            else
            {
                MessageWrongTab();
                movements--;
                dormir(4);
                return;
            }
        }
        // si nos son validos
        else
        {
            MessageIsOutLimits();
            MessageIsABadMovement();
            movements--;
            dormir(4);
            return;
        }

        // limpiar y mostrar
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
                dormir(2);
                cleanToShow();
            }
        }
        cin.clear();

        filas2 = atoi(numero.c_str());
        // recoleccion completa

        isvalidate = false;
        // recoleccion de datos.
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
                dormir(2);
                cleanToShow();
            }
        }
        cin.clear();

        colums2 = atoi(numero.c_str());

        // validacion de los limites del tablero
        if (validateLimitsX())
        {
            // en caso de que pida moverme donde estoy
            if (filas1 == filas2 && colums1 == colums2)
            {
                T[filas1][colums1] = aux1;
                cout << "esta moviendo hacia su misma ficha" << endl;
                movements--;
                MessageIsABadMovement();
                dormir(4);
                return;
            }
            if (T[filas2][colums2] != blank)
            {
                cout << "El objetivo no esta vacio!! *-*" << endl;
                T[filas1][colums1] = aux1;
                dormir(4);
                return;
            }
            // else simbolico
            aux2 = T[filas2][colums2];
            T[filas2][colums2] = "[Igo]";
        }
        // si no estoy dentro del tablero
        else
        {
            MessageIsOutLimits();
            T[filas1][colums1] = aux1;
            dormir(4);
            return;
        }

        // limpiar y mostrar
        cleanToShow();

        // usamos las tags temporales
        // se usaron para intercambiar a "iam" y "igo"
        T[filas1][colums1] = aux1;
        T[filas2][colums2] = aux2;

        // ¿mueve la correcta?

        // fichas normales
        end = time(0) - star;
        if (end < timeToMovement)
        {
            if (T[filas1][colums1] == Black)
            {
                blackMovement();
            }

            //fichas coronadas
            else if (T[filas1][colums1] == crownB)
            {
                crownBMovement();
            }
        }
        else
        {
            cleanToShow();
            movements--;
            cout << timeIsUp;
            dormir(4);
        }
    }
}

// logica necesaria para mover una ficha negra coronada
bool Table::crownBMovement()
{

    toCrown();
    // filas1,colums1 cual muevo
    // filas2,colums2 donde la muevo

    /* debe ser una reina negra, moverse en diagonal, y donde se mueva,
  debe de esta vacio, siempre.*/
    if (T[filas1][colums1] == crownB && filas2 != filas1 &&
        T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) == absoluteValue(colums1 - colums2))
    { // formas de movimiento

        cronwCanEatWhites();
    }
    else
    {
        movements--;
        MessageIsABadMovement();
        dormir(2);
        cleanToShow();
    }

    return false;
}

// se encarga de comidas simples blancas y repetir si existe otra comida
void Table::canEatWhites()
{
    // siendo que al agregar "elses" puede dificultar la lectura del codigo, se esta agregando
    // una variable booleana, se encarga de monitorear si se realizo un movimiento valido.
    // Sera inicializada a false en cada turno, asumiendo que el movimiento es invalido
    // y sera modificada a true en caso de que se realice una transformacion en la matriz, es decir.
    // un movimiento valido.
    bool band = false;

    if (colums2 - 1 != colums1)
    {
        // 		solo es posible dar un salto amplio siempre y cuando sea posible comer otra ficha.
        //	entonces se realiza un analisis. Tanto si la coordenada aciende como si deciente dentro
        // 	de la matriz se hacen las transformaciones necesarias para realizar el movimiento
        //	de manera valida, es decir, comer.

        // la coordenada aciende
        if (filas2 < filas1)
        {
            // Se movio mas de una posicion. Ahora se analiza si es valido.
            // si lo es se elimina la ficha enemiga. Tanto si es una ficha ordinaria como si
            // es una reina
            if (T[filas1 - 1][colums1 + 1] == white ||
                T[filas1 - 1][colums1 + 1] == crownW)
            {
                T[filas1 - 1][colums1 + 1] = blank;
                T[filas2][colums2] = Black;
                T[filas1][colums1] = blank;
                MessageToCpuBIsMovement();
                band = true;
                whites--;
                // Esencialmente, en caso de ser posible seguir "comiendo" el jugador debe realizar una accion
                // en dependencia de su modo de juego, el siguiente metodo realiza tal labor.
                AutomaticPlayBlack();
            }

        } // la coordenada deciende
        else if (filas2 > filas1)
        {
            if (T[filas1 + 1][colums1 + 1] == white ||
                T[filas1 + 1][colums1 + 1] == crownW)
            {
                T[filas1 + 1][colums1 + 1] = blank;
                T[filas2][colums2] = Black;
                T[filas1][colums1] = blank;
                MessageToCpuBIsMovement();
                band = true;
                whites--;
                // Esencialmente, en caso de ser posible seguir "comiendo" el jugador debe realizar una accion
                // en dependencia de su modo de juego, el siguiente metodo realiza tal labor.
                AutomaticPlayBlack();
            }
        }

        // se consulta la labor de la bandera, ¿existio alguna transformacion?
        if (!band)
        {
            movements--;
            MessageIsABadMovement();
            dormir(2);
            cleanToShow();
            return;
        }
    }
    // anteriormente hemos verificado candidatos de existencia, es decir, ¿estoy moviendo la ficha correcta?
    // ¿estoy moviendo me al lugar correcto? siendo asi, podemos afirmar que un movimiento de un unico salto
    // no necesita mas que las transformaciones de la matriz.
    else if (colums2 - 1 == colums1 && absoluteValue(filas1 - filas2) == 1)
    {
        T[filas2][colums2] = Black;
        T[filas1][colums1] = blank;
        MessageToCpuBIsMovement();
    }
    else
    {
        movements--;
        MessageIsABadMovement();
        cleanToShow();
        dormir(2);
    }
}

// administra el automatico de las negras
bool Table::AutomaticPlayBlack()

// @Perspectiva logica basica: Desde una perspectiva logica, superficial el analisis de la continuidad del turno
// solo depende de que sea posible comer otra ficha. En dependencia de la ficha en cuestion se analiza
// si las tranformaciones son en una direccion del tablero, o en otra.

{
    int opc;
    //en caso de que la diagonal superior derecha presente una ficha comestible, o en caso
    // de que la segunda diagonal superior derecha, partiendo de mi propia ficha este vacia.
    // Tambien se analiza desde la perspectiva de la diagonal inferior derecha.
    if ((filas2 - 2 >= 0 && colums2 + 2 < 8) &&
            ((T[filas2 - 1][colums2 + 1] == white ||
              T[filas2 - 1][colums2 + 1] == crownW) &&
             T[filas2 - 2][colums2 + 2] == blank)

        ||

        ((filas2 + 1 < 8 && colums2 + 2 < 8) &&
         (T[filas2 + 1][colums2 + 1] == white ||
          T[filas2 + 1][colums2 + 1] == crownW) &&
         T[filas2 + 2][colums2 + 2] == blank))
    {
        // de ser posible mover otra ficha, informamos la posibilidad
        cout << anotherPlay;

        if (!hardmode && cpu == "blancas")
        {
            int opc;
            cout << "Puede repetir turno! " << endl;
            opc = validateANumber("repite turno(0/1) --> ", configureError);
            if (opc)
            {
                blackTurn();
            }
            return 1;
        }

        // este condicinal no hace mas que verificar si el juego es condicionado por reglas.
        if (hardmode || cpu == "negras")
        {

            if (cpu != "negras")
            {
                cout << "HARMODE: Activo, turno automatico.\n";
            }

            // diagonal con mayor fichas, sea superior o inferior
            int superior = 0, inferior = 0;

            // diagonal superior derecha
            for (int i = 1; i <= 3 && filas2 - (i + 1) >= 0 && colums2 + (i + 1) < 8; i += 2)
            {

                if ((T[filas2 - i][colums2 + i] == white ||
                     T[filas2 - i][colums2 + i] == crownB) &&
                    (T[filas2 - (i + 1)][colums2 + (i + 1)] == blank))
                {
                    superior++;
                    // en caso de error, descomentar el debugger

                    //ZONA DE DEBUG
                    // cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
                    // cout << "valor del iterador: " << i << endl;
                    // cout << "primera condicion: "
                    // 	 << (T[filas2 - i][colums2 + i] == white) << endl;
                    // cout << "segunda condicion: "
                    // 	 << (T[filas2 - (i + 1)][colums2 + (i + 1)] == blank) << endl;

                    // cout << "primera condicion grafica: "
                    // 	 << (T[filas2 - i][colums2 + i]) << endl;
                    // cout << "segunda condicion grafica: "
                    // 	 << (T[filas2 - (i + 1)][colums2 + (i + 1)]) << endl;
                    // cout << "se les va restar: " << (i + 1) << endl;
                    // pause();

                    // cout << "valor de superior: " << superior << endl;
                    // ZONA DE DEBUG
                }
            }
            // diagonal inferior derecha
            for (int i = 1; i <= 3 && filas2 + (i + 1) < 8 && colums2 + (i + 1) < 8; i += 2)
            {

                if ((T[filas2 + i][colums2 + i] == white ||
                     T[filas2 + i][colums2 + i] == crownB) &&
                    T[filas2 + (i + 1)][colums2 + (i + 1)] == blank)
                {
                    inferior++;
                    // en caso de errores, descomentar el debugger para el correcto analisis.

                    // ZONA DE DEBUG
                    // cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
                    // cout << "valor del iterador: " << i << endl;
                    // cout << "primera condicion: "
                    // 	 << (T[filas2 + i][colums2 + i] == Black) << endl;
                    // cout << "segunda condicion: "
                    // 	 << (T[filas2 + (i + 1)][colums2 + (i + 1)] == blank) << endl;

                    // cout << "primera condicion grafica: "
                    // 	 << (T[filas2 + i][colums2 + i]) << endl;
                    // cout << "segunda condicion grafica: "
                    // 	 << (T[filas2 + (i + 1)][colums2 + (i + 1)]) << endl;
                    // cout << "se les va restar: " << (i + 1) << endl;

                    // cout << "valor de inferior: " << inferior << endl;
                    // pause();
                    // ZONA DE DEBUG
                }
            }
            if (inferior == superior && (superior != 0 && inferior != 0))
            {
                if (cpu == "negras")
                {
                    srand(time(0));
                    opc = 1 + rand() % (3 - 1);
                    // defino mi punto de partida
                    filas1 = filas2;
                    colums1 = colums2;
                    MessageToCpuBIsMovement();
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
                cleanToShow();
                if (opc == 1)
                {
                    filas2 = filas1 - 2;
                    colums2 = colums1 + 2;
                    blackMovement();
                    cleanToShow();
                }
                else if (opc == 2)
                {
                    filas2 = filas1 + 2;
                    colums2 = colums1 + 2;
                    blackMovement();
                    cleanToShow();
                }
                else
                {
                    cout << "opcion invalidad\n";
                    cout << penalty;
                    T[filas1][colums1] = blank;
                    blacks--;
                    cleanToShow();
                    dormir(2);
                    return 0;
                }
            }

            //en caso de las opciones no ser iguales, se deben realizar las transformaciones
            // necesarias para el caso en particular. Se asume, por el tamaño del tablero. que dado un movimiento.
            // la maxima cantidad de saltos posibles es de dos.
            else if (superior > inferior)
            {
                int opc;
                if (cpu == "negras")
                {
                    opc = 1;
                    MessageToCpuBIsMovement();
                }
                else
                {
                    opc = validateANumber(hardmodeMsj, configureError);
                }

                if (opc)
                {

                    // transformaciones para un unico salto
                    T[filas2 - 1][colums2 + 1] = blank;
                    T[filas2 - 2][colums2 + 2] = Black;
                    T[filas2][colums2] = blank;
                    whites--;

                    // vuelvo a revisar
                    filas2 -= 2;
                    colums2 += 2;
                    cleanToShow();
                    AutomaticPlayBlack();
                }
                else
                {
                    // segun las reglas, no es posible saltar el turno a voluntad en caso de ser
                    // activo el hardmode, siendo asi, segun las reglas se le soplara la ficha
                    cout << penalty;
                    T[filas2][colums2] = blank;
                    // representa las fichas negras que fueron comidas
                    blacks--;
                }
            }
            else
            {
                int opc;
                if (cpu == "negras")
                {
                    opc = 1;
                    MessageToCpuBIsMovement();
                }
                else
                {
                    opc = validateANumber(hardmodeMsj, configureError);
                }

                if (opc)
                {

                    // transformaciones para un unico salto
                    T[filas2 + 1][colums2 + 1] = blank;
                    T[filas2 + 2][colums2 + 2] = Black;
                    T[filas2][colums2] = blank;
                    whites--;

                    // vuelvo a revisar
                    filas2 += 2;
                    colums2 += 2;
                    cleanToShow();
                    AutomaticPlayBlack();
                }
                else
                {
                    cout << penalty;
                    T[filas2][colums2] = blank;
                    // representa la cantidad de fichas negras comidas
                    whites--;
                }
            }
        }

        // en caso de no ser activo el modo hardcore(reglas), es decicion del jugador, comer.
        else
        {
            int opc;
            opc = validateANumber(wantToEatAnother, configureError); // que ficha comes ahora!
            if (opc)
            {
                blackTurn();
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

// se encarga de las comidas de las fichas coronadas negras
void Table::cronwCanEatWhites()
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
        if (T[filas2 + 1][colums2 - 1] == white || T[filas2 + 1][colums2 - 1] == crownW)
        {
            for (int i = 0; i < absoluteValue(colums2 - colums1) - 2; i++)
            {

                if (T[filas1 - c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 + c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                T[filas2 + 1][colums2 - 1] = blank;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
                whites--;
                automaticPlayCronwBMovement();
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 - c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 + c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
            }
        }
    }

    // direccion: diagonal inferior derecha
    if (colums1 < colums2 && filas1 < filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 - 1][colums2 - 1] == white || T[filas2 - 1][colums2 - 1] == crownW)
        {
            // verifico que no este saltando nada
            for (int i = 0; i < absoluteValue(colums2 - colums1) - 2; i++)
            {
                if (T[filas1 + c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 + c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                T[filas2 - 1][colums2 - 1] = blank;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
                whites--;
                automaticPlayCronwBMovement();
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 + c][colums1 + c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 + c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
            }
        }
    }

    // direccion: diagonal superior izquierda
    if (colums1 > colums2 && filas1 > filas2)
    {
        // la diagonal anterior a mi objetivo es comestible?
        if (T[filas2 + 1][colums2 + 1] == white || T[filas2 + 1][colums2 + 1] == crownW)
        {
            // verifico que no este saltando nada
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 2; i++)
            {
                if (T[filas1 - c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 - c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                T[filas2 + 1][colums2 + 1] = blank;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
                whites--;
                automaticPlayCronwBMovement();
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 - c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 - c), (colums1 - c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                band = true;
                MessageToCpuBIsMovement();
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
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                T[filas2 - c][colums2 + c] = blank;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
                whites--;
                automaticPlayCronwBMovement();
            }
        }
        else
        {
            for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
            {
                if (T[filas1 + c][colums1 - c] != blank)
                {
                    MessageToBlocking((filas1 + c), (colums1 - c));
                    dormir(2);
                    cleanToShow();
                    ficha = true;
                }
                c++;
            }
            if (!ficha)
            {
                T[filas1][colums1] = blank;
                T[filas2][colums2] = crownB;
                band = true;
                MessageToCpuBIsMovement();
                cleanToShow();
            }
        }
    }
    if (!band)
    {
        movements--;
    }
}

// restriccion de comida
bool Table::eatRestricctionBlack()
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
            if (T[i][j] == Black)
            {
                // diagonal inferior derecha

                if (((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
                {
                    posibles++;
                }
                // diagonal superior derecha

                if (((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
                {
                    posibles++;
                }
            }

            // si es una reina
            if (T[i][j] == crownB)
            {
                int c = 1;
                // diagonal superior derecha
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
                {
                    // se puede mover
                    // hasta ahi no se puede mover
                    if (T[i - c][j + c] == Black || T[i - c][j + c] == crownB)
                    {
                        break;
                    }
                    if ((T[i - c][j + c] == white || T[i - c][j + c] == crownW) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
                    {
                        // cout << "en: " << i << j << endl;
                        // cout << "negrasRsr\n";
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
                    if (T[i + c][j + c] == Black || T[i + c][j + c] == crownB)
                    {
                        break;
                    }
                    if ((T[i + c][j + c] == white || T[i + c][j + c] == crownW) && T[i + (c + 1)][j + (c + 1)] == blank && i + (c + 1) < 8 && j + (c + 1) < 8)
                    {
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
                    if (T[i - c][j - c] == Black || T[i - c][j - c] == crownB)
                    {
                        break;
                    }
                    if ((T[i - c][j - c] == white || T[i - c][j - c] == crownW) && T[i - (c + 1)][j - (c + 1)] == blank && i - (c + 1) >= 0 && j - (c + 1) >= 0)
                    {
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
                    if (T[i + c][j - c] == Black || T[i + c][j - c] == crownB)
                    {
                        break;
                    }
                    if ((T[i + c][j - c] == white || T[i + c][j - c] == crownW) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
                    {
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
            if (T[i][j] == Black)
            {
                // diagonal inferior derecha

                if (((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
                {
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
                            blackMovement();
                            cleanToShow();
                            return true;
                        }
                        else
                        {
                            if ((restricted - restricted2) > timeToMovement)
                            {
                                cout << timeIsUp;
                                dormir(2);
                                cleanToShow();
                                movements--;
                                return true;
                            }
                            else if (count == posibles)
                            {
                                cout << penalty;
                                dormir(2);
                                T[i][j] = blank;
                                blacks--;
                                return true;
                            }
                        }
                    }
                }
                // diagonal superior derecha

                if (((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
                {

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
                            blackMovement();
                            cleanToShow();
                            return true;
                        }
                        else
                        {
                            if ((restricted - restricted2) > timeToMovement)
                            {
                                cout << timeIsUp;
                                dormir(2);
                                cleanToShow();
                                movements--;
                                return true;
                            }
                            else if (count == posibles)
                            {
                                cout << penalty;
                                dormir(2);
                                T[i][j] = blank;
                                blacks--;
                                return true;
                            }
                        }
                    }
                }
            }

            // si es una reina
            if (T[i][j] == crownB)
            {
                int c = 1;
                // diagonal superior derecha
                for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
                {
                    // se puede mover
                    // hasta ahi no se puede mover
                    if (T[i - c][j + c] == Black || T[i - c][j + c] == crownB)
                    {
                        break;
                    }
                    if ((T[i - c][j + c] == white || T[i - c][j + c] == crownW) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
                    {

                        // cout << "en: " << i << j << endl;
                        // cout << "negrasRsr\n";
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
                                crownBMovement();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    dormir(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    dormir(2);
                                    T[i][j] = blank;
                                    blacks--;
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
                    if (T[i + c][j + c] == Black || T[i + c][j + c] == crownB)
                    {
                        break;
                    }
                    if ((T[i + c][j + c] == white || T[i + c][j + c] == crownW) && T[i + (c + 1)][j + (c + 1)] == blank && i + (c + 1) < 8 && j + (c + 1) < 8)
                    {

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
                                crownBMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    dormir(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    dormir(2);
                                    T[i][j] = blank;
                                    blacks--;
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
                    if (T[i - c][j - c] == Black || T[i - c][j - c] == crownB)
                    {
                        break;
                    }
                    if ((T[i - c][j - c] == white || T[i - c][j - c] == crownW) && T[i - (c + 1)][j - (c + 1)] == blank && i - (c + 1) >= 0 && j - (c + 1) >= 0)
                    {

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
                                crownBMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    dormir(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    dormir(2);
                                    T[i][j] = blank;
                                    blacks--;
                                    return true;
                                }
                            }
                        }
                        break;
                    }
                    c++;
                }
                c = 1;

                // diagonal inferior izquierda
                for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j - c >= 0; a++)
                {
                    // hasta ahi no se puede mover
                    if (T[i + c][j - c] == Black || T[i + c][j - c] == crownB)
                    {
                        break;
                    }
                    if ((T[i + c][j - c] == white || T[i + c][j - c] == crownW) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
                    {

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
                                crownBMovement();
                                cleanToShow();
                                return true;
                            }
                            else
                            {
                                if ((restricted - restricted2) > timeToMovement)
                                {
                                    cout << timeIsUp;
                                    dormir(2);
                                    cleanToShow();
                                    movements--;
                                    return true;
                                }
                                else if (count == posibles)
                                {
                                    cout << penalty;
                                    dormir(2);
                                    T[i][j] = blank;
                                    blacks--;
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