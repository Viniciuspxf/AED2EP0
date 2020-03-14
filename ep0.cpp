#include <iostream>
#include "fila.h"
#define NUMERODESIMULACOES 10
using namespace std;

int main() {
    Queue fila, urgencia;
    aviao *objeto;
    int i, j, l, pista[3] = {0,0,0}, n; 
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
            objeto = new aviao[1];
            objeto->leia(arquivo, i);
            if (objeto->emergencia) urgencia.insere(objeto);
            else fila.insere(objeto);
        }
        urgencia = fila.detectaExcecoes(urgencia, i);

        while (!urgencia.filaVazia()) {
            objeto = urgencia.retira();
            if (!objeto->pousar) {
                if (pista[2] == 0) {
                    pista[2] = 3;
                    cout << "O seguinte avião está decolando na pista 3:" << endl;
                    objeto->printa();
                }
                else {
                    for (l = 0; l < 2; l++) {
                        if (pista[l] == 0) {
                            pista[l] = 3;
                            cout << "O seguinte avião está decolando na pista "<< l+1 <<":" <<endl;
                            objeto->printa();
                            break;
                        }
                    }
                    if (l == 2) {
                        cout << "infelizmente todas as pistas estão vazias, o seguinte avião voltará para a fila:" << endl;
                        objeto->printa();
                    }
                }
            }

            else {
                for (l = 0; l < 2; l++) {
                    if (pista[l] == 0) {
                        pista[l] = 3;
                        cout << "O seguinte avião está pousando na pista " << l + 1 << endl;
                        objeto->printa();
                        break;
                    }
                }
                if (l == 2) {
                    if (objeto->emergencia && pista[l] == 0) {
                        pista[l] = 3;
                        cout << "O seguinte avião está pousando na pista " << l + 1 << endl;
                        objeto->printa();
                    }
                    else {
                        cout << "Não há pistas para pouso, logo o seguinte voo vai para outro aeroporto: " << endl;
                        objeto->printa();
                    }
                }
            }
        }

        while (!fila.filaVazia()) {
            
        }
    }
    return 0;
}

/*Há um caso de um avião ser de emergência mas ir parar em outra fila, tratar depois*/