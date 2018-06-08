#include "funcoes.h"

/**
* @brief    	Funcao que realiza a leitura do arquivo com as definicoes da memoria cache
* @param    	sizeBlock, tamanho dos blocos da memoria principal
* @param    	line, quantidade de linhas da memoria cache
* @param    	block, quantidade de blocos da memoria principal
* @param    	map, mapeamento
* @param    	sub, politica de substituicao
* @param    	write, politica de escrita
*/
void configuracao(int &s, int &l, int &b, int &m, int &set_size, int &sub, int &write) {
	string linha;
	int cont = 0;

	// Caminho do arquivo
	ifstream entrada("data/config.txt");

	// Verificando consistencia do arquivo
	if(!entrada) {
		cerr << "Erro na leitura do arquivo de configuracao." << endl;
		return ;
	}

	// contador
	while(getline(entrada, linha))
		cont++;

	// Verificando quantidade de linhas do arquivo de configuracao
	if(cont != 7) {
		cout << "Arquivo de configuracao incompleto!" << endl;
		exit(1) ;
	}

	// Voltando a leitura para o inicio do arquivo
	entrada.clear();
	entrada.seekg(entrada.beg);

	// Leitura das configuracoes
	entrada >> s;
	entrada >> l;
	entrada >> b;
	entrada >> m;
	entrada >> set_size;
	entrada >> sub;
	entrada >> write;
}

/**
* @brief 	Funcao que realiza as operacoes no programa
*/
void init() {
	int sizeBlock, line, block, map, setSize, sub, write, endereco, ciclo = 0;
	string comando = "", elemento, linha;
	queue<int> fifo;
	std::map<int, int> lfu;

	// Leitura das configuracoes
	configuracao(sizeBlock, line, block, map, setSize, sub, write);

	int **v = new int*[line];
	for(int i = 0 ; i < line; i++) {
		v[i] = new int[2];
	}

	// Objeto Cache
	Cache *c = new Cache[line];

	// Objeto Memoria principal
	Mp *mem = new Mp[block];

	// Inicializando memorias
	initMp(mem, sizeBlock, block);
	initCache(c, sizeBlock, line);

	cout << "\nDigite os comandos ('sair' para finalizar o programa)\n";
	do {
		// Leitura dos comandos
		getline(cin, linha);
		stringstream ss(linha);

		ss >> comando >> elemento;

		minusculas(comando);

		ss.clear();

		if(comando == "read")  {
			endereco = stoi(elemento);
			if(endereco >= 0 && endereco <= ((sizeBlock * block) - 1) ){
				int block_cache = endereco / sizeBlock;
				if(map == 1) { //Mapeamento direto
					directed_mapped(c, mem, block_cache, line);

				} else if(map == 2) { // Totalmente associativo
					fullyAssociative_mapped(c, mem, block_cache, line, sub, fifo, lfu, ciclo);

				} else if(map == 3) { // Parcialmente associativo
					parsedAssociative_mapped(c, mem, block_cache, line, sub, setSize, v, ciclo);

				}
			}
		} else if(comando == "show") {
			print(c, mem, sizeBlock, block, line);
		} else if (comando != "sair") {
			cout << "Comando invalido, tente novamente" << endl;
		}
	} while(comando != "sair");

	for(int i = 0; i < 2; i++)
		delete[] v[i];
	
	delete[] v;
	delete[] c;
	delete[] mem;
}

/**
* @brief 	Funcao que inicializa a memoria principal com valores aleatorios
* @param 	mem, objeto do tipo Mp
* @param 	sizeBlock, tamanho do bloco da memoria principal
* @param 	block, quantidade de blocos da memoria principal
* @return 	Sem retorno
*/
void print(Cache *ca, Mp *mem, int sizeBlock, int block, int line) {
	cout << "\nCACHE L1" << endl;
	cout << "Linha - Bloco - Endereco - Conteudo" << endl;
	for(int i = 0; i < line; i++) {
		for(int j = 0; j < sizeBlock; j++) {
			vector<int> v = ca[i].getEndereco();
			vector<int> v2 = ca[i].getConteudo();

			cout << ca[i].getLinha() << " - " << ca[i].getBloco() << " - " << v[j] << " - " << v2[j];
			cout << endl;
		}
	}

	cout << "\n\n\n";

	cout << "Memória Principal" << endl;
	cout << "Bloco - Endereco - Conteudo" << endl;
	for(int i = 0; i < block; i++) {
		for(int j = 0; j < sizeBlock; j++) {
			vector<int> v = mem[i].getEndereco();
			vector<int> v2 = mem[i].getConteudo();
			cout << mem[i].getBloco() << " - " << v[j] << " - " << v2[j];
			cout << endl;
		}
	}
}

/**
* @brief 	Funcao que inicializa a memoria principal com valores aleatorios
* @param 	mem, objeto do tipo Mp
* @param 	sizeBlock, tamanho do bloco da memoria principal
* @param 	block, quantidade de blocos da memoria principal
* @return 	Sem retorno
*/
void initMp(Mp *mem, int sizeBlock, int block){
	// Inicializa a memoria principal
	int aux = 0;
	for(int i = 0; i < block; i++){
		mem[i].setBloco(i);
		int j = 0;
		while(j < sizeBlock){
			mem[i].insertEnd(aux++);
			mem[i].insertCont(aux*5);
			j++;
		}
	}
}

/**
* @brief 	Funcao que inicializa a memoria cache com -1 (vazia)
* @param 	ca, objeto do tipo Cache
* @param 	sizeBlock, tamanho do bloco da memoria cache
* @param 	line, quantidade de linhas da memoria cache
* @return 	Sem retorno
*/
void initCache(Cache *ca, int sizeBlock, int line) {
	// Inicializa memoria cache
	for (int i = 0; i < line; i++) {
		ca[i].setLinha(i);
		ca[i].setBloco(-1);
		int j = 0;
		while(j < sizeBlock){
			ca[i].insertEnd(-1);
			ca[i].insertCont(-1);
			j++;
		}
	}
}

/**
 * @brief Funcao que converte todos os caracteres para letra minuscula
 * @param s String a ser convertida
 */
void minusculas(string& s) {
	for (int i = 0; i < (int)s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}