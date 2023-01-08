#include <stdio.h>
#include <stdlib.h>
#include "tadd.h"

int main()
{
    Fila *f;
    f = criar();
    char n[30],t='a',r[30];
    int i=1,z=0;
    while(t!='s')
    {
        printf("escreva o nome do paciente a ser atendido: \n");
        scanf(" %[^\n]s",&n);
        insere(f,n);
        printf("\nescreva 's' se quiser sair, 'n' se quiser continuar;\n");
        scanf("  %c",&t);
    }

    printf("\nCHAMADA DOS PACIENTES: ");
    mostrar(f);
    z = remover(f,r);
    if(z==1)
        printf("\nnao ha pacientes na lista!");
    while(z!=1)
    {
        printf("\n%d: %s;",i,r);
        i++;
        z = remover(f,r);
    }
    return 0;
}