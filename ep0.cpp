#include <iostream>
#include <string>
#include "gerenciador.h"
#include "aviao.h"
#include "informacoes.h"
#include "fila.h"
using namespace std;



int main() {
    Queue *fila, *urgencia, *emergencia, *auxiliar;
    aviao *objeto;
    informacoes *dados = new informacoes[1];
    int i, j, pista[3] = {0,0,0}, n, numeroDeSimulacoes; 
    bool arquivo;
    fila = new Queue[1];
    urgencia = new Queue[1];
    emergencia = new Queue[1];
    auxiliar = new Queue[1];
    cout << "Digite 1 se deseja que o input seja um arquivo. Digite 0 caso contrário: ";
    cin >> arquivo;
    if (arquivo) {
        cin >> numeroDeSimulacoes;
    }
    else {
        cout << "Digite o número de simulações: ";
        cin >> numeroDeSimulacoes;
    }
    for (i = 0; i < numeroDeSimulacoes; i++) {
        for (j = 0; j < 3; j++) if (pista[j] != 0) pista[j]--; 
        if (arquivo) {
            cin >> n;
        }
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
        cout << "----------------------------------------------------------------------------------------" << endl;
        if (dados->numeroDeAvioesPousando != 0)
            cout << "Tempo médio de espera para pouso: " << ((double) dados->esperaPouso)/dados->numeroDeAvioesPousando << endl;
        if (dados->numeroDeAvioesDecolando != 0)
            cout << "Tempo médio de espera para decolagem: " << ((double) dados->esperaDecolagem)/dados->numeroDeAvioesDecolando << endl;
        dados->zera();
        cout << "----------------------------------------------------------------------------------------" << endl;
        aloca(0, emergencia, auxiliar, pista, dados);
        aloca(1, urgencia, auxiliar, pista, dados);
        aloca(2, fila, auxiliar, pista, dados);
        cout << "----------------------------------------------------------------------------------------" << endl;
        if (dados->numeroDeAvioesPousando != 0)
            cout << "Quantidade média de combustível disponível dos aviões que pousaram: " << ((double)dados->somaCombustiveis)/dados->numeroDeAvioesPousando << endl;
        cout << dados->pousandoEmergencia << " aviões pousaram em caso de emergência." << endl;
        cout << dados->decolandoEmergencia << " aviões decolaram em caso de emergência." << endl;
        dados->zera();
        cout << "----------------------------------------------------------------------------------------" << endl;
        emergencia->obtemCombustivel(dados);
        urgencia->obtemCombustivel(dados);
        fila->obtemCombustivel(dados);

        fila->printaFila();
        urgencia->printaFila();
        emergencia->printaFila();
        cout << "----------------------------------------------------------------------------------------" << endl;
        if (dados->numeroDeAvioesPousando != 0)
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
