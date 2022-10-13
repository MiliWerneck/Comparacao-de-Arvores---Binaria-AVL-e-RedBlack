#ifndef READ_HPP
#define READ_HPP

#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <random>

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "bin.hpp"
#include "avl.hpp"
#include "rb.hpp"

using namespace std;
using namespace chrono;

class Read {
private:
	steady_clock::time_point t1;
	steady_clock::time_point t2;

	duration<double> time_span;
	duration<double> time_bin;
	duration<double> time_avl;
	duration<double> time_rb;
	duration<double> time_vec;
	duration<double> time_mapa;
	duration<double> time_u_mapa;
public:
	Read();
	~Read();
	void readFile(string caminho, Bin *bin, AVL *avl, RB *rb,
		vector <float> *vec, map <float, float> *mapa, unordered_map <float, float> *u_mapa);
	void saveFile(int TAM);
	void Time(string tamanho);
	void ResetTime();
};

#endif