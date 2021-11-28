/*
 * pratica04.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include "pilha.h"

#include <stack>

using namespace std;

int ehOperador(char token) {
	switch(token) {
	case '+':
	case '-':
	case '*':
	case '/': return 1;
	default: return 0;
	}
}

int avalia(char token, int valorEsq, int valorDir) {
	switch(token) {
	case '+': return valorEsq + valorDir;
	case '-': return valorEsq - valorDir;
	case '*': return valorEsq * valorDir;
	case '/': return valorEsq / valorDir;
	default: return 0;
	}
}

int polonesa(const char * exp) {
	Pilha<int> pilha(10);
	while (*exp) {
		char token = *exp;

		if (ehOperador(token)) {
			int valorDir = pilha.desempilha();
			int valorEsq = pilha.desempilha();
			int resultado = avalia(token, valorEsq, valorDir);
			pilha.empilha(resultado);
		} else {

     		int valor = (int)(token - '0');
			pilha.empilha(valor);
		}

		exp++;

	}
	return pilha.desempilha();
}

// DESAFIO
//int polonesa(const char * exp) {
//	stack <int> pilha;
//	while (*exp) {
//		char token = *exp;
//
//		if (ehOperador(token)) {
//			int valorDir = pilha.top();
//			pilha.pop();
//			int valorEsq = pilha.top();
//			pilha.pop();
//			int resultado = avalia(token, valorEsq, valorDir);
//			pilha.push(resultado);
//		} else {
//
//     		int valor = (int)(token - '0');
//			pilha.push(valor);
//		}
//
//		exp++;
//
//	}
//	return pilha.top();
//}


int main5() {
	cout << polonesa("23+31-*") << endl;
	cout << polonesa("93*42/-") << endl;

	return 0;
}





