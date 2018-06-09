#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;
using std::stoi;
using std::getline;

#include <queue>
using std::queue;

#include <map>
using std::map;

#include <unordered_map>
using std::unordered_map;

#include "cache.h"
#include "mem.h"
#include "mapeamento.h"

void ler_config(int &s, int &l, int &b, int &m, int &set_size, int &sub, int &write) {
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

void print(Cache *ca, Mem *mem, int sizeBlock, int block, int line) {
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

void inicia_mem(Mem *mem, int sizeBlock, int block){
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

void inicia_cache(Cache *ca, int sizeBlock, int line) {
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

void minusculas(string& s) {
	for (int i = 0; i < (int)s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}
void print_config(int &s, int &l, int &b, int &m, int &sub){
	cout << "-------- Configuração ------------"<<endl;
	cout << "Tamanho do bloco: " << s <<endl; 
	cout << "Numero de linhas da cache: " << l <<endl;
	cout << "Numero de blocos da memória principal: " << b <<endl;
	cout << "Mapeamento (1 – Direto, 2 – T_Associativo, 3 – P_Associativo): " << m <<endl;
	cout << "Política de substituição (1 – Aleatório, 2 – FIFO, 3 – LFU, 4 – LRU): "<<sub<<endl;
	cout << "----------------------------------"<<endl;
}
int main() {
	
	int sizeBlock, line, block, map, setSize, sub, write, endereco, ciclo = 0;
	string comando = "", elemento, linha;
	queue<int> fifo;
	std::map<int, int> lfu;

	// Leitura das configuracoes
	ler_config(sizeBlock, line, block, map, setSize, sub, write);
	print_config(sizeBlock, line, block, map, sub);
	
	int **v = new int*[line];
	for(int i = 0 ; i < line; i++) {
		v[i] = new int[2];
	}

	// Objeto Cache
	Cache *cache = new Cache[line];

	// Objeto Memoria principal
	Mem *mem = new Mem[block];

	// Inicializando memorias
	inicia_mem(mem, sizeBlock, block);
	inicia_cache(cache, sizeBlock, line);

	//leitura do arquivo de comandos
	ifstream comandos("comandos.txt");

	// Verificando consistencia do arquivo
	if(!comandos) {
		cerr << "Erro na leitura do arquivo de comandos." << endl;
		return 0;
	}
	cout << "Lendo arquivo de comandos !!!\n\n";
	
	while(!comandos.eof()){
		// Leitura dos comandos
		getline(comandos, linha);
		stringstream ss(linha);

		ss >> comando >> elemento;

		minusculas(comando);

		ss.clear();

		if(comando == "read") {
			endereco = stoi(elemento);
			if(endereco >= 0 && endereco <= ((sizeBlock * block) - 1) ){
				int block_cache = endereco / sizeBlock;
				if(map == 1) { //Mapeamento direto
					map_direto(cache, mem, block_cache, line);

				} else if(map == 2) { // Totalmente associativo
					map_full_associativo(cache, mem, block_cache, line, sub, fifo, lfu, ciclo);

				} else if(map == 3) { // Parcialmente associativo
					map_parcial_associativo(cache, mem, block_cache, line, sub, setSize, v, ciclo);

				}
			}
		} else if(comando == "show") {
			print(cache, mem, sizeBlock, block, line);
		}
	}

	for(int i = 0; i < 2; i++)
		delete[] v[i];
	
	delete[] v;
	delete[] cache;
	delete[] mem;
	
	return 0;
}