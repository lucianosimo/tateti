//
// Created by ake on 24/6/20.
//

#include "Ficha.h"

Ficha::Ficha() {}

Ficha::Ficha(char c) {
	figura = c;
}

void Ficha::setFigura(char c) {
	figura = c;
}

char Ficha::getFigura() {
	return figura;
}

bool Ficha::compare(Ficha f) {
	return f.figura == figura;
}
