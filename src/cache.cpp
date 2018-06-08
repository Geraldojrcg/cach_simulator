/**
* @file     cache.cpp
* @brief        	Arquivo de corpo com a implementacao dos metodos da classe cache
* @author   	MrBlack (daniel99955@hotmail.com)
* @since    	12/06/2017
* @date     	14/06/2017
* @sa 		cache.h
*/

#include "cache.h"

/** @brief 	Construtor Padrão */
Cache::Cache() {
	// empty
}

/** @brief 	Destrutor */
Cache::~Cache() {
	// empty
}

/** @brief 	Retorna a linha da cache */
int Cache::getLinha() {
	return linha;
}

/** @brief 	Modifica a linha da cache */
void Cache::setLinha(int l) {
	linha = l;
}

ostream& operator<<(ostream &os, Cache &c) {
	// os << "Linha-Bloco-Endereco-Conteudo" << endl;
	// os << c.linha << " - " << c.bloco;

	return os;
}

istream& operator>>(istream &is, Cache &c) {

	return is;
}