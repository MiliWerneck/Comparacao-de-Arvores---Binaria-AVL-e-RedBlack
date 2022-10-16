#include "class/rb.hpp"

RB::RB() {}
RB::~RB() {}

TreeRB *temp, *nill;

void RB::inicializaTreeRB(TreeRB **raiz) {
	nill = (TreeRB *)malloc(sizeof(TreeRB));
	nill->cor = black;
	nill->esq = NULL;
	nill->dir = NULL;
	nill->pai = NULL;
	nill->reg.key = 0;
	(*raiz) = nill;
}

void RB::insertFixUp(TreeRB **raiz, TreeRB *child) {
	TreeRB *tio;

	while ((child != *raiz) && (child->pai->cor == red)) {
		if (child->pai == child->pai->pai->esq) {
			tio = child->pai->pai->dir;
			//caso 1:
			if ((tio != nill) && (tio->cor == red)) {
				child->pai->cor = black;
				tio->cor = black;
				child->pai->pai->cor = red;
				child = child->pai->pai;
			} else {
				//caso 2
				if (child == child->pai->dir) {
					child = child->pai;
					rotacaoSimplesEsquerda(raiz, child);
				}
				//caso 3
				child->pai->cor = black;
				child->pai->pai->cor = red;
				rotacaoSimplesDireita(raiz, child->pai->pai);
			}
		} else {
			tio = child->pai->pai->esq;
			//caso 1
			if ((tio != nill) && (tio->cor == red)) {
				child->pai->cor = black;
				tio->cor = black;
				child->pai->pai->cor = red;
				child = child->pai->pai;
			} else {
				//caso 2
				if (child == child->pai->esq) {
					child = child->pai;
					rotacaoSimplesDireita(raiz, child);
				}
				//caso 3
				child->pai->cor = black;
				child->pai->pai->cor = red;
				rotacaoSimplesEsquerda(raiz, child->pai->pai);
			}
		}
	}
	(*raiz)->cor = black;
}

void RB::insertTree(TreeRB **t, TreeRB **pai, TreeRB **raiz) {

	if (*t == nill) {
		*t = (TreeRB *)malloc(sizeof(TreeRB));
		(*t)->esq = nill;
		(*t)->dir = nill;
		(*t)->pai = pai != t ? *pai : nill;
		(*t)->cor = red;
		(*t)->reg = this->reg;
		insertFixUp(raiz, *t);
	} else {
		if (this->reg.key < (*t)->reg.key) {
			insertTree(&(*t)->esq, t, raiz);
			return;
		}
		if (this->reg.key > (*t)->reg.key) {
			insertTree(&(*t)->dir, t, raiz);
			return;
		}
	}
}

void RB::pesquisa(TreeRB **t, TreeRB **aux, Record r) {

	if (*t == nill) {
		printf("[ERROR]: Value not found!");
		return;
	}

	if ((*t)->reg.key > r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key < r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void RB::rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child) {
	TreeRB *x, *y;

	x = child;
	y = child->dir;
	x->dir = y->esq;
	if (y->esq != nill)
		y->esq->pai = x;
	y->pai = x->pai;
	if (x->pai == nill)
		*raiz = y;
	else if (x == x->pai->esq)
		x->pai->esq = y;
	else if (x == x->pai->dir)
		x->pai->dir = y;
	y->esq = x;
	x->pai = y;
}

void RB::rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child) {
	TreeRB *x, *y;

	x = child;
	y = child->esq;
	x->esq = y->dir;

	if (y->dir != nill)
		y->dir->pai = x;
	y->pai = x->pai;
	if (x->pai == nill) {
		*raiz = y;
	} else if (x == x->pai->dir)
		x->pai->dir = y;
	else if (x == x->pai->esq)
		x->pai->esq = y;
	y->dir = x;
	x->pai = y;

}

void RB::removeTree(TreeRB **root, TreeRB *aux, Record z) {
	while (aux != nill && z.key != aux->reg.key) {
		if (z.key < aux->reg.key)
			aux = aux->esq;
		else
			aux = aux->dir;
	}
	if (aux->reg.key == z.key) {
		printf("RedBlack -> ");
		printf("Record %f found!!!\n", z.key);
		RB_delete(root, aux, aux, aux);
	}
}

void RB::RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w) {
	while (x != (*root) && x->cor == black) {
		if (x == x->pai->esq) {
			w = x->pai->dir;
			if (w->cor == red) {
				w->cor = black;
				x->pai->cor = red;
				rotacaoSimplesEsquerda(root, x->pai);
				w = x->pai->dir;
			} else if (w->esq->cor == black && w->dir->cor == black) {
				w->cor = red;
				x = x->pai;
			} else if (w->dir->cor == black) {
				w->esq->cor = black;
				w->cor = red;
				rotacaoSimplesDireita(root, w);
				w = x->pai->dir;
			} else {
				w->cor = x->pai->cor;
				x->pai->cor = black;
				w->dir->cor = black;
				rotacaoSimplesEsquerda(root, x->pai);
				x = (*root);
			}
		} else {
			w = x->pai->esq;
			if (w->cor == red) {
				w->cor = black;
				x->pai->cor = red;
				rotacaoSimplesDireita(root, x->pai);
				w = x->pai->esq;
			} else if (w->dir->cor == black && w->esq->cor == black) {
				w->cor = red;
				x = x->pai;
			} else if (w->esq->cor == black) {
				w->dir->cor = black;
				w->cor = red;
				rotacaoSimplesEsquerda(root, w);
				w = x->pai->esq;
			} else {
				w->cor = x->pai->cor;
				x->pai->cor = black;
				w->esq->cor = black;
				rotacaoSimplesDireita(root, x->pai);
				x = (*root);
			}
		}
	}
	x->cor = black;
}

void RB::RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild) {
	if (aux->pai == nill)
		(*root) = auxchild;
	else if (aux == aux->pai->esq)
		aux->pai->esq = auxchild;
	else
		aux->pai->dir = auxchild;
	auxchild->pai = aux->pai;
}

void RB::RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x) {
	enum type originalcolor;	//keep track of x which moves into y's original position
	originalcolor = y->cor;	//Keep track of original cor

	//case 1
	if (z->esq == nill) {
		x = z->dir;
		RB_transplant(root, z, z->dir);
	}
	//case 2
	else if (z->dir == nill) {
		x = z->esq;
		RB_transplant(root, z, z->esq);
	}
	//two cases: z has both Children
	else {
		tree_successor(z->dir, &y);
		originalcolor = y->cor;
		x = y->dir;

		if (y->pai == z) {
			x->pai = y;
		} else {
			RB_transplant(root, y, y->dir);
			y->dir = z->dir;
			y->dir->pai = y;
		}
		RB_transplant(root, z, y);
		y->esq = z->esq;
		y->esq->pai = y;
		y->cor = z->cor;
	}
	if (originalcolor == black)
		RB_delete_fix(root, x, x);
	free(z);
}

void RB::tree_successor(TreeRB *aux_succ, TreeRB **result) {
	while (aux_succ->esq != nill)
		aux_succ = aux_succ->esq;
	*result = aux_succ;
}

void RB::preordem(TreeRB *t) {
	if (!(t == NULL)) {
		printf("%.4f - %s\t", t->reg.key, t->cor ? "black" : "red");
		preordem(t->esq);
		preordem(t->dir);
	}
}

void RB::central(TreeRB *t) {
	if (!(t == NULL)) {
		central(t->esq);
		printf("%.4f - %s\t", t->reg.key, t->cor ? "black" : "red");
		central(t->dir);
	}
}

void RB::posordem(TreeRB *t) {
	if (!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%.4f - %s\t", t->reg.key, t->cor ? "black" : "red");
	}
}