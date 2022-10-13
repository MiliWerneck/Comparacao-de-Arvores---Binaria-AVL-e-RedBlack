#ifndef RB_HPP
#define RB_HPP

#include <iostream>
#include "record.hpp"

using namespace std;

class RB {
private:
public:
	TreeRB *raiz;
	Record reg;
	RB();
	~RB();

	void CreateTree(TreeRB **t);

	void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child);
	void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child);

	void insertFixUp(TreeRB **raiz, TreeRB *child);
	void insertTree(TreeRB **t, TreeRB **pai, TreeRB **raiz);
	void pesquisa(TreeRB **t, TreeRB **aux, Record r);

	void preordem(TreeRB *t);
	void central(TreeRB *t);
	void posordem(TreeRB *t);

};

#endif