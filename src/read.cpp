#include "class/read.hpp"

Read::Read() { ResetTime(); }
Read::~Read() {}

void Read::readEntrada(vector <float> *entrada) {
	string caminho;

	caminho.assign("src/files/").append("entrada.txt");
	ifstream myfile(caminho);
	string line;

	if (myfile.is_open()) {

		while (getline(myfile, line)) {
			entrada->push_back(stof(line));
		}
	}
}

void Read::readFile(string caminho, Bin *bin, AVL *avl, RB *rb,
	vector <float> *vec, map <float, float> *mapa, unordered_map <float, float> *u_mapa) {

	string tamanho = caminho;

	caminho.insert(0, "src/files/").append(".txt");
	ifstream myfile(caminho);
	string line;
	float aux;

	bin->CreateTree(&bin->raiz);
	avl->CreateTree(&avl->raiz);
	// rb->CreateTree(&rb->raiz);
	rb->inicializaTreeRB(&rb->raiz);

	if (myfile.is_open()) {

		while (getline(myfile, line)) {
			aux = stof(line);

			bin->reg.key = aux;
			avl->reg.key = aux;
			rb->reg.key = aux;

			t1 = steady_clock::now();
			bin->insertTree(&bin->raiz);
			t2 = steady_clock::now();
			time_bin += duration_cast<duration<double>>(t2 - t1);

			t1 = steady_clock::now();
			avl->insertTree(&avl->raiz);
			t2 = steady_clock::now();
			time_avl += duration_cast<duration<double>>(t2 - t1);

			t1 = steady_clock::now();
			rb->insertTree(&rb->raiz, &rb->raiz, &rb->raiz);
			t2 = steady_clock::now();
			time_rb += duration_cast<duration<double>>(t2 - t1);

			t1 = steady_clock::now();
			vec->push_back(aux);
			t2 = steady_clock::now();
			time_vec += duration_cast<duration<double>>(t2 - t1);

			t1 = steady_clock::now();
			mapa->insert({ aux,0 });
			t2 = steady_clock::now();
			time_mapa += duration_cast<duration<double>>(t2 - t1);

			t1 = steady_clock::now();
			u_mapa->insert({ aux,0 });
			t2 = steady_clock::now();
			time_u_mapa += duration_cast<duration<double>>(t2 - t1);
		}

		t1 = steady_clock::now();
		sort(vec->begin(), vec->end()); //Ordenar o vec
		t2 = steady_clock::now();
		time_vec += duration_cast<duration<double>>(t2 - t1);

		myfile.close();
		Time(tamanho);

	} else cout << "Nao foi possivel abrir o arquivo" << endl;
	cout << endl;
}

void Read::Time(string tamanho) {
	cout << "Entrada de " << tamanho << " valores" << endl << endl;;
	cout << "Tempo Árvore Binária: " << time_bin.count() << " seconds" << endl;
	cout << "Tempo Árvore AVL: " << time_avl.count() << " seconds" << endl;
	cout << "Tempo Árvore RedBlack: " << time_rb.count() << " seconds" << endl;
	cout << "Tempo Vector: " << time_vec.count() << " seconds" << endl;
	cout << "Tempo Map: " << time_mapa.count() << " seconds" << endl;
	cout << "Tempo Unordered Map: " << time_u_mapa.count() << " seconds" << endl;
}

void Read::ResetTime() {
	t1 = steady_clock::now();
	t2 = steady_clock::now();

	time_bin = duration_cast<duration<double>>(t2 - t1);
	time_avl = duration_cast<duration<double>>(t2 - t1);
	time_rb = duration_cast<duration<double>>(t2 - t1);
	time_vec = duration_cast<duration<double>>(t2 - t1);
	time_mapa = duration_cast<duration<double>>(t2 - t1);
	time_u_mapa = duration_cast<duration<double>>(t2 - t1);
}

void Read::saveFile(int TAM) {
	string caminho;

	caminho.assign("src/files/").append(to_string(TAM)).append(".txt");

	map<string, string> ::iterator it;
	ofstream out(caminho);

	unordered_map<float, int> valores;
	unordered_map<float, int> ::iterator itr;

	while (valores.size() < TAM) {
		random_device seed;
		mt19937 gen(seed());
		uniform_real_distribution<float> dis(10, 99);
		valores.insert({ dis(seed),0 });
	}

	if (out.is_open()) {
		for (itr = valores.begin(); itr != valores.end(); ++itr) {
			out << itr->first << endl;
		}
		out.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}