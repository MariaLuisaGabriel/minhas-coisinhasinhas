#ifndef TADC_H_INCLUDED
#define TADC_H_INCLUDED

typedef struct pilha Pilha;
Pilha *criar();
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
int mostrar(Pilha *p);
int push(Pilha *p, char it);
int pop(Pilha *p, char *it);
int palindromo(Pilha *p);
int limpar(Pilha *p);
int delimitadores(Pilha *p);
int copia(Pilha *p, char it[]);
int converte(Pilha *p);
int potencia2(int p);

#endif