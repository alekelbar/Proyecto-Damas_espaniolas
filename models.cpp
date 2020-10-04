#include "Structure.h"

// NOTE: tareas
// TODO: (1) movimiento de reinas blancas/negras, (2) agregar el modo dificil con reglas.
// TODO: (3) guardado, (4) agregar el menu, (5) agregar el indicacador de fin de partida.
// TODO: (6) agregar el empate manual{decidido por el jugador}, (7) agregar el empate automatico.
// TODO: (8) implementar el menu de guardado, (9) crear la pantalla acerca de.
// TODO: (10) crear el menu de configurarion, (11) agregar un timer.
// TODO: (12) agregar mensaje personalizados de error, (13) agregar robustes.
// TODO: (14) agregar un teligencia ramdon, (15) agregar un random para los colores.
// TODO: (16) actualizar las tareas...

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
bool Table::blackMovement(int filas1, int colums1, int filas2, int colums2)
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (filas1 < 0 && filas1 >= 8 && colums1 < 0 && colums1 >= 8 ||
		filas2 < 0 && filas2 >= 8 && colums2 < 0 && colums2 >= 8)
	{

		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << badMovement;
		return false;
	}
	bool band = false;

	if (T[filas1][colums1] != blank && T[filas1][colums1] != white &&
		T[filas2][colums2] == blank && colums2 > colums1 && filas2 != filas1)
	{
		/* la ficha a mover no puede estar "vacia", tampoco puede ser "blanca", y
ademas. la ficha objetivo debe estar vacia. el movimiento debe ser
hacia la derecha y en diagonal.*/
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
			bool fc = (filas2 + 2) > 8 && (colums2 + 2) <= 0;
			bool sc = T[filas2 + 1][colums2 + 1] == white;
			bool tc = T[filas2 + 1][colums2 + 1] == crownW;
			bool foc = T[filas2 + 2][colums2 + 2] == blank;

			cout << "Primera condicion: " << fc << endl; //DEBUG
			cout << "segunda condicion: " << sc << endl; //DEBUG
			cout << "tercera condicion: " << tc << endl; //DEBUG
			cout << "cuarta condicion: " << foc << endl; //DEBUG
			cout << "Bandera: " << band << endl;
			if (!band)
			{
				cout << badMovement;
			}
		}
		else
		{
			T[filas2][colums2] = Black;
			T[filas1][colums1] = blank;
			whites++;
		}
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

	cout << " filas1 y colums2: " << filas1 << "," << filas2 << endl;  //DEBUG
	cout << " filas2 y colums2: " << filas2 << "," << colums2 << endl; //DEBUG
	blackMovement(filas1, colums1, filas2, colums2);
	toShow();
}

bool Table::whiteMovement(int colums1, int filas1, int colums2, int filas2)
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (filas1 < 0 && filas1 >= 8 && colums1 < 0 && colums1 >= 8 ||
		filas2 < 0 && filas2 >= 8 && colums2 < 0 && colums2 >= 8)
	{

		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << badMovement;
		return false;
	}
	bool band = false;

	if (T[filas1][colums1] != blank && T[filas1][colums1] != Black &&
		T[filas2][colums2] == blank && colums2 < colums1 && filas2 != filas1)
	{
		/* la ficha a mover no puede estar "vacia", tampoco puede ser "blanca", y
ademas. la ficha objetivo debe estar vacia. el movimiento debe ser
hacia la izquierda y en diagonal.*/
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
			// luego del cambio.
			// si es enemiga, y la siguiente posicion tambien. si ademas, existe
			// el espacio libre y se puede realizar el movimiento.
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
			bool fc = (filas2 + 2) > 8 && (colums2 + 2) <= 0;
			bool sc = T[filas2 + 1][colums2 + 1] == white;
			bool tc = T[filas2 + 1][colums2 + 1] == crownW;
			bool foc = T[filas2 + 2][colums2 + 2] == blank;

			cout << "Primera condicion: " << fc << endl; //DEBUG
			cout << "segunda condicion: " << sc << endl; //DEBUG
			cout << "tercera condicion: " << tc << endl; //DEBUG
			cout << "cuarta condicion: " << foc << endl; //DEBUG
			cout << "Bandera: " << band << endl;
			if (!band)
			{
				cout << badMovement;
			}
		}
		else
		{
			T[filas2][colums2] = white;
			T[filas1][colums1] = blank;
		}
	}
	else
	{
		cout << badMovement;
	}
	return true;
}

//administra el movimiento de fichas blancas.
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

	cout << " filas1 y colums2: " << filas1 << "," << filas2 << endl;  //DEBUG
	cout << " filas2 y colums2: " << filas2 << "," << colums2 << endl; //DEBUG
	whiteMovement(filas1, colums1, filas2, colums2);
	toShow();
}

// NOTE: zona de metodos no implementados.

bool Table::crownBMovement(int filas1, int colums1, int filas2, int colums2)
{
	toCrown();
	// filas1,colums1 cual muevo
	// filas2,colums2 donde la muevo

	// despejar la probabilidad de que se salga de la matriz.
	if (filas1 < 0 && filas1 >= 8 && colums1 < 0 && colums1 >= 8 ||
		filas2 < 0 && filas2 >= 8 && colums2 < 0 && colums2 >= 8)
	{

		// si la coordenada objetivo es invalida, entonces
		// el movimiento no es valido
		cout << badMovement;
		return false;
	}
	bool band = false;

	/* debe ser una ficha negra y estar en diagonal*/
	if (T[filas1][colums1] == Black &&
		T[filas2][colums2] == blank && filas2 != filas1)
	{

		if (colums2 - 1 != colums1)
		{

			// la coordenada aciende

			if (filas2 < filas1)
			{
				// Se movio mas de una posicion. Ahora se analiza si es valido.
				// si lo es se elimina la ficha enemiga.
				if (T[filas2 + 1][colums2 - 1] == white ||
					T[filas2 + 1][colums2 - 1] == crownW)
				{
					T[filas2 + 1][colums2 - 1] = blank;
					T[filas2][colums2] = Black;
					T[filas1][colums1] = blank;
					band = true;
				}
				// si esta bajando
			}
			else if (filas2 > filas1)
			{
				if (T[filas2 - 1][colums2 - 1] == white ||
					T[filas1 - 1][colums1 - 1] == crownW)
				{
					T[filas2 - 1][colums2 - 1] = blank;
					T[filas2][colums2] = Black;
					T[filas1][colums1] = blank;
					band = true;
				}
			}
			// luego del cambio.
			// si es enemiga, y la siguiente posicion tambien. si ademas, existe
			// el espacio libre y se puede realizar el movimiento.
			if (T[filas2 - 2] >= 0) //TODO: continuar
			{
			}
			bool fc = (filas2 + 2) > 8 && (colums2 + 2) <= 0;
			bool sc = T[filas2 + 1][colums2 + 1] == white;
			bool tc = T[filas2 + 1][colums2 + 1] == crownW;
			bool foc = T[filas2 + 2][colums2 + 2] == blank;

			cout << "Primera condicion: " << fc << endl; //DEBUG
			cout << "segunda condicion: " << sc << endl; //DEBUG
			cout << "tercera condicion: " << tc << endl; //DEBUG
			cout << "cuarta condicion: " << foc << endl; //DEBUG
			cout << "Bandera: " << band << endl;
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
	else
	{
		cout << badMovement;
	}
	return true;
}

// NOTE: main de pruebas
int main(int argc, char const *argv[])
{
	Table t;
	t.blackTurn();
	t.whiteTurn();

	return 0;
}
