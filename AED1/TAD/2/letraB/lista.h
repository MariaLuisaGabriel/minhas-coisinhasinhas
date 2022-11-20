#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 100

struct aluno
{
    int mat;
    char nome[30];
    float n1;
};

typedef struct lista Lista;

Lista *criar();

void limpar(Lista*l);

int inserirInicio(Lista *l,struct aluno it);

int inserirFim(Lista *l,struct aluno it);

int inserirPosicao(Lista *l,struct aluno it,int pos);

int removerInicio(Lista *l);

int removerFim(Lista *l);

int removerPosicao(Lista *l,int pos);

int removerItem(Lista*l,int chave);

int buscarItemChave(Lista*l,int chave,struct aluno *retorno);

int buscarPosicao(Lista *l,int pos,struct aluno *retorno);

int listaVazia(Lista *l);

int listaCheia(Lista *l);

int tamanho(Lista *l);

void mostrar(Lista *l);

void mostrarAluno(struct aluno *a);

int contemItem(Lista *l,int pos);

int Reversa(Lista *l);

int contaitem(Lista *l, float poss);

#endif