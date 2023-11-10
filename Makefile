#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Cecília Junqueira V. M. Pereira (ceciliajunq@ufmg.br), baseado no Makefile do prof. Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2023-10-03 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/listaadjacencia.o $(OBJ)/grafo.o $(OBJ)/lista.o $(OBJ)/celula.o $(OBJ)/sort.o $(OBJ)/checa_coloracao.o
HDRS = $(INC)/listaadjacencia.hpp $(INC)/grafo.hpp $(INC)/lista.hpp $(INC)/celula.hpp $(INC)/sort.hpp $(INC)/checa_coloracao.hpp
CFLAGS = -g -pg -Wall -std=c++17 -c -I$(INC)

EXE = $(BIN)/tp2.out

all: use $(EXE)

use:
	mkdir -p bin/
	mkdir -p obj/
	
$(BIN)/tp2.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/listaadjacencia.o: $(HDRS) $(SRC)/listaadjacencia.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/listaadjacencia.o $(SRC)/listaadjacencia.cpp 

$(OBJ)/grafo.o: $(HDRS) $(SRC)/grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp 

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp 

$(OBJ)/celula.o: $(HDRS) $(SRC)/celula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/celula.o $(SRC)/celula.cpp 

$(OBJ)/sort.o: $(HDRS) $(SRC)/sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sort.o $(SRC)/sort.cpp 

$(OBJ)/checa_coloracao.o: $(HDRS) $(SRC)/checa_coloracao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/checa_coloracao.o $(SRC)/checa_coloracao.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out