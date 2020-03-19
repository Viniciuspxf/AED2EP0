#include <iostream>
#include "informacoes.h"
#include "fila.h"
#include "aviao.h"
#include "gerenciador.h"
using namespace std;

int main(){
    Queue *fila[3];
    informacoes *dados;
    aviao *objeto;
    int escolhaDaFuncao = -1, Fila, instante, a, b, modo, pistas[3] = {0,0,0};
    fila[1] = new Queue[1];
    fila[2] = new Queue[1];
    fila[3] = new Queue[1];
    dados = new informacoes[1];
    objeto = new aviao[1];

    while (escolhaDaFuncao != 30) {
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
                cout << "Digite a fila: "; cin >> a;
                fila[a]->insere(objeto);
                break;
            case 6:
                cout << "Digite a fila: "; cin >> a;
                fila[a]->insereNoFim(objeto);
                break;
            case 7:
                cout << "Digite a fila: "; cin >> a;
                objeto = fila[a]->retira();
                break;
            case 8:
                cout << "Digite a fila: "; cin >> a;
                if (fila[a]->filaVazia())
                    cout << "Fila está vazia" << endl;
                else cout << "Fila não está vazia" << endl;
                break;
            case 9:
                cout << "Digite a fila: "; cin >> a;
                objeto = fila[a]->fimDaFila();
                break;
            case 10:
                cout << "Digite a fila: "; cin >> a;
                fila[a]->printaFila();
                break;
            case 11:
                cout << "Digite a fila: "; cin >> a;
                fila[a]->printaFilaDebugger();
                break;
            case 12:
                cout << "Digite o instante: "; cin >> instante;
                cout << "Digite a fila: "; cin >> a;
                fila[a]->obtemTempo(instante, dados);
                break;
            case 13:
                cout << "Digite a fila: "; cin >> a;
                fila[a]->obtemCombustivel(dados);
                break;
            case 14:
                cout << "Digite o instante: "; cin >> instante;
                cout << "Digite a fila: "; cin >> a;
                cout << "Digite a fila auxiliar: "; cin >> b;
                fila[a]->detectaExcecoes(fila[b], instante);
                break;
            case 15:
                cout << "Digite o modo: "; cin >> modo;
                cout << "Digite a primeira fila: "; cin >> a;
                cout << "Digite a segunda fila: "; cin >> b;
                aloca(modo, fila[a], fila[b], pistas, dados);
                break;
            case 16:
                cout << "Digite qual pista você quer mudar: "; cin >> a;
                cin >> pistas[a];
                break;
            case 17:
                desviaAviao(objeto);
                break;
            case 18:
                cout << "Digite qual pista você quer mudar: "; cin >> a;
                pousaAviao(objeto, a, pistas, dados);
                break;
            case 19:
                cout << "Digite qual pista você quer mudar: "; cin >> a;
                decolaAviao(objeto, a, pistas, dados);
                break;
            default:
                break;
        }
    }  

    delete [] fila[1];
    delete [] fila[2];
    delete [] fila[3];
    delete [] dados;
    delete [] objeto;
}