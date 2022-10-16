#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "record.hpp"

using namespace std;

class AVL {
private:
public:
	TreeAVL *raiz;
	Record reg;
	AVL();
	~AVL();

	void CreateTree(TreeAVL **t);
	void insertTree(TreeAVL **t);
	void pesquisa(TreeAVL **t, TreeAVL **aux, Record r);
	int isInTree(TreeAVL *t, Record r);

	//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
	void removeTree(TreeAVL **t, TreeAVL **f);
	void antecessor(TreeAVL **t, TreeAVL *aux);
	void rebalanceTree(TreeAVL **t);

	void preordem(TreeAVL *t);
	void central(TreeAVL *t);
	void posordem(TreeAVL *t);

	int getWeight(TreeAVL **t);
	int getMaxWeight(int left, int right);

	void rotacaoSimplesDireita(TreeAVL **t);
	void rotacaoSimplesEsquerda(TreeAVL **t);
	void rotacaoDuplaDireita(TreeAVL **t);
	void rotacaoDuplaEsquerda(TreeAVL **t);

};


#endif