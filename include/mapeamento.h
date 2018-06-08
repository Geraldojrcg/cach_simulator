/**
* @file 		mapeamento.h
* @brief 	Arquivo cabecalho com as definicoes das funcoes de mapeamento
* @author 	MrBlack (daniel99955@hotmail.com)
* @since 	14/06/2017
* @date 	19/06/2017
* @sa 		mp.h
* @sa 		cache.h
* @sa 		subs.h
*/

#ifndef MAPEAMENTO_H
#define MAPEAMENTO_H

#include <iostream>
using std::endl;
using std::cout;

#include <queue>
using std::queue;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <ctime>
#include <cstdlib>

#include "mp.h"
#include "cache.h"
#include "subs.h"

/**
* @brief 	Funcao que realiza o aplica o mapeamento direto
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @return 	Sem retorno
*/
void directed_mapped(Cache *c, Mp *m, int block_cache, int line) ;

/**
* @brief    Funcao que realiza o aplica o mapeamento totalmente associativo
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @param 	sub, tipo de politica de substituicao
* @param 	fifo, fila para substituicao do tipo fifo
* @param 	lfu, map para substituicao do tipo lfu e lru
* @param 	ciclo, contagem dos ciclos para lru
* @return 	Sem retorno
*/
void fullyAssociative_mapped(Cache *c, Mp *m, int block_cache, int line, int sub, queue<int> &fifo, map<int, int> &lfu, int &ciclo);

/**
* @brief    Funcao que realiza o aplica o mapeamento totalmente associativo
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @param 	sub, tipo de politica de substituicao
* @param 	setSize, numero de vias
* @param 	v, matriz para substituicao do tipo lfu e lru e FIFO
* @param 	ciclo, contagem dos ciclos para lru
* @return 	Sem retorno
*/
void parsedAssociative_mapped(Cache *c, Mp *m, int block_cache, int line, int sub, int setSize,  int **v, int &cont) ;

#endif