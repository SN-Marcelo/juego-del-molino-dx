//Main
#include <iostream>
#include <locale.h>
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#define color SetConsoleTextAttribute
using namespace std;
void inicio(); //Pantalla de inicio
void menu(); //Te da elegir entre opciones
void jugador1(int **, int &fichas,int &song); //Tablero para un jugador
void jugar(int &song); // Te permite jugar
void instrucciones(); //Muestra las instrucciones
void reglas(); //Muestra las reglas
int temas(); //Te da a elegir entre las opciones gráficas y musicales
void gameover(bool &win); //Pantalla que aparece cuando termina el juego
void tablero_inicial(int &fichas, short &turno,int &song); //Define la matriz mapa (el tablero)
void dibujar_tablero(int **, int &fichas,  short &turno,int &song); //Dibuja el tablero
void comprobar_posicion(int &x, int &y, int **,int &fichas,  short &turno,int &song); //Se comprueba la posicion de la ficha
void sin_movimientos(int **, short &turno); // Comprobar si hay movimientos
void mover_fichas(int &x, int &y, int**, int &fichas,  short &turno,int &song); //Te permite mover las fichas
void cambiar_valor(int &x, int &y, int **, int &fichas, short &turno,int &song); //Se cambia el valor de la ficha
void molino(int &x, int &y, int **, int &fichas, short &turno,int &song); // Comprueba si hay un molino
void activo(int **, short &turno); //Se comprueba si un molino está activo
void auxiliar_activo(); //Desactiva automáticamente todos los molinos
void eliminar(int &x, int &y, int **, int &fichas, short &turno,int &song); //Te permite eliminar la ficha del oponente
void muerte_subita(int &x, int &y, int **, int &fichas, short &turno, int &song, short contador); //Movimiento libre (3 fichas)
void creditos(); //Aparecen las personas que colaboraron en el desarrollo del juego
short turno; //Determina el turno
bool aux; //aux del aux
struct jugadores{
	string nombre;
	int victoria;
	
}player[2];
int main(){
	//caracteres en español
	setlocale(LC_ALL,"spanish");
	player[0].victoria = 0;
	player[1].victoria = 0;
	inicio();
	return 0;
}
void inicio(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	color(hConsole,9); // Pinta el texto del color especificado
	cout << endl;
			cout << "\t\t\t\t\t\t\t\t    /$$$$$                                              " << endl
			     << "\t\t\t\t\t\t\t\t   |__  $$                                              " << endl
			     << "\t\t\t\t\t\t\t\t      | $$ /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$       " << endl
			     << "\t\t\t\t\t\t\t\t      | $$| $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$      " << endl
			     << "\t\t\t\t\t\t\t\t /$$  | $$| $$  | $$| $$$$$$$$| $$  \\ $$| $$  \\ $$    " << endl
			     << "\t\t\t\t\t\t\t\t| $$  | $$| $$  | $$| $$_____/| $$  | $$| $$  | $$      " << endl
			     << "\t\t\t\t\t\t\t\t|  $$$$$$/|  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$/      " << endl
			     << "\t\t\t\t\t\t\t\t \\______/  \\______/  \\_______/ \\____  $$ \\______/  " << endl
			     << "\t\t\t\t\t\t\t\t       /$$           /$$       /$$  \ $$                " << endl
			     << "\t\t\t\t\t\t\t\t      | $$          | $$      |  $$$$$$/                " << endl
			     << "\t\t\t\t\t\t\t\t  /$$$$$$$  /$$$$$$ | $$       \\______/                " << endl
			     << "\t\t\t\t\t\t\t\t /$$__  $$ /$$__  $$| $$                                " << endl
			     << "\t\t\t\t\t\t\t\t| $$  | $$| $$$$$$$$| $$                                " << endl
			     << "\t\t\t\t\t\t\t\t| $$  | $$| $$_____/| $$                                " << endl
			     << "\t\t\t\t\t\t\t\t|  $$$$$$$|  $$$$$$$| $$                                " << endl
			     << "\t\t\t\t\t\t\t\t \\_______/ \\_______/|__/                              " << endl
			     << "\t\t\t\t\t\t\t\t /$$      /$$           /$$ /$$                         " << endl
			     << "\t\t\t\t\t\t\t\t| $$$    /$$$          | $$|__/                         " << endl
			     << "\t\t\t\t\t\t\t\t| $$$$  /$$$$  /$$$$$$ | $$ /$$ /$$$$$$$   /$$$$$$      " << endl
			     << "\t\t\t\t\t\t\t\t| $$ $$/$$ $$ /$$__  $$| $$| $$| $$__  $$ /$$__  $$     " << endl
			     << "\t\t\t\t\t\t\t\t| $$  $$$| $$| $$  \\ $$| $$| $$| $$  \\ $$| $$  \\ $$  " << endl
			     << "\t\t\t\t\t\t\t\t| $$\\  $ | $$| $$  | $$| $$| $$| $$  | $$| $$  | $$    " << endl
			     << "\t\t\t\t\t\t\t\t| $$ \\/  | $$|  $$$$$$/| $$| $$| $$  | $$|  $$$$$$/    " << endl
			     << "\t\t\t\t\t\t\t\t|__/     |__/ \\______/ |__/|__/|__/  |__/ \\______/    " << endl;
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\tPRESIONE CUALQUIER BOTON PARA EMPEZAR\n";
			color(hConsole,7);
			_getch();
			system("cls");
			menu(); //Se llama al menu de opciones
}
void menu() {
	PlaySound(TEXT("Wait.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP|SND_NOSTOP);
	aux = false;
	//Declaración de variable
	short *opc = new short;
	int *song = new int; *song = 1;
	//Comprobación que la opción ingresada sea correcta
	do{
		do {
		do {
			cout << "\nIngrese una opción:\n1)Jugar\n2)Temas\n3)¿Cómo jugar?\n4)Créditos\n5)Salir\n";
			if(cin>>*opc) {
				system("cls");
				break;
			}
			else {
				system("cls");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				
			}
		} while(true);
	} while(*opc <1 || *opc >5);
	//Según el valor de *opc, se elige una de las siguientes funciones:
	switch(*opc){
		case 1: jugar(*song); break;
		case 2:
			system("cls");
		    *song = temas();
		    system("cls");
		    break;
		case 3: 
		    system("cls");
		    instrucciones(); 
		    break;
		case 4:
		   system("cls");
		   creditos();
		   break;
		case 5:
		    system("cls");
		    cout << "Programa finalizado";
		    exit(0);
		    break;
		/*Solo por si acaso algo vaya a fallar*/
		default: 
		    cout << "ERROR!";
		    system("cls");
		    menu(); 
		    break; 
	}
	}while(*opc!=5);
	
	opc = NULL;
	delete opc;
}

void jugar(int &song){
	auxiliar_activo();
	system("cls");
	bool *revancha = new bool; *revancha = false;
	if(player[0].victoria>0 || player[1].victoria>0){
		cout << "\n\t-------------------------------";
		cout << "\n\tN° Victorias de " << player[0].nombre << ": " << player[0].victoria;
		cout << "\n\tN° Victorias de " << player[1].nombre << ": " << player[1].victoria;
		cout << "\n\t-------------------------------";
		cout << "\n\n\t*-¿Revancha?-*\n";
		cout << "\tSi(1) ~ No(0)";
		do{
			do{
				if(cin >> *revancha) break;
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
				}
			}while(true);
		}while(*revancha != 0 && *revancha != 1);
	}
	short *auxiliar = new short;
	if(!*revancha){	
		*auxiliar = rand()%9;
	system("cls");
	if(*auxiliar < 5) {
		for(int i=0; i<=1;i++){
		cout << "Ingrese los datos del jugador "<<i+1<<":\n";
	    cin >> player[i].nombre;
	    player[i].victoria = 0;
	    }
	}
	else {
		for(int i=0, j=1; i<=1;i++,j--){
		cout << "Ingrese los datos del jugador "<<i+1<<":\n";
	    cin >> player[j].nombre;
	    player[j].victoria = 0;
	        }
	    }
	}
	system("cls");
	turno = 1;
	PlaySound(NULL,0,0);
	//Reproduce la música
	//Repro.Musica(nombre de canción,NULL,lee el nombre de archivo)
	switch(song){
		case 1: PlaySound(TEXT("Predeterminado.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 2: PlaySound(TEXT("Bloque.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 3: PlaySound(TEXT("Retro.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 4: PlaySound(TEXT("Escolar.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 5: PlaySound(TEXT("Elegante.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 6: PlaySound(TEXT("Fantasia.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 7: PlaySound(TEXT("Tenebroso.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 8: PlaySound(TEXT("Galaxia.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		case 9: PlaySound(TEXT("Tuberias.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
	}
	int *fichas = new int; *fichas = 5; //Fichas del tablero
	tablero_inicial(*fichas,turno,song); //Se dibuja el tablero
	//Se borran los punteros
    fichas = NULL;
	delete fichas;
}
void jugador1(int **mapa, int &fichas, int &song){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(turno==1){
		cout <<"\nTurno del jugador " <<player[0].nombre;
		cout << " ("; color(hConsole,17); cout <<turno; color(hConsole,7); cout << ")";
	} else {
		cout<<"\nTurno del jugador " <<player[1].nombre;
		cout << " ("; color(hConsole,204); cout <<turno; color(hConsole,7); cout << ")";
	}
	//Declaración de punteros
	int *x = new int;
	int *y = new int;
	int *sinfichas1 = new int;
	short *contador = new short[2]; contador[0] = 0; contador[1] = 0;
    bool *win = new bool;
    
	    (fichas==-1)? *sinfichas1 = 1: *sinfichas1 = 0;
    if(*sinfichas1==1){
    	sin_movimientos(mapa,turno);
    	for(int i=0; i<=6; i++){
	            for(int j=0; j<=6;j++){
		            if(mapa[i][j]== 1) contador[0] +=1;
		            else if(mapa[i][j] == 2)contador[1] += 1;
		        }
	        } //Se cuenta si alguno de los jugadores tiene menos de 3 fichas (perdió)
	    if ((contador[0] == 3 || contador[1] == 3) && aux == false){
	    	aux = true;
	    	(contador[0]==3)? cout << "\nJugador 1 en peligro": cout << "\nJugador 2 en peligro!";
	    	switch(song){
	    		case 1: PlaySound(TEXT("Predeterminado_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 2: PlaySound(TEXT("Bloque_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 3: PlaySound(TEXT("Retro_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 4: PlaySound(TEXT("Escolar_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 5: PlaySound(TEXT("Elegante_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 6: PlaySound(TEXT("Fantasia_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 7: PlaySound(TEXT("Tenebroso_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 8: PlaySound(TEXT("Galaxia_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
		        case 9: PlaySound(TEXT("Tuberias_MS.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP); break;
			}
		}
	    else if(contador[0]<3){
		    *win = true;
		    system("cls");
            gameover(*win);
	    } else if(contador[1]<3){
		    system("cls");
		    *win = false;
		    gameover(*win);
	        }
	}
	//Dibuja el tablero
	dibujar_tablero(mapa,fichas,turno,song);
	//Ingresa las coordenadas de x
	do {
	    cout << "\nIngrese las coordenadas: (x)(y)\n";
		do {
			cout << "X:";
			if(cin >> *x) break;
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		} while(true);
	} while(*x<-1 || *x>6);
	/*Te permite salir*/
	if(*x == -1||*y == -1) {
		//Para la música
		PlaySound(NULL,0,0);
		system("cls");
		turno = 1;
		menu();
	}
	//Ingresa las coordenadas de y
	else {
	    do{
		    do{
			    cout << "Y:";
			    if(cin >> *y) break;
			    else {
				    cin.clear();
				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    }
		    } while(true);
	    } while(*y<-1 || *y>6);
	    
	    /*Te permite salir*/
	    if(*y == -1 || *x==-1) {
	    	//Para la música
	    	PlaySound(NULL,0,0);
		    system("cls");
		    turno = 1;
		    menu();
	    } else {
	    	/*Se comprueba si la posicion es correcta y se 
	        vuelve a imprimir el tablero en pantalla*/
	    if(contador[0] <= 3 && *sinfichas1 == 1 && turno==1){
	    	muerte_subita(*x,*y,mapa,fichas,turno,song,contador[0]);
		} 
	    else if(contador[1] <= 3 && *sinfichas1 == 1 && turno==2) {
	    	muerte_subita(*x,*y,mapa,fichas,turno,song,contador[1]);
		}
	    //Si sinfichas es verdadero, se empezarán a mover las fichas
		else if(*sinfichas1==1) mover_fichas(*x,*y, mapa,fichas,turno,song);
		//Sino, se pondrán las fichas
		else comprobar_posicion(*x,*y,mapa,fichas,turno,song);
	 }
    }
    //Se borran los punteros
	x,y,sinfichas1 = NULL;
	delete x,y,sinfichas1;
	contador,win = NULL;
	delete []contador; delete win;
}

void gameover(bool &win){
	system("cls");
	PlaySound(TEXT("Success.wav"),NULL, SND_FILENAME|SND_ASYNC);
	if(!win){
		cout << "\n\n\n\t------------------\n\tGanó el jugador 1";
		cout << "\n\tFelicidades " << player[0].nombre;
		cout << "\n\tJuego Terminado\n\t------------------";
		player[0].victoria+=1;
	} else{
		cout << "\n\n\n\t------------------\n\tGanó el jugador 2";
		cout << "\n\tFelicidades " << player[1].nombre;
		cout << "\n\tJuego Terminado\n\t------------------";
		player[1].victoria+=1;
	}
	getch();
	PlaySound(NULL,0,0);
	system("cls");
	menu();
}

