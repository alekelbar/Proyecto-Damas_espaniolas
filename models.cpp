#include "Structure.h"
#include <cctype>
#include <cstdlib>


// NOTE: tareas
// TODO: (1) movimiento de reinas blancas/negras, (2) agregar el modo dificil
// con reglas.
// TODO: (3) guardado, (4) agregar el menu, (5) agregar el indicacador de fin de
// partida.
// TODO: (6) agregar el empate manual{decidido por el jugador}, (7) agregar el
// empate automatico.
// TODO: (8) implementar el menu de guardado, (9) crear la pantalla acerca de.
// TODO: (10) crear el menu de configurarion, (11) agregar un timer.
// TODO: (12) agregar mensaje personalizados de error, (13) agregar robustes.
// TODO: (14) agregar un inteligencia ramdon, (15) agregar un random para los
// colores.
// TODO: (16) aplicar optimizaciones, (17) actualizar las tareas...

// NOTE: juego con las negras

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
		T[filas2][colums2] == blank)
	{
		canEatWhites();
	}

	// si las condiciones logicas no se dan, el movimiento debe ser deslegitimado sin ninguna transformacion.
	else
	{
		cout << badMovement;
		getchar();
	}
	return true;
}

// administra el turno de fichas negras.
void Table::blackTurn()
{
	// para saber que datos mostrar
	isWhite = false; // cambia de turno

	// verificar si es posible coronar
	toCrown();

	// mostrar los datos
	cleanToShow();

	// recoleccion de datos.
	cout << myBlack;
	cin >> filas1 >> colums1;

	// validacion de limites del tablero

	// si los limtes son validos
	if (validateLimitsY())
	{
		aux1 = T[filas1][colums1];
		T[filas1][colums1] = "[i'm]";
	}
	// si nos son validos
	else
	{
		MessageIsOutLimits();
		pause();
		return;
	}

	// limpiar y mostrar
	cleanToShow();

	// recoleccion de datos
	cout << objetive;
	cin >> filas2 >> colums2;

	// validacion de los limites del tablero
	if (validateLimitsX())
	{
		// en caso de que pida moverme donde estoy
		if (filas1 == filas2 && colums1 == colums2)
		{
			T[filas1][colums1] = aux1;
			MessageIsABadMovement();
			pause();
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
		pause();
		return;
	}

	// limpiar y mostrar
	cleanToShow();

	//continuar
	MessageToContinue();
	pause();
	cleanToShow();

	// usamos las tags temporales
	// se usaron para intercambiar a "iam" y "igo"
	T[filas1][colums1] = aux1;
	T[filas2][colums2] = aux2;

	// ¿mueve la correcta?

	// fichas normales
	if (T[filas1][colums1] == Black)
	{
		blackMovement();
	}

	//fichas coronadas
	else if (T[filas1][colums1] == crownB)
	{
		crownBMovement();
	}

	// ficha equivocada
	else
	{
		MessageWrongTab();
		pause();
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
		T[filas2][colums2] == blank)
	{ // formas de movimiento

		cronwCanEatWhites();
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
				band = true;
				whites++;
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
				band = true;
				whites++;
			}
		}

		// se consulta la labor de la bandera, ¿existio alguna transformacion?
		if (!band)
		{
			cout << badMovement;
			cin.ignore(256, '\n');
			getchar();
			return;
		}

		// Esencialmente, en caso de ser posible seguir "comiendo" el jugador debe realizar una accion
		// en dependencia de su modo de juego, el siguiente metodo realiza tal labor.
		AutomaticPlayBlack(band);
	}

	// anteriormente hemos verificado candidatos de existencia, es decir, ¿estoy moviendo la ficha correcta?
	// ¿estoy moviendo me al lugar correcto? siendo asi, podemos afirmar que un movimiento de un unico
	// no necesita mas que las transformaciones de la matriz.
	else
	{
		T[filas2][colums2] = Black;
		T[filas1][colums1] = blank;
	}
}

// administra el automatico de las negras
void Table::AutomaticPlayBlack(bool band)

// @Perspectiva logica basica: Desde una perspectiva logica, superficial el analisis de la continuidad del turno
// solo depende de que sea posible comer otra ficha. En dependencia de la ficha en cuestion se analiza
// si las tranformaciones son en una direccion del tablero, o en otra.

{
	//en caso de que la diagonal superior derecha presente una ficha comestible, o en caso
	// de que la segunda diagonal superior derecha, partiendo de mi propia ficha este vacia.
	// Tambien se analiza desde la perspectiva de la diagonal inferior derecha.
	if (((T[filas2 - 1][colums2 + 1] == white ||
		  T[filas2 - 1][colums2 + 1] == crownW) &&
		 T[filas2 - 2][colums2 + 2] == blank && band)

		||

		(T[filas2 + 1][colums2 + 1] == white ||
		 T[filas2 + 1][colums2 + 1] == crownW) &&
			T[filas2 + 2][colums2 + 2] == blank && band)
	{
		// de ser posible mover otra ficha, informamos la posibilidad
		cout << anotherPlay;

		// este condicinal no hace mas que verificar si el juego es condicionado por reglas.
		if (hardmode)
		{
			// TODO: agregar las coordenadas automaticas

			// diagonal con mayor fichas, sea superior o inferior
			int superior = 0, inferior = 0;
			cout << "HARMODE: Activo, turno automatico.\n";

			// diagonal superior derecha
			for (int i = 1; i <= 3; i += 2)
			{

				if ((T[filas2 - i][colums2 + i] == white ||
					 T[filas2 - i][colums2 + i] == crownB) &&
					(T[filas2 - (i + 1)][colums2 + (i + 1)] == blank))
				{
					superior++;
					// en caso de error, descomentar el debugger

					// ZONA DE DEBUG
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

					// cout << "valor de inferior: " << superior << endl;
					// ZONA DE DEBUG
				}
			}
			// diagonal inferior derecha
			for (int i = 1; i <= 3; i += 2)
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
					// ZONA DE DEBUG
				}
			}
			if (inferior == superior)
			{
				// ¿existe la misma cantidad de fichas en ambas diagonales?
				cout << "Las alternativas a comer son identicas. Eliga usted.\n";
				whiteTurn();
			}

			//en caso de las opciones no ser iguales, se deben realizar las transformaciones
			// necesarias para el caso en particular. Se asume, por el tamaño del tablero. que dado un movimiento.
			// la maxima cantidad de saltos posibles es de dos.
			else if (superior > inferior)
			{
				int opc;
				cout << hardmodeMsj;
				cin >> opc;

				if (opc)
				{
					if (superior < 2)
					{
						// transformaciones para un unico salto
						T[filas2 + 1][colums2 + 1] = blank;
						T[filas2 + 2][colums2 + 2] = Black;
						T[filas2][colums2] = blank;
						whites++;
					}
					else
					{
						// transformaciones para un dos saltos
						T[filas2][colums2] = blank;
						T[filas2 + 1][colums2 + 1] = blank;
						T[filas2 + 2][colums2 + 2] = Black;
						whites++;

						T[filas2 + 2][colums2 + 2] = blank;
						T[filas2 + 3][colums2 + 3] = blank;
						T[filas2 + 4][colums2 + 4] = Black;
						whites++;
					}
				}
				else
				{
					// segun las reglas, no es posible saltar el turno a voluntad en caso de ser
					// activo el hardmode, siendo asi, segun las reglas se le soplara la ficha
					cout << penalty;
					T[filas2][colums2] = blank;
					// representa las fichas negras que fueron comidas
					blacks++;
				}
			}
			else
			{
				int opc;
				cout << hardmodeMsj;
				cin >> opc;

				if (opc)
				{
					if (inferior < 2)
					{
						// transformaciones para un unico salto
						T[filas2 + 1][colums2 + 1] = blank;
						T[filas2 + 2][colums2 + 2] = Black;
						T[filas2][colums2] = blank;
						whites++;
					}
					else
					{
						// transformaciones para dos saltos
						T[filas2 + 1][colums2 + 1] = blank;
						T[filas2 + 2][colums2 + 2] = Black;
						T[filas2][colums2] = blank;
						whites++;

						T[filas2 + 3][colums2 + 3] = blank;
						T[filas2 + 4][colums2 + 4] = Black;
						T[filas2 + 2][colums2 + 2] = blank;
						whites++;
					}
				}
				else
				{
					cout << penalty;
					T[filas2][colums2] = blank;
					// representa la cantidad de fichas negras comidas
					blacks++;
				}
			}
		}

		// en caso de no ser activo el modo hardcore(reglas), es decicion del jugador, comer.
		else
		{
			int opc;
			cout << "¿Desea comer otra? (1/0) ---> ";
			cin >> opc;
			cin.ignore(256, '\n');
			if (opc)
			{
				blackTurn();
			}
		}
	}
}

// se encarga de las comidas de las fichas coronadas negras TODO: automatico
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

			for (int i = 0; i < (colums1 - colums2) - 2; i++)
			{

				if (T[filas1 - 1][colums1 + 1] != blank)
				{
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
				T[filas2 + 1][colums2 - 1] = blank;
				whites++;
				band = true;
			}
		}
		else
		{
			for (int i = 0; i < (colums1 - colums2) - 1; i++)
			{
				if (T[filas1 - 1][colums1 + 1] != blank)
				{
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
				whites++;
				band = true;
			}
		}
	}

	// direccion: diagonal inferior derecha
	if (colums1 < colums2 && filas1 < filas2)
	{
		// la diagonal anterior a mi objetivo es comestible?
		if (T[filas2 - 1][colums2 - 1] == white || T[filas2 - 1][colums2 - 1] == crownW)
		{
			cout << T[filas2 - 1][colums2 - 1] << endl;
			pause();

			// verifico que no este saltando nada
			for (int i = 0; i < (colums1 - colums2) - 2; i++)
			{

				if (T[filas1 + 1][colums1 + 1] != blank)
				{
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
				T[filas2 - 1][colums2 - 1] = blank;
				whites++;
				band = true;
			}
		}
		else
		{
			for (int i = 0; i < (colums1 - colums2) - 1; i++)
			{
				if (T[filas1 + 1][colums1 + 1] != blank)
				{
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
				whites++;
				band = true;
			}
		}
	}

	// la bdandera define si se realizo algun movimiento
	if (band)
	{
		NULL;
	}
	else
	{
		MessageIsABadMovement();
	}
}

// NOTE: juego con las blancas

// se encarga de las comidas de las fichas coronadas blancas TODO: automatico
void Table::cronwCanEatBlacks()
{
	// si existe un ficha chocando al movimiento debemos saberlo
	bool ficha = false;
	bool band = false; // mimsma funciones que las demas banderas

	// siendo que la reina presenta  la movilidad tando de fichas negras como blancas, y elimina restricciones
	//  esta sera compuesta por una estructura casi identica a la de las fichas individuales, pero con los cambios
	// de movilidad necesarios para la total libertad de movilidad de la reina.

	// primero vamos a definir la direccion diagonal del movimiento

	// movimiento: diagonal, superior derecha
	if (filas1 > filas2 && colums2 > colums1)
	{
		// vamos a definir las limitaciones del salto de la ficha
		if (absoluteValue(colums2 - colums1) == 2 && T[filas1 - 1][colums1 + 1] != blank)
		{
			if (T[filas1 - 1][colums1 + 1] == Black || T[filas1 - 1][colums1 + 1] == crownB && absoluteValue(filas2 - filas1) == 2)
			{
				// como ya sabemos que el objetivo es vacio, y que es un movimiento de dos maximos
				// entonces, podemos afirmar el movimiento
				T[filas1 - 1][colums1 + 1] = blank;
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
		// si la diferencia no es 2, podemos afirmar por las modificaciones anteriores
		// que la fichas origen es valida y el espacio objetivo tambien.
		else
		{ // sumatoria
			int c = 0;
			// analisamos toda la diagonal
			for (int i = colums1; i < colums2; i++)
			{
				c++;
				if (T[filas1 - c][colums1 + c] != blank)
				{
					ficha = true;
				}
			}
			if (ficha)
			{
				system("clear");
				cout << badMovement;
				cin.ignore(256, '\n');
				getchar();
			}
			else
			{
				// si no existe una ficha durante el recorrido, vamos a decir que se
				// se realiza el cambio sin problemas.
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
	}

	// movimiento: diagonal, inferior derecha
	if (filas1 < filas2 && colums2 > colums1)
	{
		// vamos a definir las limitaciones del salto de la ficha
		if (absoluteValue(colums2 - colums1) == 2 && T[filas1 + 1][colums1 + 1] != blank)
		{
			if (T[filas1 + 1][colums1 + 1] == Black || T[filas1 + 1][colums1 + 1] == crownB && absoluteValue(filas2 - filas1) == 2)
			{
				// como ya sabemos que el objetivo es vacio, y que es un movimiento de dos maximos
				// entonces, podemos afirmar el movimiento
				T[filas1 + 1][colums1 + 1] = blank;
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
		// si la diferencia no es 2, podemos afirmar por las modificaciones anteriores
		// que la fichas origen es valida y el espacio objetivo tambien.
		else
		{ // sumatoria
			int c = 0;
			// analisamos toda la diagonal
			for (int i = colums1; i < colums2; i++)
			{
				c++;
				if (T[filas1 + c][colums1 + c] != blank)
				{
					cout << T[filas1 + i][colums1 + i] << endl;
					ficha = true;
				}
			}
			if (ficha)
			{
				system("clear");
				cout << badMovement;
				cin.ignore(256, '\n');
				getchar();
			}
			else
			{
				// si no existe una ficha durante el recorrido, vamos a decir que se
				// se realiza el cambio sin problemas.
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
	}

	// movimiento: diagonal, superior izquierdo
	if (filas1 > filas2 && colums2 < colums1)
	{
		// vamos a definir las limitaciones del salto de la ficha
		if (absoluteValue(colums2 - colums1) == 2 && T[filas1 - 1][colums1 - 1] != blank)
		{
			if (T[filas1 - 1][colums1 - 1] == Black || T[filas1 - 1][colums1 - 1] == crownB && absoluteValue(filas2 - filas1) == 2)
			{
				// como ya sabemos que el objetivo es vacio, y que es un movimiento de dos maximos
				// entonces, podemos afirmar el movimiento
				T[filas1 - 1][colums1 - 1] = blank;
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
		// si la diferencia no es 2, podemos afirmar por las modificaciones anteriores
		// que la fichas origen es valida y el espacio objetivo tambien.
		else
		{
			//sumatoria
			int c = 0;
			// analisamos toda la diagonal
			for (int i = colums2; i < colums1; i++)
			{
				c++;
				if (T[filas1 - c][colums1 - c] != blank)
				{
					ficha = true;
				}
			}
			if (ficha)
			{
				system("clear");
				cout << badMovement;
				cin.ignore(256, '\n');
				getchar();
			}
			else
			{
				// si no existe una ficha durante el recorrido, vamos a decir que se
				// se realiza el cambio sin problemas.
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
	}

	// movimiento: diagonal, inferior izquierdo
	if (filas1 < filas2 && colums2 < colums1)
	{
		// vamos a definir las limitaciones del salto de la ficha
		if (absoluteValue(colums2 - colums1) == 2 && T[filas1 + 1][colums1 - 1] != blank)
		{
			if (T[filas1 + 1][colums1 - 1] == Black || T[filas1 + 1][colums1 - 1] == crownB && absoluteValue(filas2 - filas1) == 2)
			{
				// como ya sabemos que el objetivo es vacio, y que es un movimiento de dos maximos
				// entonces, podemos afirmar el movimiento
				T[filas1 + 1][colums1 - 1] = blank;
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
		// si la diferencia no es 2, podemos afirmar por las modificaciones anteriores
		// que la fichas origen es valida y el espacio objetivo tambien.
		else
		{
			//sumatoria
			int c = 0;
			// analisamos toda la diagonal
			for (int i = colums2; i < colums1; i++)
			{
				c++;
				if (T[filas1 + c][colums1 - c] != blank)
				{
					ficha = true;
				}
			}
			if (ficha)
			{
				system("clear");
				cout << badMovement;
				cin.ignore(256, '\n');
				getchar();
			}
			else
			{
				// si no existe una ficha durante el recorrido, vamos a decir que se
				// se realiza el cambio sin problemas.
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
				band = true;
			}
		}
	}
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
				band = true;
				blacks++;
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
				band = true;
				blacks++;
			}
		}
		if (!band)
		{
			cout << badMovement;
			cin.ignore(256, '\n');
			getchar();
			return;
		}
		AutomaticPlayWhite(band);
	}
	else
	{
		T[filas2][colums2] = white;
		T[filas1][colums1] = blank;
	}
}

//administra el turno automatico de las fichas blancas
void Table::AutomaticPlayWhite(bool band)
{
	// existe otra ficha que comer?
	if (((filas2 - 2) >= 0 && (colums2 - 2) >= 0 &&
		 (T[filas2 - 1][colums2 - 1] == Black ||
		  T[filas2 - 1][colums2 - 1] == crownB) &&
		 T[filas2 - 2][colums2 - 2] == blank && band) ||

		((filas2 + 2) < 8 && (colums2 - 2) >= 0 &&
		 (T[filas2 + 1][colums2 - 1] == Black ||
		  T[filas2 + 1][colums2 - 1] == crownB) &&
		 T[filas2 + 2][colums2 - 2] == blank && band))
	{
		cout << anotherPlay;

		if (hardmode)
		{
			int superior = 0, inferior = 0;
			// TODO: poner a comer automaticamente
			cout << "HARMODE: Activo, turno automatico.\n";

			// diagonal superior izquierda
			for (int i = 1; i <= 3; i += 2)
			{

				if ((T[filas2 - i][colums2 - i] == Black ||
					 T[filas2 - i][colums2 - i] == crownB) &&
					(T[filas2 - (i + 1)][colums2 - (i + 1)] == blank))
				{
					superior++;
					// ZONA DE DEBUG
					cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
					cout << "valor del iterador: " << i << endl;
					cout << "primera condicion: "
						 << (T[filas2 - i][colums2 - i] == Black) << endl;
					cout << "segunda condicion: "
						 << (T[filas2 - (i + 1)][colums2 - (i + 1)] == blank) << endl;

					cout << "primera condicion grafica: "
						 << (T[filas2 - i][colums2 - i]) << endl;
					cout << "segunda condicion grafica: "
						 << (T[filas2 - (i + 1)][colums2 - (i + 1)]) << endl;
					cout << "se les va restar: " << (i + 1) << endl;

					cout << "valor de superior: " << superior << endl;
					// ZONA DE DEBUG
				}
			}
			// diagonal inferior izquierda
			for (int i = 1; i <= 3; i += 2)
			{
				if ((T[filas2 + i][colums2 - i] == Black ||
					 T[filas2 + i][colums2 - i] == crownB) &&
					T[filas2 + (i + 1)][colums2 - (i + 1)] == blank)
				{
					inferior++;
					// ZONA DE DEBUG
					cout << "Filas y columnas: " << filas2 << "," << colums2 << endl;
					cout << "valor del iterador: " << i << endl;
					cout << "primera condicion: "
						 << (T[filas2 + i][colums2 - i] == Black) << endl;
					cout << "segunda condicion: "
						 << (T[filas2 + (i + 1)][colums2 - (i + 1)] == blank) << endl;

					cout << "primera condicion grafica: "
						 << (T[filas2 + i][colums2 - i]) << endl;
					cout << "segunda condicion grafica: "
						 << (T[filas2 + (i + 1)][colums2 - (i + 1)]) << endl;
					cout << "se les va restar: " << (i + 1) << endl;

					cout << "valor de superior: " << inferior << endl;
					// ZONA DE DEBUG
				}
			}
			if (inferior == superior)
			{
				cout << "las opciones a comer son identicas, eliga usted.\n";
				whiteTurn();
			}
			else if (superior > inferior)
			{
				int opc;
				cout << hardmodeMsj;
				cin >> opc;

				if (opc)
				{
					if (superior < 2)
					{
						// una diagonal en blanco, dos es donde cae mi ficha, y de
						// donde partio, en blanco.
						T[filas2 - 1][colums2 - 1] = blank;
						T[filas2 - 2][colums2 - 2] = white;
						T[filas2][colums2] = blank;
						blacks++;
					}
					else
					{
						// una diagonal en blanco, dos es donde cae mi ficha, y de
						// donde partio, en blanco.
						T[filas2 - 1][colums2 - 1] = blank;
						T[filas2 - 2][colums2 - 2] = white;
						T[filas2][colums2] = blank;
						blacks++;

						// tres diagonales arriba, en blanco, 4 es donde cae mi ficha, y 2
						// (donde cayo antes) en blanco.
						T[filas2 - 3][colums2 - 3] = blank;
						T[filas2 - 4][colums2 - 4] = white;
						T[filas2 - 2][colums2 - 2] = blank;
						blacks++;
					}
				}
				else
				{
					cout << penalty;
					T[filas2][colums2] = blank;
					whites++;
				}
			}
			else
			{
				int opc;
				cout << hardmodeMsj;
				cin >> opc;

				if (opc)
				{
					if (inferior < 2)
					{
						// una diagonal en blanco, dos es donde cae mi ficha, y de
						// donde partio, en blanco.
						T[filas2 + 1][colums2 - 1] = blank;
						T[filas2 + 2][colums2 - 2] = white;
						T[filas2][colums2] = blank;
					}
					else
					{
						// una diagonal en blanco, dos es donde cae mi ficha, y de
						// donde partio, en blanco.
						T[filas2 + 1][colums2 - 1] = blank;
						T[filas2 + 2][colums2 - 2] = white;
						T[filas2][colums2] = blank;

						// tres diagonales arriba, en blanco, 4 es donde cae mi ficha, y 2
						// (donde cayo antes) en blanco.
						T[filas2 + 3][colums2 - 3] = blank;
						T[filas2 + 4][colums2 - 4] = white;
						T[filas2 + 2][colums2 - 2] = blank;
					}
				}
				else
				{
					cout << penalty;
					T[filas2][colums2] = blank;
					whites++;
				}
			}
		}
		else
		{
			int opc;
			cout << "¿Desea comer otra? (1/0) ---> ";
			cin >> opc;
			cin.ignore(256, '\n');
			if (opc)
			{
				whiteTurn();
			}
		}
	}
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
		T[filas2][colums2] == blank)
	{ // formas de movimiento

		cronwCanEatBlacks();
	}
	return false;
}

// logica necesaria para efectuar el turno de las fichas blacas
void Table::whiteTurn()
{
	isWhite = true;

	// verificamos si es posible coronar
	toCrown();

	// mostrar el tablero
	cleanToShow();

	// recoleccion de datos
	cout << myWhite;
	cin >> filas1 >> colums1;

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
		pause();
		return;
	}

	// actualizamos los datos
	cleanToShow();

	// recoleccion de datos
	cout << objetive;
	cin >> filas2 >> colums2;

	// verificamos limites del tablero
	if (validateLimitsX())
	{
		// en caso de que quiera moverse donde esta
		if (filas1 == filas2 && colums1 == colums2)
		{
			T[filas1][colums1] = aux1;
			MessageIsABadMovement();
			pause();
			return;
		}
		//else simbolico
		aux2 = T[filas2][colums2];
		T[filas2][colums2] = "[Igo]";
	}
	else
	{
		MessageIsOutLimits();
		pause();
		return;
	}

	cleanToShow();

	MessageToContinue();
	pause();

	// usamos las tags, auxiliares
	T[filas1][colums1] = aux1;
	T[filas2][colums2] = aux2;

	// ¿mueve la ficha correcta?

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
		MessageWrongTab();
		pause();
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
		T[filas2][colums2] == blank)
	{
		// se encarga de comer fichas y si existe la posibilidad de comer otra
		// repetir turno
		canEatBlacks();
	}
	else
	{
		cout << badMovement;
		getchar();
	}
	return true;
}

// NOTE: configuraciones y validaciones de juego

// muestra el tablero
void Table::toShow()
{
	cout << data;
	if (!isWhite)
	{
		cout << "BLANCAS Eliminadas --> " << whites << endl
			 << endl;
	}
	else
	{
		cout << "NEGRAS Eliminadas --> " << blacks << endl
			 << endl;
	}

	cout << "     0     1     2     3     4     5     6     7 \n";
	for (int i = 0; i < 8; i++)
	{
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
			else if (T[rows][colums] == white && colums == 0)
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
	cout << contin;
}

// mensaje para una ficha equivocada
void Table::MessageWrongTab()
{
	cout << wrongTab << endl;
	cout << lossTurn;
}

// dar una pequeña pausa
void Table::pause()
{
	cin.ignore(256, '\n');
	getchar();
}

// bucle principal del juego
void Table::play()
{
	while (true)
	{
		whiteTurn();
		blackTurn();
	}
}

// NOTE: main de pruebas
int main(int argc, char const *argv[])
{
	Table t;
	t.play();
	return 0;
}
