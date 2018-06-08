/**
* @file     mp.h
* @brief        	Arquivo cabecalho com a definicao de atributos e metodos da classe memória principal
* @author   	MrBlack (daniel99955@hotmail.com)
* @since    	12/06/2017
* @date     	14/06/2017
*/
#ifndef MP_H
#define MP_H

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

/**
* @class 	Classe Mp
* @brief 	Classe que representa a memória principal
*/
class Mp {
	protected:
		int bloco;			/**< Bloco da Mp */
		vector<int> endereco;		/**< endereco da Mp */
		vector<int> conteudo; 		/**< conteudo da Mp */

	public:
		Mp();					/**< Construtor Padrão*/
		~Mp();					/**< Destrutor*/

		int getBloco();				/**< Retorna o bloco da Mp */
		void setBloco(int b);			/**< Altera o bloco da Mp*/

		vector<int> getEndereco();		/**< Retorna o endereco da Mp*/
		void setEndereco(vector<int> e);	/**< Altera o endereco da Mp*/

		vector<int> getConteudo(); 		/**< Retorna o conteudo da Mp*/
		void setConteudo(vector<int> c); 	/**< Altera o endereco da Mp*/

		void insertEnd(int el);			/**< Insere endereco*/
		void insertCont(int el);			/**< Insere conteudo*/

		// friend ostream& operator<<(ostream &os, Mp &m);
		// friend istream& operator>>(istream &is, Mp &m);
};

#endif