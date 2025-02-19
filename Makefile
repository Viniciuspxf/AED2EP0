ep0: aviao.o informacoes.o ep0.o fila.o gerenciador.o debugger
	g++ aviao.o informacoes.o ep0.o fila.o gerenciador.o -o ep0

debugger: debugger.o fila.o informacoes.o aviao.o gerenciador.o
	g++ debugger.o fila.o informacoes.o aviao.o gerenciador.o -o debugger

debugger.o: aviao.h informacoes.h fila.h gerenciador.h debugger.cpp
	g++ -g -c debugger.cpp

ep0.o: aviao.h informacoes.h fila.h gerenciador.h ep0.cpp
	g++ -g -c ep0.cpp

gerenciador.o: aviao.h informacoes.h fila.h gerenciador.h gerenciador.cpp
	g++ -g -c gerenciador.cpp

fila.o: aviao.h informacoes.h fila.h fila.cpp
	g++ -g -c fila.cpp

informacoes.o: aviao.h informacoes.h informacoes.cpp
	g++ -g -c informacoes.cpp

aviao.o: aviao.cpp aviao.h
	g++ -g -c aviao.cpp