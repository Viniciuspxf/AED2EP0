#include <iostream>
#include "gerenciador.h"
#include "fila.h"
#include "informacoes.h"
#include "aviao.h"
using namespace std;


void desviaAviao(aviao *objeto) {
    cout << "Avião ";
    objeto->printa();
    cout << " é desviado para aeroporto vizinho"; 
    if (objeto->emergencia) cout << " (Emergência)";
    cout << endl;
    delete [] objeto;
}

void pousaAviao(aviao *objeto, int l, int pistas[3], informacoes *dados) {
    pistas[l] = 3;
    cout << "Avião  ";
    objeto->printa();
    cout << " pousa na pista " << l + 1;
    dados->numeroDeAvioesPousando++;
    dados->somaCombustiveis = dados->somaCombustiveis + objeto->combustivel;
    if (objeto->emergencia) { 
        dados->pousandoEmergencia++;
        cout << " (Emergência)";
    }
    cout << endl;
    delete [] objeto;
}

void decolaAviao(aviao *objeto, int l, int pistas[3], informacoes *dados) {
    pistas[l] = 3;
    cout << "Avião ";
    objeto->printa();
    cout << " decola na pista " << l + 1;
    if (objeto->emergencia) {
        dados->decolandoEmergencia++;
        cout << " (Emergência)";
    }
    cout << endl;
    delete [] objeto;
}

void aloca(int modo, Queue *fila, Queue *auxiliar, int pistas[3], informacoes *dados) {
    int l;
    while (!fila->filaVazia()) {
        if (fila->fimDaFila()->pousar) {
            for (l = 0; l < 2; l++) {
                if (pistas[l] == 0) {
                    pousaAviao(fila->retira(), l, pistas, dados);
                    break;
                } 
            }
            if (l == 2) {
                if (modo == 0 && pistas[l] == 0) pousaAviao(fila->retira(), l, pistas, dados);
                else if (modo != 2) desviaAviao(fila->retira());
                else {
                    if (pistas[2] == 0) auxiliar->insereNoFim(fila->retira());
                    else break;
                }
            }
        }
        else {
            for (l = 2; l >= 0; l--) {
                if (pistas[l] == 0) {
                    decolaAviao(fila->retira(), l, pistas, dados);
                    break;
                }
            }
            if (l == -1) {
                if (modo == 2) break /*código para parar iteração*/;
                else {
                    auxiliar->insereNoFim(fila->retira());
                }
            }
        }
    }
    while (!auxiliar->filaVazia()) fila->insereNoFim(auxiliar->retira());
}