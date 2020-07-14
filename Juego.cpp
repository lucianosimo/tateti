//
// Created by ake on 24/6/20.
//

#include "Juego.h"
#include "conio2.h"

//Metodos privados
void Juego::setFichaIn(int x, int y, char c) {
	miTablero.setFichaIn(x, y, c);
}

void Juego::imprimirPantalla(bool opciones) {
	if (opciones) {
		miTablero.mostrar();
	} else {
		imprimirCabecera();
	}

}

void Juego::imprimirTablero() {
	miTablero.mostrar();
}

void Juego::imprimirSeparador() {
	textcolor(RED);
	cout << endl << "**************************" << endl;
	cout << "**************************" << endl << endl;
	textcolor(WHITE);
}

void Juego::imprimirTurno(bool turno1) {
	if (turno1) {
		cout << "Turno del jugador 1" << endl;
	} else {
		cout << "Turno del jugador 2" << endl;
	}
}

int Juego::getKey(){
	bool casilleroValido = false;
	int casillero = 0;
	char caracter = '0';
	int posicion[2] = {0, 0};
	
	do {
		cout << "Ingrese un casillero: ";
		cin >> casillero;
		
		if (cin.good()) {
			if ((casillero < 1 || casillero > 9)) {
				cout << "El casillero ingresado no es valido" << endl;
				cin.clear();
				cin.ignore(10, '\n');
			} else {
				casilleroValido = true;
			}
		} else {
			cout << "No ingrese caracteres, solo numeros" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}
		
	} while(!casilleroValido);
	
	if (turno1) {
		caracter = 'X';
	}
	
	insertKey(casillero, caracter);
}


void Juego::insertKey(int k, char c){
	int posicion[2];
	
	switch(k) {
	case 1:
		posicion[0] = 0;
		posicion[1] = 0;
		break;
	case 2: 
		posicion[0] = 0;
		posicion[1] = 1;
		break;
	case 3:
		posicion[0] = 0;
		posicion[1] = 2;
		break;
	case 4: 
		posicion[0] = 1;
		posicion[1] = 0;
		break;
	case 5:
		posicion[0] = 1;
		posicion[1] = 1;
		break;
	case 6:
		posicion[0] = 1;
		posicion[1] = 2;
		break;
	case 7: 
		posicion[0] = 2;
		posicion[1] = 0;
		break;
	case 8: 
		posicion[0] = 2;
		posicion[1] = 1;
		break;
	case 9: 
		posicion[0] = 2;
		posicion[1] = 2;
		break;
	}
	
	if (!miTablero.hayFicha(posicion[0], posicion[1])) {
		turno1 = !turno1;
	}
	
	miTablero.setFichaIn(posicion[0], posicion[1], c);
}

bool Juego::checkTateti(){
	if (miTablero.compararFichas(0, 0, 1, 1, 2, 2)) {
		tateti = true;
	} else if (miTablero.compararFichas(0, 0, 0, 1, 0, 2)) {
		tateti = true;
	} else if (miTablero.compararFichas(1, 0, 1, 1, 1, 2)) {
		tateti = true;
	} else if (miTablero.compararFichas(2, 0, 2, 1, 2, 2)) {
		tateti = true;
	} else if (miTablero.compararFichas(0, 2, 1, 1, 1, 0)) {
		tateti = true;
	} else if (miTablero.compararFichas(0, 0, 1, 0, 2, 0)) {
		tateti = true;
	} else if (miTablero.compararFichas(0, 1, 1, 1, 2, 1)) {
		tateti = true;
	} else if (miTablero.compararFichas(0, 2, 1, 2, 2, 2)) {
		tateti = true;
	}
	
		
	return tateti;
}

void Juego::imprimirGanador(bool turno1) {
	
}

void Juego::imprimirTerminar(bool turno1) {
	
}

void Juego::imprimirCabecera() {
	textcolor(WHITE);
	cout << "--------------------------------------------" << endl;
	cout << "|   Bienvenido al TATETI de Luciano Simo   |" << endl;
	cout << "--------------------------------------------" << endl;
	textcolor(RED);
	cout << "Jugador 1 --> X                             " << endl;
	textcolor(BLUE);
	cout << "Jugador 2 --> 0                             " << endl;
	cout << "                                            " << endl;
	textcolor(WHITE);
	
}

//Metodos publicos
Juego::Juego() {
	turno1 = true;
	tateti = false;
}

void Juego::play() {
	imprimirPantalla(false);
	
	do {
		imprimirPantalla(true);
		imprimirTurno(turno1);
		getKey();
		imprimirSeparador();
		
	} while(!miTablero.isComplete() && !checkTateti());
	
	imprimirPantalla(true);
	textcolor(GREEN);
	
	if (tateti) {
		cout << "**************************" << endl;
		//Si el proximo turno que tocaba era el jugador 1 quiere decir que gano el 2 y viceversa
		if (turno1) {
			cout << "EL GANADOR ES EL JUGADOR 2" << endl;
		} else {
			cout << "EL GANADOR ES EL JUGADOR 1" << endl;
		}
		
		cout << "**************************" << endl;
	} else {
		cout << "**************************" << endl;
		cout << "EL RESULTADO ES UN EMPATE!" << endl;
		cout << "**************************" << endl;
	}
	
	textcolor(WHITE);
}
