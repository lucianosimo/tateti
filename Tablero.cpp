//
// Created by ake on 24/6/20.
//

#include "Tablero.h"
#include "conio2.h"

Tablero::Tablero() {
	int celda = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char casillero = '0';
			celda++;
			casillero = casillero + celda;
			
			mapa[i][j].setFigura(casillero);
		}
	}
}

void Tablero::setFichaIn(int x, int y, char c){
	if (!hayFicha(x, y)) {
		mapa[x][y] = c;
	} else {
		cout << endl << "Esa posicion ya esta ocupada" << endl << endl;
	}
	
}

void Tablero::mostrar() {
	cout << "=================" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|| ";
		for (int j = 0; j < 3; j++) {
			
			if (hayFicha(i, j)) {
				textcolor(RED);
			} else {
				textcolor(GREEN);
			}
			
			cout << mapa[i][j].getFigura();
			textcolor(WHITE);
			cout << " || ";
		}
		cout << endl << "=================" << endl;
	}
	cout << endl;
}

bool Tablero::hayFicha(int x, int y) {
	if (mapa[x][y].getFigura() == 'X' || mapa[x][y].getFigura() == '0') {
		return true;
	}
	
	return false;
}

bool Tablero::compararFichas(int x0,int y0,int x1 ,int y1, int x2, int y2){
	return (mapa[x0][y0].getFigura() == mapa[x1][y1].getFigura()) && (mapa[x1][y1].getFigura() == mapa[x2][y2].getFigura());
}

bool Tablero::isComplete(){
	int vacios = 9;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mapa[i][j].getFigura() == 'X' || mapa[i][j].getFigura() == '0') {
				vacios--;
			}
		}
	}
	
	return vacios == 0;
}
