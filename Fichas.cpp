//Fichas
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <limits>
#include <windows.h>
using namespace std;
void menu();
void jugador1(int **, int &fichas,int &song);
void cambiar_valor(int &x, int &y, int **, int &fichas,short &turno,int &song);
void mover_fichas(int &x, int &y, int**, int &fichas,  short &turno,int &song);
void molino(int &x, int &y, int **, int &fichas,short &turno,int &song);
void dibujar_tablero(int **, int &fichas,short &turno,int &song);
void eliminar(int &x, int &y, int **, int &fichas,short &turno,int &song);
void comprobar_posicicion(int &x, int &y, int **mapa, int &fichas,short &turno,int &song);
void muerte_subita(int &x, int &y, int **, int &fichas, short &turno, int &song, short contador);
void sin_movimientos(int **);
void activo(int **);
void auxiliar_activo();
void gameover(bool &win);

void cambiar_valor(int &x, int &y, int **mapa, int &fichas,short &turno,int &song){
	/*Como el cuadrado es de 8*8 y solo usamos 6*6, x,y
	tiene el valor predeterminado de 7, si es que no vale
	eso, será asignado el valor correspondiente*/
	if(x!=7 && y!=7 && mapa[x][y] != 1 && mapa[x][y] != 2){
	system("cls");
	mapa[x][y] = turno;
	(turno==1)? turno=2: turno=1;
	if(fichas!=0 && turno == 2) fichas -= 1;
	else if(fichas==0 && turno==1) fichas -=1;
	//Disminuye en 1 las fichas del jugador
	//Se comprueba si en el anterior turno hubo un molino
	molino(x,y,mapa,fichas,turno,song);
	} else if(mapa[x][y] == 3 || mapa[x][y] == 1){
		//Aqui debe cambiar el color
		system("cls");
		(turno==1)? turno=2: turno=1;
	    cout << "Casilla inválida";
	    //Se dibuja el tablero
	    dibujar_tablero(mapa,fichas,turno,song);
	}
	
	if(fichas==-1) cout << "Jugadores sin fichas" << endl;
}

void comprobar_posicion(int &x, int &y, int **mapa, int &fichas, short &turno,int &song){
/*Si la posición no es válida, los valores de x,y 
se vuelven los predeterminados (7) y se vuelve al tablero de juego.
Si son válidos, solo se cambia el valor al indicado y vuelves al tablero*/
	if(mapa[x][y]!=0){
	    system("cls");
	    x=7;y=7;
	    cout << "Casilla inválida";
	    jugador1(mapa,fichas,song);
    } 
    else { 
	    system("cls");
	    cambiar_valor(x,y,mapa,fichas,turno,song);
	    jugador1(mapa, fichas,song);
    }
}

void mover_fichas(int &x, int &y, int**mapa, int &fichas,short &turno,int &song){
/*En cada fila, si la columna no es válida, los valores de x,y 
se vuelven los predeterminados (7) y se vuelve al tablero de juego.
Si son válidos, se le pedirá al jugador ingresar un valor para moverse hacia 
cualquiera de las 4 direcciones. La posición cambiará al número del jugador, 
la actual cambiará a 0 y se volverá al tablero*/
if(mapa[x][y]!= turno && mapa[x][y] != 4){
	system("cls");
	x=7;y=7;
	cout << "Coordenada inválida";
	jugador1(mapa, fichas,song);
}
char *movimiento = new char;
    do{
    	do{
    		cout << "\n¿Hacia dónde quiere moverse?\n Arriba(W) - Abajo(S) \n Izquiera (A) - Derecha (D): ";
    		if(cin>>*movimiento) break;
    		else {
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		}while(true);
	//El caracter obtenido se vuelve mayúscula
	*movimiento = toupper(*movimiento);	
	}while(*movimiento!='A' && *movimiento !='D' && *movimiento!='S' && *movimiento!='W');
	
	switch(x){
		case 0: case 6:
			//Ninguno puede moverse hacia arriba, estan en la primera fila
			if((*movimiento == 'W' && x==0) || (*movimiento == 'S' && x==6) || 
			(y==0 && *movimiento == 'A') || (y==6 && *movimiento == 'D')) {
				system("cls");
				cout << "Movimiento inválido\n";
				x=7; y=7;
				jugador1(mapa, fichas,song); 
			}
				else{
					switch(*movimiento){
						case 'A': case 'D':
							if((mapa[x][y-3]!=0 && *movimiento == 'A')||(mapa[x][y+3]!=0)&& *movimiento == 'D'){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa, fichas,song);  
			    	            break;
							}else {
								mapa[x][y] = 0;
								(*movimiento=='A')?y-= 3:y+=3;
								mapa[x][y] = turno;
								system("cls");
								(turno==1)? turno=2: turno=1;
								//Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
								x=7;y=7;
							    jugador1(mapa, fichas,song); 
							    break;
							}
							
						case 'S': case 'W':
							if((*movimiento == 'S' && mapa[x+3][y] !=0 && mapa[x+1][y]!=0) || 
							(*movimiento == 'W' && mapa[x-3][y] !=0 && mapa[x-1][y]!=0)){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa, fichas,song); 
			    	            break;
							}else {
								mapa[x][y] = 0;
								if(*movimiento=='S') {
									(y!=3)?x+=3:x+=1;
								} else {
									(y!=3)?x-=3:x-=1;
								}
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
	                            //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
						        x=7;y=7;
							    jugador1(mapa, fichas,song); 
							    break;
							    }
					        }
				        }
//-------------------------------------------------				
		case 1:
			if((*movimiento == 'W' && y!=3 && x==1) || (y==1 && *movimiento == 'A') || (y==5 && *movimiento == 'D')) {
				system("cls");
				cout << "Movimiento inválido\n";
				x=7; y=7;
				jugador1(mapa, fichas,song); 
			}
			else{ 
					switch(*movimiento){
						case 'A': case 'D':
							if((mapa[x][y-2]!=0 && *movimiento == 'A') ||(mapa[x][y+2]!=0 && *movimiento == 'D')){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa, fichas,song);
			    	            break;
							} else {
								mapa[x][y] = 0;
								(*movimiento == 'A')? y-= 2: y+= 2;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
							    x=7;y=7;
							    jugador1(mapa, fichas,song);
							    break;
							}
						case 'W': case 'S':
							if(x==1 && (y==1||y==5) && *movimiento =='S') {
								mapa[x][y] = 0;
								x+= 2;
								mapa[x][y] = turno;
								(turno==1)? turno=2: turno=1;
								//Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
						    	x=7;y=7;
							    system("cls");
							    jugador1(mapa,fichas,song);
							    break;
							}
							else if((mapa[x-1][y]!=0 && *movimiento == 'W' && y==3)|| (mapa[x+1][y]!=0 && *movimiento == 'S' && y==3) 
							       ||( mapa[x+2][y]!=0 && *movimiento == 'S' && y!=3)){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa,fichas,song);
			    	            break;
							} else {
								mapa[x][y] = 0;
								if (*movimiento == 'W')x-=1;
								else (y!=3)?x+=2:x+=1;
							    mapa[x][y] = turno;
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
						    	x=7;y=7;
							    system("cls");
							    jugador1(mapa,fichas,song);
							    break;
							}
					    }
				    }
//-------------------------------------------------
        case 5:
			if((*movimiento == 'S' && y!=3 && x==5) || (y==1 && *movimiento == 'A') || (y==5 && *movimiento == 'D')) {
				system("cls");
				cout << "Movimiento inválido\n";
				x=7; y=7;
				jugador1(mapa, fichas,song); 
			}
			else{ 
					switch(*movimiento){
						case 'A': case 'D':
							if((mapa[x][y-2]!=0 && *movimiento == 'A') ||(mapa[x][y+2]!=0 && *movimiento == 'D')){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa, fichas,song);
			    	            break;
							} else {
								mapa[x][y] = 0;
								(*movimiento == 'A')? y-= 2: y+= 2;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
							    x=7;y=7;
							    jugador1(mapa, fichas,song);
							    break;
							}
						case 'W': case 'S':
						    if((mapa[x-1][y]!=0 && *movimiento == 'W' && y==3)|| (mapa[x-2][y]!=0 && *movimiento == 'W' && y!=3)
							 ||(mapa[x+2][y]!=0 && *movimiento == 'S'&&y!=3) || ( mapa[x+1][y]!=0 && *movimiento == 'S'&&y==3)){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa,fichas,song);
			    	            break;
							} else {
								mapa[x][y] = 0;
								if (*movimiento == 'W')(y!=3)?x-=2:x-=1;
								else x+=1;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
						    	x=7;y=7;
							    jugador1(mapa,fichas,song);
							    break;
							}
					    }
				    }
//-------------------------------------------------				
		case 2: case 4: 
			if(((*movimiento == 'W' && y!=3 && x==2) || (*movimiento == 'S' && y!=3 && x==4))||
			(y==2 && *movimiento == 'A') || y==4 && *movimiento == 'D') {
				system("cls");
				cout << "Movimiento inválido\n";
				x=7; y=7;
				jugador1(mapa, fichas,song);
			    }else{
					switch(*movimiento){
						case 'A': case 'D':
							if((mapa[x][y-1]!=0 && *movimiento == 'A') || (mapa[x][y+1]!=0 && *movimiento == 'D')){
								system("cls");
				                cout << "Movimiento inválido\n";
				                x=7; y=7;
				                jugador1(mapa, fichas,song);
							} else {
								mapa[x][y] = 0;
							    (*movimiento=='A')? y-= 1: y+=1;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;							    
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
							    x=7;y=7;
							    jugador1(mapa, fichas,song);
						    	break;
							}
	
						case 'W': case 'S':
							if((mapa[x-1][y]!=0 && *movimiento == 'W') || (mapa[x+1][y]!=0 && *movimiento == 'S')){
								system("cls");
				                cout << "Movimiento inválido\n";
				                x=7; y=7;
				                jugador1(mapa, fichas,song);
							} else {
								mapa[x][y] = 0;
							    (*movimiento=='W')? x-=1: x+=1;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
							    x=7;y=7;
							    jugador1(mapa, fichas,song);
							    break;
							}
							
					    }
				    }
//-------------------------------------------------
        case 3:
			if((y==4 && *movimiento == 'A')||((y==2||y==6) && *movimiento == 'D')) {
			    system("cls");
				cout << "Movimiento inválido\n";
			    x=7; y=7;
			    jugador1(mapa, fichas,song);
			}else{
				switch(*movimiento){
					case 'A': case 'D':
						if((mapa[x][y-1]!=0 && *movimiento == 'A') || (mapa[x][y+1]!=0 && *movimiento == 'D')){
							system("cls");
				            cout << "Movimiento inválido\n";
			    	        x=7; y=7;
			    	        jugador1(mapa, fichas,song);
			    	        break;
						} else {
							mapa[x][y] = 0;
							(*movimiento == 'A')?y-= 1 : y+=1;
							mapa[x][y] = turno;
							system("cls");
							(turno==1)? turno=2: turno=1;
							//Se comprueba si en el anterior turno hubo un molino
	                        molino(x,y,mapa,fichas,turno,song);
							jugador1(mapa, fichas,song);
							break;
							}
							
						case 'W': case 'S':
							if((mapa[x-1][y]!=0 && mapa[x-2][y] !=0 && mapa[x-3][y] !=0 && *movimiento == 'W')
							|| (mapa[x+1][y]!=0 && mapa[x+2][y] !=0 && mapa[x+3][y] !=0 && *movimiento == 'S')){
								system("cls");
				                cout << "Movimiento inválido\n";
			    	            x=7; y=7;
			    	            jugador1(mapa, fichas,song);
			    	            break;
							}else {
								mapa[x][y] = 0;
							    if(y==0 || y==6) {
							        (*movimiento == 'W')? x-=3 : x+=3;
								} else if (y==1 || y==5) {
									(*movimiento == 'W')? x-=2: x+=2;
								} else (*movimiento=='W')? x-=1: x+=1;
							    mapa[x][y] = turno;
							    system("cls");
							    (turno==1)? turno=2: turno=1;
							    //Se comprueba si en el anterior turno hubo un molino
	                            molino(x,y,mapa,fichas,turno,song);
							    x=7;y=7;
							    jugador1(mapa, fichas,song);
							    break;
							}
					    }
				    }
				}						
	movimiento =NULL;
	delete movimiento;
}

void muerte_subita(int &x, int &y, int **mapa, int &fichas, short &turno, int &song, short contador){
	
	int *copy_x = new int; *copy_x = x;
	int *copy_y = new int; *copy_y = y;
	cout << "\nIngrese las coordenadas de destino: (x)(y)\n";
	do {
		do {
			cout << "X:";
			if(cin >> x) break;
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		} while(true);
	} while(x<-1 || x>6);
	/*Te permite salir*/
	if(x == -1||y == -1) {
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
			    if(cin >> y) break;
			    else {
				    cin.clear();
				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			    }
		    } while(true);
	    } while(y<-1 || y>6);
	    /*Te permite salir*/
	    if(y == -1 || x==-1) {
	    	//Para la música
	    	PlaySound(NULL,0,0);
		    system("cls");
		    turno = 1;
		    menu();
	} else if(*copy_x==x && *copy_y==y || mapa[*copy_x][*copy_y] == 0 || mapa[x][y] != 0){
		copy_x, copy_y = NULL;
		delete copy_x, copy_y;
		x=7;y=7;
		system("cls");
		cout << "Casilla inválida";
		jugador1(mapa,fichas,song);
	} else {
		mapa[*copy_x][*copy_y] = 0;
		mapa[x][y] = turno;
		system("cls");
		(turno==1)? turno=2: turno=1;
		//Se comprueba si en el anterior turno hubo un molino
	    molino(x,y,mapa,fichas,turno,song);
		x=7;y=7;
		jugador1(mapa, fichas,song); 
		copy_x, copy_y = NULL;
		delete copy_x, copy_y;
	}	
	}
}

void sin_movimientos(int **mapa, short &turno){
	int *j1 = new int; *j1 = 0;
	int *j2 = new int; *j2 = 0;
	bool *win = new bool;
	int *contador1 = new int; *contador1 = 0;
	int *contador2 = new int; *contador2 = 0;
	int **copia; copia = new int*[8];
	//Espacios disponibles, (fila y columna 7 no cuentan)
	for(int i=0; i<=8; i++){
	    copia[i]= new int [8];
	}
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7;j++){
			copia[i][j] = mapa[i][j];
			if(copia[i][j]==1) *j1+=1; 
			if(copia[i][j]==2) *j2+=1;
		}
	}
	//Fila 0
	if(mapa[0][0] == turno && mapa[0][3] != 0 && mapa[3][0] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[0][3] == turno && mapa[0][0] != 0 && mapa[1][3] !=0 && mapa[0][6] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[0][6] == turno && mapa[0][3] != 0 && mapa[3][6] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 1
	if(mapa[1][1] == turno && mapa[1][3] != 0 && mapa[3][1] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[1][3] == turno && mapa[1][1] != 0 && mapa[1][5] !=0 && mapa[0][3] != 0 && mapa[2][3] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[1][5] == turno && mapa[1][3] != 0 && mapa[3][5] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 2
	if(mapa[2][2] == turno && mapa[2][3] != 0 && mapa[3][2] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[2][3] == turno && mapa[2][2] != 0 && mapa[1][3] !=0 && mapa[2][4] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[2][4] == turno && mapa[2][3] != 0 && mapa[3][4] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 3 A
	if(mapa[3][0] == turno && mapa[3][1] != 0 && mapa[0][0] !=0 && mapa[6][0] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[3][1] == turno && mapa[3][0] != 0 && mapa[3][2] !=0 && mapa[1][1] != 0 && mapa[5][1] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[3][2] == turno && mapa[2][2] != 0 && mapa[4][2] !=0 && mapa[3][1] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	//Fila 3 B
	if(mapa[3][6] == turno && mapa[3][5] != 0 && mapa[0][6] !=0 && mapa[6][6] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[3][5] == turno && mapa[3][4] != 0 && mapa[3][6] !=0 && mapa[1][5] != 0 && mapa[5][5] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[3][4] == turno && mapa[2][4] != 0 && mapa[4][4] !=0 && mapa[3][5] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 4
	if(mapa[4][2] == turno && mapa[4][3] != 0 && mapa[3][2] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[4][3] == turno && mapa[4][2] != 0 && mapa[1][5] !=0 && mapa[4][4] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[4][4] == turno && mapa[4][3] != 0 && mapa[3][4] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 5
	if(mapa[5][1] == turno && mapa[5][3] != 0 && mapa[3][1] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[5][3] == turno && mapa[5][1] != 0 && mapa[5][5] !=0 && mapa[4][3] != 0 && mapa[6][3] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[5][5] == turno && mapa[5][3] != 0 && mapa[3][5] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	//Fila 6
	if(mapa[6][0] == turno && mapa[6][3] != 0 && mapa[3][0] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[6][3] == turno && mapa[6][0] != 0 && mapa[5][3] !=0 && mapa[6][6] != 0) (turno==1)?*contador1 +=1:*contador2 +=1;
	if(mapa[6][6] == turno && mapa[6][3] != 0 && mapa[3][6] !=0) (turno==1)?*contador1 +=1:*contador2 +=1;
	
	if(*contador1 >= *j1){
		*win = true;
		gameover(*win);
	} else if(*contador2 >= *j2){
		*win = false;
		gameover(*win);
	}
}
