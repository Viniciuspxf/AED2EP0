#ifndef QUEUE_H
#define QUEUE_H

template <class Item>
class Queue {
  	private:

			typedef struct Celula celula;
			struct Celula {
				Item *conteudo;
				celula *proximo;
				celula *anterior;
			};

			celula *cabeca;
			celula *fim;
		
		public:

			Queue();
			~Queue();
			void insere(Item *item);
			Item *retira();
			Item *comecoDaFila();
			Item *fimDaFila();
			bool filaVazia();
};

template <class Item>
Queue<Item>::Queue(): cabeca(new celula[1]), fim(cabeca) {
	cabeca->conteudo = nullptr;
	cabeca->proximo = nullptr;
	cabeca->anterior = nullptr;
};

template <class Item>
Queue<Item>::~Queue(){
	celula *aux;
	for (; cabeca != nullptr; cabeca = aux){
		aux = cabeca->proximo;
		delete [] cabeca;
	}
}

template <class Item>
void Queue<Item>::insere(Item *item) {
	celula *aux, *novo;
	novo = new celula[1];
	novo->conteudo = item;
	aux = cabeca->proximo;
	aux->anterior = novo;
	item->proximo = aux;
	cabeca->proximo = novo;
	if (filaVazia()) fim = novo;
}

template <class Item>
Item *Queue<Item>::retira() {
	Item *item;
	celula *aux;
	if (filaVazia()) {
		return nullptr;
	}
	else {
		item = fim->conteudo;
		aux = fim;
		fim = fim->anterior;
		delete [] aux;
		return item;
	}

}

template <class Item>
Item *Queue<Item>::comecoDaFila() {
	if (filaVazia()) 
		return nullptr;
	else return cabeca->proximo->conteudo;
}

template <class Item>
Item *Queue<Item>::fimDafila() {
	return fim->conteudo;
}

template <class Item>]
bool Queue<Item>::filaVazia() {
	return (cabeca == fim);
}

#endif