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