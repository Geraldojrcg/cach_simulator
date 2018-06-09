#ifndef CACHE_H
#define CACHE_H

#include "mem.h"

class Cache : public Mem{
	private:
		int linha;

	public:
		Cache() = default; 		
		~Cache() = default;	
		int getLinha(){
			return linha;
		}
		void setLinha(int l){
			linha = l;
		}
};

#endif