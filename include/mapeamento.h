#ifndef MAPEAMENTO_H
#define MAPEAMENTO_H

#include <iostream>
using std::endl;
using std::cout;

#include <queue>
using std::queue;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <ctime>
#include <cstdlib>

#include "mem.h"
#include "cache.h"
#include "subs.h"


void map_direto(Cache *c, Mem *m, int block_cache, int line) ;

void map_full_associativo(Cache *c, Mem *m, int block_cache, int line, int sub, queue<int> &fifo, map<int, int> &lfu, int &ciclo);

void map_parcial_associativo(Cache *c, Mem *m, int block_cache, int line, int sub, int setSize,  int **v, int &cont) ;

#endif