#include <iostream>

#include "class/read.hpp"

int Menu();
void Gerador();

int main() {
	Bin bin;
	AVL avl;
	RB rb;
	int op;

	vector <float> vec;
	map <float, float> mapa;
	unordered_map <float, float> u_mapa;

	steady_clock::time_point t1 = steady_clock::now();
	Read r;
	string path;

	do {
		op = Menu();
		r.ResetTime();

		switch (op) {
		case 0:
			cout << "Finalizando programa..." << endl;
			return EXIT_SUCCESS;
		case 1:
			path.assign("500");
			r.readFile(path, &bin, &avl, &rb, &vec, &mapa, &u_mapa);
			break;
		case 2:
			path.assign("5000");
			r.readFile(path, &bin, &avl, &rb, &vec, &mapa, &u_mapa);
			break;
		case 3:
			path.assign("50000");
			r.readFile(path, &bin, &avl, &rb, &vec, &mapa, &u_mapa);
			break;
		case 4:
			path.assign("500000");
			r.readFile(path, &bin, &avl, &rb, &vec, &mapa, &u_mapa);
			break;
		default:
			cout << "Opcao invalida!!!" << endl;
		}

	} while (op != 0);

	// Gerador(); //Comentado para não gerar novos dados.

	steady_clock::time_point t2 = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Tempo: " << time_span.count() << " seconds." << endl;

	return 0;
}

void Gerador() {
	Read r;
	r.saveFile(500);
	r.saveFile(5000);
	r.saveFile(50000);
	r.saveFile(500000);
}

int Menu() {
	int op;

	cout << " ======== Menu ==========" << endl;
	cout << " [1] 500" << endl;
	cout << " [2] 5000" << endl;
	cout << " [3] 50000" << endl;
	cout << " [4] 500000" << endl;
	cout << " [0] Sair" << endl;

	cin >> op;
	return op;
}