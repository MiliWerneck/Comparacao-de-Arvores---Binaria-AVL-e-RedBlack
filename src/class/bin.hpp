#ifndef BIN_HPP
#define BIN_HPP

#include <iostream>
#include "record.hpp"

using namespace std;

class Bin {
private:
public:
	Tree *raiz;
	Tree *raizAux;
	Record reg;

	Bin();
	~Bin();

	void CreateTree(Tree **t);
	bool TVazia(Tree **t);
	void insertTree(Tree **t);
	void pesquisa(Tree **t, Tree **aux);
	int isInTree(Tree *t, Record r);

	void removeTree(Tree **t);
	void antecessor(Tree **t, Tree *aux);

	void preordem(Tree *t);
	void central(Tree *t);
	void posordem(Tree *t);
	void widthPath(Tree *t);

};


#endif