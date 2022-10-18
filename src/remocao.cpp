#include "class/remocao.hpp"

Remocao::Remocao() {

}

Remocao::Remocao(vector <float> entrada) {
	setEntrada(entrada);
	ResetTime();
}

Remocao::~Remocao() {}

void Remocao::setEntrada(vector<float> entrada) {
	this->entrada.assign(entrada.begin(), entrada.end());
}

void Remocao::removerDados(int tamanho, Bin *bin, AVL *avl, RB *rb,
	vector <float> *vec, map <float, float> *mapa, unordered_map <float, float> *u_mapa) {

	map <float, float> ::iterator it_mapa;
	unordered_map <float, float> ::iterator it_umapa;
	vector <float> ::iterator it_vec;
	ResetTime();

	for (auto dado : this->entrada) {
		bin->reg.key = dado;
		avl->reg.key = dado;
		rb->reg.key = dado;

		t1 = steady_clock::now();
		bin->removeTree(&bin->raiz);
		t2 = steady_clock::now();
		time_bin += duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		avl->removeTree(&avl->raiz, &avl->raiz);
		t2 = steady_clock::now();
		time_avl += duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		rb->removeTree(&rb->raiz, rb->raiz, rb->reg);
		t2 = steady_clock::now();
		time_rb += duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		it_mapa = mapa->find(dado);
		if (it_mapa != mapa->end()) {
			printf("Map -> ");
			printf("Record %f found!!!\n", dado);
			mapa->erase(it_mapa);
		}
		t2 = steady_clock::now();
		time_mapa += duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		it_umapa = u_mapa->find(dado);
		if (it_umapa != u_mapa->end()) {
			printf("unordered_Map -> ");
			printf("Record %f found!!!\n", dado);
			u_mapa->erase(it_umapa);
		}
		t2 = steady_clock::now();
		time_u_mapa += duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		if (binary_search(vec->begin(), vec->end(), dado)) {
			printf("Vector -> ");
			printf("Record %f found!!!\n\n", dado);
			for (it_vec = vec->begin(); it_vec != vec->end(); ++it_vec) {
				if (*it_vec == dado) {
					vec->erase(it_vec);
					break;
				}
			}
		}
		t2 = steady_clock::now();
		time_vec += duration_cast<duration<double>>(t2 - t1);
	}
	Time(tamanho);
}

void Remocao::Time(int tamanho) {
	cout << "\nEntrada de " << tamanho << " para pesquisa e remocao com 10.000 valores " << endl << endl;;
	cout << "Tempo Árvore Binária: " << time_bin.count() << " seconds" << endl;
	cout << "Tempo Árvore AVL: " << time_avl.count() << " seconds" << endl;
	cout << "Tempo Árvore RedBlack: " << time_rb.count() << " seconds" << endl;
	cout << "Tempo Vector: " << time_vec.count() << " seconds" << endl;
	cout << "Tempo Map: " << time_mapa.count() << " seconds" << endl;
	cout << "Tempo unordereded Map: " << time_u_mapa.count() << " seconds" << endl;
}

void Remocao::ResetTime() {
	t1 = steady_clock::now();
	t2 = steady_clock::now();

	time_bin = duration_cast<duration<double>>(t2 - t1);
	time_avl = duration_cast<duration<double>>(t2 - t1);
	time_rb = duration_cast<duration<double>>(t2 - t1);
	time_vec = duration_cast<duration<double>>(t2 - t1);
	time_mapa = duration_cast<duration<double>>(t2 - t1);
	time_u_mapa = duration_cast<duration<double>>(t2 - t1);
}