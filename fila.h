#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>
using namespace std;

class aviao {
    public:
        string nome;
        bool pousar;
        bool emergencia;
        string origemDestino; //usar union????
        int combustivel; //juntar combustivel e tempoestimado ????
        int tempoEstimado;
        void leia(bool arquivo);
        void printa();
};

aviao::leia(bool arquivo) {
    if (arquivo) {

    }
    else {
        cout << "Digite a identificação do avião: ";
        cin >> nome;
        cout << "Digite 1 se deseja pousar, digite 0 se não: ";
        cin >> pousar;
        if (pousar) {
            cout << "Digite o combustível restante: ";
            cin >> combustivel;
            cout << "Digite o código de origem do avião: ";
        }
        else {
            cout << "Digite o tempo estimado de voo: ";
            cin >> tempoEstimado;
            cout << "Digite o código de destino do avião: ";
        }
        cin >> origemDestino;
        cout << "Digite 1 se for um voo de emergencia, digite 0 se não: ";
        cin >> emergencia;
    }
}

aviao::printa() {
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Identificação do avião: " << nome << endl;
    cout << "O avião deseja " << (pousar ? "pousar." : "decolar.") << endl; 
    cout << (pousar ? "Combustível restante: " : "Tempo estimado de voo: ") << (pousar ? combustivel:tempoEstimado) << endl;
    cout << (pousar ? "Origem: ": "Destino: ") << origemDestino << endl;
    cout << (emergencia ? "O voo é de emergência." : "O voo não é de emergência.") << endl;
    
}

class Queue {
  	private:

			typedef struct Celula celula;
			struct Celula {
				aviao *conteudo;
				celula *proximo;
				celula *anterior;
			};

			celula *cabeca;
			celula *fim;
		
		public:

			Queue();
			~Queue();
			void insere(aviao *objeto);
			aviao *retira();
			aviao *comecoDaFila();
			aviao *fimDaFila();
			bool filaVazia();
			void printaFila();
};

Queue::Queue(): cabeca(new celula[1]), fim(cabeca) {
	cabeca->conteudo = nullptr;
	cabeca->proximo = nullptr;
	cabeca->anterior = nullptr;
}

Queue::~Queue() {
	celula *aux;
	for (; cabeca != nullptr; cabeca = aux){
		aux = cabeca->proximo;
		delete [] cabeca;
	}
}

void Queue::insere(aviao *objeto) {
	celula *aux, *novo;
	novo = new celula[1];
	novo->conteudo = objeto;
	aux = cabeca->proximo;
	aux->anterior = novo;
	objeto->proximo = aux;
	cabeca->proximo = novo;
	if (filaVazia()) fim = novo;
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
		delete [] aux;
		return objeto;
	}

}

aviao *Queue::comecoDaFila() {
	if (filaVazia()) 
		return nullptr;
	else return cabeca->proximo->conteudo;
}

aviao *Queue::fimDafila() {
	return fim->conteudo;
}

bool Queue::filaVazia() {
	return (cabeca == fim);
}

void Queue::printaFila() {
	aviao *aux;

	for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo)
		*aux.printa();

    cout << "--------------------------------------------------------------------------" << endl;

}
#endif