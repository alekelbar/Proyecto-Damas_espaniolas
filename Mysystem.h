#include "SaveSystem.h"

// NOTE: configuraciones y validaciones de juego

// muestra el tablero
void Table::toShow()
{
	cout << "\t\t\t";
	cout << data;
	cout << " *** BLANCAS restantes: " << whites;

	cout << "   		    	        NEGRAS restantes: " << blacks << " ***" << endl
		 << endl;

	string vs;
	if (!multiplayer)
	{
		vs = "CPU";
	}
	else
	{
		vs = playerName2;
	}

	cout << "                                  " << playerName << " VS " << vs << endl;
	ToHours();
	cout << endl;
	cout << "                             Tiempo Restante: " << hAux << ":" << mAux << ":" << sAux << endl
		 << endl;

	cout << "\t\t";
	cout << "           Movimientos disponibles: " << movements << endl;
	cout << "\t\t";
	cout << "     0     1     2     3     4     5     6     7 \n";
	for (int i = 0; i < 8; i++)
	{
		cout << "\t\t";
		cout << i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << " " << this->T[i][j];
		}
		cout << "\n\n";
	}
}

// corona posibles reinas. Tanto negras como blancas.
void Table::toCrown()
{
	for (int rows = 0; rows < 8; rows++)
	{
		for (int colums = 0; colums < 8; colums++)
		{

			// coronacion blanca
			if (T[rows][colums] == Black && colums == 7)
			{
				T[rows][colums] = crownB;

				// coronacion negra
			}
			if (T[rows][colums] == white && colums == 0)
			{
				T[rows][colums] = crownW;
			}
		}
	}
}

// limita el tablero de la coordenada Y
bool Table::validateLimitsY()
{
	//auxiliares
	int a = filas1, b = colums1;

	// analizando los limites superiores e inferiores
	if ((a >= 0 && a < 8) && (b >= 0 && b < 8))
	{
		return true;
	}
	return false;
}

// valida los limites de la coordenada X
bool Table::validateLimitsX()
{
	//auxiliares
	int a = filas2, b = colums2;

	// analizando los limites superiores e inferiores
	if ((a >= 0 && a < 8) && (b >= 0 && b < 8))
	{
		return true;
	}
	return false;
}

// mensaje para cuando fue un mal movimiento
void Table::MessageIsABadMovement()
{
	cout << badMovement;
}

// mensaje para cuando se sale de los limites
void Table::MessageIsOutLimits()
{
	cout << outLimits;
	cout << lossTurn;
}

// limpiar y volver a mostrar
void Table::cleanToShow()
{
	system("clear");
	toShow();
}

// mensaje para continuar
void Table::MessageToContinue()
{
	cout << "\nInserte una \"c\" para continuar (*-^) -- >";
}

// mensaje para una ficha equivocada
void Table::MessageWrongTab()
{
	cout << wrongTab << endl;
}

// pantalla de acerca de
void Table::aboutItscreen()
{
	system("clear");
	cout << endl;
	cout << "\t     ";
	cout << "           *********       Acerca de    **********" << endl;
	cout << "\t     ";
	cout << "           ***** Curso:                      *****" << endl;
	cout << "\t     ";
	cout << "           **            Programacion I         **" << endl;
	cout << "\t     ";
	cout << "           **                                   **" << endl;
	cout << "\t     ";
	cout << "           **    Estudiantes:                   **" << endl;
	cout << "\t     ";
	cout << "           **            Alexander Gutierrez    **" << endl;
	cout << "\t     ";
	cout << "           **            Dayana Gamboa          **" << endl;
	cout << "\t     ";
	cout << "           **                                   **" << endl;
	cout << "\t     ";
	cout << "           **    Ciclo II 2020                  **" << endl;
	cout << "\t     ";
	cout << "           **                                   **" << endl;
	cout << "\t     ";
	cout << "            **************************************" << endl;

	cout << endl;
	cout << "\t\t\t  " << data << endl;
	cout << "	Las damas es un juego de mesa para dos contrincantes. El juego consiste" << endl;
	cout << "en mover las piezas en diagonal a través de los cuadros negros (o blancos en" << endl;
	cout << "algunas variantes) de un tablero de 64 o 100 cuadros. Si alguien no mata(captura)" << endl;
	cout << "al jugar contrario perderá esa pieza a la intención obligatoria de capturar (comer)" << endl;
	cout << "las piezas del jugador contrario, pasando por encima de dichas piezas." << endl
		 << endl;

	cout << "\t\t\t  ";
	cout << "Como Jugar Esta Version Del Juego\n\n";
	cout << "	De manera estandar nuestro juego demora 10 minutos por partida y tiene 20" << endl;
	cout << "segundos para pensar su movimiento. Puede configurar los parametros basicos en las " << endl;
	cout << "opciones del menu. La opcion (2) le permite modificar el tiempo de juego, la " << endl;
	cout << "cantidad de movimientos por partida, entre otros. Ademas de otras configuraciones" << endl;
	cout << "mas significativas como el modo con reglas o el modo multijugador. \n";

	cout << endl;
	sleep(2);
	system("clear");

	cout << "\t\t\t\t  ";
	cout << "Movilidad Basica\n\n";
	cout << "	Siendo un tablero de 8x8 espacios cada ficha tiene un par de ejes coordenados." << endl;
	cout << "Esto significa que para indicar la posicion de una ficha se debe señalar mediante" << endl;
	cout << "un par ordenado. Por ejemplo, observemos la siguiente ficha y su ubicacion en el tablero" << endl;

	cout << endl
		 << endl;
	cout << "   0   1\n";
	cout << "0 [B] ( )\n";
	cout << "1 ( ) ( )\n";
	cout << endl;
	cout << "	El espacio que contiene la ficha 'B' se localiza mediante el eje coordenada como" << endl;
	cout << "<0 0>. a diferencia de las demas posiciones que se encuentran vacias. Dichas posiciones" << endl;
	cout << "se localizan facilmente por las indicaciones coordenadas. Si quisieramos mover la ficha " << endl;
	cout << "a la diagonal inferior derecha(siendo que es un movimiento valido) diriamos entonces " << endl;
	cout << "que la ficha <0 0> se movere a la diagonal <1 1> siendo el primer '1' la coordenada " << endl;
	cout << "horizontal de la ficha y el segundo '1' la coordenada vertical." << endl;
	cout << endl
		 << endl;
	sleep(2);
	system("clear");

	cout << "\t\t\t";
	cout << "Modo Multijugar y Modo de un Solo Jugador" << endl
		 << endl;
	cout << "	Puede jugar contra una CPU algo ordiniaria o turnarse con un conocido." << endl;
	cout << "Por defecto el juego esta en <single player>, sin embargo, es posible jugar en un modo" << endl;
	cout << "de dos jugadores, accediendo a las configuraciones del juego y activando el modo. " << endl;
	cout << "Dentro de este juego casi cualquier confirmacion y/o negacion se realiza con valores " << endl;
	cout << "booleanos. Definiremos un valor verdadero como cualquier valor distinto de cero, de" << endl;
	cout << "preferencia (1) y como una negacion al (0). Eso quiere decir que si usted es consultado" << endl;
	cout << "y su respuesta es un valor distinto de cero, usted esta respondiendo afirmativamente.\n";

	cout << endl
		 << endl;
	sleep(2);
	system("clear");

	cout << "\t\t\t ";
	cout << "Modo de Dificultad con Reglas\n\n";
	cout << "	Este modo agrega un sistema automatico, y ciertas obligacion del jugador." << endl;
	cout << "En el modo con reglas, o <hardmode> es completamente obligatorio comer." << endl;
	cout << "Eso implica una reglamentacion basica que te obliga a realizar ciertos " << endl;
	cout << "movimientos, o en caso contrario sera penalizado perdiendo la ficha en cuestion." << endl;
	cout << "los fundamentos para obligar estos movimientos son la cantidad de comidad y" << endl;
	cout << "su calidad. ¿que sucede si existe la misma cantidad? En ese caso, sera su decicion." << endl;

	cout << endl
		 << endl;
	sleep(2);
	cleanToShowMenu();
}

// existe una ficha en medio
void Table::MessageTabInTheMiddle()
{
	cout << tabinthemiddle << endl;
}

// mensaje cuando hay un obstaculo
void Table::MessageToBlocking(int a, int b)
{
	cout << blocking << a << "," << b << endl;
}

// verificar si existe posibilidad de movimiento
bool Table::ICanFollow()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// note: negras revisadas
			// revisamos las negras
			if (T[i][j] == Black)
			{
				// diagonal inferior derecha
				if (i + 1 < 8 && j + 1 < 8)
				{
					if ((T[i + 1][j + 1] == blank) || ((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
					{
						// cout << "en1: " << i << j << endl;
						// cout << "negras\n";
						return true;
					}
				}
				// diagonal superior derecha
				else if (i - 1 >= 0 && j + 1 < 8)
				{
					if ((T[i - 1][j + 1] == blank) || ((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
					{
						// cout << "en2: " << i << j << endl;
						// cout << "negras\n";
						return true;
					}
				}
			}
			// note: blancas revisadas
			// revisamos las blancas
			if (T[i][j] == white)
			{
				// diagonal inferior izquierda
				if (i + 1 < 8 && j - 1 >= 0)
				{
					if ((T[i + 1][j - 1] == blank) || ((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
					{
						// cout << "en1: " << i << j << endl;
						// cout << "blancas\n";
						return true;
					}
				}

				//diagonal superior derecha
				else if (i - 1 >= 0 && j - 1 >= 0)
				{
					if ((T[i - 1][j - 1] == blank) || ((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
					{
						// cout << "en2: " << i << j << endl;
						// cout << "blancas\n";
						return true;
					}
				}
			}
			// revision de reinas negras
			if (T[i][j] == crownB)
			{
				int c = 1;
				if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRsr\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRir\n";
					return true;
				}
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
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRsi\n";
					return true;
				}
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
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRii\n";
					return true;
				}
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
						// 	cout << "en: " << i << j << endl;
						// 	cout << "negrasRii\n";
						return true;
					}
					c++;
				}
			}
			// revision de reinas blancas
			if (T[i][j] == crownW)
			{
				int c = 1;
				// se puede mover
				if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRsr\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRir\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRsi\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRii\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
			}
		}
	}
	return false;
}

// cambia el tiempo total a segundos
void Table::ToSeconds()
{
	int h = 0, m = 0, s = 0;
	h = hours * 3600;
	m = minutes * 60;
	s += seconds + h + m;
	timeOf = s;
}

// transforma segundos a horas, minutos y segundos
void Table::ToHours()
{
	int totalSec = absoluteValue((int)timeOf - (int)t1);
	hAux = totalSec / 3600; // horas totales
	totalSec %= 3600;		// dwriuento las horas

	mAux = totalSec / 60; // minutos totales
	sAux = totalSec % 60; // dwriuento los minutos y ajusto los segundos totales
}

// pantalla de configuracion
void Table::screenConfig()
{
	string reglas = "MODO SIN REGLAS", multi = "OFF";
	if (hardmode)
	{
		reglas = "MODO CON REGLAS.";
	}
	if (multiplayer)
	{
		multi = "ON";
	}

	// pantalla de configuracion impresa
	int h = hours, m = minutes, s = seconds;

	cout << endl;
	cout << "\t\t";
	cout << " 		      Cronometro         \n";
	cout << "\t\t";
	cout << " 	 ______________________________________\n";
	cout << "\t\t";
	cout << "	    HORAS: " << h << " MINUTOS: " << m << " SEGUNDOS: " << s << "\n";
	cout << "\t\t";
	cout << "         ______________________________________\n";
	cout << "\t\t";
	cout << "      Cantidad maxima de movimientos permitidos: " << movements << " \n\n";
	cout << "\t\t";
	cout << "       Tiempo permitido por movimiento: " << timeToMovement << "\n\n";
	cout << "\t\t";
	cout << "       modo de dificultad activa: " << reglas << "\n\n";
	cout << "\t\t";
	cout << "       modo de multijugador: " << multi;
	cout << endl;
	cout << endl;
	sleep(2);
	cleanToShowMenu();
}

// seleccion de ficha
void Table::tagSelecction()
{
	if (multiplayer)
	{
		cout << endl;
		cout << "\t\t\t";
		cout << "## El jugador uno juega con negras ##" << endl
			 << endl;
		cout << "\t\t\t";
		while (playerName.length() != 4)
		{
			cout << "\n\t\t\t";
			cout << "$ use un nickname de 4 caracteres $" << endl;
			cout << "\t\t\t";
			cout << "Jugador uno, ¿cual es su nombre? --> ";
			cin >> playerName;
		}

		while (playerName2.length() != 4)
		{
			cout << "\n\t\t\t";
			cout << "$ use un nickname de 4 caracteres $" << endl;
			cout << "\t\t\t";
			cout << "Jugador dos, ¿cual es su nombre? --> ";
			cin >> playerName2;
		}
	}
	else
	{
		//restore
		playerName = "";
		playerName2 = "";
		cpu = "";

		int aleatorio = 0;
		while (playerName.length() != 4)
		{
			cout << "\n\t\t\t";
			cout << "$ use un nickname de 4 caracteres $" << endl;
			cout << "\t\t\t";
			cout << "Jugador uno, ¿cual es su nombre? --> ";
			cin >> playerName;
		}

		srand(time(0));
		aleatorio = 1 + rand() % (3 - 1);
		if (aleatorio == 1)
		{
			cpu = "negras";
		}

		else
		{
			cpu = "blancas";
		}

		if (cpu == "blancas")
		{
			cout << "\t\t\t";
			cout << " USTED JUEGA CON NEGRAS!! \n";
		}
		else
		{
			cout << "\t\t\t";
			cout << "USTED JUEGA CON BLANCAS!! \n";
		}
	}
}

// menu de seleccion
void Table::Menu()
{
	string nick;
	system("clear");
	while (true)
	{
		string numero;
		bool isvalidate = false; // parto de que no es un numero valido
		int opc1;
		cout << "\t\t\t  ";
		cout << data;
		cout << "\t\t\t";
		cout << "********** MENU DE SELECCION ************" << endl;
		cout << "\t\t\t";
		cout << "********* Jugar(1);            **********" << endl;
		cout << "\t\t\t";
		cout << "*******   Cargar partida(2)       *******" << endl;
		cout << "\t\t\t";
		cout << "*****     Ver configuraciones(3)    *****" << endl;
		cout << "\t\t\t";
		cout << "****      Configuraciones(4)         ****" << endl;
		cout << "\t\t\t";
		cout << "***       borrar Partida(5)           ***" << endl;
		cout << "\t\t\t";
		cout << "**        Acerca de(6)                 **" << endl;
		cout << "\t\t\t";
		cout << "*         Salir(7)                      *" << endl;
		cout << "\t\t\t";

		while (!isvalidate)
		{
			try
			{
				cout << "OPCION --> ";
				cin >> numero;
				isvalidate = ValidateData(numero);
				if (!isvalidate)
				{
					throw numero;
				}
			}
			catch (string e)
			{
				Menu();
			}
		}
		// lo pasamos a un numero
		opc1 = atoi(numero.c_str());

		switch (opc1)
		{
		case 1:
			play();
			break;
		case 2:
			chargingSave();
			break;
		case 3:
			screenConfig();
			break;
		case 4:
			configure();
			break;
		case 5:
			restoreSave(nick, false);
			break;
		case 6:
			aboutItscreen();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "Opcion no disponible." << endl;
			sleep(2);
		}
		cleanToShowMenu();
	}
}

// limpiar y mostrar el menu
void Table::cleanToShowMenu()
{
	system("clear");
	restore();
	Menu();
}

// metodo para configurar
void Table::configure()
{
	bool validateNum = false;
	cout << "\t\t\t";
	cout << "## Parametros de juego ##" << endl;
	cout << "\t\t\t";
	cout << "TIEMPO DE PARTIDA: \n";

	string numero; // para probar
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "HORAS: ";
			cin >> numero;
			validateNum = ValidateData(numero);
			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	this->hours = atoi(numero.c_str());
	cout << endl;

	// segunda validacion!
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "MINUTOS: ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	minutes = atoi(numero.c_str());
	cout << endl;

	// tercera validacion
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "SEGUNDOS: ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	seconds = atoi(numero.c_str());
	cout << endl;

	// tercera validacion
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "Cantidad maxima de movimientos permitidos: ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	movements = atoi(numero.c_str());
	cout << endl;

	// cuarta validacion
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";

			cout << "Tiempo permitido por movimiento: ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	timeToMovement = atoi(numero.c_str());
	cout << endl;

	// quinta validacion
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "Modo de dificultad activa(1/0): ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	hardmode = atoi(numero.c_str());
	cout << endl;

	// sexta validacion
	validateNum = false;
	while (!validateNum)
	{
		try
		{
			cout << "\t\t\t";
			cout << "Modo de multijugador(1/0): ";
			cin >> numero;
			validateNum = ValidateData(numero);

			if (!validateNum)
			{
				throw numero;
			}
		}
		catch (string e)
		{
			cout << "\t\t\t";
			cout << configureError;
		}
	}
	multiplayer = atoi(numero.c_str());
	cout << endl;
	ToSeconds();
	sleep(2);
	cleanToShowMenu();
}

// metodo de validacion de datos embebido
int Table::validateANumber(string message, string error)
{
	string numero;
	bool isvalidate = false;
	while (!isvalidate)
	{
		try
		{
			cout << message;
			cin >> numero;
			cin.clear();
			isvalidate = ValidateData(numero);
			if (!isvalidate)
				throw numero;
		}
		catch (string e)
		{
			cout << error;
			sleep(2);
		}
	}
	return atoi(numero.c_str());
}

// movimiento automatico generado por el cpu
bool Table::cpuBlackMovement()
{
	srand(time(0));
	int num = rand() % (2);

	if (num)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				// NOTE: listo
				if (T[i][j] == Black)
				{
					// diagonal inferior derecha
					if (i + 1 < 8 && j + 1 < 8)
					{
						if ((T[i + 1][j + 1] == blank) || ((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
						{
							// cout << "en1: " << i << j << endl;
							// cout << "negras\n";
							if (((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i + 2;
								colums2 = j + 2;
								// cout << "1 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << " , " << colums2 << endl;
								// sleep(2);
								blackMovement();
								return 1;
							}
							else
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i + 1;
								colums2 = j + 1;
								// cout << "2 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// cout << "los iteradores son: " << i << "," << j << endl;
								// pause();
								blackMovement();
								return 1;
							}

							// return true;
						}
					}
					// NOTE: listo
					// diagonal superior derecha
					else if (i - 1 >= 0 && j + 1 < 8)
					{
						if ((T[i - 1][j + 1] == blank) || ((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
						{
							if (((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i - 2;
								colums2 = j + 2;
								// cout << "3 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								blackMovement();
								return 1;
							}
							else
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i - 1;
								colums2 = j + 1;
								// cout << "4 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								blackMovement();
								return 1;
							}

							// cout << "en2: " << i << j << endl;
							// cout << "negras\n";
						}
					}
				}
				// note: listo
				// revision de reinas negras
				if (T[i][j] == crownB)
				{
					int c = 1;
					if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsr\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde me voy
						filas2 = i - c;
						colums2 = j + c;
						// cout << "5 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde me voy a mover
							filas2 = i - (c + 1);
							colums2 = j + (c + 1);
							// cout << "6 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note: listo
					c = 1;
					// se puede mover
					if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						//donde me voy a mover
						filas2 = i + c;
						colums2 = j + c;
						// cout << "7 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// cout << "en: " << i << j << endl;
							// cout << "negrasRir\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// ficha donde me voy a mover
							filas2 = i + (c + 1);
							colums2 = j + (c + 1);
							// cout << "8 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i - c;
						colums2 = j - c;
						// cout << "9 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// cout << "en: " << i << j << endl;
							// cout << "negrasRsi\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i - (c + 1);
							colums2 = j - (c + 1);
							// cout << "10 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRii\n";
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i + c;
						colums2 = j - c;
						// cout << "11 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// 	cout << "en: " << i << j << endl;
							// 	cout << "negrasRii\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i + (c + 1);
							colums2 = j - (c + 1);
							// cout << "12 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 8; j > 0; j--)
			{
				// NOTE: listo
				if (T[i][j] == Black)
				{
					// diagonal inferior derecha
					if (i + 1 < 8 && j + 1 < 8)
					{
						if ((T[i + 1][j + 1] == blank) || ((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
						{
							// cout << "en1: " << i << j << endl;
							// cout << "negras\n";
							if (((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i + 2;
								colums2 = j + 2;
								// cout << "1 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << " , " << colums2 << endl;
								// pause();
								blackMovement();
								return 1;
							}
							else
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i + 1;
								colums2 = j + 1;
								// cout << "2 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// cout << "los iteradores son: " << i << "," << j << endl;
								sleep(2);
								blackMovement();
								return 1;
							}

							// return true;
						}
					}
					// NOTE: listo
					// diagonal superior derecha
					else if (i - 1 >= 0 && j + 1 < 8)
					{
						if ((T[i - 1][j + 1] == blank) || ((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
						{
							if (((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i - 2;
								colums2 = j + 2;
								// cout << "3 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								blackMovement();
								return 1;
							}
							else
							{
								// de donde parto
								filas1 = i;
								colums1 = j;
								//a donde voy
								filas2 = i - 1;
								colums2 = j + 1;
								// cout << "4 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								blackMovement();
								return 1;
							}

							// cout << "en2: " << i << j << endl;
							// cout << "negras\n";
						}
					}
				}
				// note: listo
				// revision de reinas negras
				if (T[i][j] == crownB)
				{
					int c = 1;
					if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsr\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde me voy
						filas2 = i - c;
						colums2 = j + c;
						// cout << "5 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde me voy a mover
							filas2 = i - (c + 1);
							colums2 = j + (c + 1);
							// cout << "6 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note: listo
					c = 1;
					// se puede mover
					if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						//donde me voy a mover
						filas2 = i + c;
						colums2 = j + c;
						// cout << "7 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// cout << "en: " << i << j << endl;
							// cout << "negrasRir\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// ficha donde me voy a mover
							filas2 = i + (c + 1);
							colums2 = j + (c + 1);
							// cout << "8 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i - c;
						colums2 = j - c;
						// cout << "9 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// cout << "en: " << i << j << endl;
							// cout << "negrasRsi\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i - (c + 1);
							colums2 = j - (c + 1);
							// cout << "10 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRii\n";
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i + c;
						colums2 = j - c;
						// cout << "11 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownBMovement();
						return 1;
					}
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
							// 	cout << "en: " << i << j << endl;
							// 	cout << "negrasRii\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i + (c + 1);
							colums2 = j - (c + 1);
							// cout << "12 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownBMovement();
							return 1;
						}
						c++;
					}
				}
			}
		}
	}

	return false;
}

// genera los turnos CPU blancos
bool Table::cpuWhiteMovement()
{
	srand(time(0));
	int num = rand() % (2);

	if (num)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				// NOTE: listo
				if (T[i][j] == white)
				{
					// diagonal inferior izquierda
					if (i + 1 < 8 && j - 1 >= 0)
					{
						if ((T[i + 1][j - 1] == blank) || ((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
						{
							// cout << "en1: " << i << j << endl;
							// cout << "blancas\n";
							if (((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								//donde voy
								filas2 = i + 2;
								colums2 = j - 2;
								// cout << "1 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
							else
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde voy
								filas2 = i + 1;
								colums2 = j - 1;
								// cout << "2 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
						}
					}

					//diagonal superior derecha
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if ((T[i - 1][j - 1] == blank) || ((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
						{
							// cout << "en2: " << i << j << endl;
							// cout << "blancas\n";
							if (((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde yo voy
								filas2 = i - 2;
								colums2 = j - 2;
								// cout << "3 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
							else
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde yo voy
								filas2 = i - 1;
								colums2 = j - 1;
								// cout << "4 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
						}
					}
				}
				// note: listo
				// revision de reinas negras
				if (T[i][j] == crownW)
				{
					int c = 1;
					if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsr\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde me voy
						filas2 = i - c;
						colums2 = j + c;
						// cout << "5 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
					// diagonal superior derecha
					for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
					{
						// se puede mover
						// hasta ahi no se puede mover
						if (T[i - c][j + c] == white || T[i - c][j + c] == crownW)
						{
							break;
						}
						if ((T[i - c][j + c] == Black || T[i - c][j + c] == crownB) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
						{
							// cout << "en: " << i << j << endl;
							// cout << "negrasRsr\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde me voy a mover
							filas2 = i - (c + 1);
							colums2 = j + (c + 1);
							// cout << "6 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note: listo
					c = 1;
					// se puede mover
					if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						//donde me voy a mover
						filas2 = i + c;
						colums2 = j + c;
						// cout << "7 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// cout << "negrasRir\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// ficha donde me voy a mover
							filas2 = i + (c + 1);
							colums2 = j + (c + 1);
							// cout << "8 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i - c;
						colums2 = j - c;
						// cout << "9 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// cout << "negrasRsi\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i - (c + 1);
							colums2 = j - (c + 1);
							// cout << "10 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRii\n";
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i + c;
						colums2 = j - c;
						// cout << "11 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// 	cout << "en: " << i << j << endl;
							// 	cout << "negrasRii\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i + (c + 1);
							colums2 = j - (c + 1);
							// cout << "12 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 8; j > 0; j--)
			{
				// NOTE: listo
				if (T[i][j] == white)
				{
					// diagonal inferior izquierda
					if (i + 1 < 8 && j - 1 >= 0)
					{
						if ((T[i + 1][j - 1] == blank) || ((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
						{
							// cout << "en1: " << i << j << endl;
							// cout << "blancas\n";
							if (((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								//donde voy
								filas2 = i + 2;
								colums2 = j - 2;
								// cout << "1 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
							else
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde voy
								filas2 = i + 1;
								colums2 = j - 1;
								// cout << "2 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
						}
					}

					//diagonal superior derecha
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if ((T[i - 1][j - 1] == blank) || ((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
						{
							// cout << "en2: " << i << j << endl;
							// cout << "blancas\n";
							if (((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde yo voy
								filas2 = i - 2;
								colums2 = j - 2;
								// cout << "3 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
							else
							{
								// mi ficha
								filas1 = i;
								colums1 = j;
								// donde yo voy
								filas2 = i - 1;
								colums2 = j - 1;
								// cout << "4 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
								// pause();
								whiteMovement();
								return 1;
							}
						}
					}
				}
				// note: listo
				// revision de reinas negras
				if (T[i][j] == crownW)
				{
					int c = 1;
					if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsr\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde me voy
						filas2 = i - c;
						colums2 = j + c;
						// cout << "5 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
					// diagonal superior derecha
					for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j + c < 8; a++)
					{
						// se puede mover
						// hasta ahi no se puede mover
						if (T[i - c][j + c] == white || T[i - c][j + c] == crownW)
						{
							break;
						}
						if ((T[i - c][j + c] == Black || T[i - c][j + c] == crownB) && T[i - (c + 1)][j + (c + 1)] == blank && i - (c + 1) >= 0 && j + (c + 1) < 8)
						{
							// cout << "en: " << i << j << endl;
							// cout << "negrasRsr\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde me voy a mover
							filas2 = i - (c + 1);
							colums2 = j + (c + 1);
							// cout << "6 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note: listo
					c = 1;
					// se puede mover
					if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						//donde me voy a mover
						filas2 = i + c;
						colums2 = j + c;
						// cout << "7 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// cout << "negrasRir\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// ficha donde me voy a mover
							filas2 = i + (c + 1);
							colums2 = j + (c + 1);
							// cout << "8 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						// mi ficha
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i - c;
						colums2 = j - c;
						// cout << "9 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// cout << "negrasRsi\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i - (c + 1);
							colums2 = j - (c + 1);
							// cout << "10 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
					// note listo
					c = 1;
					// se puede mover
					if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
					{
						// cout << "en: " << i << j << endl;
						// cout << "negrasRii\n";
						filas1 = i;
						colums1 = j;
						// donde voy
						filas2 = i + c;
						colums2 = j - c;
						// cout << "11 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
						// pause();
						crownWMovement();
						return 1;
					}
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
							// 	cout << "en: " << i << j << endl;
							// 	cout << "negrasRii\n";
							// mi ficha
							filas1 = i;
							colums1 = j;
							// donde voy
							filas2 = i + (c + 1);
							colums2 = j - (c + 1);
							// cout << "12 se seleciono: " << filas1 << "," << colums1 << " hacia " << filas2 << ", " << colums2 << endl;
							// pause();
							crownWMovement();
							return 1;
						}
						c++;
					}
				}
			}
		}
	}
	return false;
}

// mensaje para cuando mueve el  CPU
void Table::MessageToCpuWIsMovement()
{
	if (cpu == "blancas")
	{
		cout << cpuMovement << filas1 << "," << colums1 << " Hacia --> " << filas2 << "," << colums2 << endl;
		sleep(2);
	}
}

// mensaje cuando el cpu negro mueva
void Table::MessageToCpuBIsMovement()
{
	if (cpu == "negras")
	{
		cout << cpuMovement << filas1 << "," << colums1 << " Hacia --> " << filas2 << "," << colums2 << endl;
		sleep(2);
	}
}

// valida los datos
bool Table::ValidateData(string numero)
{
	// la cadena inicia en cero
	int inicio = 0;

	// que no sea una cadena vacia
	if (numero.length() == 0)
	{
		return 0;
	}

	// verificamos el signo
	if (numero[0] == '+' || numero[0] == '-')
	{
		// no es solo un signo
		inicio = 1;
		// si es solo una signo vacio
		if (numero.length() == 1)
		{
			return 0;
		}
	}
	// ahora vamos a ver si todos los valores son digitos
	for (int i = inicio; i < numero.length(); i++)
	{
		// si no es un numero entre 0-9
		if (!isdigit(numero[i]))
		{
			return 0;
		}
	}
	return 1;
}

// ¿pueden mover las ficcha negras
bool Table::canMoveBlack()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (T[i][j] == Black)
			{
				// diagonal inferior derecha
				if (i + 1 < 8 && j + 1 < 8)
				{
					if ((T[i + 1][j + 1] == blank) || ((i + 2 < 8 && j + 2 < 8 && T[i + 1][j + 1] == white || T[i + 1][j + 1] == crownW) && T[i + 2][j + 2] == blank))
					{
						// cout << "en1: " << i << j << endl;
						// cout << "negras\n";
						return true;
					}
				}
				// diagonal superior derecha
				else if (i - 1 >= 0 && j + 1 < 8)
				{
					if ((T[i - 1][j + 1] == blank) || ((i - 2 >= 0 && j + 2 < 8 && T[i - 1][j + 1] == white || T[i - 1][j + 1] == crownW) && T[i - 2][j + 2] == blank))
					{
						// cout << "en2: " << i << j << endl;
						// cout << "negras\n";
						return true;
					}
				}
			}

			// si es una reina
			if (T[i][j] == crownB)
			{
				int c = 1;
				if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRsr\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRir\n";
					return true;
				}
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
						// cout << "en: " << i << j << endl;
						// cout << "negrasRir\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRsi\n";
					return true;
				}
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
						// cout << "en: " << i << j << endl;
						// cout << "negrasRsi\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "negrasRii\n";
					return true;
				}
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
						// 	cout << "en: " << i << j << endl;
						// 	cout << "negrasRii\n";
						return true;
					}
					c++;
				}
			}
		}
	}
	return false;
}

// ¿ se pueden mover la fichas blancas?
bool Table::canMoveWhite()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// revisamos las blancas
			if (T[i][j] == white)
			{
				// diagonal inferior izquierda
				if (i + 1 < 8 && j - 1 >= 0)
				{
					if ((T[i + 1][j - 1] == blank) || ((i + 2 < 8 && j - 2 >= 0 && T[i + 1][j - 1] == Black || T[i + 1][j - 1] == crownB) && T[i + 2][j - 2] == blank))
					{
						// cout << "en1: " << i << j << endl;
						// cout << "blancas\n";
						return true;
					}
				}

				//diagonal superior derecha
				else if (i - 1 >= 0 && j - 1 >= 0)
				{
					if ((T[i - 1][j - 1] == blank) || ((i - 2 >= 0 && j - 2 >= 0 && T[i - 1][j - 1] == Black || T[i - 1][j - 1] == crownB) && T[i - 2][j - 2] == blank))
					{
						// cout << "en2: " << i << j << endl;
						// cout << "blancas\n";
						return true;
					}
				}
			}
			if (T[i][j] == crownW)
			{
				int c = 1;
				// se puede mover
				if (T[i - c][j + c] == blank && i - c >= 0 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRsr\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j + c] == blank && i + c < 8 && j + c < 8)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRir\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRsi\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
				{
					// cout << "en: " << i << j << endl;
					// cout << "blancasRii\n";
					return true;
				}
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
						return true;
					}
					c++;
				}
			}
		}
	}
	return false;
}

// fin de la partida
void Table::endOfGame()
{
	if (tiee)
	{
		cout << isATie;
		sleep(2);
	}

	else if (t1 > timeOf)
	{
		cout << timeEnd;
		if (blacks == whites)
		{
			cout << OrdinaryTie;
			sleep(2);
		}
		else if (blacks > whites)
		{
			cout << blacksWin;
			sleep(2);
		}
		else
		{
			cout << whitesWin;
			sleep(2);
		}
	}

	if (movements <= 0)
	{
		cout << noMoreMovements;
		if (blacks == whites)
		{
			cout << OrdinaryTie;
			sleep(2);
		}
		else if (blacks > whites)
		{
			cout << blacksWin;
			sleep(2);
		}
		else
		{
			cout << whitesWin;
			sleep(2);
		}
	}

	if (!ICanFollow())
	{
		cout << imposibleMove;
		if (blacks == whites)
		{
			cout << OrdinaryTie;
			sleep(2);
		}
		else if (blacks > whites)
		{
			cout << blacksWin;
			sleep(2);
		}
		else
		{
			cout << whitesWin;
			sleep(2);
		}
	}
	else if (!canMoveWhite())
	{
		cout << cantMoveWhite;
		sleep(2);
	}
	else if (!canMoveBlack())
	{
		cout << cantMoveBlack;
		sleep(2);
	}
	restore();
}

// restaura los valores del tablero luego de guardar
void Table::restore()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			T[i][j] = Aux[i][j];
		}
	}
	// tiempo restante de juego en segundos
	int timeOf = (600);

	// implementacion de cronometro
	time_t t0, t1 = 0;

	//horas default
	hours = 0;

	// minutos default
	minutes = 10;

	// segundos default
	seconds = 0;

	// cuantos movimientos pueden realizarse default
	movements = 20;

	// modo con reglas
	hardmode = true;

	// si existe un ficha chocando al movimiento debemos saberlo
	ficha = false;

	// multijugador
	multiplayer = false;

	// contador de fichas blancas
	whites = 12;

	//contador de fichas negras
	blacks = 12;

	// tiempo para moverse
	timeToMovement = 15;
}

// bucle pincipal del juego
void Table::play()
{
	bool tagBlack = true, tagWhite = true;
	tiee = false;
	tagSelecction();
	// hora de inicio
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
