#ifndef ESTRINGUE_H_INCLUDED
#define ESTRINGUE_H_INCLUDED

typedef struct strring String;

String *criar(char *s);

int tamanho(String *s);

int ocorrencias(String *s, char *d);

void exibir(String *s);

#endif //ESTRINGUE_H_INCLUDED