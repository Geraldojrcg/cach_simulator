#include "subs.h"

void randomT(Cache *c, Mem *m, int line, int block_cache) {
	bool hit = false, emp = false;
	int prox;

	for(int i = 0; i < line ; i++) {
		if(c[i].getBloco() == block_cache) {
			hit = true;
		}
	}

	if(!hit){
		for(int i = 0; i < line; i++) {
			if(c[i].getBloco() == -1) {
				emp = true;
				prox = i;
				break;
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;

		} else {
			srand(time(NULL));
			
			int r = rand() % line;
			c[r].setBloco(m[block_cache].getBloco());
			c[r].setEndereco(m[block_cache].getEndereco());
			c[r].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << r << endl;
		}

	} else {
		cout << "HIT" << endl;
	}
}

void FIFOT(Cache *c, Mem *m, int line, int block_cache, queue<int> &fifo) {
	bool hit = false, emp = false;
	int prox;

	for(int i = 0; i < line ; i++) {
		if(c[i].getBloco() == block_cache) {
			hit = true;
		}
	}

	if(!hit){
		for(int i = 0; i < line; i++) {
			if(c[i].getBloco() == -1) {
				emp = true;
				prox = i;
				break;
			}
		}


		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;
			fifo.push(block_cache);

		} else {
			int r = fifo.front();

			for(int i = 0; i < line; i++) {
				if(c[i].getBloco() == r) {
					c[i].setBloco(m[block_cache].getBloco());
					c[i].setEndereco(m[block_cache].getEndereco());
					c[i].setConteudo(m[block_cache].getConteudo());
					cout << "MISS => bloco alocado na linha " << i << endl;
					fifo.pop();
					fifo.push(block_cache);
				}
			}
		}

	} else {
		cout << "HIT" << endl;
	}
}

void LFUT(Cache *c, Mem *m, int line, int block_cache, map<int, int> &lfu) {
	bool hit = false, emp = false;
	int prox;

	for(int i = 0; i < line ; i++) {
			if(c[i].getBloco() == block_cache) {
				hit = true;
				lfu[block_cache] += 1;

			}
		}

		if(!hit){
			for(int i = 0; i < line; i++) {
				if(c[i].getBloco() == -1) {
					emp = true;
					prox = i;
					break;
				}
			}


			if(emp){
				c[prox].setBloco(m[block_cache].getBloco());
				c[prox].setEndereco(m[block_cache].getEndereco());
				c[prox].setConteudo(m[block_cache].getConteudo());
				cout << "MISS => bloco alocado na linha " << prox << endl;

				lfu.insert(pair<int, int>(block_cache, 1));

			} else {
				map<int, int>::iterator it = lfu.begin();
				int b = it->first;
				int menor = it->second;

				for(it = lfu.begin(); it != lfu.end(); ++it) {
					if(menor > it->second) {
						menor = it->second;
						b = it->first;
					}
				}

				int r = b;

				for(int i = 0; i < line; i++) {
					if(c[i].getBloco() == r) {
						c[i].setBloco(m[block_cache].getBloco());
						c[i].setEndereco(m[block_cache].getEndereco());
						c[i].setConteudo(m[block_cache].getConteudo());
						cout << "MISS => bloco alocado na linha " << i << endl;
						lfu.erase(r);
						lfu.insert(pair<int, int>(block_cache, 1));
					}
				}
			}

		} else {
			cout << "HIT" << endl;
		}
}

void LRUT(Cache *c, Mem *m, int line, int block_cache, map<int, int> &lru, int &ciclo) {
	bool hit = false, emp = false;
	int prox;

	for(int i = 0; i < line ; i++) {
		if(c[i].getBloco() == block_cache) {
			hit = true;
			lru[block_cache] = ciclo++;
		}
	}

	if(!hit){
		for(int i = 0; i < line; i++) {
			if(c[i].getBloco() == -1) {
				emp = true;
				prox = i;
				break;
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;
			lru.insert(pair<int, int>(block_cache, ciclo++));

		} else {
			map<int, int>::iterator it = lru.begin();
			int b = it->first;
			int menor = it->second;
			cout << menor << endl;
			for(it = lru.begin(); it != lru.end(); ++it) {
				if(menor > it->second) {
					menor = it->second;
					b = it->first;
				}
			}

			int r = b;
			for(int i = 0; i < line; i++) {
				if(c[i].getBloco() == r) {
					c[i].setBloco(m[block_cache].getBloco());
					c[i].setEndereco(m[block_cache].getEndereco());
					c[i].setConteudo(m[block_cache].getConteudo());
					cout << "MISS => bloco alocado na linha " << i << endl;
					lru.erase(r);
					lru.insert(pair<int, int>(block_cache, ciclo));
					ciclo++;
				}
			}
		}
	} else {
		cout << "HIT" << endl;
	}
}

void randomMem(Cache *c, Mem *m, int line, int block_cache, int setSize) {
	bool hit = false, emp = false;
	int prox;

	int divisoes = line / setSize;

	int way = block_cache % setSize;

	cout << "\nVia: " << way << endl;

	for(int i = 0; i < setSize ; i++) {
		if(i == way) {
			for(int j = i; j < divisoes + i; j++) {
				if(c[j + i ].getBloco() == block_cache) {
					hit = true;
				}
			}
		}
	}

	if(!hit){
		for(int i = 0; i < setSize ; i++) {
			if(i == way) {
				for(int j = i; j < divisoes + i; j++) {
					if(c[ j + i ].getBloco() == -1) {
						emp = true;
						prox = i + j;
						break;
					}
				}
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;

		} else {
			int r;
			
			srand(time(NULL));

			for(int i = 0; i < setSize; i++) {
				if(i == way) {
					r = rand() % setSize + ( i + way ) ;
				}
			}

			c[r].setBloco(m[block_cache].getBloco());
			c[r].setEndereco(m[block_cache].getEndereco());
			c[r].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << r << endl;
		}

	} else {
		cout << "HIT" << endl;
	}
}

void FIFOP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v, int &cont) {
	bool hit = false, emp = false;
	int prox;

	int divisoes = line / setSize;

	int way = block_cache % setSize;

	cout << "\nVia: " << way << endl;

	for(int i = 0; i < setSize ; i++) {
		if(i == way) {
			for(int j = i; j < divisoes + i; j++) {
				if(c[j + i ].getBloco() == block_cache) {
					hit = true;
				}
			}
		}
	}

	if(!hit){
		for(int i = 0; i < setSize ; i++) {
			if(i == way) {
				for(int j = i; j < divisoes + i; j++) {
					if(c[ j + i ].getBloco() == -1) {
						emp = true;
						prox = i + j;
						break;
					}
				}
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;
			v[prox][0] = block_cache;
			v[prox][1] = cont++;

		} else {
			int b;
			int menor;

			for(int i = 0; i < setSize ; i++) {
				if(i == way) {
					menor = v[i+way][1];
					b = v[i+way][0];
					for(int j = i + way; j < setSize + way + i; j++){
						if(v[j][1] < menor) {
							menor = v[j][1];
							b = v[j][0];
						}
					}
				}
			}

			int r = b;

			for(int i = 0; i < setSize; i++){
				if(i == way) {
					for(int j = (i + way); j < setSize + (i + way); j++) {
						if(c[j].getBloco() == r) {
							c[j].setBloco(m[block_cache].getBloco());
							c[j].setEndereco(m[block_cache].getEndereco());
							c[j].setConteudo(m[block_cache].getConteudo());
							cout << "MISS => bloco alocado na linha " << j << endl;
					
							v[j][0] = block_cache;
							v[j][1] = cont++;
					
						}
					}
				}
			}
		}
	} else {
		cout << "HIT => Linha "<<block_cache << endl;
	}
}

void LFUP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v) {
	bool hit = false, emp = false;
	int prox;

	int divisoes = line / setSize;

	int way = block_cache % setSize;

	cout << "\nVia: " << way << endl;

	for(int i = 0; i < setSize ; i++) {
		if(i == way) {
			for(int j = i; j < divisoes + i; j++) {
				if(c[j + i ].getBloco() == block_cache) {
					hit = true;
					v[j + i][1] += 1;
				}
			}
		}
	}

	if(!hit){
		for(int i = 0; i < setSize ; i++) {
			if(i == way) {
				for(int j = i; j < divisoes + i; j++) {
					if(c[ j + i ].getBloco() == -1) {
						emp = true;
						prox = i + j;
						break;
					}
				}
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;
			v[prox][0] = block_cache;
			v[prox][1] = 1;

		} else {
			int b;
			int menor;

			for(int i = 0; i < setSize ; i++) {
				if(i == way) {
					menor = v[i+way][1];
					b = v[i+way][0];
					for(int j = i + way; j < setSize + way + i; j++){
						if(v[j][1] < menor) {
							menor = v[j][1];
							b = v[j][0];
						}
					}
				}
			}

			int r = b;

			for(int i = 0; i < setSize; i++){
				if(i == way) {
					for(int j = (i + way); j < setSize + (i + way); j++) {
						if(c[j].getBloco() == r) {
							c[j].setBloco(m[block_cache].getBloco());
							c[j].setEndereco(m[block_cache].getEndereco());
							c[j].setConteudo(m[block_cache].getConteudo());
							cout << "MISS => bloco alocado na linha " << j << endl;
					
							v[j][0] = block_cache;
							v[j][1] = 1;
					
						}
					}
				}
			}
		}
	} else {
		cout << "HIT" << endl;
	}
}

void LRUP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v, int &cont) {
	bool hit = false, emp = false;
	int prox;

	int divisoes = line / setSize;

	int way = block_cache % setSize;

	cout << "\nVia: " << way << endl;

	for(int i = 0; i < setSize ; i++) {
		if(i == way) {
			for(int j = i; j < divisoes + i; j++) {
				if(c[j + i ].getBloco() == block_cache) {
					hit = true;
					v[j + i][1] = cont++;
				}
			}
		}
	}

	if(!hit){
		for(int i = 0; i < setSize ; i++) {
			if(i == way) {
				for(int j = i; j < divisoes + i; j++) {
					if(c[ j + i ].getBloco() == -1) {
						emp = true;
						prox = i + j;
						break;
					}
				}
			}
		}

		if(emp){
			c[prox].setBloco(m[block_cache].getBloco());
			c[prox].setEndereco(m[block_cache].getEndereco());
			c[prox].setConteudo(m[block_cache].getConteudo());
			cout << "MISS => bloco alocado na linha " << prox << endl;
			v[prox][0] = block_cache;
			v[prox][1] = cont++;

		} else {
			int b;
			int menor;

			for(int i = 0; i < setSize ; i++) {
				if(i == way) {
					menor = v[i+way][1];
					b = v[i+way][0];
					for(int j = i + way; j < setSize + way + i; j++){
						if(v[j][1] < menor) {
							menor = v[j][1];
							b = v[j][0];
						}
					}
				}
			}

			int r = b;

			for(int i = 0; i < setSize; i++){
				if(i == way) {
					for(int j = (i + way); j < setSize + (i + way); j++) {
						if(c[j].getBloco() == r) {
							c[j].setBloco(m[block_cache].getBloco());
							c[j].setEndereco(m[block_cache].getEndereco());
							c[j].setConteudo(m[block_cache].getConteudo());
							cout << "MISS => bloco alocado na linha " << j << endl;
					
							v[j][0] = block_cache;
							v[j][1] = cont++;
					
						}
					}
				}
			}
		}
	} else {
		cout << "HIT" << endl;
	}
}