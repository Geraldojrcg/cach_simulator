#ifndef MP_H
#define MP_H

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Mem {
	protected:
		int bloco;			
		vector<int> endereco;		
		vector<int> conteudo; 

	public:
		Mem() = default;					
		~Mem() = default;				

		int getBloco(){
			return bloco;
		}		
		void setBloco(int b){
			bloco = b;
		}	
		vector<int> getEndereco(){
			return endereco;
		}	
		void setEndereco(vector<int> e){
			endereco = e;
		}
		vector<int> getConteudo(){
			return conteudo;
		}	
		void setConteudo(vector<int> c){
			conteudo = c;
		}
		void insertEnd(int el){
			endereco.push_back(el);
		}	
		void insertCont(int el){
			conteudo.push_back(el);
		}
};

#endif