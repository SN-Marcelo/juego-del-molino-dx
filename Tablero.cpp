//Tablero
#include <iostream>
#include <windows.h>
#define color SetConsoleTextAttribute
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void menu(); //Te da elegir entre opciones
void jugador1(int **, int &fichas,int &song); //Tablero para un jugador
void dibujar_tablero(int **, int &fichas, short &turno,int &song); //Dibuja el tablero
void tablero_inicial(int& fichas, short& turno, int& song) {
	//Declarando parámetros del mapa (tablero)
	int** mapa;
	mapa = new int* [8];
	//Espacios disponibles, (fila y columna 8 no cuentan)
	for (int i = 0; i <= 7; i++) {
		mapa[i] = new int[7];
	}
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			switch (i) {
			default: mapa[i][j] = 0; break;
			case 0: case 6: //Primera y sétima fila
				if (j == 1 || j == 2 || j == 4 || j == 5) mapa[i][j] = 3;
				else mapa[i][j] = 0;
				break;
			case 1: case 5: //Segunda y sexta fila
				if (j == 0 || j == 2 || j == 4 || j == 6) mapa[i][j] = 3;
				else mapa[i][j] = 0;
				break;
			case 2: case 4: //Tercera y quinta fila
				if (j == 0 || j == 1 || j == 5 || j == 6) mapa[i][j] = 3;
				else mapa[i][j] = 0;
				break;
			case 3: //Tercera fila
				if (j == 3) mapa[i][j] = 3;
				else mapa[i][j] = 0;
				break;
			case 7: mapa[i][j] = 4; break;
			}
		}
	}

	jugador1(mapa, fichas, song);
	for (int i = 0; i <= 7; i++) {
		delete[]mapa[i];
	} delete []mapa;
}

void dibujar_tablero(int** mapa, int& fichas, short& turno, int& song) {
	//Dibujar mapa
	for (int espacioY = 0; espacioY < 3; espacioY++) {
		if (espacioY == 1 && fichas > -1) {
			if (fichas != 0) cout << "Fichas Jugador " << turno << ": " << fichas;
			else cout << "Fichas Jugador " << turno << ": " << fichas + 1;
		}
		//Esto será para indicar qué valores tienes para poder ingresar las coordenadas
		(espacioY == 2) ? cout << "     0  1  2  3  4  5  6\n" : cout << '\n';
	}
	for (int i = 0; i <= 6; i++) {
		for (int espacioX = 0; espacioX < 5; espacioX++) {
			if (espacioX == 2) {
				//Lo mismo que lo anterior, pero verticalmente
				cout << char(i + 48);
			}
			else cout << " ";
		}
		for (int j = 0; j <= 6; j++) {
			if (mapa[i][j] == 3) {
				switch (i) {
					//Se dibuja las líneas horizontales de la fila 0 y 6
				case 0: case 6: cout << "---"; break;

					//filas 1 y 5
				case 1: case 5:
					//verticales en las columnas 0 y 6
					if (j == 0 || j == 6) cout << "|  ";
					// líneas horizontales
					else cout << "---";
					break;

					//fila 2 y 4
				case 2: case 4:
					// [...] columnas 0,1,5,6
					if (j == 0 || j == 1 || j == 5 || j == 6) cout << "|  ";
					// líneas horizontales
					else cout << "---";
					break;

					//Como en el medio no va líneas, usamos espacios
				case 3:
					cout << "   "; break;
					//En caso algo raro ocurra, vuelves al menu
				default: menu(); break;
				}
			}
			else {
				//Esto es para imprimir los números del tablero 
				switch (i) {
					//En todos los casos, se escoge si se imprime " " o "--"
				case 0: case 6:
					if (j == 6) cout << mapa[i][j] << "  ";
					else cout << mapa[i][j] << "--";
					break;
				case 1: case 5:
					if (j == 5) cout << mapa[i][j] << "  ";
					else cout << mapa[i][j] << "--";
					break;
				case 2: case 4:
					if (j == 4) cout << mapa[i][j] << "  ";
					else cout << mapa[i][j] << "--";
					break;
				case 3:
					if (j == 2 || j == 6) cout << mapa[i][j] << "  ";
					else cout << mapa[i][j] << "--";
					break;
					//De algo ocurrir mal, vuelves al menu
				default: menu(); break;
				}
			}
		}
		//Al terminar de imprimir la fila, se salta la línea
		cout << '\n';
	}
}
