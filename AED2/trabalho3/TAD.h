#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

typedef struct palavra pal;

pal *criaFila();
void insereFila(pal *fila, char *palavra, char *estrofe, char *nome, char *autor);
pal *POPFila(pal *fila);
void mostraFila(pal *fila);

//pal *criaBuscaBin();
void insereBuscaBin(pal *buscaBin, int *tam, pal *no);
void ordenaVetor(pal *buscaBin, int tam);
void Swap(pal *i, pal *j);

pal *criaArvBin();
void insereArvBin();

pal *criaArvAVL();
void insereArvAVL_pal();
void insereArvAVL_freq();

//funçoes de pesquisa para cada tipo de arvore

#endif