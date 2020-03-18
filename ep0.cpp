#include <iostream>
#include <string>
#define NUMERODESIMULACOES 10
using namespace std;

class aviao {
    public:
        string nome;
        bool pousar;
        bool emergencia;
        string origemDestino; //usar union????
        int combustivel; //juntar combustivel e tempoestimado ????
        int tempoEstimado;
		int instante;
        void leia(bool arquivo, int instante);
        void printa();
};

void aviao::leia(bool arquivo, int instante) {
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

void aviao::printa() {
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Identificação do avião: " << nome << endl;
    cout << "O avião deseja " << (pousar ? "pousar." : "decolar.") << endl; 
    cout << (pousar ? "Combustível restante: " : "Tempo estimado de voo: ") << (pousar ? combustivel:tempoEstimado) << endl;
    cout << (pousar ? "Origem: ": "Destino: ") << origemDestino << endl;
    cout << (emergencia ? "O voo é de emergência." : "O voo não é de emergência.") << endl;
    
}

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
		void printaFila();
		Queue detectaExcecoes(Queue urgencia, int instante);
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
	if (filaVazia()) fim = novo;
	
	aux = cabeca->proximo;
	aux->anterior = novo;
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

void Queue::printaFila() {
	celula *aux;

	for (aux = cabeca->proximo; aux != nullptr; aux = aux->proximo)
		aux->conteudo->printa();

    cout << "--------------------------------------------------------------------------" << endl;

}

Queue Queue::detectaExcecoes(Queue urgencia, int instante) {
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
				urgencia.insere(objeto);
				delete [] atual;
				atual = aux2;
			}
			else if (objeto->pousar && objeto->combustivel - tempo < 2){
				aux = atual->proximo;
				atual->anterior->proximo = aux;
				aux2  = atual->anterior;
				if (atual->proximo != nullptr) atual->proximo->anterior = atual->anterior;
				else fim = aux2;
				urgencia.insere(objeto);
				delete [] atual;
				atual = aux2;
			}
			else atual = atual->anterior;
		}
	}
	return urgencia;
}

void desviaAviao(aviao *objeto) {
    cout << "O seguinte avião será desviado: " << endl;
    objeto->printa();
    delete [] objeto;
}

void pousaAviao(aviao *objeto, int l, int pistas[3]){
    pistas[l] = 3;
    cout << "O seguinte avião está pousando na pista " << l + 1 << endl;
    objeto->printa();
    delete [] objeto;
}

void decolaAviao(aviao *objeto, int l, int pistas[3]) {
    pistas[l] = 3;
    cout << "O seguinte avião está decolando na pista " << l + 1 << endl;
    objeto->printa();
    delete [] objeto;
}

void aloca(int modo, Queue fila, Queue auxiliar, int pistas[3]) {
    int l;
    while (!fila.filaVazia()) {
        if (fila.fimDaFila()->pousar) {
            for (l = 0; l < 2; l++) {
                if (pistas[l] == 0) {
                    pousaAviao(fila.retira(), l, pistas);
                    break;
                } 
            }
            if (l == 2) {
                if (modo == 0 && pistas[l] == 0) pousaAviao(fila.retira(), l, pistas);
                else if (modo != 2) desviaAviao(fila.retira());
                else {
                    if (pistas[2] == 0) auxiliar.insereNoFim(fila.retira());
                    else break;
                }
            }
        }
        else {
            for (l = 2; l >= 0; l--) {
                if (pistas[l] == 0) {
                    decolaAviao(fila.retira(), l, pistas);
                    break;
                }
            }
            if (l == -1) {
                if (modo == 2) break /*código para parar iteração*/;
                else {
                    auxiliar.insereNoFim(fila.retira());
                }
            }
        }
    }
    while (!auxiliar.filaVazia()) fila.insereNoFim(auxiliar.retira());
    
}

int main() {
    Queue fila, urgencia, emergencia, auxiliar;
    aviao *objeto;
    int i, j, pista[3] = {0,0,0}, n; 
    bool arquivo;
    cout << "Digite 1 se deseja que o input seja um arquivo. Digite 0 caso contrário: ";
    cin >> arquivo;
    if (arquivo) {}
    for (i = 0; i < NUMERODESIMULACOES; i++) {
        for (j = 0; j < 3; j++) if (pista[j] != 0) pista[j]--; 
        if (arquivo) {}
        else {
            cout << "Digite o número de aviões: ";
            cin >> n;
        }
        for (j = 0; j < n; j++) {
            objeto = new aviao[1];
            objeto->leia(arquivo, i);
            if (objeto->emergencia) emergencia.insere(objeto);
            else fila.insere(objeto);
        }
        urgencia = fila.detectaExcecoes(urgencia, i);
        aloca(0, emergencia, auxiliar, pista);
        aloca(1, urgencia, auxiliar, pista);
        aloca(2, fila, auxiliar, pista);
        
    }
    return 0;
}

/*Há um caso de um avião ser de emergência mas ir parar em outra fila, tratar depois*/
/*caso problema: urgencia sem espaço, ele volta pra fila, mas aí surgem outras emergências 
em um instante posterior. (bagunçando a fila)

solução: criar uma fila SÓ para emergências.

*/
//Tratar caso pousar, todas as pistas cheias exceto a terceira, com decolar atrás
//usar fila auxiliar

//urgência não é sinônimo de emergência


/* 
Que aviões estão esperando para pousar e decolar / depois da alocação
O tempo médio de espera para o pouso/ antes da alocação
O tempo médio de espera para decolagem / antes da alocação
a quantidade média de combustível dos aviões esperando para pousar / depois da alocação
a quantidade média de combustível disponível dos aviões que pousaram / durante a alocação
a quantidade de aviões pousando/decolando em condições de emergência /durante a alocação

*/