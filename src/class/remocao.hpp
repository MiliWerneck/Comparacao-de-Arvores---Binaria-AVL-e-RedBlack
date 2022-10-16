#ifndef REMOCAO_HPP
#define REMOCAO_HPP

#include <ctime>
#include <ratio>
#include <chrono>
#include <algorithm>

#include <vector>
#include <map>
#include <unordered_map>

#include "bin.hpp"
#include "avl.hpp"
#include "rb.hpp"

using namespace std;
using namespace chrono;

class Remocao {
private:
	steady_clock::time_point t1;
	steady_clock::time_point t2;

	duration<double> time_bin;
	duration<double> time_avl;
	duration<double> time_rb;
	duration<double> time_vec;
	duration<double> time_mapa;
	duration<double> time_u_mapa;

	vector <float> entrada;
public:
	Remocao();
	Remocao(vector <float> entrada);
	~Remocao();

	void setEntrada(vector<float> entrada);
	void removerDados(int tamanho, Bin *bin, AVL *avl, RB *rb,
		vector <float> *vec, map <float, float> *mapa, unordered_map <float, float> *u_mapa);
	void ResetTime();
	void Time(int tamanho);
};
#endif