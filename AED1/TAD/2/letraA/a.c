#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p=0,pos,j,r,z;
    struct aluno it,retorno;
    Lista *a;
    while(1)
    {
        puts("MENU DAS LISTAS:");
        puts("================");
        puts("0-sair;");
        puts("1-criar lista;");
        if(p==1)
        {
            puts("2-inserir aluno na lista;");
            puts("3-remover aluno da lista;");
            puts("4-buscar item da lista;");
            puts("5-mostrar estado atual da lista;");
            puts("6-limpar .");
        }
        printf("\nescreva seu comando->");
        scanf("%d",&j);
        if(j==0) break;
        switch(j)
        {
            case 1:
            {
                a = criar();
                p=1;
                break;
            }
            case 2:
            {
                puts("\n");
                puts("INSERCAO DE ELEMENTOS:");
                puts("======================");
                puts("1-inserir no inicio da lista;");
                puts("2-inserir no final da lista;");
                puts("3-inserir numa posicao especifica.");
                printf("\n->");
                scanf("%d",&z);
                //captura dos dados do aluno a inserir:
                printf("\nnome do aluno: ");
                scanf(" %[^\n]s",it.nome);
                printf("\nnumero de matricula: ");
                scanf("%d",&it.mat);
                printf("\nnota do aluno: ");
                scanf("%f",&it.n1);
                switch(z)
                {
                    case 1:
                    {
                        r = inserirInicio(a,it);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista cheia!");break;
                            case 2:
                                printf("\nlista inexistente!");p=0;break;
                        }
                        break;
                    }
                    case 2:
                    {
                        r = inserirFim(a,it);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista cheia!");break;
                            case 2:
                                printf("\nlista inexistente!");p=0;break;
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("\ninsira a posicao desejada(posicao minima: 0,posicao maxima: 100, o dado sera alocado n): ");
                        scanf("%d",&pos);
                        r = inserirPosicao(a,it,pos);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista cheia!");break;
                            case 2:
                                printf("\nlista inexistente!");p=0;break;
                            case 8:
                                printf("\nposicao alem dos limites da lista!");break;
                        }
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                puts("\n");
                puts("REMOCAO DE ELEMENTOS:");
                puts("=====================");
                puts("1-remover do inicio da lista;");
                puts("2-remover do final da lista;");
                puts("3-remover de uma posicao especifica;");
                puts("4-remover por chave de matricula.");
                printf("\n->");
                scanf("%d",&z);
                switch(z)
                {
                    case 1:
                    {
                        r = removerInicio(a);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                                printf("\nlista inexistente!\n");p=0;break;
                        }
                        break;
                    }
                    case 2:
                    {
                        r = removerFim(a);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                                printf("\nlista inexistente!\n");p=0;break;
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("\ninsira a posicao desejada(posicao minima: 0, posicao maxima: 100, o dado sera alocado n): ");
                        scanf("%d",&pos);
                        r = removerPosicao(a,pos);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                                printf("\nlista inexistente!\n");p=0;break;
                            case 8:
                                printf("\nposicao alem dos limites da lista!");break;
                        }
                        break;
                    }
                    case 4:
                    {
                        printf("\ninsira a chave de matricula:");
                        scanf("%d",&pos);
                        r = removerItem(a,pos);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                                printf("\nlista inexistente!\n");p=0;break;
                        }
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                puts("BUSCA POR ITEM:");
                puts("===============");
                puts("1-busca por chave de matricula;");
                puts("2-busca por posicao na lista.");
                printf("\n->");
                scanf("%d",&z);
                if(z==1)
                {
                    printf("\ninsira a chave de matricula: ");
                    scanf("%d",&pos);
                    r = buscarItemChave(a,pos,&retorno);
                    switch(r)
                    {
                        case 1:
                            mostrarAluno(&retorno);break;
                        case 0:
                            printf("\nlista vazia!\n");break;
                        case 2:
                            printf("\nlista inexistente!\n");p=0;break;
                    }
                }
                if(z==2)
                {
                    printf("\ninsira a posicao do aluno na fila: ");
                    scanf("%d",&pos);
                    r = buscarPosicao(a,pos,&retorno);
                    switch(r)
                    {
                        case 1:
                            mostrarAluno(&retorno);break;
                        case 0:
                            printf("\nlista vazia!\n");break;
                        case 2:
                            printf("\nlista inexistente!\n");p=0;break;
                        case 8:
                            printf("\nposicao alem dos limites da lista!");break;
                    }
                }
                break;
            }
            case 5:
            {
                puts("\n");
                mostrar(a);
                puts("\n");
                break;
            }
            case 6:
            {
                limpar(a);
                break;
            }
        }
    }
    puts("FIM DA EDICAO DA LISTA!!");
    printf("\ntamanho final da lista: %d\n",tamanho(a));
    puts("LISTA CRIADA: ");
    mostrar(a);
    return 0;
}