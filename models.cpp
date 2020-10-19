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

// movimiento automatico de las reinas negras
void Table::automaticPlayCronwBMovement()
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
	descripcion del problema: debo verificar el mayor de 4 valores.
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
		if (hardmode)
		{
			int opc;
			cout << hardmodeMsj;
			cin >> opc;
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
				T[filas2][colums2] = blank;
				return;
			}

			// si no esta activo el hardmode
		}
		else
		{
			int opc;
			cout << wantToEatAnother; // que ficha comes ahora!
			cin >> opc;
			cin.ignore(256, '\n');
			if (opc)
			{
				blackTurn();
			}
		}
	}
	return;
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
		MessageIsABadMovement();
		pause();
		cleanToShow();
	}
	return true;
}

// administra el turno de fichas negras.
void Table::blackTurn()
{
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
			pause();
			cleanToShow();
		}
	}

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
			pause();
			cleanToShow();
		}
	}

	colums1 = atoi(numero.c_str());
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
			pause();
			cleanToShow();
		}
	}

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
			pause();
			cleanToShow();
		}
	}

	colums2 = atoi(numero.c_str());

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
		T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) == absoluteValue(colums1 - colums2))
	{ // formas de movimiento

		cronwCanEatWhites();
	}
	else
	{
		MessageIsABadMovement();
		pause();
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
			MessageIsABadMovement();
			pause();
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
	}
	else
	{
		MessageIsABadMovement();
		pause();
		cleanToShow();
	}
}

// administra el automatico de las negras
void Table::AutomaticPlayBlack()

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

		// este condicinal no hace mas que verificar si el juego es condicionado por reglas.
		if (hardmode)
		{
			// TODO: agregar las coordenadas automaticas

			// diagonal con mayor fichas, sea superior o inferior
			int superior = 0, inferior = 0;
			cout << "HARMODE: Activo, turno automatico.\n";

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
				// ¿existe la misma cantidad de fichas en ambas diagonales?
				cout << identicalOptions; // las opciones a comer son identicas
				pause();
				// defino mi punto de partida
				filas1 = filas2;
				colums1 = colums2;
				// ahora eligirada donde se movera
				cout << youDecide;
				cin >> opc;
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
					blacks--;
					pause();
					return;
				}
			}

			//en caso de las opciones no ser iguales, se deben realizar las transformaciones
			// necesarias para el caso en particular. Se asume, por el tamaño del tablero. que dado un movimiento.
			// la maxima cantidad de saltos posibles es de dos.
			else if (superior > inferior)
			{
				cout << hardmodeMsj;
				cin >> opc;

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
				cout << hardmodeMsj;
				cin >> opc;

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
			cout << wantToEatAnother; // que ficha comes ahora!
			cin >> opc;
			if (opc)
			{
				blackTurn();
			}
		}
	}
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
					pause();
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
				automaticPlayCronwBMovement();
				whites--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 - c][colums1 + c] != blank)
				{
					MessageToBlocking((filas1 - c), (colums1 + c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
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
					pause();
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
				automaticPlayCronwBMovement();
				whites--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 + c][colums1 + c] != blank)
				{
					MessageToBlocking((filas1 + c), (colums1 + c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
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
					pause();
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
				automaticPlayCronwBMovement();
				whites--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 - c][colums1 - c] != blank)
				{
					MessageToBlocking((filas1 - c), (colums1 - c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
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
					pause();
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
				automaticPlayCronwBMovement();
				whites--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 + c][colums1 - c] != blank)
				{
					MessageToBlocking((filas1 + c), (colums1 - c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownB;
			}
		}
	}
}

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
					pause();
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
				automaticPlayCronwWMovement();
				blacks--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 - c][colums1 + c] != blank)
				{
					MessageToBlocking((filas1 - c), (colums1 + c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
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
					pause();
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
				automaticPlayCronwWMovement();
				blacks--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 + c][colums1 + c] != blank)
				{
					MessageToBlocking((filas1 + c), (colums1 + c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
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
					pause();
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
				automaticPlayCronwWMovement();
				blacks--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 - c][colums1 - c] != blank)
				{
					MessageToBlocking((filas1 - c), (colums1 - c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
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
					pause();
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
				automaticPlayCronwWMovement();
				blacks--;
			}
		}
		else
		{
			for (int i = 0; i < absoluteValue(colums1 - colums2) - 1; i++)
			{
				if (T[filas1 + c][colums1 - c] != blank)
				{
					MessageToBlocking((filas1 + c), (colums1 - c));
					pause();
					cleanToShow();
					ficha = true;
				}
				c++;
			}
			if (!ficha)
			{
				T[filas1][colums1] = blank;
				T[filas2][colums2] = crownW;
			}
		}
	}
}

// se encarga del movimiento automatico de las fichas blancas
void Table::automaticPlayCronwWMovement()
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
	descripcion del problema: debo verificar el mayor de 4 valores.
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
		if (hardmode)
		{
			int opc;
			cout << hardmodeMsj;
			cin >> opc;
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
				return;
			}

			// si no esta activo el hardmode
		}
		else
		{
			int opc;
			cout << wantToEatAnother; // que ficha comes ahora!
			cin >> opc;
			cin.ignore(256, '\n');
			if (opc)
			{
				whiteTurn();
			}
		}
	}
	return;
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
				blacks--;

				AutomaticPlayWhite();
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
				blacks--;

				AutomaticPlayWhite();
			}
		}
		if (!band)
		{
			MessageIsABadMovement();
			pause();
			cleanToShow();
			return;
		}
	}
	else if (colums2 + 1 == colums1 && absoluteValue(filas1 - filas2) == 1)
	{
		T[filas2][colums2] = white;
		T[filas1][colums1] = blank;
	}
	else
	{
		MessageIsABadMovement();
		pause();
		cleanToShow();
	}
}

//administra el turno automatico de las fichas blancas
void Table::AutomaticPlayWhite()
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

		if (hardmode)
		{
			int superior = 0, inferior = 0;
			// TODO: poner a comer automaticamente
			cout << "HARMODE: Activo, turno automatico.\n";

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

					// cout << "valor de superior: " << inferior << endl;
					// ZONA DE DEBUG
				}
			}
			if (inferior == superior && (superior != 0 && inferior != 0))
			{
				// ¿existe la misma cantidad de fichas en ambas diagonales?
				cout << identicalOptions; // las opciones a comer son identicas
				pause();
				// defino mi punto de partida
				filas1 = filas2;
				colums1 = colums2;
				// ahora eligirada donde se movera
				cout << youDecide;
				cin >> opc;
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
					pause();
					return;
				}
			}
			else if (superior > inferior)
			{
				cout << hardmodeMsj;
				cin >> opc;

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
				cout << hardmodeMsj;
				cin >> opc;

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
			cout << wantToEatAnother; // que ficha comes ahora!
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
		T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) == absoluteValue(colums1 - colums2))
	{ // formas de movimiento

		cronwCanEatBlacks();
	}
	else
	{
		MessageIsABadMovement();
		pause();
		cleanToShow();
	}

	return false;
}

// logica necesaria para efectuar el turno de las fichas blacas
void Table::whiteTurn()
{
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
			pause();
			cleanToShow();
		}
	}

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
			pause();
			cleanToShow();
		}
	}

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
		pause();
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
			pause();
			cleanToShow();
		}
	}

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
			pause();
			cleanToShow();
		}
	}

	colums2 = atoi(numero.c_str());

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
		T[filas2][colums2] == blank && absoluteValue(filas1 - filas2) < 3)
	{
		// se encarga de comer fichas y si existe la posibilidad de comer otra
		// repetir turno
		canEatBlacks();
	}
	else
	{
		MessageIsABadMovement();
		pause();
		cleanToShow();
	}
	return true;
}

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

	cout << "                              " << playerName << " VS " << vs << endl;
	ToHours();
	cout << endl;
	cout << "                             Tiempo Restante: " << hAux << ":" << mAux << ":" << sAux << endl
		 << endl;

	cout
		<< "\t\t";
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
	MessageToContinue();
	cin.ignore(256, '\n');
	getchar();
}

// cometario
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
	pause();
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
	pause();
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
	pause();
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
	pause();
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
					if (T[i][j] == Black || T[i][j] == crownB)
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
					if (T[i][j] == Black || T[i][j] == crownB)
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
					if (T[i][j] == Black || T[i][j] == crownB)
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
					if (T[i][j] == Black || T[i][j] == crownB)
					{
						break;
					}
					if ((T[i + c][j - c] == white || T[i + c][j - c] == crownW) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
						// {
						// 	cout << "en: " << i << j << endl;
						// 	cout << "negrasRii\n";
						return true;
				}
				c++;
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
					if (T[i][j] == white || T[i][j] == crownW)
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
					cout << "en: " << i << j << endl;
					cout << "blancasRir\n";
					return true;
				}
				// diagonal inferior derecha
				for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j + c < 8; a++)
				{
					// hasta ahi no se puede mover
					if (T[i][j] == white || T[i][j] == crownW)
					{
						break;
					}
					if ((T[i + c][j + c] == Black || T[i + c][j + c] == crownB) && T[i + (c + 1)][j + (c + 1)] == blank && i + (c + 1) < 8 && j + (c + 1) < 8)
					{
						cout << "en: " << i << j << endl;
						cout << "blancasRif\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i - c][j - c] == blank && i - c >= 0 && j - c >= 0)
				{
					cout << "en: " << i << j << endl;
					cout << "blancasRsi\n";
					return true;
				}
				// diagonal superior izquierda
				for (int a = j; a < absoluteValue(j - 7) && i - c >= 0 && j - c >= 0; a++)
				{
					// hasta ahi no se puede mover
					if (T[i][j] == white || T[i][j] == crownW)
					{
						break;
					}
					if ((T[i - c][j - c] == Black || T[i - c][j - c] == crownB) && T[i - (c + 1)][j - (c + 1)] == blank && i - (c + 1) >= 0 && j - (c + 1) >= 0)
					{
						cout << "en: " << i << j << endl;
						cout << "blancasRsi\n";
						return true;
					}
					c++;
				}
				c = 1;
				// se puede mover
				if (T[i + c][j - c] == blank && i + c < 8 && j - c >= 0)
				{
					cout << "en: " << i << j << endl;
					cout << "blancasRii\n";
					return true;
				}
				// diagonal inferior izquierda
				for (int a = j; a < absoluteValue(j - 7) && i + c < 8 && j - c >= 0; a++)
				{
					// hasta ahi no se puede mover
					if (T[i][j] == white || T[i][j] == crownW)
					{
						break;
					}
					if ((T[i + c][j - c] == Black || T[i + c][j - c] == crownB) && T[i + (c + 1)][j - (c + 1)] == blank && i + (c + 1) < 8 && j - (c + 1) >= 0)
					{
						cout << "en: " << i << j << endl;
						cout << "blancasRii\n";
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
	int h, m, s;
	h = hours * 3600;
	m = minutes * 60;
	s += seconds + h + m;
	timeOf = s;
}

// transforma segundos a horas, minutos y segundos
void Table::ToHours()
{
	int h, m, s, totalSec = absoluteValue(timeOf - t1);
	hAux = totalSec / 3600; // horas totales
	totalSec %= 3600;		// descuento las horas

	mAux = totalSec / 60; // minutos totales
	sAux = totalSec % 60; // descuento los minutos y ajusto los segundos totales
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
	pause();
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
		cout << "Jugador uno, ¿cual es su nombre? --> ";
		cin >> playerName;
		cout << "\t\t\t";
		cout << "Jugador dos, ¿cual es su nombre? --> ";
		cin >> playerName2;
	}
	else
	{
		int aleatorio = 0;
		cout << "\t\t\t";
		cout << "Jugador uno, ¿cual es su nombre? --> ";
		cin >> playerName;
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
	system("clear");
	while (true)
	{
		string numero;
		bool isvalidate = false; // parto de que no es un numero valido
		int opc1;
		cout << "\t\t\t  ";
		cout << data;
		cout << "\t\t\t";
		cout << "********* MENU DE SELECCION ***********" << endl;
		cout << "\t\t\t";
		cout << "******** Jugar(1);            *********" << endl;
		cout << "\t\t\t";
		cout << "******   Configurar(2)           ******" << endl;
		cout << "\t\t\t";
		cout << "****     Ver configuraciones(3)    ****" << endl;
		cout << "\t\t\t";
		cout << "***      Acerca de(4)               ***" << endl;
		cout << "\t\t\t";
		cout << "**       Salir(5)                    **" << endl;
		cout << "\t\t\t";
		cout << "*                                     *" << endl;
		cout << "\t\t\t";
		cout << "SELECCION: --> ";

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
			configure();
			break;
		case 3:
			screenConfig();
			break;
		case 4:
			aboutItscreen();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Opcion no disponible." << endl;
			pause();
		}
		cleanToShowMenu();
	}
}

// limpiar y mostrar el menu
void Table::cleanToShowMenu()
{
	system("clear");
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
	hours = atoi(numero.c_str());
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

	pause();
	cleanToShowMenu();
}

// bucle principal del juego
void Table::play()
{
	tagSelecction();
	// hora de inicio
	t0 = time(NULL);

	while (ICanFollow() && t1 < timeOf)
	{
		whiteTurn();
		blackTurn();
		t1 = time(NULL) - t0;
	}
	cleanToShowMenu();
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

// NOTE: main de pruebas
int main(int argc, char const *argv[])
{
	Table t;
	t.Menu();
	return 0;
}
