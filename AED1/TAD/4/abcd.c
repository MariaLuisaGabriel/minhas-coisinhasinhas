#include "listadupla.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pA=0,pB=0,pos,j,r,z,k,o=0,n0=0,n1=0,A;
    AL it,*retorno;
    Lista *a,*b;
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
                puts("1-cadastrar aluno;");
                puts("2-remover aluno da lista;");
                puts("3-mostrar estado atual da lista;");
                puts("4-mostrar a maior nota entre os alunos da lista;");
                puts("5-trocar dois elementos de posicao na lista;");
                puts("6-verificar se ha semelhanca entre as duas listas;");
                puts("7-verificar se a lista esta em ordem crescente;");
                puts("8-limpar lista;");
                puts("9-mudar de lista.");
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
                puts("1-cadastrar aluno;");
                puts("2-remover aluno da lista;");
                puts("3-mostrar estado atual da lista;");
                puts("4-mostrar a maior nota entre os alunos da lista;");
                puts("5-trocar dois elementos de posicao na lista;");
                puts("6-verificar se ha semelhanca entre as duas listas;");
                puts("7-verificar se a lista esta em ordem crescente;");
                puts("8-limpar lista;");
                puts("9-mudar de lista.");
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
                puts("CADASTRAR ALUNO:");
                puts("================");
                puts("1-cadastrar no inicio da lista;");
                if(k==1)
                {
                    if(A==0)
                        {
                            puts("2-cadastrar no final da lista;");
                            puts("3-cadastrar numa posicao especifica.");
                        }
                }
                else
                {
                    if(A==0)
                        {
                            puts("2-cadastrar no final da lista;");
                            puts("3-cadastrar numa posicao especifica.");
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
                scanf("%f",&it.nota);
                switch(z)
                {
                    case 1:
                    {
                        if(k==1)
                        {
                            r = cadastrarinicio(a,&it);
                        }
                        else 
                        {
                            r = cadastrarinicio(b,&it);
                        }
                        switch(r)
                        {
                            case 0:
                                break;
                            case -1:
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
                        if(k==1) r = cadastrarfim(a,&it);
                        else r = cadastrarfim(a,&it);
                        switch(r)
                        {
                            case -1:
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
                        if(k==1) r = cadastrarposicao(a,&it,pos);
                        else r = cadastrarposicao(a,&it,pos);
                        switch(r)
                        {
                            case -1:
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
                printf("\n->");
                scanf("%d",&z);
                switch(z)
                {
                    case 1:
                    {
                        if(k==1) r = removerinicio(a);
                        else r = removerinicio(b);
                        switch(r)
                        {
                            case 1:
                                printf("\nlista vazia!\n");break;
                            case -1:
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
                        if(k==1) r = removerfim(a);
                        else r = removerfim(b);
                        switch(r)
                        {
                            case 1:
                                printf("\nlista vazia!\n");break;
                            case -1:
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
                        if(k==1) r = removerposicao(a,pos);  
                        else removerposicao(b,pos);               
                        switch(r)
                        {
                            case -3:
                                printf("\nlista vazia!\n");break;
                            case -1:
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
                                printf("\nposicao alem dos limites da lista!");break;
                        }
                        break;
                    }
                }
                break;
            }
            case 4://mostrar estado atual da lista
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
            case 5://maior nota da lista
            {
                if(k==1) 
                {
                    r = maiornota(a,retorno);
                }
                else
                {
                    r = maiornota(b,retorno);
                }
                switch(r)
                {
                    case -1:
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
                        printf("\nlista vazia!\n");break;
                    case 0:
                    {
                        puts("o aluno com maior nota da lista é:");
                        mostrarAluno(retorno);
                        break;
                    }
                }
                break;
            }
            case 6://trocar dois elementos de posicao
            {
                printf("\nescreva duas posicoes que deseja trocar: ");
                scanf("%d %d",&pos,&z);
                if(k==1)
                {
                    r = troca(a,pos,z);
                    switch(r)
                    {
                        case -3:
                            printf("\nlista vazia!\n");break;
                        case -1:
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
                            printf("\nposicao alem dos limites da lista!");break;
                        }
                    break;
                }
                else
                {
                    r = troca(b,pos,z);
                    switch(r)
                    {
                        case -3:
                            printf("\nlista vazia!\n");break;
                        case -1:
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
                            printf("\nposicao alem dos limites da lista!");break;
                        }
                    break;
                }
            }
            case 7://verificar semelhança entre duas listas
            {
                r = semelhanca(a,b);
                switch(r)
                {
                    case -1:
                        printf("\nlista vazia!\n");break;
                    case 1:
                    {
                        printf("\nlista 1 e 2 nao sao semelhantes.");
                        break;
                    }
                }
                break;
            }
            case 8://verificar ordem da lista
            {
                if(k==1)
                {
                    r = ordemmat(a);
                    switch(r)
                    {
                        case -1:
                        {
                            printf("\nlista inexistente!");
                            pA = 0;
                        }
                        case 2:
                        {
                            printf("\nlista vazia!");
                        }
                        case 1:
                            printf("\na lista nao esta em ordem crescente.");break;
                        case 0:
                            printf("\na lista esta em ordem crescente.");break;
                    }
                }
                else
                {
                    r = ordemmat(b);
                    switch(r)
                    {
                        case -1:
                        {
                            printf("\nlista inexistente!");
                            pA = 0;
                        }
                        case 2:
                        {
                            printf("\nlista vazia!");
                        }
                        case 1:
                            printf("\na lista nao esta em ordem crescente.");break;
                        case 0:
                            printf("\na lista esta em ordem crescente.");break;
                    }
                }
            }
            case 9://limpar lista
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
            case 10://mudar de lista
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
    return 0;
}