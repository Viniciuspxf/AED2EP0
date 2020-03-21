#include <iostream>
#include <cstdlib>
#define NUMERODESIMULACOES 50
#define SEED 500
using namespace std;


void printaAviao() {
    switch (rand() % 5) {
        case 0:
            cout << "LA";
            break;
        case 1:
            cout << "GA";
            break;
        case 2:
            cout << "AD";
            break;
        case 3:
            cout << "JB";
            break;
        case 4:
            cout << "PD";
            break;
    }
    cout << rand()%10 << rand()%10 << rand()%10 << endl;
}

void printaAeroporto() {
    switch (rand() % 29) {
        case 0:
            cout << "GIG";
            break;
        case 1:
            cout << "BSB";
            break;
        case 2:
            cout << "SSA";
            break;
        case 3:
            cout << "POA";
            break;
        case 4:
            cout << "CNF";
            break;
        case 5:
            cout << "FOR";
            break;
        case 6:
            cout << "REC";
            break;
        case 7:
            cout << "CWB";
            break;
        case 8:
            cout << "MAO";
            break;
        case 9:
            cout << "VCP";
            break;
        case 10:
            cout << "FLN";
            break;
        case 11:
            cout << "BEL";
            break;
        case 12:
            cout << "GYN";
            break;
        case 13:
            cout << "VIX";
            break;
        case 14:
            cout << "SDU";
            break;
        case 15:
            cout << "NAT";
            break;
        case 16:
            cout << "CGH";
            break;
        case 17:
            cout << "CGB";
            break;
        case 18:
            cout << "IGU";
            break;
        case 19:
            cout << "BPS";
            break;
        case 20:
            cout << "MCZ";
            break;
        case 21:
            cout << "CGR";
            break;
        case 22:
            cout << "LDB";
            break;
        case 23:
            cout << "NVT";
            break;
        case 24:
            cout << "UDI";
            break;
        case 25:
            cout << "SLZ";
            break;
        case 26:
            cout << "AJU";
            break;
        case 27:
            cout << "THE";
            break;
        case 28:
            cout << "RAO";
            break;
    }
}

int main() {
    int numeroDeAvioes, i, j, combustivel, tempo, pousar, tempoEstimado, emergencia, aleatorio;
    srand(SEED);
    cout << 1 << endl;
    cout << NUMERODESIMULACOES << endl;
    for (i = 0; i < NUMERODESIMULACOES; i++) {
        aleatorio = rand() % 100;
        
        if (aleatorio < 95) {
            numeroDeAvioes = rand()%3;
        }
        else if (aleatorio < 98) {
            numeroDeAvioes = 3;
        }
        else if (aleatorio < 99) {
            numeroDeAvioes = rand()%2 + 4;
        }
        else {
            numeroDeAvioes = 6;
        }
    
        cout << numeroDeAvioes << endl;
        for (j = 0; j < numeroDeAvioes; j++) {
            printaAviao();
            if (rand()%2 == 0) pousar = 1;
            else pousar = 0;
            cout << pousar << endl;
            aleatorio = rand()%100;
            if (pousar == 1) {
                if (aleatorio < 10) {
                    combustivel = rand()%3 + 1;
                }
                else if (aleatorio < 25) {
                    combustivel = rand()%7 + 4;
                }
                else {
                    combustivel = rand()%20 + 11;
                }
                cout << combustivel << endl;
                printaAeroporto();
                cout << "/GRU" << endl;
            }
            else {
                if (aleatorio < 10) {
                    tempoEstimado = rand()%11 + 10;
                }
                else if (aleatorio < 25) {
                    tempoEstimado = rand()%10 + 21;
                }
                else {
                    tempoEstimado = rand()%31 + 31;
                }
                cout << tempoEstimado << endl;
                cout << "GRU/";
                printaAeroporto();
                cout << endl;
            }
            
           if (rand()%100 < 10) emergencia = 1;
           else emergencia = 0;
           cout << emergencia << endl;
        }

    }
    return 0;
}