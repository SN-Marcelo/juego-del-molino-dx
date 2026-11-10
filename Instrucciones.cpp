//Instrucciones
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <limits>
#include <string>
using namespace std;
void menu(); //Te da elegir entre opciones
void instrucciones(){
	cout << "\n\t\t*-Instrucciones-*\n"
	<< " - Cada jugador tiene 9 fichas\n"
	<< " - Ganas cuando:\n"
	" . El oponente tiene 2 fichas\n"
	" . El oponente no puede realizar ningún movimiento\n\n";
	cout << "\t\t   *-REGLAS-*"
	<< "\nFASES DEL JUEGO:\n"
	
	<< "\t\t-COLOCAR FICHAS-\n"
	<< " . Cada jugador coloca una ficha por turno en el tablero\n"
	<< " . No puede colocar una ficha fuera de los espacios señalados\n"
	<< "   ni en el mismo lugar que en la ficha tuya o del oponente\n"
	<< " . Si realizas una línea de 3 fichas, formas un 'molino' \n\n"
	
	<< "\t\t-MOVER FICHAS-\n"
	<< " . Cada jugador mueve una ficha por turno en el tablero\n"
	<< " . Solo puedes moverte mediante el flujo de las líneas\n"
	<< " . No puedes moverte al mismo lugar que la ficha de tu oponente\n"
	<< " . Si realizas una línea de 3 fichas, formas un molino\n"
	<< " . Si solo te quedan 3 fichas, puedes moverte a cualquier\n"
	<< "   espacio disponible, sin importar tu posición\n\n"
	
	<<"\t\t-MOLINO-\n"
	<<" .Al realizar un molino debes eliminar 1 ficha del oponente\n"
	<<" .No podrás eliminar la ficha si está en un molino\n\n";
	system("pause");
	system("cls");
	menu();
}

int temas(){
	//Nota: La música no está incluída en el repositorio
	cout << "\n\tIngrese una Tema\n";
	cout << "\n1)Predeterminado\n2)Bloque\n3)Retro\n4)Escolar\n5)Elegante\n"<<
			"6)Fantasía\n7)Tenebroso\n8)Galaxia\n9)Tuberías\n10)Volver\n\nOpción: ";
	short *opc = new short;
	do {
		do {
			if(cin>>*opc) break;
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		} while(true);
	} while(*opc <1 || *opc >10);
	switch(*opc){
		case 1: return 1; /*"Predeterminado.wav"*/; break;
		case 2: return 2; /*"Bloque.wav"*/; break;
		case 3: return 3; /*"Retro.wav"*/; break;
		case 4: return 4; /*"Escolar.wav"*/; break;
		case 5: return 5; /*"Elegante.wav"*/; break;
		case 6: return 6; /*"Fantasia.wav"*/; break;
		case 7: return 7; /*"Tenebroso.wav"*/; break;
		case 8: return 8; /*"Galaxia.wav"*/; break;
		case 9: return 9; /*"Tuberias.wav"*/; break;
		default: return 1; menu(); break;
	}

}

void creditos(){
	cout << "\n\t  -*CRÉDITOS*-";
	cout << "\n\n\tPARTICIPANTES:\n";
	cout << " - Marcelo Neyra\n";
	cout << " - [redacted]\n";
	cout << " - [redacted]\n";
	cout << " - [redacted]\n";
	     
    cout << "\n\n\tPARTICIPACIÓN:";
	cout << "\n - Desarrollador del juego:\t Marcelo Neyra";
	cout << "\n - Mecánicas:\t\t\t Marcelo Neyra";
	cout << "\n - Diseño del tablero:\t\t Marcelo Neyra";
	cout << "\n - Debugging:\t\t\t Marcelo Neyra";
	cout << "\n - Elección de la música:\t Marcelo Neyra";
	cout << "\n - Logo del juego:\t\t [redacted]\n\n";
	system("pause");
	system("cls");
	menu();
}
