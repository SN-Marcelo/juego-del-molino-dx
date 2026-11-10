//Molino
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <limits>
#include <windows.h>
using namespace std;
void menu();
void dibujar_tablero(int **, int &fichas,short &turno,int &song);
void molino(int &x, int &y, int **, int &fichas,short &turno,int &song);
void auxiliar_molino(int &x, int &y, int **, int &fichas,short &turno,int &song); //Para no escribir lo mismo a cada rato
void eliminar(int &x, int &y, int **, int &fichas,short &turno,int &song);
void auxiliar_eliminar(int &x, int &y, int **, int &fichas,short &turno,int &song); //Para no escribir lo mismo a cada rato
void activo(int **, short &turno);
void auxiliar_activo();
bool activado[16];

void auxiliar_activo(){
	for(int i=0; i<16; i++) activado[i] = false;
}

void molino(int &x, int &y, int **mapa, int &fichas,short &turno,int &song){
	switch(x){
		case 0:
			//Fila 0, horizontal
			if((mapa[0][0] == mapa[0][3]) && (mapa[0][3] == mapa[0][6]) && (mapa[0][0] !=0 && mapa[0][0] !=turno) && x==0){
				auxiliar_molino(x,y,mapa,fichas,turno,song);
			} // Fila 0, Columna 0
			else if((mapa[0][0] == mapa[3][0]) && (mapa[3][0] == mapa[6][0]) && (mapa[0][0] !=0 && mapa[0][0] !=turno) && (y==0)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
			//Fila 0, Columna 3 
			else if((mapa[0][3] == mapa[1][3]) && (mapa[1][3] == mapa[2][3]) && (mapa[1][3] !=0 && mapa[1][3] !=turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 0, Columna 6
			else if((mapa[0][6] == mapa[3][6]) && (mapa[3][6] == mapa[6][6]) && (mapa[6][6] !=0 && mapa[6][6] !=turno) && y==6){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
	    case 1:
	    	//Fila 1, horizontal
	        if((mapa[1][1] == mapa[1][3]) && (mapa[1][3] == mapa[1][5]) && (mapa[1][1] !=0 && mapa[1][1] !=turno) && x==1){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    }
	        // Fila 1, Columna 1
	        else if ((mapa[1][1] == mapa[3][1]) && (mapa[3][1] == mapa[5][1]) && (mapa[1][1] !=0 && mapa[1][1] !=turno) && y==1) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        }//Fila 1, Columna 3
	        else if((mapa[0][3] == mapa[1][3]) && (mapa[1][3] == mapa[2][3]) && (mapa[1][3] !=0 && mapa[1][3] !=turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    }// Fila 1, Columna 5
		    else if(((mapa[1][5] == mapa[3][5]) && (mapa[3][5] == mapa[5][5]) && (mapa[5][5] !=0 && mapa[5][5] !=turno)) && y==5){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		}
		case 2:
			//Fila 2, horizontal
			if((mapa[2][2] == mapa[2][3]) && (mapa[2][3] == mapa[2][4]) && (mapa[2][2] !=0 && mapa[2][2] !=turno) && x==2) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 2, Columna 2
			else if ((mapa[2][2] == mapa[3][2]) && (mapa[3][2] == mapa[4][2]) && (mapa[2][2] !=0 && mapa[2][2] !=turno) && y==2) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        }//Fila 2, Columna 3
	        else if((mapa[0][3] == mapa[1][3]) && (mapa[1][3] == mapa[2][3]) && (mapa[1][3] !=0 && mapa[1][3] !=turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    }//Fila 2, Columna 4
		    else if((mapa[2][4] == mapa[3][4]) && (mapa[3][4] == mapa[4][4]) && (mapa[4][4] !=0 && mapa[4][4] !=turno)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
		case 3:
			//Fila 3, horizontal A
			if((mapa[3][0] == mapa[3][1]) && (mapa[3][1] == mapa[3][2]) && (mapa[3][0] !=0 && mapa[3][0] !=turno) && x==3 && y<=2){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 3, horizontal B
			else if ((mapa[3][4] == mapa[3][5]) && (mapa[3][5] == mapa[3][6]) && (mapa[3][4] !=0 && mapa[3][4] !=turno) && x==3 && y>=4){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	    	system("cls");
	        }
		    // Fila 3, Columna 0
			else if((mapa[0][0] == mapa[3][0]) && (mapa[3][0] == mapa[6][0]) && (mapa[0][0] !=0 && mapa[0][0] !=turno) && (y==0)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		        system("cls");
			}//Fila 3, Columna 2
			else if ((mapa[2][2] == mapa[3][2]) && (mapa[3][2] == mapa[4][2]) && (mapa[2][2] !=0 && mapa[2][2] !=turno) && y==2) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        } //Fila 3, Columna 4
	        else if((mapa[2][4] == mapa[3][4]) && (mapa[3][4] == mapa[4][4]) && (mapa[4][4] !=0 && mapa[4][4] !=turno) && y==4){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 3, Columna 6
			else if((mapa[0][6] == mapa[3][6]) && (mapa[3][6] == mapa[6][6]) && (mapa[6][6] !=0 && mapa[6][6] !=turno) && y==6){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
		case 4:
			//Fila 4, horizontal
			if((mapa[4][2] == mapa[4][3]) && (mapa[4][3] == mapa[4][4]) && (mapa[4][2] !=0 && mapa[4][2] !=turno && x==4)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}//Fila 4, Columna 2
			else if ((mapa[2][2] == mapa[3][2]) && (mapa[3][2] == mapa[4][2]) && (mapa[2][2] !=0 && mapa[2][2] !=turno) && y==2) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        }//Fila 4, Columna 3
	        else if((mapa[4][3] == mapa[5][3]) && (mapa[5][3] == mapa[6][3]) && (mapa[5][3] !=0 &&  mapa[5][3] != turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    } //Fila 4, Columna 4
		    else if((mapa[2][4] == mapa[3][4]) && (mapa[3][4] == mapa[4][4]) && (mapa[4][4] !=0 && mapa[4][4] !=turno) && y==4){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
		case 5:
			//Fila 5, horizontal
			if((mapa[5][1] == mapa[5][3]) && (mapa[5][3] == mapa[5][5]) && (mapa[5][5] !=0 && mapa[5][5] !=turno && x==5)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 5, Columna 1
			else if ((mapa[1][1] == mapa[3][1]) && (mapa[3][1] == mapa[5][1]) && (mapa[1][1] !=0 && mapa[1][1] !=turno) && y==1) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        } //Fila 5, Columna 3
	        else if((mapa[4][3] == mapa[5][3]) && (mapa[5][3] == mapa[6][3]) && (mapa[5][3] !=0 && mapa[5][3] != turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    }//Fila 5, Columna 5
		    else if(((mapa[1][5] == mapa[3][5]) && (mapa[3][5] == mapa[5][5]) && (mapa[5][5] !=0 && mapa[5][5] !=turno)) && y==5){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
		    }
		case 6:
			//Fila 6, horizontal
	        if((mapa[6][0] == mapa[6][3]) && (mapa[6][3] == mapa[6][6]) && (mapa[6][6] !=0 && mapa[6][6] !=turno) && x==6) {
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
	        } //Fila 6, Columna 0
	        else if((mapa[0][0] == mapa[3][0]) && (mapa[3][0] == mapa[6][0]) && (mapa[0][0] !=0 && mapa[0][0] !=turno) && (y==0)){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
			//Fila 6, Columna 3 
			else if((mapa[4][3] == mapa[5][3]) && (mapa[5][3] == mapa[6][3]) && (mapa[5][3] !=0 && mapa[5][3] != turno) && y==3){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			} //Fila 6, Columna 6
			else if((mapa[0][6] == mapa[3][6]) && (mapa[3][6] == mapa[6][6]) && (mapa[6][6] !=0 && mapa[6][6] !=turno) && y==6){
	            auxiliar_molino(x,y,mapa,fichas,turno,song);
			}
    }
}
void auxiliar_molino(int &x, int &y, int **mapa, int &fichas,short &turno,int &song){
	dibujar_tablero(mapa,fichas,turno,song); //Dibuja el tablero
	cout << "\t   Molino!" <<endl;
	activo(mapa,turno); //Se activa el molino
	eliminar(x,y,mapa,fichas,turno,song); //Se elimina las fichas
	system("cls");
}

void eliminar(int &x, int &y, int **mapa, int &fichas,short &turno,int &song){
	cout<< "Elige una ficha para eliminar:\n";
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
	        }
	if(mapa[x][y] == turno && mapa[x][y] != 0) {
		switch(x){
			case 0: 
			    if(activado[0] || (activado[1] && y==0) || (activado[2] && y==3) || (activado[3] && y==6)){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					} else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			    
			case 1:
				if((activado[2] && y==3) || activado[4] || (activado[5] && y==1) || (activado[6] && y==5)){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			    
			case 2:
				if((activado[2] && y==3) || activado[7] || (activado[8] && y==2) || (activado[9] && y==4)){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			    
			case 3:
				if((activado[1] && y==0) || (activado[2] && y==3) || (activado[5] && y==1) || (activado[6] && y==5) || 
				  (activado[8] && y==2)|| (activado[9] && y==4) || activado[10] || activado[11]){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			    
			case 4:
				if((activado[8] && y==2) || (activado[9] && y==4) || activado[12] || (activado[13] && y==3)){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			
			case 5:
				if((activado[5] && y==1) || (activado[6] && y==5) || activado[12] || activado[14]){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
			
			case 6:
				if((activado[1] && y==0) || (activado[3] && y==6) || (activado[13] && y==3) || activado[15]){
				    auxiliar_eliminar(x,y,mapa,fichas,turno,song); 
					}else {
						mapa [x][y] = 0;
	                    system("cls");
					}break;
		}
	} else auxiliar_eliminar(x,y,mapa,fichas,turno,song);
  }
}
void auxiliar_eliminar(int &x, int &y, int **mapa, int &fichas,short &turno,int &song){
	system("cls"); //Borra pantalla
	cout << "Coordenada inválida";
	dibujar_tablero(mapa,fichas,turno,song); //Dibuja tablero
	eliminar(x,y,mapa,fichas,turno,song); //Se vuelve a ejecutar la función eliminar
}

void activo(int **mapa, short &turno){
	//Auxiliares, para detectar si todas las fichas están en un molino 
	int *j1 = new int; *j1 = 0;
	int *j2 = new int; *j2 = 0;
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
	//Fila 0  horizontal
    if((mapa[0][0] == mapa[0][3]) && (mapa[0][3] == mapa[0][6]) && mapa[0][0] !=0) {
    	activado[0] = true;
    	if(turno==2) for(int i=0;i<=6;i+=3) copia[0][i] = 5;
		else for(int j=0;j<=6;j+=3) copia[0][j] = 6;
	} else activado[0] = false;
	// Fila 0 :: Fila 3 :: Fila 6, Columna 0
	if((mapa[0][0] == mapa[3][0]) && (mapa[3][0] == mapa[6][0]) && mapa[0][0] !=0){
		activado[1] = true;
	    if(turno==2) for(int i=0;i<=6;i+=3) copia[i][0] = 5;
	    else for(int i=0;i<=6;i+=3) copia[i][0] = 6;
	}  else activado[1] = false;
	//Fila 0 :: Fila 1 :: Fila 2, Columna 3
	if((mapa[0][3] == mapa[1][3]) && (mapa[1][3] == mapa[2][3]) && mapa[1][3] !=0){
		activado[2] = true;
		if(turno==2) for(int i=0;i<=3;i++) copia[i][3] = 5;
	    else for(int i=0;i<=3;i++) copia[i][3] = 6;
	} else activado[2] = false; 
	//Fila 0 :: Fila 6, Columna 6
	if((mapa[0][6] == mapa[3][6]) && (mapa[3][6] == mapa[6][6]) && mapa[6][6] !=0){
		activado[3] = true;
		if(turno==2) for(int i=0;i<=6;i+=3) copia[i][6] = 5;
	    else for(int i=0;i<=6;i+=3) copia[i][6] = 6;
	}  else activado[3] = false;
	//Fila 1, horizontal
	if((mapa[1][1] == mapa[1][3]) && (mapa[1][3] == mapa[1][5]) && mapa[1][1] !=0){
		activado[4] = true;
		if(turno==2) for(int i=1;i<=5;i+=2) copia[1][i] = 5;
		else for(int j=1;j<=5;j+=2) copia[1][j] = 6;
	}  else activado[4] = false;
	// Fila 1 :: Fila 3 :: Fila 5 Columna 1
	if((mapa[1][1] == mapa[3][1]) && (mapa[3][1] == mapa[5][1]) && mapa[1][1] !=0){
		activado[5] = true;
		if(turno==2) for(int i=1;i<=5;i+=2) copia[i][1] = 5;
	    else for(int i=1;i<=5;i+=2) copia[i][1] = 6;
	}  else activado[5] = false;
	// Fila 1 :: Fila 3 :: Fila 5, Columna 5
	if((mapa[1][5] == mapa[3][5]) && (mapa[3][5] == mapa[5][5]) && mapa[5][5] !=0){
		activado[6] = true;
		if(turno==2) for(int i=1;i<=5;i+=2) copia[i][5] = 5;
	    else for(int i=1;i<=5;i+=2) copia[i][5] = 6;
	}  else activado[6] = false;
	//Fila 2 horizontal
	if((mapa[2][2] == mapa[2][3]) && (mapa[2][3] == mapa[2][4]) && mapa[2][2] !=0){
		activado[7] = true;
		if(turno==2) for(int i=2;i<=4;i++) copia[2][i] = 5;
		else for(int j=2;j<=4;j++) copia[2][j] = 6;
	}  else activado[7] = false;
	//Fila 2 :: Fila 3 :: Fila 4, Columna 2
	if((mapa[2][2] == mapa[3][2]) && (mapa[3][2] == mapa[4][2]) && mapa[2][2] !=0){
		activado[8] = true;
		if(turno==2) for(int i=2;i<=4;i++) copia[i][2] = 5;
	    else for(int i=2;i<=4;i++) copia[i][2] = 6;
	}  else activado[8] = false;
	//Fila 2 :: Fila 3 :: Fila 4, Columna 4
	if((mapa[2][4] == mapa[3][4]) && (mapa[3][4] == mapa[4][4]) && mapa[4][4] !=0){
		activado[9] = true;
		if(turno==2) for(int i=2;i<=4;i++) copia[i][4] = 5;
	    else for(int i=2;i<=4;i++) copia[i][4] = 6;
	}  else activado[9] = false;
	//Fila 3, horizontal A
	if((mapa[3][0] == mapa[3][1]) && (mapa[3][1] == mapa[3][2]) && mapa[3][0] !=0){
		activado[10] = true;
		if(turno==2) for(int i=0;i<=2;i++) copia[3][i] = 5;
		else for(int j=0;j<=2;j++) copia[3][j] = 6;
	}  else activado[10] = false;
	 //Fila 3, horizontal B
	if((mapa[3][4] == mapa[3][5]) && (mapa[3][5] == mapa[3][6]) && mapa[3][4] !=0){
		activado[11] = true;
		if(turno==2) for(int i=4;i<=5;i++) copia[3][i] = 5;
		else for(int j=3;j<=5;j++) copia[3][j] = 6;
	}  else activado[11] = false;
	//Fila 4, horizontal
	if((mapa[4][2] == mapa[4][3]) && (mapa[4][3] == mapa[4][4]) && mapa[4][2] !=0){
		activado[12] = true;
		if(turno==2) for(int i=2;i<=4;i++) copia[4][i] = 5;
		else for(int j=2;j<=4;j++) copia[4][j] = 6;
	}  else activado[12] = false;
	//Fila 4 :: Fila 5 :: Fila 6, Columna 3
	if((mapa[4][3] == mapa[5][3]) && (mapa[5][3] == mapa[6][3]) && mapa[5][3] !=0){
		activado[13] = true;
		if(turno==2) for(int i=4;i<=6;i++) copia[i][3] = 5;
	    else for(int i=4;i<=6;i++) copia[i][4] = 6;
	}  else activado[13] = false;
	//Fila 5, horizontal
	if((mapa[5][1] == mapa[5][3]) && (mapa[5][3] == mapa[5][5]) && mapa[5][5] !=0){
		activado[14] = true;
		if(turno==2) for(int i=1;i<=5;i+=2) copia[5][i] = 5;
		else for(int j=1;j<=5;j+=2) copia[5][j] = 6;
	}  else activado[14] = false;
	//Fila 6, horizontal
	if((mapa[6][0] == mapa[6][3]) && (mapa[6][3] == mapa[6][6]) && mapa[6][6] !=0){
		activado[15] = true;
		if(turno==2) for(int i=0;i<=6;i+=3) copia[6][i] = 5;
		else for(int j=0;j<=6;j+=3) copia[6][j] = 6;
	}  else activado[15] = false;
	//Comprobar todas las fichas estan en un molino
	for(int i=0; i<=6; i++){
		for(int j=0; j<=6;j++){
			if(copia[i][j] == 5) *contador1 += 1;
			if(copia[i][j] == 6) *contador2 += 1;
		}
	}
	if(turno==1 && *contador2 == *j2){
		for(int i=0;i<16;i++) activado[i] = false;
	}
	if(turno==2 && *contador1 == *j1){
		for(int i=0;i<16;i++) activado[i] = false;
	}
}
