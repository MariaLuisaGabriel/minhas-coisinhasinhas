#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

typedef struct ab arvBin;
arvBin *criaArv(int raiz);
void insereNo(arvBin *a, int no, int lv);
arvBin *removeNo(arvBin *a, int chave, int tipo);
arvBin *buscaArv(arvBin *a, int chave);
void mostraArv(arvBin *a);
void mostraArvAlin(arvBin *a);
void corrigenivel(arvBin *a, int i);
void percursos(arvBin *a, int tipo);
int getValor(arvBin *a);
int getmenor(arvBin *a);
int getmaior(arvBin *a);
void contTAM(arvBin *a, int aux, int *res);
int maior(arvBin *a);
void niveis(arvBin *a, int *pilha, int *pos);

#endif