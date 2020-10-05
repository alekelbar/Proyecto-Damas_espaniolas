#include "Structure.h"

// NOTE: tareas
// TODO: (1) movimiento de reinas blancas/negras, (2) agregar el modo dificil con reglas.
// TODO: (3) guardado, (4) agregar el menu, (5) agregar el indicacador de fin de partida.
// TODO: (6) agregar el empate manual{decidido por el jugador}, (7) agregar el empate automatico.
// TODO: (8) implementar el menu de guardado, (9) crear la pantalla acerca de.
// TODO: (10) crear el menu de configurarion, (11) agregar un timer.
// TODO: (12) agregar mensaje personalizados de error, (13) agregar robustes.
// TODO: (14) agregar un teligencia ramdon, (15) agregar un random para los colores.
// TODO: (16) aplicar optimizaciones, (17) actualizar las tareas...

// NOTE: Zona de metodos implementados

// muestra el tablero
void Table::toShow()
{
	cout << "     0     1     2     3     4     5     6     7 \n\n";
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

// maneja la logica del movimiento de fichas negras.
bool Table::blackMovement()
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (!validateLimits())
	{

		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << badMovement;
		return false;
	}
	//necesito mover una ficha negra, que se mueva en diagonal, y que se mueva de manera frontal y
	// al lugar donde me movere, debe esta vacio
	if (T[filas1][colums1] == Black && filas1 != filas2 && colums1 < colums2 && T[filas2][colums2] == blank)
	{
		canEatWhites();
	}
	else
	{
		cout << badMovement;
	}
	return true;
}

// administra el turno de fichas negras.
void Table::blackTurn()
{
	system("clear");
	toCrown();
	cout << data;
	// apartir de aca se muestran datos del juego
	cout << "Fichas blancas comidas: " << whites << endl;
	toShow();
	cout << "¿Que ficha ** NEGRA ** movera? Coordenadas--> ";
	cin >> filas1 >> colums1;
	cin.ignore(256, '\n');
	cout << " ¿A donde movera? Coordenadas--> ";
	cin >> filas2 >> colums2;

	cout << " filas1 y colums1: " << filas1 << "," << colums1 << endl; //DEBUG
	cout << " filas2 y colums2: " << filas2 << "," << colums2 << endl; //DEBUG
	if (T[filas1][colums1] == Black)
	{
		blackMovement();
	}
	else if (T[filas1][colums1] == crownB)
	{
		crownBMovement();
	}
	else
	{
		cout << "Esta moviendo la pieza incorrecta." << endl;
	}

	toShow();
}

//maneja la logica de movimiento de fichas blancas
bool Table::whiteMovement()
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (!validateLimits())
	{
		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << "entro al primero";
		cout << badMovement;
		return false;
	}
	// donde estoy: debe ser una ficha blanca, debe moverse en diagonal y hacia su frente.
	// donde voy: debe estar vacio
	if (T[filas1][colums1] == white && filas1 != filas2 && colums2 < colums1 &&
		T[filas2][colums2] == blank)
	{
		// se encarga de comer fichas y si existe la posibilidad de comer otra
		// repetir turno
		canEatBlacks();
	}
	else
	{
		cout << "entro al ultimo";
		cout << badMovement;
	}
	return true;
}

//administra el turno de fichas blancas.
void Table::whiteTurn()
{
	system("clear");
	toCrown();
	cout << data;
	// apartir de aca se muestran estadisticas.
	cout << "Fichas negras comidas: " << whites << endl;
	toShow();
	cout << "¿Que ficha ** BLANCA ** movera? Coordenadas--> ";
	cin >> filas1 >> colums1;
	cin.ignore(256, '\n');
	cout << " ¿A donde movera? Coordenadas--> ";
	cin >> filas2 >> colums2;

	cout << " filas1 y colums1: " << filas1 << "," << colums1 << endl; //DEBUG
	cout << " filas2 y colums2: " << filas2 << "," << colums2 << endl; //DEBUG
	whiteMovement();
	toShow();
}

// administra el movimiento y comidas basicas de reinas negras
bool Table::crownBMovement()
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (!validateLimits())
	{
		cout << "Entro al area de limites" << endl;
		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << badMovement;
		return false;
	}

	/* debe ser una reina negra, moverse en diagonal, y donde se mueva, 
	debe de esta vacio, siempre.*/
	if (T[filas1][colums1] == crownB && filas2 != filas1 && T[filas2][colums2] == blank)
	{ //formas de movimiento
		cout << "entro al primer if" << endl;

		cronwCanEatWhites();
	}
	return false;
}

// limita el tablero
bool Table::validateLimits()
{
	int a = filas1, b = colums1, c = filas2, d = colums2;
	bool aIs = false, bIs = false, cIs = false, dIs = false;
	for (int i = 0; i < 8; i++)
	{
		if (i == a)
		{
			aIs = true;
		}
		if (i == b)
		{
			bIs = true;
		}
		if (i == c)
		{
			cIs = true;
		}
		if (i == d)
		{
			dIs = true;
		}
	}
	if ((aIs && dIs) && (cIs && dIs))
	{
		return true;
	}

	return false;
}

// se encarga de comidas simples negras y repetir si existe otra comida
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
				// TODO: poner a comer automaticamente
				whiteTurn();
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
		if (!band)
		{
			cout << "no entro aca";
			cout << badMovement;
		}
	}
	else
	{
		T[filas2][colums2] = white;
		T[filas1][colums1] = blank;
	}
}

// se encarga de comidas simples blancas y repetir si existe otra comida
void Table::canEatWhites()
{
	bool band = false;
	// ¿cuanto se movio? ¿solo una vez?
	if (colums2 - 1 != colums1)
	{
		// la coordenada aciende
		if (filas2 < filas1)
		{
			// Se movio mas de una posicion. Ahora se analiza si es valido.
			// si lo es se elimina la ficha enemiga.
			if (T[filas1 - 1][colums1 + 1] == white ||
				T[filas1 - 1][colums1 + 1] == crownW)
			{
				T[filas1 - 1][colums1 + 1] = blank;
				T[filas2][colums2] = Black;
				T[filas1][colums1] = blank;
				band = true;
				whites++;
			}
			// si esta bajando
		}
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
		// luego del cambio.
		// si es enemiga, y la siguiente posicion tambien. si ademas, existe
		// el espacio libre y se puede realizar el movimiento.
		if (((filas2 - 2) >= 0 && (colums2 + 2) < 8 &&
			 (T[filas2 - 1][colums2 + 1] == white ||
			  T[filas2 - 1][colums2 + 1] == crownW) &&
			 T[filas2 - 2][colums2 + 2] == blank && band) ||

			((filas2 + 2) < 8 && (colums2 + 2) < 8 &&
			 (T[filas2 + 1][colums2 + 1] == white ||
			  T[filas2 + 1][colums2 + 1] == crownW) &&
			 T[filas2 + 2][colums2 + 2] == blank && band))
		{
			cout << anotherPlay;

			if (hardmode)
			{
				// TODO: agregar las coordenadas automaticas
				blackTurn();
			}
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
		if (!band)
		{
			cout << badMovement;
		}
	}
	else
	{
		T[filas2][colums2] = Black;
		T[filas1][colums1] = blank;
	}
}

// aplica la logica necesaria para que la reina coma TODO: que repita comida
void Table::cronwCanEatWhites()
{
	bool band = false;

	if (colums2 - 1 != colums1 || colums2 + 1 != colums1)
	{
		// NOTE: CONDICIONAL REVISADO
		// diagonal, superior derecha
		if (filas2 != filas1 && colums2 > colums1 && !(T[filas1 - 1][colums1 + 1] == white && colums2 - colums2 > 2))
		{
			if (T[filas2 + 1][colums2 - 1] == white || T[filas2 + 1][colums2 - 1] == crownW)
			{
				T[filas2 + 1][colums2 - 1] = blank;
				T[filas2][colums2] = crownB;
				T[filas1][colums1] = blank;
				band = true;
			}
		}
		// NOTE: CONDICIONAL REVISADO
		// diagonal superior izquierda
		if (filas2 != filas1 && colums2 < colums1 && !(T[filas1 - 1][colums1 - 1] == white && colums1 - colums2 > 2))
		{
			if (T[filas2 + 1][colums2 + 1] == white || T[filas2 + 1][colums2 + 1] == crownW)
			{
				T[filas2 + 1][colums2 + 1] = blank;
				T[filas2][colums2] = crownB;
				T[filas1][colums1] = blank;
				band = true;
			}
		}
		// NOTE: CONDICIONAL REVISADO
		//diagonal inferior derecha
		if (filas2 != filas1 && colums2 > colums1 && !(T[filas1 + 1][colums1 + 1] == white && colums2 - colums1 > 2))
		{
			if (T[filas2 - 1][colums2 - 1] == white || T[filas2 - 1][colums2 - 1] == crownW)
			{
				T[filas2 - 1][colums2 - 1] = blank;
				T[filas2][colums2] = crownB;
				T[filas1][colums1] = blank;
				band = true;
			}
		}
		// NOTE: CONDICIONAL REVISADO
		// diagonal inferior izquierda
		if (filas2 != filas1 && colums2 < colums1 && !(T[filas1 + 1][colums1 - 1] == white && colums1 - colums2 > 2))
		{
			if (T[filas2 - 1][colums2 + 1] == white || T[filas2 - 1][colums2 + 1] == crownW)
			{
				T[filas2 - 1][colums2 + 1] = blank;
				T[filas2][colums2] = crownB;
				T[filas1][colums1] = blank;
				band = true;
			}
		}
		if (!band)
		{
			cout << badMovement;
		}
	}
	else
	{
	}
}

// NOTE: zona de metodos no implementados.

// NOTE: main de pruebas
int main(int argc, char const *argv[])
{
	Table t;
	t.blackTurn();

	return 0;
}
