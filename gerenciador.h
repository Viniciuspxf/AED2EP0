#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "informacoes.h"
#include "aviao.h"
#include "fila.h"

void desviaAviao(aviao *objeto);
void pousaAviao(aviao *objeto, int l, int pistas[3], informacoes *dados);
void decolaAviao(aviao *objeto, int l, int pistas[3], informacoes *dados);
void aloca(int modo, Queue *fila, Queue *auxiliar, int pistas[3], informacoes *dados);

#endif