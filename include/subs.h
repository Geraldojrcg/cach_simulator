#ifndef SUBS_H
#define SUBS_H

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

void randomT(Cache *c, Mem *m, int line, int block_cache);

void FIFOT(Cache *c, Mem *m, int line, int block_cache, queue<int> &fifo);

void LFUT(Cache *c, Mem *m, int line, int block_cache, map<int, int> &lfu);

void LRUT(Cache *c, Mem *m, int line, int block_cache, map<int, int> &lru, int &ciclo);

void randomMem(Cache *c, Mem *m, int line, int block_cache, int setSize) ;

void FIFOP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v, int &cont);

void LFUP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v);

void LRUP(Cache *c, Mem *m, int line, int block_cache, int setSize, int **v, int &cont);

#endif