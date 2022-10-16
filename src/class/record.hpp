#ifndef RECORD_HPP
#define RECORD_HPP

using namespace std;

enum type { red, black };

typedef struct Record Record;
typedef struct Tree Tree;
typedef struct TreeAVL TreeAVL;
typedef struct TreeRB TreeRB;

struct Record {
	float key;
	float value;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
};

struct TreeAVL {
	Record reg;
	TreeAVL *left, *right;
	int weight;
};

struct TreeRB {
	Record reg;
	TreeRB *esq, *dir;
	TreeRB *pai; //específico para rubro negra
	// bool cor;  //específico para rubro negra (FALSE = VERMELHO, TRUE = PRETO)
	enum type cor;
};
#endif