#include <iostream>
#include <string>
#include "aviao.h"
#include "informacoes.h"
#include "fila.h"
#define NUMERODESIMULACOES 10
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
    cout << "pousa na pista " << l + 1;
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
    cout << "decola na pista " << l + 1;
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

int main() {
    Queue *fila, *urgencia, *emergencia, *auxiliar;
    aviao *objeto;
    informacoes *dados = new informacoes[1];
    int i, j, pista[3] = {0,0,0}, n; 
    bool arquivo;
    fila = new Queue[1];
    urgencia = new Queue[1];
    emergencia = new Queue[1];
    auxiliar = new Queue[1];
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
            if (objeto->emergencia) emergencia->insere(objeto);
            else fila->insere(objeto);
        }
        fila->detectaExcecoes(urgencia, i);
        dados->zera();
        emergencia->obtemTempo(i, dados);
        urgencia->obtemTempo(i, dados);
        fila->obtemTempo(i, dados);
        cout << "Tempo médio de espera para pouso: " << ((double) dados->esperaPouso)/dados->numeroDeAvioesPousando << endl;
        cout << "Tempo médio de espera para decolagem: " << ((double) dados->esperaDecolagem)/dados->numeroDeAvioesDecolando << endl;
        dados->zera();
        aloca(0, emergencia, auxiliar, pista, dados);
        aloca(1, urgencia, auxiliar, pista, dados);
        aloca(2, fila, auxiliar, pista, dados);
        cout << "Quantidade média de combustível disponível dos aviões que pousaram: " << ((double)dados->somaCombustiveis)/dados->numeroDeAvioesPousando << endl;
        cout << dados->pousandoEmergencia << " aviões pousaram em caso de emergência." << endl;
        cout << dados->decolandoEmergencia << " aviões decolaram em caso de emergência." << endl;
        dados->zera();
        emergencia->obtemCombustivel(dados);
        urgencia->obtemCombustivel(dados);
        fila->obtemCombustivel(dados);

        fila->printaFila();
        urgencia->printaFila();
        emergencia->printaFila();
        
        cout << "Quantidade média de combustível disponível dos aviões esperando pousar: " << ((double)dados->somaCombustiveis)/dados->numeroDeAvioesPousando << endl;

        emergencia->atualizaCombustivel();
        urgencia->atualizaCombustivel();
        fila->atualizaCombustivel();
    }
    delete [] dados;
    delete [] fila;
    delete [] emergencia;
    delete [] urgencia;
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

a quantidade média de combustível dos aviões esperando para pousar / depois da alocação
*/

//mudar combustível, criar função que atualiza combustíveis, função que detecta exceções;
//transformar tudo em ponteiro
// deletar os ponteiros