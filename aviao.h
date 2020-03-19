#ifndef _AVIAO_H
#define _AVIAO_H
#include <string>
using namespace std;
//typedef char* string;
class aviao {
    public:
        string nome;
        bool pousar;
        bool emergencia;
        string origemDestino;
        int combustivel; //juntar combustivel e tempoestimado ????
        int tempoEstimado;
		int instante;
        void leia(bool arquivo, int instante);
        void printaDebugger();
        void printa();
};

#endif