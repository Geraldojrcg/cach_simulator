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