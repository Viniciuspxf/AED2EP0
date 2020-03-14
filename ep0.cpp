#include <iostream>
#include "fila.h"
#define NUMERODESIMULACOES 10
using namespace std;

int main() {
    Queue fila, urgencia;
    int i, j, pista[3] = {0,0,0}, n; 
    bool arquivo;
    cout << "Digite 1 se deseja que o input seja um arquivo. Digite 0 caso contrário: ";
    cin >> arquivo;
    if (arquivo) {}
    for (i = 0; i < NUMERODESIMULACOES; i++) {
        if (arquivo) {}
        else {
            cout << "Digite o número de aviões: ";
            cin >> n;
        }
        for (j = 0; j < n; j++) {
            aviao *objeto = new aviao[1];
            objeto->leia(arquivo);
            if (objeto->emergencia) urgencia.insere(objeto);
            else fila.insere(objeto);
        }
        urgencia = fila.detectaExcecoes(urgencia);
        
    }
    return 0;
}