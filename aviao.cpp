#include "aviao.h"
#include <iostream>
using namespace std;
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
    cout << nome << " " << origemDestino;
}

void aviao::printaDebugger() {
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Identificação do avião: " << nome << endl;
    cout << "O avião deseja " << (pousar ? "pousar." : "decolar.") << endl; 
    cout << (pousar ? "Combustível restante: " : "Tempo estimado de voo: ") << (pousar ? combustivel:tempoEstimado) << endl;
    cout << (pousar ? "Origem: ": "Destino: ") << origemDestino << endl;
    cout << (emergencia ? "O voo é de emergência." : "O voo não é de emergência.") << endl;
    
}