/**
* @file     funcoes.h
* @brief 	Arquivo cabecalho com as definicoes das funcoes de manipulacao do programa
* @author 	MrBlack (daniel99955@hotmail.com)
* @since 	12/06/2017
* @date 	18/06/2017
* @sa 		cache.h
* @sa 		mp.h
* @sa 		mapeamento.h
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;
using std::stoi;
using std::getline;

#include <queue>
using std::queue;

#include <map>
using std::map;

#include <unordered_map>
using std::unordered_map;

#include "cache.h"
#include "mp.h"
#include "mapeamento.h"

/**
* @brief 	Funcao que realiza a leitura do arquivo com as definicoes da memoria cache
* @param 	sizeBlock, tamanho dos blocos da memoria principal
* @param 	line, quantidade de linhas da memoria cache
* @param 	block, quantidade de blocos da memoria principal
* @param 	map, mapeamento
* @param 	sub, politica de substituicao
* @param 	write, politica de escrita
*/
void configuracao(int &s, int &l, int &b, int &m, int &set_size, int &sub, int &write) ;

/**
* @brief 	Funcao que realiza as operacoes no programa
*/
void init() ;

/**
* @brief 	Funcao que inicializa a memoria principal com valores aleatorios e a memoria cache vazia
* @param 	mem, objeto do tipo Mp
* @param 	sizeBlock, tamanho do bloco da memoria principal
* @param 	block, quantidade de blocos da memoria principal
* @return 	Sem retorno
*/
void print(Cache *ca, Mp *mem, int sizeBlock, int block, int line) ;

/**
* @brief 	Funcao que inicializa a memoria principal com valores aleatorios
* @param 	mem, objeto do tipo Mp
* @param 	sizeBlock, tamanho do bloco da memoria principal
* @param 	block, quantidade de blocos da memoria principal
* @return 	Sem retorno
*/
void initMp(Mp *mem, int sizeBlock, int block);

/**
* @brief 	Funcao que inicializa a memoria cache com -1 (vazia)
* @param 	ca, objeto do tipo Cache
* @param 	sizeBlock, tamanho do bloco da memoria cache
* @param 	line, quantidade de linhas da memoria cache
* @return 	Sem retorno
*/
void initCache(Cache *c, int sizeBlock, int line);

/**
 * @brief Funcao que converte todos os caracteres para letra minuscula
 * @param s String a ser convertida
 */
void minusculas(string& s) ;

#endif