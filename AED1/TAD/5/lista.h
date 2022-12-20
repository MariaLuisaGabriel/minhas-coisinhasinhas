#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED

typedef struct aluno
{
    char nome[30];
    int mat;
    float nota;
}AL;
typedef struct No no;
typedef struct lista Lista;

Lista *criar();

int cadastrarinicio(Lista *l, AL *aluno);

int cadastrarfim(Lista *l, AL *aluno);

int cadastrarposicao(Lista *l, AL *aluno, int pos);

int removerinicio(Lista *l);

int removerfim(Lista *l);

int removerposicao(Lista *l, int pos);

void mostrar(Lista *l);

void limpar(Lista *l);

int maiornota(Lista *l,AL *aluno);

int troca(Lista *l,int pos1, int pos2);

int ordemmat(Lista *l);

int semelhanca(Lista *l, Lista *k);

void mostrarAluno(AL *a);

int buscarPosicao(Lista *l,int pos,AL *retorno);

int tamanho(Lista *l);

#endif