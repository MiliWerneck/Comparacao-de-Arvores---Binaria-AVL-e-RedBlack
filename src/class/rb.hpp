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

	void inicializaTreeRB(TreeRB **raiz);

	void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child);
	void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child);

	void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x);
	void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w);
	void removeTree(TreeRB **root, TreeRB *aux, Record z);
	void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild);
	void tree_successor(TreeRB *aux_succ, TreeRB **result);

	void insertFixUp(TreeRB **raiz, TreeRB *child);
	void insertTree(TreeRB **t, TreeRB **pai, TreeRB **raiz);
	void pesquisa(TreeRB **t, TreeRB **aux, Record r);

	void preordem(TreeRB *t);
	void central(TreeRB *t);
	void posordem(TreeRB *t);

};

#endif