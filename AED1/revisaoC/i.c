/*
Faça um programa que cria uma estrutura livro, que contém os elementos título, ano de edição,número de páginas e preço. Criar uma variável dessa estrutura que é um vetor de 5 elementos.
Ler os valores para a estrutura e imprimir a média do número de páginas dos livros.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct livro
{
    char ti[31];
    int ano;
    int pag;
    int pre;
};
int Inserir(struct livro *i);
int Remover(struct livro *n);
int Mover(struct livro *w,struct livro *d);
void MoverAlt(struct livro *r,struct livro *t);
int main()
{
    struct livro li[6];
    int b,c,i=0;
    char com[2];
    int ls=0;
    int Ls=0;
    char ins[6];
    for(int j=0;j<5;j++)
    {
        li[j].ano = 0;
        li[j].pag = 0;
        li[j].pre = 0;
        ins[j]=0;
    }
    while(1)
    {
        c=0;
        for(b=0;b<5;b++)
        {
            if(ins[b]==0)
                c++;
        }
        fflush(stdin);
        printf("Ola! por esse MENU voce tera como inserir 5 livros da sua preferencia, com as devidas informacoes, numa lista.\n");
        puts("|MENU");
        puts("|====");
        if(ins[0]==0)
            printf("|livro 1:");
        else
            printf("|livro 1: %s, do ano de %d, com %d paginas e custando $%d.",li[0].ti,li[0].ano,li[0].pag,li[0].pre);
        if(ins[1]==0)
            printf("\n|livro 2:");
        else
            printf("\n|livro 2: %s, do ano de %d, com %d paginas e custando $%d.",li[1].ti,li[1].ano,li[1].pag,li[1].pre);
        if(ins[2]==0)
            printf("\n|livro 3:");
        else
            printf("\n|livro 3: %s, do ano de %d, com %d paginas e custando $%d.",li[2].ti,li[2].ano,li[2].pag,li[2].pre);
        if(ins[3]==0)
            printf("\n|livro 4:");
        else
            printf("\n|livro 4: %s, do ano de %d, com %d paginas e custando $%d.",li[3].ti,li[3].ano,li[3].pag,li[3].pre);
        if(ins[4]==0)
            printf("\n|livro 5:");
        else
            printf("\n|livro 5: %s, do ano de %d, com %d paginas e custando $%d.",li[4].ti,li[4].ano,li[4].pag,li[4].pre);
        printf("\n*para inserir um livro, escreva I\n*para retirar um livro, escreva R\n*para mover um livro na lista, escreva M\n*para sair do MENU, escreva S:\n->");
        scanf("%s",com);
        if(strlen(com)>1)
        {
            printf("\nERRO: escreva um comando por vez!\n\n");
            return -1;
        }
        else
        {
            if(strcmp(com,"I")==0||strcmp(com,"i")==0)
            {
                if(c==0)
                {
                    printf("\nops! lista completa! remova um livro da lista para inserir outro!\n\n");
                }
                else
                {
                    printf("em qual lugar da lista deseja inserir o livro? ");
                    scanf("%d",&ls);
                    if(isdigit(c)==0)
                    {
                        printf("\ninsira somente numeros!\n\n");
                        setbuf(stdin,0);
                    }
                    else if(ls<1||ls>5)
                    {
                    printf("\ninsira um numero de 1 a 5!\n\n");
                    }
                    else
                    {
                        if(ins[ls-1]==1)
                        {
                            printf("\nopa! ja existe um livro nessa posicao da lista!\n\n");
                        }
                        else
                            ins[ls-1]=Inserir(&li[ls-1]);
                    }
                }
            }
            else if(strcmp(com,"R")==0||strcmp(com,"r")==0)
            {
                if(c==5)
                {
                    printf("\nnao ha livros na lista a serem removidos!\n\n");
                }
                else
                {
                    printf("em qual local esta o livro que deseja remover da lista? ");
                    scanf("%d",&ls);
                    if(isdigit(c)==0)
                    {
                        printf("\ninsira somente numeros!\n\n");
                        setbuf(stdin,0);
                    }
                    else if(ls<1||ls>5)
                    {
                        printf("\ninsira um numero de 1 a 5!\n\n");
                    }
                    else
                    {   
                        ins[ls-1]=Remover(&li[ls-1]);
                    }
                }
            }
            else if(strcmp(com,"M")==0||strcmp(com,"m")==0)
            {
                if(c==5)
                {
                    printf("\nnao ha livros na lista a serem movidos!\n\n");
                }
                else
                {
                    printf("qual o local do livro na lista que sera movido? ");
                    scanf("%d",&ls);
                    if(isdigit(c)==0)
                    {
                        printf("\ninsira somente numeros!\n\n");
                        setbuf(stdin,0);
                    }
                    else if(ls<1||ls>5)
                    {
                        printf("\ninsira um numero de 1 a 5!\n\n");
                    }
                    else
                    {
                        printf("para qual local da lista deseja mover o livro? ");
                        scanf("%d",&Ls);
                        if(ins[Ls-1]==0)
                        {
                            ins[ls-1]=Mover(&li[ls-1],&li[Ls-1]);
                            ins[Ls-1]=1;
                        }
                        else
                        {
                            MoverAlt(&li[ls-1],&li[Ls-1]);
                        }
                    }
                }
            }
            else if(strcmp(com,"S")==0||strcmp(com,"s")==0)
                break;
            else
            {
                printf("\nesse comando nao existe...\n\n");
            }
        }
    }
    if(c==5)
        printf("\nMEDIA DAS PAGINAS DE TODOS OS LIVROS LISTADOS: 0");
    else
        printf("\nMEDIA DAS PAGINAS DE TODOS OS LIVROS LISTADOS: %d",(li[0].pag + li[1].pag + li[2].pag + li[3].pag + li[4].pag)/(5-c) );
    return 0;
}
int Inserir(struct livro *u)
{
    setbuf(stdin,0);
    printf("\n1-escreva o titulo do livro:");
    scanf("%[^\n]s",u->ti);
    printf("\n2-escreva o ano em que o livro foi publicado/editado:");
    scanf("%d",&u->ano);
    printf("\n3-escreva o numero de paginas desse livro:");
    scanf("%d",&u->pag);
    printf("\n4-escreva o preco desse livro: $");
    scanf("%d",&u->pre);
    return 1;
}
int Remover(struct livro *n)
{
    n->pag=0;
    return 0;
}
int Mover(struct livro *w,struct livro *d)
{
    d->ano = w->ano;
    d->pag = w->pag;
    d->pre = w->pre;
    strcpy(d->ti,w->ti);
    return 0;
}
void MoverAlt(struct livro *r,struct livro *t)
{
    struct livro compt;
    compt.ano=r->ano;
    compt.pag=r->pag;
    compt.pre=r->pre;
    printf("\n%d\n",compt.pre);
    strcpy(compt.ti,r->ti);
    r->ano=t->ano;
    r->pag=t->pag;
    r->pre=t->pre;
    strcpy(r->ti,t->ti);
    t->ano=compt.ano;
    t->pag=compt.pag;
    t->pre=compt.pre;
    printf("\n%d\n",t->pre);
    strcpy(t->ti,compt.ti);
}