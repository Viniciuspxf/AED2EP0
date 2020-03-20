#include <iostream>
#include "fila.h"
using namespace std;

Queue::Queue(): cabeca(new celula[1]), fim(cabeca) {
	cabeca->conteudo = nullptr;
	cabeca->proximo = nullptr;
	cabeca->anterior = nullptr;
};

Queue::~Queue() {
	celula *aux;
	for (; cabeca != nullptr; cabeca = aux) {
		aux = cabeca->proximo;
		delete [] cabeca;
	}
}

void Queue::insere(aviao *objeto) {
	celula *aux, *novo;
	novo = new celula[1];
	novo->conteudo = objeto;
	aux = cabeca->proximo;
	if (filaVazia()) fim = novo;
	else aux->anterior = novo;
	novo->proximo = aux;
	cabeca->proximo = novo;
	novo->anterior = cabeca;
}

void Queue::insereNoFim(aviao *objeto) {
	celula *aux, *novo;
	novo = new celula[1];
	novo->conteudo = objeto;
	aux = fim;
	fim = novo;
	aux->proximo = novo;
	novo->anterior = aux;
	novo->proximo = nullptr;
}

aviao *Queue::retira() {
	aviao *objeto;
	celula *aux;
	if (filaVazia()) {
		return nullptr;
	}
	else {
		objeto = fim->conteudo;
		aux = fim;
		fim = fim->anterior;
		fim->proximo = nullptr;
		delete [] aux;
		return objeto;
	}

}

aviao *Queue::comecoDaFila() {
	if (filaVazia()) 
		return nullptr;
	else return cabeca->proximo->conteudo;
}

aviao *Queue::fimDaFila() {
	return fim->conteudo;
}

bool Queue::filaVazia() {
	return (cabeca == fim);
}

void Queue::printaFilaDebugger() {
	celula *aux;

	for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo)
		aux->conteudo->printaDebugger();

    cout << "--------------------------------------------------------------------------" << endl;

}

void Queue::printaFila() {
    celula *aux;
    aviao *objeto;
    for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo) {
        objeto = aux->conteudo;
        cout << "Avião ";
        objeto->printa();
        cout << " está aguardando liberação para ";
        if (objeto->pousar) cout << "pouso." << endl;
        else cout << "decolagem." << endl;
    }
}

void Queue::detectaExcecoes(Queue *urgencia, int instante) {
	celula *atual, *aux, *aux2;
	aviao *objeto;
	int tempo;
	if (!filaVazia()) {
		for (atual = fim; atual != cabeca;) {
			objeto = atual->conteudo;
			tempo = instante - objeto->instante;
			if (!objeto->pousar && ((double)tempo)/objeto->tempoEstimado > 0.1) {
				aux = atual->proximo;
				atual->anterior->proximo = aux;
				aux2  = atual->anterior;
				if (atual->proximo != nullptr) atual->proximo->anterior = atual->anterior;
				else fim = aux2;
				urgencia->insere(objeto);
				delete [] atual;
				atual = aux2;
			}
			else if (objeto->pousar && objeto->combustivel < 2) {
				aux = atual->proximo;
				atual->anterior->proximo = aux;
				aux2  = atual->anterior;
				if (atual->proximo != nullptr) atual->proximo->anterior = atual->anterior;
				else fim = aux2;
				urgencia->insere(objeto);
				delete [] atual;
				atual = aux2;
			}
			else atual = atual->anterior;
		}
	}
}

void Queue::obtemTempo(int instanteAtual, informacoes *dados) {
    celula *aux;
    aviao *objeto;
    for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo) {
        objeto = aux->conteudo;
        if (objeto->pousar) {
            dados->numeroDeAvioesPousando++;
            dados->esperaPouso = dados->esperaPouso + instanteAtual - objeto->instante;
        }
        else {
            dados->numeroDeAvioesDecolando++;
            dados->esperaDecolagem = dados->esperaDecolagem + instanteAtual - objeto->instante;
        }
    
    }

}

void Queue::obtemCombustivel(informacoes *dados) {
    celula *aux;
    aviao *objeto;
    for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo) {
        objeto = aux->conteudo;
        if (objeto->pousar) {
            dados->numeroDeAvioesPousando++;
            dados->somaCombustiveis = dados->somaCombustiveis + objeto->combustivel;
        }
    }
}

void Queue::atualizaCombustivel() {
    celula *aux;
    for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo) {
        if (aux->conteudo->pousar) aux->conteudo->combustivel--;
    }
}
