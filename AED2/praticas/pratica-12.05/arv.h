#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

typedef struct ab arvBin;
arvBin *criaArv();
void insereNo(arvBin **raiz, int valor, char nome[], char sigla[], char end[], int nivel);
int converte(char c[]);
arvBin *removeNo(arvBin *a, int chave, int tipo);
arvBin *buscaArv(arvBin *a, int chave);
void mostraArv(arvBin *a);
void mostraArvAlin(arvBin *a);
void corrigenivel(arvBin *a, int i);
void percursos(arvBin *a, int tipo);
void getValores(arvBin *a);
arvBin *getmenor(arvBin *a);
arvBin *getmaior(arvBin *a);
void altura(arvBin *a, int *i);
#endif