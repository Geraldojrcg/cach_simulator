RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src
TEST_DIR = ./test

# Opcoes de compilacao
CFLAGS01 = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean simulator

debug: CFLAGS01 += -g -O0
debug: clean simulator

# Alvo (target) para a construcao do executavel simulator
# Define os arquivos cache.o, mp.o, mapeamento.o, subs.o, funcoes.o e main.o como dependencias
simulator: $(OBJ_DIR)/mp.o $(OBJ_DIR)/cache.o $(OBJ_DIR)/mapeamento.o $(OBJ_DIR)/subs.o $(OBJ_DIR)/funcoes.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS01) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel simulator criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto mp.o
# Define o arquivo mp.h e mp.cpp como dependencias.
$(OBJ_DIR)/mp.o: $(SRC_DIR)/mp.cpp $(INC_DIR)/mp.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto cache.o
# Define o arquivo cache.cpp e cache.h como dependencias.
$(OBJ_DIR)/cache.o: $(SRC_DIR)/cache.cpp $(INC_DIR)/cache.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto mapeamento.o
# Define o arquivo mapeamento.h e mapeamento.cpp como dependencias.
$(OBJ_DIR)/mapeamento.o: $(SRC_DIR)/mapeamento.cpp $(INC_DIR)/mapeamento.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto subs.o
# Define o arquivo subs.h e subs.cpp como dependencias.
$(OBJ_DIR)/subs.o: $(SRC_DIR)/subs.cpp $(INC_DIR)/subs.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto funcoes.o
# Define o arquivo funcoes.h e funcoes.cpp como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/funcoes.cpp $(INC_DIR)/funcoes.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*