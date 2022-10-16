#include <iostream>

#include "class/read.hpp"
#include"class/remocao.hpp"

int Menu();
int Escolha(int op);
void Gerador();


int main() {
	Bin bin;
	AVL avl;
	RB rb;
	int op;

	vector <float> vec;
	vector <float> entrada;
	map <float, float> mapa;
	unordered_map <float, float> u_mapa;

	steady_clock::time_point t1 = steady_clock::now();
	Read r;
	string path;
	r.readEntrada(&entrada);

	Remocao *rem = new Remocao(entrada);

	do {
		system("clear");
		op = Menu();
		r.ResetTime();
		int tamanho = Escolha(op);

		if (tamanho == 0) {
			cout << "Finalizando programa..." << endl;
			delete(rem);
			return EXIT_SUCCESS;
		} else if (tamanho != -1) {
			path.assign(to_string(tamanho));
			r.readFile(path, &bin, &avl, &rb, &vec, &mapa, &u_mapa);

			system("read -p \"Pressione enter para continuar...\n\" continue");

			rem->removerDados(tamanho, &bin, &avl, &rb, &vec, &mapa, &u_mapa);
		} else
			cout << "Opcao invalida!!!" << endl;
		system("read -p \"\nPressione enter para continuar...\n\" continue");

	} while (op != 0);

	// Gerador(); //Comentado para não gerar novos dados.

	return 0;
}

void Gerador() {
	Read r;
	r.saveFile(500);
	r.saveFile(5000);
	r.saveFile(50000);
	r.saveFile(500000);
}

int Escolha(int op) {
	switch (op) {
	case 0: return 0;
	case 1: return 500;
	case 2: return 5000;
	case 3: return 50000;
	case 4: return 500000;
	default: return -1;
	}
}

int Menu() {
	int op;

	cout << " ======== Menu de opções ==========" << endl;
	cout << " [1] 500" << endl;
	cout << " [2] 5000" << endl;
	cout << " [3] 50000" << endl;
	cout << " [4] 500000" << endl;
	cout << " [0] Sair" << endl;

	cin >> op;
	return op;
}