#include "mapeamento.h"

void map_direto(Cache *c, Mem *m, int block_cache, int line) {
	int line_cache = block_cache % line;

	if(c[line_cache].getBloco() == block_cache)
		cout << "HIT => Linha "<< c[line_cache].getLinha() << endl;
	else {
		c[line_cache].setBloco(m[block_cache].getBloco());
		c[line_cache].setEndereco(m[block_cache].getEndereco());
		c[line_cache].setConteudo(m[block_cache].getConteudo());
		cout << "MISS => Alocado na linha " << line_cache << endl;
	}
}

void map_full_associativo(Cache *c, Mem *m, int block_cache, int line, int sub, queue<int> &fifo, map<int, int> &lfu, int &ciclo) {
	if(sub == 1) { //Aleatorio
		randomT(c, m, line, block_cache);

	} else if(sub == 2) { //FIFO
		FIFOT(c, m, line, block_cache, fifo);

	} else if(sub == 3) { // LFU
		LFUT(c, m, line, block_cache, lfu);

	} else if(sub == 4) { // LRU
		LRUT(c, m, line, block_cache, lfu, ciclo);
	}
}

void map_parcial_associativo(Cache *c, Mem *m, int block_cache, int line, int sub, int setSize,  int **v, int &cont) {
	if(sub == 1) { //Aleatorio
		randomMem(c, m, line, block_cache, setSize);

	} else if(sub == 2) { //FIFO
		FIFOP(c, m, line, block_cache, setSize, v, cont);

	} else if(sub == 3) { // LFU
		LFUP(c, m, line, block_cache, setSize, v) ;

	} else if(sub == 4) { // LRU
		LRUP(c, m, line, block_cache, setSize, v, cont);
	}
}