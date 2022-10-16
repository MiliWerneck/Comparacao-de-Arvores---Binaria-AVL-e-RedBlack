#include "class/bin.hpp"

Bin::Bin() {
	// cout << "Construiu!!" << endl;
	this->CreateTree(&this->raiz);
}
Bin::~Bin() {
	// cout << "Destruiu!!" << endl;
}

void Bin::CreateTree(Tree **t) {
	*t = NULL;
}

bool Bin::TVazia(Tree **t) {
	return *t == NULL;
}

void Bin::insertTree(Tree **t) {

	if (TVazia(t)) {
		*t = (Tree *)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = this->reg;
	} else {
		if (this->reg.key < (*t)->reg.key) {
			insertTree(&(*t)->esq);
		}
		if (this->reg.key > (*t)->reg.key) {
			insertTree(&(*t)->dir);
		}
	}
}

void Bin::pesquisa(Tree **t, Tree **aux) {

	if (*t == NULL) {
		printf("[ERROR]: Node not found!");
		return;
	}
	if ((*t)->reg.key > this->reg.key) { pesquisa(&(*t)->esq, aux); return; }
	if ((*t)->reg.key < this->reg.key) { pesquisa(&(*t)->dir, aux); return; }
	*aux = *t;
}


int Bin::isInTree(Tree *t, Record r) {

	if (t == NULL) {
		return 0;
	}
	return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void Bin::antecessor(Tree **t, Tree *aux) {

	if ((*t)->dir != NULL) {
		antecessor(&(*t)->dir, aux);
		return;
	}
	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}


void Bin::removeTree(Tree **t) {
	Tree *aux;

	if (*t == NULL) {
		// printf("[ERROR]: Record not found!!!\n");
		return;
	}
	if (this->reg.key < (*t)->reg.key) { removeTree(&(*t)->esq); return; }
	if (this->reg.key > (*t)->reg.key) { removeTree(&(*t)->dir); return; }
	if (*t != NULL) {
		printf("Binaria -> ");
		printf("Record %f found!!!\n", reg.key);
	}
	if ((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		return;
	}
	if ((*t)->esq != NULL) { antecessor(&(*t)->esq, *t); return; }

	aux = *t;
	*t = (*t)->dir;
	free(aux);
}

void Bin::preordem(Tree *t) {
	if (!(t == NULL)) {
		printf("%.4f ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void Bin::central(Tree *t) {
	if (!(t == NULL)) {
		central(t->esq);
		printf("%.4f ", t->reg.key);
		central(t->dir);
	}
}

void Bin::posordem(Tree *t) {
	if (!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%.4f ", t->reg.key);
	}
}