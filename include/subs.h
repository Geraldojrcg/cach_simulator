/**
* @file     subs.h
* @brief	Arquivo cabecalho com a definicao das funcoes de politica de substituicao
* @author 	MrBlack (daniel99955@hotmail.com)
* @since 	14/06/2017
* @date 	19/06/2017
* @sa 		mp.h
* @sa 		cache.h
*/

#ifndef SUBS_H
#define SUBS_H

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

/**
* @brief	Funcao que realiza a substituicao aleatoria no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @return 	Sem retorno
*/
void randomT(Cache *c, Mp *m, int line, int block_cache);

/**
* @brief	Funcao que realiza a substituicao FIFO no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	fifo, fila para realizar controle com FIFO
* @return 	Sem retorno
*/
void FIFOT(Cache *c, Mp *m, int line, int block_cache, queue<int> &fifo);

/**
* @brief	Funcao que realiza a substituicao LFU no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	lfu, map para controlar quantidade de uso de um bloco
* @return 	Sem retorno
*/
void LFUT(Cache *c, Mp *m, int line, int block_cache, map<int, int> &lfu);

/**
* @brief	Funcao que realiza a substituicao LRU no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	lru, map para controlar quantidade de uso de um bloco
* @param 	ciclo, quantidade de ciclos executados
* @return 	Sem retorno
*/
void LRUT(Cache *c, Mp *m, int line, int block_cache, map<int, int> &lru, int &ciclo);

/**
* @brief	Funcao que realiza a substituicao aleatoria no Parcialmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	setSize, quantidade de vias
* @return 	Sem retorno
*/
void randomP(Cache *c, Mp *m, int line, int block_cache, int setSize) ;

/**
* @brief	Funcao que realiza a substituicao FIFO no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	setSize, quantidade de vias
* @param 	v, matriz para realizar controle com FIFO
* @param 	cont, controle de entradas
* @return 	Sem retorno
*/
void FIFOP(Cache *c, Mp *m, int line, int block_cache, int setSize, int **v, int &cont);

/**
* @brief	Funcao que realiza a substituicao LFU no Parcialmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	setSize, quantidade de vias
* @param 	v, matriz para controlar quantidade de uso de um bloco
* @return 	Sem retorno
*/
void LFUP(Cache *c, Mp *m, int line, int block_cache, int setSize, int **v);

/**
* @brief	Funcao que realiza a substituicao LRU no Totalmente Associativo
* @param 	c, ponteiro para objeto do tipo Cache
* @param 	m, ponteiro para objeto do tipo Mp
* @param 	line, quantidade de linhas da memoria cache
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	setSize, quantidade de vias
* @param 	v, matriz para controlar quantidade de uso de um bloco
* @param 	cont, quantidade de ciclos executados
* @return 	Sem retorno
*/
void LRUP(Cache *c, Mp *m, int line, int block_cache, int setSize, int **v, int &cont);

#endif