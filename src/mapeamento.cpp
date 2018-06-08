#include "mapeamento.h"

/**
* @brief 	Funcao que realiza o aplica o mapeamento direto
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @return 	Sem retorno
*/
void directed_mapped(Cache *c, Mp *m, int block_cache, int line) {
	int line_cache = block_cache % line;

	if(c[line_cache].getBloco() == block_cache)
		cout << "HIT" << endl;
	else {
		c[line_cache].setBloco(m[block_cache].getBloco());
		c[line_cache].setEndereco(m[block_cache].getEndereco());
		c[line_cache].setConteudo(m[block_cache].getConteudo());
		cout << "MISS => Alocado na linha " << line_cache << endl;
	}
}

/**
* @brief    Funcao que realiza o aplica o mapeamento totalmente associativo
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @param 	sub, tipo de politica de substituicao
* @param 	fifo, fila para substituicao do tipo fifo
* @param 	lfu, map para substituicao do tipo lfu e lru
* @param 	ciclo, contagem dos ciclos para lru
* @return 	Sem retorno
*/
void fullyAssociative_mapped(Cache *c, Mp *m, int block_cache, int line, int sub, queue<int> &fifo, map<int, int> &lfu, int &ciclo) {
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

/**
* @brief    Funcao que realiza o aplica o mapeamento totalmente associativo
* @param 	c, objeto do tipo Cache
* @param 	m, objeto do tipo Mp
* @param 	block_cache, bloco da memoria principal para substituir na cache
* @param 	line, linhas da memoria cache
* @param 	sub, tipo de politica de substituicao
* @param 	setSize, numero de vias
* @param 	v, matriz para substituicao do tipo lfu e lru e FIFO
* @param 	ciclo, contagem dos ciclos para lru
* @return 	Sem retorno
*/
void parsedAssociative_mapped(Cache *c, Mp *m, int block_cache, int line, int sub, int setSize,  int **v, int &cont) {
	if(sub == 1) { //Aleatorio
		randomP(c, m, line, block_cache, setSize);

	} else if(sub == 2) { //FIFO
		FIFOP(c, m, line, block_cache, setSize, v, cont);

	} else if(sub == 3) { // LFU
		LFUP(c, m, line, block_cache, setSize, v) ;

	} else if(sub == 4) { // LRU
		LRUP(c, m, line, block_cache, setSize, v, cont);
	}
}