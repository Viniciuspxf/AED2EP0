#ifndef QUEUE_H
#define QUEUE_H

#include "aviao.h"
#include "informacoes.h"

typedef struct Celula celula;
struct Celula {
	aviao *conteudo;
	celula *proximo;
	celula *anterior;
};

class Queue {
  	private:
		celula *cabeca;
		celula *fim;	
	public:
		Queue();
		~Queue();
		void insere(aviao *objeto);
		void insereNoFim(aviao *objeto);
		aviao *retira();
		aviao *comecoDaFila();
		aviao *fimDaFila();
		bool filaVazia();
		void printaFilaDebugger();
        void printaFila();
		void detectaExcecoes(Queue *urgencia, int instante);
        void obtemTempo(int instanteAtual, informacoes *dados);
        void obtemCombustivel(informacoes *dados);
        void atualizaCombustivel();
};

#endif