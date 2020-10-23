#include "tagsWhite.h"

// note: sistema de guardado

// guardae y empatar
void Table::tieAndSave()
{
    cleanToShow();
    int opc;
    string opciones;
    if (!multiplayer)
    {
        opciones = "\ncontinuar(1) - Empate Manual(2) - guardar partida(3): ";
    }
    else
    {
        opciones = "\ncontinuar(1) - Empate manual(2): ";
    }

    opc = validateANumber(opciones, configureError);
    switch (opc)
    {
    case 1:
        break;
    case 2:
        tiee = true;
        break;
    case 3:
        if (!multiplayer)
        {
            save();
            cleanToShowMenu();
        }
        else
        {
            cout << "VALOR INCORRECTO\n";
            tieAndSave();
            sleep(2);
        }
        break;

    default:
        cout << "VALOR INCORRECTO\n";
        tieAndSave();
        sleep(2);
        break;
    }
}

// guardar
void Table::save()
{
    // esta bandera se le envia al metodo restoreSave para saber que se esta llamando para sobreescribir datos!
    bool bandToRestore = true;
    if (!validateSave(playerName))
    {
        //     nick     cpu
        string mytags = playerName, yourtags = cpu;

        // tiempo total, tiempo inicial, tiempo final, timepo de movimiento, cantidad de movimientos y el restante de cada ficha
        int timeRemaining = absoluteValue((int)timeOf - (int)t1), tmovement = timeToMovement, canMovem = movements;
        int remainingBlack = blacks, remainigWhites = whites;
        //  relleno3
        string vacia3 = "vacia3";

        // objetos de lectura
        wri.open("guardado.txt", ios::out | ios::app);

        if (wri.is_open())
        {
            wri << mytags << " " << yourtags << " " << timeRemaining << " " << tmovement << " " << canMovem << "  " << remainingBlack << " " << remainigWhites << " " << vacia3 << endl;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    wri << T[i][j] << " ";
                    cout << T[i][j] << " ";
                }
                cout << endl;
                wri << endl;
            }
            wri.close();
            cout << "La partida esta a salvo ;D!\n";
            sleep(2);
            cleanToShowMenu();
        }
        else
        {
            cout << "el archivo no se abrio correctamente... ! \n";
            sleep(2);
        }
        return;
    }
    else
    {
        int opc;
        // sobreescribir
        cout << "Ya existe un registro con ese nickname\n";
        string numero;
        bool isvalidate = false;
        while (!isvalidate && (numero != "0" || numero != "1"))
        {
            try
            {
                cout << "Desea sobreescribir la partida(0/1): ";
                cin >> numero;
                isvalidate = ValidateData(numero);
                if (!isvalidate)
                    throw numero;
            }
            catch (string e)
            {
                cout << "el valor " << e << " no es valido amiguito" << endl;
                sleep(2);
            }
        }
        if (opc)
        {
            restoreSave(playerName, bandToRestore);
            cleanToShowMenu();
        }
        cout << "muy bien! continuamos..." << endl;
        sleep(1);
    }
}

// cargar la partida en el tablero
bool Table::validateSave(string nick)
{
    // variables de recorrido
    string mytags, yourtags;
    int timeRemaining, tmovement, canMovem;
    int remainingBlacks, RemainingWhite;
    string vacia3;
    // variables de relleno
    string value1, value2, value3;
    // objeto de manipulacion de archivos
    rea.open("guardado.txt", ios::in);

    rea >> mytags;
    while (!rea.eof())
    {
        if (mytags == nick)
        {
            rea.close();
            return true;
        }

        rea >> yourtags >> timeRemaining >> tmovement >> canMovem >> remainingBlacks >> RemainingWhite >> vacia3;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                rea >> value1 >> value2 >> value3;
            }
        }
        rea >> mytags;
    }
    rea.close();
    return false;
}

//cargar la partida
void Table::chargingSave()
{
    bool notRegister = seeSaveGame();
    if (!notRegister)
    {
        sleep(2);
        cleanToShowMenu();
    }

    string nick;
    cout << "\n INSERTE EL NICKNAME (0 para volver al menu): (u.u) -> ";
    cin >> nick;

    // volver al menu
    if (nick == "0")
    {
        cleanToShowMenu();
    }

    bool band = false; // para ver si se encontro
    // variables de recorrido
    string mytags, yourtags;
    int timeRemaining, tmovement, canMovem;
    int remainingBlacks, RemainingWhite;
    string vacia3;
    // variables de relleno
    string value1, value2, value3;
    // objeto de manipulacion de archivos
    ifstream rea("guardado.txt", ios::in);

    rea >> mytags;
    while (!rea.eof())
    {
        rea >> yourtags >> timeRemaining >> tmovement >> canMovem >> remainingBlacks >> RemainingWhite >> vacia3;

        // si es mi partida la cargo
        if (mytags == nick)
        {
            // indica si se cargo correctamente la partida
            band = true;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    rea >> value1 >> value2 >> value3;
                    T[i][j] = value1 + " " + value2 + " " + value3;
                }
            }
            // definiendo el nombre
            playerName = mytags;
            // las fichas del CPU
            cpu = yourtags;
            // el tiempo restante en segundos
            timeOf = timeRemaining;
            // tiempo de movimiento
            timeToMovement = tmovement;
            // cantidad restante de movimientos
            movements = canMovem;
            // cantidad de negras restantes
            blacks = remainingBlacks;
            // blancas restantes
            whites = RemainingWhite;
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    rea >> value1 >> value2 >> value3;
                }
            }
        }
        rea >> mytags;
    }
    rea.close();
    if (band)
    {
        cout << "La partida esta cargada U.U\n";
        playChargin();
    }
    else
    {
        cout << "Ese nickname no existe u.u" << endl;
        sleep(2);
    }
}

// ver partidas guardadas
bool Table::seeSaveGame()
{
    system("clear");
    cout << "\nLISTA DE PARTIDAS GUARDADAS 1 POR 1\n";
    // variables de recorrido
    string mytags, yourtags;
    int timeRemaining, tmovement, canMovem;
    int remainingBlacks, RemainingWhite;
    string vacia3;
    // variables de relleno
    string value1, value2, value3;
    // objeto de manipulacion de archivos
    rea.open("guardado.txt", ios::in);

    //	lectura adelantada
    rea >> mytags;
    if (rea.eof())
    {
        cout << "No hay registros!\n";
        rea.close();
        return false;
    }

    while (!rea.eof())
    {
        rea >> yourtags >> timeRemaining >> tmovement >> canMovem >> remainingBlacks >> RemainingWhite >> vacia3;
        cout << "/-/ Nickname; " << mytags << endl;
        cout << "/-/ Tiempo restante de juego en segundos: " << timeRemaining << endl;
        cout << "/-/ Movimientos restantes: " << canMovem << endl;
        cout << "/-/ fichas negras restantes: " << remainingBlacks << endl;
        cout << "/-/ fichas blancas restantes: " << RemainingWhite << endl;
        cout << endl;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                rea >> value1 >> value2 >> value3;
                T[i][j] = value1 + " " + value2 + " " + value3;
                cout << T[i][j] << " ";
            }
            cout << endl;
        }

        rea >> mytags;
    }
    rea.close();
    return true;
}

// jugar la partida cargada
void Table::playChargin()
{
    bool tagBlack = true, tagWhite = true;

    tiee = false;
    t0 = time(NULL);
    // el juego continua mientras:
    // puedan moverse fichas, no se acabe el tiempo, niguna ficha llegue a cero, pueda mover el otro player
    while (ICanFollow() && t1 < timeOf && blacks > 0 && whites > 0 && movements > 0 && !tiee && tagWhite && tagBlack)
    {
        // si antes de su turno el jugador no puede mover, perdera al finalizar la ronda.
        tagWhite = canMoveWhite();
        whiteTurn();
        // si antes de su turno el jugador no puede mover, perdera al finalizar la ronda.
        tagBlack = canMoveBlack();
        blackTurn();
        // fin de la ronda, empate, guardar o continuar!
        tieAndSave();

        t1 = time(NULL) - t0;
    }
    endOfGame();
}

// restablecer un juego guardado
void Table::restoreSave(string nick, bool band)
{
    // mirar los registros devulve false si no existen registros, de sera asi salimos de inmediato
    bool notRegister = seeSaveGame();

    // si no se encuentran registros y no la llamo save

    if (!notRegister && !band)
    {
        sleep(2);
        cleanToShowMenu();
    }

    // si la bandera lleva true le llaman de "save"
    // al contrario en menu
    if (!band)
    {
        // volver al menu de inicion 0
        cout << "\n INSERTE EL NICKNAME (0 para volver al menu): (u.u) -> ";
        cin >> nick;

        // volver al menu
        if (nick == "0")
        {
            cleanToShowMenu();
        }
    }

    // esta bandera sirve para saber si encontro el nick
    bool bandNIck = false;

    // variables de recorrido
    string mytags, yourtags;
    int timeRemaining, tmovement, canMovem;
    int remainingBlacks, RemainingWhite;
    string value1 = "", value2 = "", value3 = "";

    // variables de relleno
    string vacia3;

    // objeto de manipulacion de archivos
    rea.open("guardado.txt", ios::in);
    wri.open("auxiliar.txt", ios::out);

    // verificamos si se abrio el archivo
    if (rea.is_open() && wri.is_open())
    {
        // lectura adelantada
        rea >> mytags;
        while (!rea.eof())
        {
            rea >> yourtags >> timeRemaining >> tmovement >> canMovem >> remainingBlacks >> RemainingWhite >> vacia3;
            // ¿es el tablero que estoy buscando?
            if (mytags == nick)
            {
                bandNIck = true;
                cout << "\n Eliminando registro anterior....\n";
                sleep(1);
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        rea >> value1 >> value2 >> value3;
                    }
                }
            }
            // si no lo es, continuo buscando
            else
            {
                wri << mytags << " " << yourtags << " " << timeRemaining << " " << tmovement << " " << canMovem << "  " << remainingBlacks << " " << RemainingWhite << " " << vacia3 << endl;
                for (int a = 0; a < 8; a++)
                {
                    for (int b = 0; b < 8; b++)
                    {
                        rea >> value1 >> value2 >> value3;
                        wri << value1 + " " + value2 + " " + value3 << " ";
                    }
                    wri << endl;
                }
            }
            // lectura adelantada
            rea >> mytags;
        }
        // cerramos antes de terminar
        wri.close();
        rea.close();
    }
    // informamos de un posible error
    else
    {
        cout << "error al encontrar el archivo..\n";
        sleep(2);
    }

    // hacemos el cambio de los archivos
    remove("guardado.txt");
    rename("auxiliar.txt", "guardado.txt");

    // ahora, si lo llamo "save" es para restablecer, asi que hacemos el cambio
    // save se envia true
    if (band)
    {
        save();
    }

    // si la bandera sigue en false, no se encontro
    if (!bandNIck)
    {
        cout << "Ese nickname no existe! u.u" << endl;
    }
}
