#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pA=0,pB=0,pos,j,r,z,k,o=0,n0=0,n1=0,A;
    struct aluno it,retorno;
    Lista *a,*b,*c;
    while(1)
    {
        if(o==0)
        {
            puts("MENU DAS LISTAS:");
            puts("================");
            puts("0-sair;");
            puts("com qual lista quer mecher?");
            puts("-1;");
            puts("-2;");
            printf("\n->");
            scanf("%d",&k);
        }
        if(k==0) break;
        switch(k)
        {
        case 1:
        {
            o=1;
            puts("0-sair;");
            if(pA==0)
                puts("1-criar lista;");
            else
            {
                puts("1-inserir aluno na lista;");
                puts("2-remover aluno da lista;");
                puts("3-buscar item da lista;");
                puts("4-mostrar estado atual da lista;");
                puts("5-mostrar a maior nota entre os alunos da lista;");
                puts("6-limpar lista;");
                puts("7-mudar de lista.");
            }
            break;
        }
        case 2:
        {
            o=1;
            puts("0-sair;");
            if(pB==0)
                puts("1-criar lista;");
            else
            {
                puts("1-inserir aluno na lista;");
                puts("2-remover aluno da lista;");
                puts("3-buscar item da lista;");
                puts("4-mostrar estado atual da lista;");
                puts("5-mostrar a maior nota entre os alunos da lista;");
                puts("6-limpar lista.");
                puts("7-mudar de lista");
            }
            break;
        }
        }
        printf("\nescreva seu comando->");
        scanf("%d",&j);
        if(j==0) break;
        if((j==1)&&(k==1)&&(n0==0))
        {
            a = criar();
            n0=1;
            pA=1;
            A=1;
        }
        else if((j==1)&&(k==2)&&(n1==0))
        {
            b = criar();
            n1=1;
            pB=1;
            A=1;
        }
        else
        {
            j=j+1;
        }
        switch(j)
        {
            case 2:
            {
                puts("\n");
                puts("INSERCAO DE ELEMENTOS:");
                puts("======================");
                puts("1-inserir no inicio da lista;");
                if(k==1)
                {
                    if(A==0)
                        {
                            puts("2-inserir no final da lista;");
                            puts("3-inserir numa posicao especifica.");
                        }
                }
                else
                {
                    if(A==0)
                        {
                            puts("2-inserir no final da lista;");
                            puts("3-inserir numa posicao especifica.");
                        }
                }
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
                        if(k==1)
                        {
                            r = inserirInicio(a,it);
                        }
                        else 
                        {
                            r = inserirInicio(b,it);
                        }
                        switch(r)
                        {
                            case 1:
                                break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nAlista inexistente!\n");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nBlista inexistente!\n");
                                    pB=0;
                                }
                                break;
                            }
                        }
                        A=0;
                        break;
                    }
                    case 2:
                    {
                        if(k==1) r = inserirFim(a,it);
                        else r = inserirFim(b,it);
                        switch(r)
                        {
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("\ninsira a posicao desejada(posicao minima: 0,posicao maxima: 100, o dado sera alocado n): ");
                        scanf("%d",&pos);
                        if(k==1) r = inserirPosicao(a,it,pos);
                        else r = inserirPosicao(b,it,pos);
                        switch(r)
                        {
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                            case 8:
                                printf("\nposicao atras dos limites da lista!");break;
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
                puts("4-remover por chave de matricula;");
                puts("5-remover tudo a partir de uma certa posiçao.");
                printf("\n->");
                scanf("%d",&z);
                switch(z)
                {
                    case 1:
                    {
                        if(k==1) r = removerInicio(a);
                        else r = removerInicio(b);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        if(k==1) r = removerFim(a);
                        else r = removerFim(b);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("\ninsira a posicao desejada(posicao minima: 0, posicao maxima: 100, o dado sera alocado n): ");
                        scanf("%d",&pos);
                        if(k==1) r = removerPosicao(a,pos);  
                        else removerPosicao(b,pos);               
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                            case 8:
                                printf("\nposicao alem dos limites da lista!");break;
                        }
                        break;
                    }
                    case 4:
                    {
                        printf("\ninsira a chave de matricula:");
                        scanf("%d",&pos);
                        if(k==1) r = removerItem(a,pos);
                        else r = removerItem(b,pos);
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                            case -1:
                                printf("\nelemento nao existe na lista!\n");break;
                        }
                        break;
                    }
                    case 5:
                    {
                        printf("\ninsira a posicao desejada(posicao minima: 0, posicao maxima: 100, o dado sera alocado n): ");
                        scanf("%d",&pos);
                        if(k==1) r = removerapartir(a,pos);
                        else r = removerapartir(b,pos);                 
                        switch(r)
                        {
                            case 0:
                                printf("\nlista vazia!\n");break;
                            case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                            case 8:
                                printf("\nposicao alem dos limites da lista!");break;
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
                    if(k==1) r = buscarItemChave(a,pos,&retorno);
                    else r = buscarItemChave(b,pos,&retorno);
                    switch(r)
                    {
                        case 1:
                            mostrarAluno(&retorno);break;
                        case 0:
                            printf("\nlista vazia!\n");break;
                        case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                        case 8:
                            printf("\naluno nao existe na lista!\n");break;
                    }
                }
                if(z==2)
                {
                    printf("\ninsira a posicao do aluno na fila: ");
                    scanf("%d",&pos);
                    if(k==1) r = buscarPosicao(a,pos,&retorno);
                    else r = buscarPosicao(b,pos,&retorno);
                    switch(r)
                    {
                        case 1:
                            mostrarAluno(&retorno);break;
                        case 0:
                            printf("\nlista vazia!\n");break;
                        case 2:
                            {
                                if(k==1)
                                {
                                    printf("\nlista inexistente!");
                                    pA=0;
                                }
                                else
                                {
                                    printf("\nlista inexistente!");
                                    pB=0;
                                }
                                break;
                            }
                        case 8:
                            printf("\nposicao alem dos limites da lista!");break;
                    }
                }
                break;
            }
            case 5:
            {
                if(k==1)
                {
                    puts("\n");
                    mostrar(a);
                    puts("\n");
                }
                if(k==2)
                {
                    puts("\n");
                    mostrar(b);
                    puts("\n");
                }
                break;
            }
            case 6:
            {
                if(k==1) 
                {
                    printf("yey");
                    r = maiorNota(a,&retorno);
                }
                else
                {
                    r = maiorNota(b,&retorno);
                }
                switch(r)
                {
                    case 0:
                        printf("\nlista inexistente!");break;
                    case 2:
                    {
                        if(k==1)
                        {
                            printf("\nlista inexistente!");
                            pA=0;
                        }
                        else
                        {
                            printf("\nlista inexistente!");
                            pB=0;
                        }
                        break;
                    }
                    case 1:
                    {
                        puts("o aluno com maior nota da lista é:");
                        mostrarAluno(&retorno);
                    }
                }
                break;
            }
            case 7:
            {
                if(k==1)
                {
                    limpar(a);A=1;
                }
                if(k==2)
                {
                    limpar(b);A=1;
                }
                break;
            }
            case 8:
            {
                o=0;
                break;
            }
        }
    }
    puts("FIM DA EDICAO DAS LISTAS!!");
    if((pA!=0)&&(a!=NULL))
    {
        printf("\ntamanho final da lista 1: %d\n",tamanho(a));
        puts("LISTA CRIADA: ");
        mostrar(a);
    }
    if((pB!=0)&&(b!=NULL))
    {
        printf("\ntamanho final da lista 2: %d\n",tamanho(b));
        puts("LISTA CRIADA: ");
        mostrar(b);
    }
    if((a!=NULL)&&(b!=NULL))
    {
        c = criar();
        r = concatena(a,b,c);
        switch(r)
        {
            case 0:
                puts("lista 1 nao existe!");break;
            case -1:
                puts("lista 2 nao existe!");break;
            case -2:
                puts("lista concatenada inexistente!");break;
            case 1:
            {
                puts("LISTA RESULTANTE DA CONCATENACAO DAS LISTAS 1 E 2:");
                printf("\ntamanho final da lista 3: %d\n",tamanho(c));
                puts("LISTA CRIADA: ");
                mostrar(c);
                break;
            }
        }
    }
    return 0;
}