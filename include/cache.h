/**
* @file     cache.h
* @brief    	Arquivo cabecalho com a definicao de atributos e metodos da classe cache
* @author	MrBlack (daniel99955@hotmail.com)
* @since 	12/06/2017
* @date 	14/06/2017
* @sa 		mp.h
*/
#ifndef CACHE_H
#define CACHE_H

#include "mp.h"

/**
* @class 	Classe Cache
* @brief 	Classe que representa memória cache
*/
class Cache : public Mp{
	private:
		int linha;		/**< Linha da cache */

	public:
		Cache(); 		/**< Construtor Padrão */
		~Cache();		/**< Destrutor */
		int getLinha();		/**< Retorna a linha da cache */
		void setLinha(int l);	/**< Modifica a linha da cache */

		friend ostream& operator<<(ostream &os, Cache &c); /**< Sobrecarga operador de extracao */
		friend istream& operator>>(istream &is, Cache &c);
};

#endif