#include <iostream>
#include "informacoes.h"
#include "fila.h"
#include "aviao.h"
using namespace std;

int main(){
    Queue *fila1, *fila2, *fila3;
    informacoes *dados;
    aviao *objeto;
    int escolhaDaFuncao = -1, Fila, instante;
    fila1 = new Queue[1];
    fila2 = new Queue[2];
    fila3 = new Queue[3];

    while (escolhaDaFuncao != 17) {
        cout << "Digite o que voce quer fazer: "; cin >> escolhaDaFuncao;  
        switch (escolhaDaFuncao) {
            case 0:
                objeto = new aviao[1];
                break;
            case 1:
                dados->zera();
                break; 
            case 2:
                cout << "Digite o instante: "; cin >> instante;
                objeto->leia(0, instante);
                break;
            case 3:
                objeto->printa();
                break;
            case 4:
                objeto->printaDebugger();
                break;
            case 5:
                fila1->insere(objeto);
                break;
            case 6:
                fila1->insereNoFim(objeto);
                break;
            case 7:
                objeto = fila1->retira();
                break;
            case 8:
                if (fila1->filaVazia())
                    cout << "Fila está vazia" << endl;
                else cout << "Fila não está vazia" << endl;
                break;
            case 9:
                objeto = fila1->fimDaFila();
                break;
            case 10:
                fila1->printaFila();
                break;
            case 11:
                fila1->printaFilaDebugger();
                break;
            case 12:
                cout << "Digite o instante: "; cin >> instante;
                fila1->obtemTempo(instante, dados);
                break;
            case 13:
                fila1->obtemCombustivel(dados);
                break;
            case 14:
                cout << "Digite o instante: "; cin >> instante;
                fila1->detectaExcecoes(fila2, instante);
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
        }
    }  

    delete [] fila1;
    delete [] fila2;
    delete [] fila3;
    delete [] objeto;
}