/**
* @file     mp.cpp
* @brief         	Arquivo de corpo com as implementacoes dos metodos da classe mp
* @author      	MrBlack (daniel99955@hotmail.com)
* @since        	12/06/2017
* @date         	14/06/2017
* @sa 		mp.h
*/
#include "mp.h"

/** @brief 	Construtor Padrão */
Mp::Mp() {

}

/**@ brief 	Destrutor Padrão */
Mp::~Mp() {

}

/** @brief	Retorna o bloco da Mp */
int Mp::getBloco(){
	return bloco;
}

/** @brief 	Altera o bloco da Mp*/
void Mp::setBloco(int b) {
	bloco = b;
}

/** @brief 	Retorna o endereco da Mp*/
vector<int> Mp::getEndereco() {
	return endereco;
}

/** @brief 	Altera o endereco da Mp*/
void Mp::setEndereco(vector<int> e) {
	endereco = e;
}

/** @brief  	Retorna o conteudo da Mp*/
vector<int> Mp::getConteudo() {
	return conteudo;
}

/** @brief 	Retorna o conteudo da Mp*/
void Mp::setConteudo(vector<int> c) {
	conteudo = c;
}

/**
* @brief 	Insere endereco no vector
* @param 	el, inteiro a ser inserido
*/
void Mp::insertEnd(int el) {
	endereco.push_back(el);
}

/**
* @brief 	Insere conteudo no vector
* @param 	el, inteiro a ser inserido
*/
void Mp::insertCont(int el) {
	conteudo.push_back(el);
}

// ostream& operator<<(ostream &os, Mp &m) {
// 	os << m.endereco << " - " << m.conteudo;

// 	return os;
// }

// istream& operator>>(istream &is, Mp &m) {

// 	return is;
// }