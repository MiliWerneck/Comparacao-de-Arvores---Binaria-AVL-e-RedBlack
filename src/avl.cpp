#include "class/avl.hpp"

AVL::AVL() {
	this->CreateTree(&this->raiz);
}
AVL::~AVL() {}

void AVL::CreateTree(TreeAVL **t) {
	*t = NULL;
}

void AVL::insertTree(TreeAVL **t) {

	if (*t == NULL) {
		*t = (TreeAVL *)malloc(sizeof(TreeAVL));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = this->reg;

	} else {
		if (this->reg.key < (*t)->reg.key) {
			insertTree(&(*t)->left);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2) {
				if (this->reg.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}
		if (this->reg.key > (*t)->reg.key) {
			insertTree(&(*t)->right);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2) {
				if (this->reg.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void AVL::pesquisa(TreeAVL **t, TreeAVL **aux, Record r) {

	if (*t == NULL) {
		printf("[ERROR]: Node not found!");
		return;
	}
	if ((*t)->reg.key > r.key) { pesquisa(&(*t)->left, aux, r); return; }
	if ((*t)->reg.key < r.key) { pesquisa(&(*t)->right, aux, r); return; }

	*aux = *t;
}

int AVL::isInTree(TreeAVL *t, Record r) {

	if (t == NULL) {
		return 0;
	}
	return t->reg.key == r.key || isInTree(t->left, r) || isInTree(t->right, r);
}

void AVL::antecessor(TreeAVL **t, TreeAVL *aux) {

	if ((*t)->right != NULL) {
		antecessor(&(*t)->right, aux);
		return;
	}
	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void AVL::rebalanceTree(TreeAVL **t) {
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);

}

void AVL::removeTree(TreeAVL **t, TreeAVL **f) {
	TreeAVL *aux;

	if (*t == NULL) {
		return;
	}
	if (this->reg.key < (*t)->reg.key) { removeTree(&(*t)->left, t); return; }
	if (this->reg.key > (*t)->reg.key) { removeTree(&(*t)->right, t); return; }

	if (*t != NULL) {
		printf("AVL -> ");
		printf("Record %f found!!!\n", reg.key);
	}
	if ((*t)->right == NULL) {
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceTree(f);
		return;
	}
	if ((*t)->left != NULL) {
		antecessor(&(*t)->left, *t);
		rebalanceTree(t);
		rebalanceTree(f);
		return;
	}
	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceTree(t);
	rebalanceTree(f);
}

void AVL::preordem(TreeAVL *t) {
	if (!(t == NULL)) {
		printf("%.4f:%d\t", t->reg.key, t->weight);
		preordem(t->left);
		preordem(t->right);
	}
}

void AVL::central(TreeAVL *t) {
	if (!(t == NULL)) {
		central(t->left);
		printf("%.4f\t", t->reg.key);
		central(t->right);
	}
}

void AVL::posordem(TreeAVL *t) {
	if (!(t == NULL)) {
		posordem(t->left);
		posordem(t->right);
		printf("%.4f\t", t->reg.key);
	}
}

int AVL::getWeight(TreeAVL **t) {
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int AVL::getMaxWeight(int left, int right) {
	if (left > right)
		return left;
	return right;
}

void AVL::rotacaoSimplesDireita(TreeAVL **t) {
	TreeAVL *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void AVL::rotacaoSimplesEsquerda(TreeAVL **t) {
	TreeAVL *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void AVL::rotacaoDuplaDireita(TreeAVL **t) {
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void AVL::rotacaoDuplaEsquerda(TreeAVL **t) {
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}