/*
 * pilha.h
 *
 *  Created on: 24 de nov. de 2021
 *      Author: bill
 */

#ifndef SRC_PILHA_H_
#define SRC_PILHA_H_

#include <string.h>
using namespace std;

class PilhaEx : public exception{

protected:
	char mensagem[100];

public:

	PilhaEx(const char * msg){
		strcpy(mensagem,msg);
	}

	virtual const char * what(){
		return mensagem;
	}

};


template <class T>
class Pilha {

private:

	T * items;
	int capacidade;
	int topo;
// Atributos para array de items, capacidade e topo da pilha

public:

	Pilha(int capacidade) {

		items = new T[capacidade];
		this->capacidade = capacidade;
		topo = 0;
		// instancia array de items, inicializa capacidade e topo
	}

	~Pilha() {

		delete [] items;
	// destroy array de items
	}

	void empilha(T item) {

		if(topo > (capacidade - 1)){

			throw PilhaEx("estouro de pilha");
			return;
		}

	this-> items[topo] = item;
	topo++;

// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
	}

	T desempilha() {

		if(topo <= 0){

				throw PilhaEx("pilha vazia");
				return 0;
			}

	T conteudo = items[topo-1];
	topo--;
	return conteudo;
	// remove um item do topo da pilha; lança “Pilha vazia” se vazia
	}

	int tamanho() {

		return topo;

		// retorna o número de elementos na pilha.
	}
};



#endif /* SRC_PILHA_H_ */
